#include <bits/stdc++.h>
using namespace std;

int numSubseq(vector<int> &nums, int target)
{

    const int MOD = 1e9 + 7;
    // use two pointer approach
    // sort the vector
    sort(nums.begin(), nums.end());
    // then check with min value + max value by two pointer
    // when the sum is less then or equal to target calculate 2^(j-i) is the number of
    // subsequence from this range. Add all possible subsequence by this process
    int i = 0;
    int j = nums.size() - 1;
    long long count = 0;

    while (i <= j)
    {
        int sum = nums[i] + nums[j];
        if (sum > target)
        {
            j--;
        }
        else
        {
            count += (my_pow(2, j - i, MOD)) % MOD;
            i++;
        }
    }

    return count;
}

long long my_pow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}