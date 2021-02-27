#include "UnOptimizedVersion.hpp"

UnOptimizedVersion::UnOptimizedVersion(TaskGenerator *task)
{
    first_word = task->get_first_word();
    second_word = task->get_second_word();
}

std::string UnOptimizedVersion::solve()
{
    int length_first_word = (int)first_word.size();
    int length_second_word = (int)second_word.size();
    int length_min = std::min(length_first_word, length_second_word);

    int ans = 0, id_left = -1;
    std::string result;
    for (int subLen = 1; subLen <= length_min; subLen++)
    {
        for (int ls = 0; ls + subLen - 1 < length_first_word; ls++)
        {
            for (int lt = 0; lt + subLen - 1 < length_second_word; lt++)
            {
                int rs = ls + subLen;
                int rt = lt + subLen;
                if (ok(ls, rs, lt, rt))
                {
                    id_left = ls;
                    ans = subLen;
                }
            }
        }
    }

    for(int i = id_left; i < id_left+ans; i++)
    {
        result.push_back(first_word[i]);
    }
    return result;
}

bool UnOptimizedVersion::ok(int ls, int rs, int lt, int rt)
{
    bool res = true;
    while (ls < rs && lt < rt)
    {
        index++;
        if (first_word[ls] != second_word[lt])
            res = false;
        ls++;
        lt++;
    }
    return res;
}