#pragma once
#include <string>
#include "TaskGenerator.hpp"

class Strategy
{
protected:
    std::string second_word;
    std::string first_word;
    int index = 0;
public:
    std::string get_first_word();
    std::string get_second_word();
    ~Strategy() = default;
    int get_index() const { return index; }
    virtual std::string solve() = 0;
};
