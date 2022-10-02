#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int climbStairs(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i < n + 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main()
{
    
    return 0;
}
