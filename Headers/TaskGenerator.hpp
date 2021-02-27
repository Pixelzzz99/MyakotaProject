#pragma once 
#include <string>
class TaskGenerator
{
private:
    std::string first_word;
    std::string second_word;
    std::string generate_word(int length_word);
public:
    TaskGenerator(int n, int m);
    TaskGenerator(std::string first_word, std::string second_word);
    ~TaskGenerator() = default;
    std::string get_first_word() const;
    std::string get_second_word() const;
    
};

