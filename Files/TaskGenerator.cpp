#include "TaskGenerator.hpp"
#include <ctime>

TaskGenerator::TaskGenerator(int n, int m)
{
    std::srand(std::time(nullptr));
    this->first_word = generate_word(n);
    this->second_word = generate_word(m);  
}

std::string TaskGenerator::generate_word(int length_word)
{
    std::string word;
    for (int i = 0; i < length_word; i++) word.push_back('a' + rand() % 26);
    return word;
}

TaskGenerator::TaskGenerator(std::string first_word, std::string second_word)
{
    this->first_word = first_word;
    this->second_word = second_word;
}

std::string TaskGenerator::get_first_word() const
{
    return this->first_word;
}

std::string TaskGenerator::get_second_word() const
{
    return this->second_word;
}
