#include <fstream>
#include "UserData.h"

UserData::UserData(std::string name, unsigned short age,
                   std::string regDate, std::vector<PictureData> pictures)
        : name(std::move(name)), age(age), regDate(std::move(regDate)),
          pictures(std::move(pictures))
{}

void UserData::writeUserData(std::ofstream& ofs, std::string& path)
{
    while (!path.empty() && path.back() != '.')
        path.pop_back();
    path.pop_back();
    path += "_pic_data.bin";
    std::ofstream ofs_pictures(path, std::ios::binary);
    if (!ofs.is_open())
        throw std::runtime_error(path + " not open");

    ofs.write((const char*) &age, sizeof(unsigned short));

    size_t size = name.length();
    ofs.write((const char*) &size, sizeof(size_t));
    ofs.write(name.c_str(), size);

    size = regDate.length();
    ofs.write((const char*) &size, sizeof(size_t));
    ofs.write(regDate.c_str(), size);

    if (!ofs.good())
        throw std::runtime_error("User Data writing error");

    size_t picturesSize = pictures.size();
    ofs.write((const char*) &picturesSize, sizeof(size_t));
    for (size_t i = 0; i < picturesSize; ++i) {
        pictures[i].writePictureData(ofs_pictures);
        if (!ofs.good())
            throw std::runtime_error("User Data writing error");
    }
    ofs_pictures.close();
}

void UserData::readUserData(std::ifstream& ifs, std::string& path)
{
    while (!path.empty() && path.back() != '.')
        path.pop_back();
    path.pop_back();
    path += "_pic_data.bin";
    std::ifstream ifs_pictures(path, std::ios::binary);
    if (!ifs.is_open())
        throw std::runtime_error(path + " not open");

    ifs.read((char*) &age, sizeof(unsigned short));
    size_t size;

    ifs.read((char*) &size, sizeof(size_t));
    if (!name.empty())
        name.clear();
    name.resize(size);
    ifs.read((char *)name.c_str(), size);

    ifs.read((char*) &size, sizeof(size_t));
    if (!regDate.empty())
        regDate.clear();
    regDate.resize(size);
    ifs.read((char *)regDate.c_str(), size);
    if (!ifs.good())
        throw std::runtime_error("User Data reading error");

    size_t picturesSize;
    ifs.read((char*) &picturesSize, sizeof(size_t));
    if (!pictures.empty())
        pictures.clear();
    pictures.resize(picturesSize);
    for (size_t i = 0; i < picturesSize; ++i) {
        pictures[i].readPictureData(ifs_pictures);
        if (!ifs.good())
            throw std::runtime_error("User Data reading error");
    }
    ifs_pictures.close();
}

