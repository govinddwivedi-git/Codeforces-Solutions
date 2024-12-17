#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define pb push_back
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
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


bool f(int ind, int sum, string &s, vector<vector<int>> &dp) {

    if (ind == s.size()) {
        return sum % 9 == 0;
    }

    if (dp[ind][sum] != -1) {
        return dp[ind][sum];
    }

    bool nt = f(ind + 1, sum, s, dp);
    
    bool t = false;
    if (s[ind] == '2' || s[ind] == '3') {
        int nsum = sum;
        if (s[ind] == '2') {
            nsum = (sum - 2 + 4) % 9;  
        }
        else if (s[ind] == '3') {
            nsum = (sum - 3 + 9) % 9;  
        }
        t = f(ind + 1, nsum, s, dp);
    }

    return dp[ind][sum] = nt || t;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }
    
    sum %= 9;
    
    vector<vector<int>> dp(n, vector<int>(9, -1));

    if(f(0, sum, s, dp)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int32_t main(){
    fast

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
