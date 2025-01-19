#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<long long>> C(n + 1, vector<long long>(k + 1, 0));
        for(int i = 0; i <= n; ++i){
            C[i][0] = 1;
            for(int j = 1; j <= min(i, k); ++j){
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        long long sum = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= k; ++j){
                if(i + 1 >= j){
                    sum = (sum + (nums[i] * C[i][j-1]) % MOD) % MOD;
                }
            }
            for(int j = 1; j <= k; ++j){
                if(n - i >= j){
                    sum = (sum + (nums[i] * C[n-i-1][j-1]) % MOD) % MOD;
                }
            }
        }

        return sum % MOD;
    }
};