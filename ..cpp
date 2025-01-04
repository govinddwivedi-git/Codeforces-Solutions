//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    static const long long MOD = 1000000007;
    long long fastPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    long long modInv(long long x) {
        // Fermat's little theorem for prime MOD
        return fastPow(x, MOD - 2);
    }
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        int n = arr.size();
        int mx = n == 0 ? 0 : *max_element(arr.begin(), arr.end());
        int limit = max(mx + 1, r + 1);
        vector<long long> freq(limit + 1, 0), missing(limit + 1, 0);
        for (int x : arr) freq[x]++;
        // missing[i] = number of j < i with freq[j] == 0
        for(int i = 1; i <= limit; i++){
            missing[i] = missing[i - 1] + (freq[i - 1] == 0 ? 1 : 0);
        }
        // pre2[i] = product of 2^freq[j] for j < i
        // pre1[i] = product of (2^freq[j]-1) for j < i
        vector<long long> pre2(limit + 2, 1), pre1(limit + 2, 1);
        for(int i = 1; i <= limit; i++){
            long long p2 = fastPow(2, freq[i - 1]);
            pre2[i] = (pre2[i - 1] * p2) % MOD;
            long long p1 = (p2 + MOD - 1) % MOD; // 2^freq[j]-1
            pre1[i] = (pre1[i - 1] * p1) % MOD;
        }
        // inv2[i] = inv of pre2[i], inv1[i] = inv of pre1[i]
        vector<long long> inv2(limit + 2, 1), inv1(limit + 2, 1);
        inv2[limit] = modInv(pre2[limit]);
        inv1[limit] = modInv(pre1[limit]);
        for(int i = limit - 1; i >= 0; i--){
            inv2[i] = (inv2[i + 1] * fastPow(2, freq[i])) % MOD;
            long long p1 = (fastPow(2, freq[i]) + MOD - 1) % MOD;
            inv1[i] = (inv1[i + 1] * modInv(p1)) % MOD;
        }
        auto ways = [&](int m){
            if(m == 0) {
                // MEX=0 => pick none from freq[0], so product for i>0 => pre2[limit+1]/pre2[1]
                return (missing[1] == 1 ? 0LL : (pre2[limit] * inv2[1]) % MOD);
            }
            if(missing[m] - missing[0] > 0) return 0LL; // some i < m missing
            // pick >=1 for all i < m => pre1[m]/pre1[0], skip i=m => 1, pick anything for i>m => pre2[limit]/pre2[m+1]
            long long part1 = (pre1[m] * inv1[0]) % MOD;
            long long part2 = (pre2[limit] * inv2[m + 1]) % MOD;
            return (part1 * part2) % MOD;
        };
        long long ans = 0;
        for(int m = l; m <= r; m++){
            if(m <= limit) ans = (ans + ways(m)) % MOD;
        }
        return (int)ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int l;
        cin >> l;
        cin.ignore();
        int r;
        cin >> r;
        cin.ignore();
        Solution ob;
        int ans = ob.cntSubsets(arr, l, r);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends