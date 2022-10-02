#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<int> dp;
    int helper(vector<int> &nums, int target)
    {
        if (target < 0)
        {
            return 0;
        }
        else if (target == 0)
        {
            return 1;
        }

        if (dp[target] != -1)
        {
            return dp[target];
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target - nums[i] >= 0)
            {
                cnt += helper(nums, target - nums[i]);
            }
        }

        dp[target] = cnt;
        return cnt;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1);
        fill(dp.begin(), dp.end(), -1);
        return helper(nums, target);
    }
};

int main()
{

    return 0;
}