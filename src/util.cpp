#include "util.h"
#include <cstdio>
#include <string>

void clrscr()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitEnter()
{
    while (std::getchar() != '\n');
}

std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

std::string ReplaceAll(std::string &&str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
