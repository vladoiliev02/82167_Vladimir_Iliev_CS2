#include <iostream>
#include "UserData.h"


int main()
{
    std::string path = "user1.bin";

//    std::vector<PictureData> picDataVec;
//    std::vector<Comment> comments;
//    comments.emplace_back("hey there i am ...", "vlado", "15.2.2021");
//    comments.emplace_back("what's up my g :)", "from me", "12.12.2025");
//
//
//    picDataVec.emplace_back("First picture yaya", 5, 2, comments);
//    comments.emplace_back("nothing much :(", "Someone else :0", "15.25.2303");
//    picDataVec.emplace_back("Cool 2nd picture", 7, 3, comments);
//    comments.emplace_back("last comment", "Last guy", "15.12.2564");
//    picDataVec.emplace_back("new pic 3rd", 15, 4, comments);
//    UserData user1("Vlado", 19, "25.02.2002", picDataVec);
//
//    std::ofstream ofs(path, std::ios::binary | std::ios::trunc);
//    if (!ofs.is_open())
//        return 1;
//    user1.writeUserData(ofs, path);
//    ofs.close();

    std::ifstream ifs(path, std::ios::binary);
    if (!ifs.is_open())
        return 1;
    UserData user2;
    user2.readUserData(ifs, path);
    ifs.close();
    std::cout << user2 << '\n';

    return 0;
}
