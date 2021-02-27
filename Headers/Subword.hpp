#pragma once
#include <string>
#include "Strategy.hpp"

class Subword
{
private:
    Strategy *interface;

public:
    Subword(Strategy *interface = nullptr);
    ~Subword();
    std::string DoAlgorithm();
    void setInterface(Strategy *);
    std::string get_first_word() const;
    std::string get_second_word() const;
    int get_index() const {return interface->get_index();}
};
