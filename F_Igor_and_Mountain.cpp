#include <bits/stdc++.h>
using namespace std;

// Macros and constants
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

const int mod = 998244353;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;

int f(vector<vector<char>> &a, vector<vector<int>> &dp, int i, int j, int d){
    if(i == 0) {
        if(j < 0 || j >= a[0].size()) return 0;
        if(a[i][j] == '#') return 0;
        return 1;
    }
    if(j < 0 || j >= a[0].size()) return 0;
    if(a[i][j] == '#') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    for(int k = 0; k < a[0].size(); k++) {
        double dist = sqrt((j - k) * (j - k));
        if(dist <= d) {
            ans = (ans + f(a, dp, i, k, d)) % mod;
        }
        dist = sqrt((j - k) * (j - k) + 1);
        if(dist <= d) {
            ans = (ans + f(a, dp, i-1, k, d)) % mod;
        }
    }
    return dp[i][j] = ans % mod;
}

void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'X') cnt++;
        }
        if(cnt == 0) {
            cout << 0 << endl;
            return;
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 0;
    for(int i = 0; i < m; i++){
        if(a[n - 1][i] == '#') continue;
        ans = (ans + f(a, dp, n - 1, i, d)) % mod;
    }
    cout << ans << endl;
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