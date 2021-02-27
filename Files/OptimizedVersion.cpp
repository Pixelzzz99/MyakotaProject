#include "OptimizedVersion.hpp"

OptimizedVersion::OptimizedVersion(TaskGenerator *task)
{
    first_word = task->get_first_word();
    second_word = task->get_second_word();
}

std::string OptimizedVersion::solve()
{
    if ((int)second_word.size() > first_word.size())
        std::swap(first_word, second_word);
    std::string myT;
    int ans = 0;
    std::string result;
    int id_left = -1;
    for (int add = second_word.size() - 1; add >= 0; add--)
    {
        myT = second_word[add] + myT;
        std::string st = myT + "#" + first_word;
        std::vector<int> p((int)st.size(), 0);
        p = prefix_function(st);
        for (int i = (int)myT.size(); i < (int)st.size(); i++)
        {
            index++;
            if (ans < p[i])
            {
                ans = p[i];
                id_left = i - ans - (int)myT.size();
            }
        }
    }

    for (int i = id_left; i < id_left + ans; i++)
    {
        result.push_back(first_word[i]);
    }
    return result;
}

std::vector<int> OptimizedVersion::prefix_function(std::string s)
{
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        index++;
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
