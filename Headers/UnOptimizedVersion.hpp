#pragma once
#include "Strategy.hpp"

class UnOptimizedVersion : public Strategy
{
private:
    bool ok(int ls, int rs, int lt, int rt);
public:
    UnOptimizedVersion(TaskGenerator *);
    ~UnOptimizedVersion() = default;
    std::string solve() override;
};
