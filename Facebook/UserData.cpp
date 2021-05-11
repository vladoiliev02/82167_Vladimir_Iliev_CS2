#include <fstream>
#include "UserData.h"

UserData::UserData(std::string name, unsigned short age,
                   std::string regDate, std::vector<PictureData> pictures)
        : name(std::move(name)), age(age), regDate(std::move(regDate)),
          pictures(std::move(pictures))
{}

void UserData::writeUserData(std::ofstream& ofs)
{
    ofs.write((const char*) &age, sizeof(unsigned short));
    size_t nameLen = name.length();
    ofs.write((const char*) &nameLen, sizeof(size_t));
    ofs.write((const char*) name.c_str(), nameLen * sizeof(char));
    size_t regDateLen = regDate.length();
    ofs.write((const char*) &regDateLen, sizeof(size_t));
    ofs.write((const char*) regDate.c_str(), regDateLen * sizeof(char));
    if (!ofs.good())
        throw std::runtime_error("User Data writing error");

    size_t picturesSize = pictures.size();
    ofs.write((const char*) &picturesSize, sizeof(size_t));
    for (size_t i = 0; i < picturesSize; ++i) {
        pictures[i].writePictureData(ofs);
        if (!ofs.good())
            throw std::runtime_error("User Data writing error");
    }
}

void UserData::readUserData(std::ifstream& ifs)
{
    ifs.read((char*) &age, sizeof(unsigned short));
    size_t nameLen;
    ifs.read((char*) &nameLen, sizeof(size_t));
    char* name = new char [nameLen+1];
    ifs.read((char*) name, nameLen * sizeof(char));
    name[nameLen] = '\0';
    this->name = std::string(name);
    delete[] name;

    size_t regDateLen;
    ifs.read((char*) &regDateLen, sizeof(size_t));
    char* regDate = new char[regDateLen+1];
    ifs.read((char*) regDate, regDateLen * sizeof(char));
    regDate[regDateLen] = '\0';
    this->regDate = std::string(regDate);
    delete[] regDate;
    if (!ifs.good())
        throw std::runtime_error("User Data reading error");

    size_t picturesSize;
    ifs.read((char*) &picturesSize, sizeof(size_t));
    if (!pictures.empty())
        pictures.clear();
    for (size_t i = 0; i < picturesSize; ++i) {
        pictures.emplace_back();
        pictures.back().readPictureData(ifs);
        if (!ifs.good())
            throw std::runtime_error("User Data reading error");
    }
}

