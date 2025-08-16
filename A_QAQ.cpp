#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define pb push_back
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define mini2(a, b, c, d) min(d, min(c, min(a, b))) 
#define rrep(i,s,n) for(int i=n-1;i>=s;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define scin(str) getline(cin, str)

// Debugging Macros
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

// Aliases and Types
using vec = vector<int>;
using pii=pair<int,int>;
using mapi=map<int,int>;
using si=set<int>;

const int mod = 1e9+7;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;

int f(vector<vector<int>> &dp, int i, int j, string &s, string &t) {
    if(j < 0) return 1;
    if(i < 0 ) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int notTake = f(dp, i - 1, j, s, t);
    int take = 0;
    if(s[i] == t[j]) {
        take = f(dp, i - 1, j - 1, s, t);
    }
    
    return dp[i][j] = take + notTake;

}


int32_t main(){
    fast

    string s;
    cin >> s;
    string t = "QAQ";
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = f(dp, n - 1, m - 1, s, t);
    cout << ans << endl;


    return 0;
}