#include "PictureData.h"

#include <utility>
#include <fstream>

PictureData::PictureData(std::string description, unsigned int numberOfLikes, unsigned int numberOfComments,
                         std::vector<Comment> comments) : description(std::move(description)),
                                                          numberOfLikes(numberOfLikes),
                                                          numberOfComments(numberOfComments),
                                                          comments(std::move(comments))
{}

void PictureData::writePictureData(std::ofstream& ofs)
{
    size_t descriptionLength = description.size();
    ofs.write((const char*) &descriptionLength, sizeof(size_t));
    ofs.write(description.c_str(), descriptionLength);
    if (!ofs.good())
        throw std::runtime_error("PictureData writing error");
    ofs.write((const char*) &numberOfLikes, sizeof(size_t));
    numberOfComments = comments.size();
    ofs.write((const char*) &numberOfComments, sizeof(size_t));
    for (size_t i = 0; i < numberOfComments; ++i) {
        comments[i].writeComment(ofs);
        if (!ofs.good())
            throw std::runtime_error("PictureData writing error");
    }
}

void PictureData::readPictureData(std::ifstream& ifs)
{
    size_t descriptionLength;
    ifs.read((char*) &descriptionLength, sizeof(size_t));
    if(!description.empty())
        description.clear();
    description.resize(descriptionLength);
    ifs.read((char*) description.c_str(), descriptionLength);

    if (!ifs.good())
        throw std::runtime_error("PictureData writing error");
    ifs.read((char*) &numberOfLikes, sizeof(size_t));
    ifs.read((char*) &numberOfComments, sizeof(size_t));
    if (!comments.empty())
        comments.clear();
    for (size_t i = 0; i < numberOfComments; ++i) {
        comments.emplace_back();
        comments.back().readComment(ifs);
        if (!ifs.good())
            throw std::runtime_error("PictureData reading error");
    }
}
