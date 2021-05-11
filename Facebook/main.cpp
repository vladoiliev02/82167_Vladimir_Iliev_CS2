#include <iostream>
#include "UserData.h"


int main()
{
//    std::vector<PictureData> picDataVec;
//    std::vector<Comment> comments;
//    comments.emplace_back(std::string("hey there i am ..."), std::string("vlado"), std::string("15.2.2021"));
//    comments.emplace_back("what's up my g", "from me", "45.12.2");
//
//
//    picDataVec.emplace_back("First picture yaya", 5, 2, comments);
//    comments.emplace_back("nothing much", "Someone else", "15.25.2303");
//    picDataVec.emplace_back("Cool picture", 3, 3, comments);
//    comments.emplace_back("last comment", "Last guy", "45.12.2564");
//    picDataVec.emplace_back("new pic", 15, 4, comments);
//    UserData user1("Vlado", 19, "25.02.2002", picDataVec);
//
//    std::ofstream ofs("user1.bin", std::ios::binary | std::ios::trunc);
//    if (!ofs.is_open())
//        return 1;
//    user1.writeUserData(ofs);
//    ofs.close();

    std::ifstream ifs("user1.bin", std::ios::binary);
    if (!ifs.is_open())
        return 1;
    UserData user2;
    user2.readUserData(ifs);
    ifs.close();
    std::cout << user2 << '\n';

    return 0;
}
