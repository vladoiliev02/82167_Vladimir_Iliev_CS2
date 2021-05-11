#include "Comment.h"
#include <fstream>

void Comment::writeComment(std::ofstream& ofs) const
{
    size_t size = content.length();
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write(content.c_str(), size);

    size = publisher.length();
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write(publisher.c_str(), size);

    size = date.length();
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write(date.c_str(), size);

    if (!ofs.good())
        throw std::runtime_error("File not saved.");
}

void Comment::readComment(std::ifstream& ifs)
{
    size_t size ;
    ifs.read((char*) &size, sizeof(size_t));
    if (content.empty())
        content.clear();
    content.resize(size);
    ifs.read((char*) content.c_str(), size);

    ifs.read((char*) &size, sizeof(size_t));
    if (publisher.empty())
        publisher.clear();
    publisher.resize(size);
    ifs.read((char*) publisher.c_str(), size);

    ifs.read((char*) &size, sizeof(size_t));
    if (date.empty())
        date.clear();
    date.resize(size);
    ifs.read((char*) date.c_str(), size);

    if (!ifs.good())
        throw std::runtime_error("File not saved.");
}

Comment::Comment(std::string content, std::string publisher, std::string date)
    :content(content), publisher(publisher), date(date)
{

}
