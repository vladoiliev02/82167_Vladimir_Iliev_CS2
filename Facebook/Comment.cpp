#include "Comment.h"
#include <fstream>

void Comment::writeComment(std::ofstream& ofs)
{
    size_t size = content.length();
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write((const char*) content.c_str(), size);

    size = publisher.length();
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write((const char*) publisher.c_str(), size);

    size = date.length();
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write((const char*) date.c_str(), size);

    if (!ofs.good())
        throw std::runtime_error("File not saved.");
}

void Comment::readComment(std::ifstream& ifs)
{
    size_t size ;
    ifs.read((char*) &size, sizeof(size_t));
    char* content = new char[size+1];
    ifs.read((char*)  content, size);
    content[size] = '\0';
    this->content = std::string(content);
    delete[] content;

    ifs.read((char*) &size, sizeof(size_t));
    char* publisher = new char[size+1];
    ifs.read((char*)  publisher, size);
    publisher[size] = '\0';
    this->publisher = std::string(publisher);
    delete[] publisher;

    ifs.read((char*) &size, sizeof(size_t));
    char* date = new char[size+1];
    ifs.read((char*)  date, size);
    date[size] = '\0';
    this->date = std::string(date);
    delete[] date;

    if (!ifs.good())
        throw std::runtime_error("File not saved.");
}

Comment::Comment(std::string content, std::string publisher, std::string date)
    :content(content), publisher(publisher), date(date)
{

}
