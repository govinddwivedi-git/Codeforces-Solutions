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

int f(string &a, string &b, string &c, int i, int j, vector<vector<int>> &dp){
    if(i + j == c.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1e9;
    if(i < a.size()){
        ans = min(ans, (a[i] != c[i+j]) + f(a, b, c, i+1, j, dp));
    }
    if(j < b.size()){
        ans = min(ans, (b[j] != c[i+j]) + f(a, b, c, i, j+1, dp));
    }
    return dp[i][j] = ans;
}

void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << f(a, b, c, 0, 0, dp) << endl;
}

int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}