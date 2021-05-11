#pragma once

#include<string>
#include<vector>
#include"PictureData.h"

struct UserData {
    std::string name;
    unsigned short age = 0;
    std::string regDate;
    std::vector<PictureData> pictures;

    UserData(std::string name = "No name specified", unsigned short age = 0, std::string regDate = "No reg date", std::vector<PictureData> pictures = {});

    void writeUserData(std::ofstream& ofs, std::string& path);
    void readUserData(std::ifstream& ifs, std::string& path);

    friend std::ostream& operator<<(std::ostream& os, const UserData& userData)
    {
        os << "Name: " << userData.name << '\n'
            <<  "Age: " << userData.age << '\n'
            << "Registration date: " << userData.regDate << "\n\n";
        size_t i = 1;
        for (auto& pic : userData.pictures)
            os << "Picture " << i++ << ":\n" << pic << '\n';

        return os;
    }
};


