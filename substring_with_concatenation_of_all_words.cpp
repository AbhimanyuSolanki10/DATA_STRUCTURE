#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        int n = words.size();
        int len = words[0].size();
        if (s.size() < (n * len))
        {
            return ans;
        }
        for (int i = 0; i <= s.size() - (n * len); i++)
        {
            unordered_map<string, int> mp;
            for (int j = 0; j < n; j++)
            {
                mp[words[j]]++;
            }
            int k = 0;
            for (k = 0; k < n; k++)
            {
                string str = s.substr(k * len + i, len);
                if (mp.count(str) == 0)
                {
                    break;
                }
                else
                {
                    if (mp[str] != 0)
                    {
                        mp[str]--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (k == n)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}