#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define M 1000000007
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        map<char, long long> mp, cpy;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        cpy = mp;

        int ans = 5;
        while (n > 1)
        {
            ans = (mp['a'] + mp['e'] * 2 + mp['i'] * 4 + mp['o'] * 2 + mp['u'])%M;
            mp['a'] = (cpy['i'] + cpy['e'] + cpy['u']) % M;
            mp['e'] = (cpy['i'] + cpy['a']) % M;
            mp['i'] = (cpy['e'] + cpy['o']) % M;
            mp['o'] = cpy['i'];
            mp['u'] = (cpy['i'] + cpy['o']) % M;
            cpy = mp;
            n--;
        }

        return ans;
    }
};

int main()
{

    return 0;
}