#pragma once 
#include "Strategy.hpp"
#include <vector>  
class OptimizedVersion : public Strategy
{
private:
    std::vector<int> prefix_function(std::string s);
public:
    OptimizedVersion(TaskGenerator *);
    ~OptimizedVersion() = default;

    std::string solve() override;
};
