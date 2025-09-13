#include <string>
#include <vector>
#include <iostream>
#include <cstring>

std::string longestPrefixBrute(std::vector<std::string> &strs)
{
    for (int i = 0; i < strs.size(); ++i)
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); ++j)
        {
            if (i >= strs[j].size() || strs[j][i] != c)
            {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> words = {"flower", "flow", "flight"};
    std::string result = longestPrefixBrute(words);
    std::cout << result << std::endl;
    return 0;
}
