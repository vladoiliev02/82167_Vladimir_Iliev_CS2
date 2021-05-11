#pragma once
#include<string>

#include <fstream>

struct Comment {
    std::string content;
    std::string publisher;
    std::string date;

    Comment(std::string content = "No content", std::string publisher = "Unknown", std::string date = "0.0.0");
    void writeComment(std::ofstream& ofs);
    void readComment(std::ifstream& ifs);

    friend std::ostream& operator<<(std::ostream& os, const Comment& comment)
    {
        os << "Publisher: " << comment.publisher << ':' << '\n'
            << "  " << comment.content << '\n'
            << "    " <<comment.date;
        return os;
    }

};



