#pragma once

#include <string>
#include <vector>
#include "Comment.h"

struct PictureData {
    std::string description;
    size_t numberOfLikes = 0;
    size_t numberOfComments = 0;
    std::vector<Comment> comments;

    explicit PictureData(std::string description = "empty", unsigned int numberOfLikes = 0,
                         unsigned int numberOfComments = 0,
                         std::vector<Comment> comments = {});

    void writePictureData(std::ofstream& ofs);
    void readPictureData(std::ifstream& ifs);

    friend std::ostream& operator<<(std::ostream& os, const PictureData& pictureData)
    {
        os << "Description: " << pictureData.description << '\n'
           << "Likes: " << pictureData.numberOfLikes << '\n'
           << "Comments: " << pictureData.numberOfComments << '\n';
        for (auto& comment : pictureData.comments)
            os << comment << '\n';
        return os;
    }
};


