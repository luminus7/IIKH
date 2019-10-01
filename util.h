#pragma once
#include <string>

void clrscr();
void waitEnter();
std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to);
std::string ReplaceAll(std::string &&str, const std::string& from, const std::string& to);
