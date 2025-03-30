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

const int mod = 1e9+7;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;


void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<int> curr(m, 0);
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'X') {
                if(i == n-1) {
                    dp[i][j] = 1;
                } 
                else {
                    int l = max(-1LL, j - d);
                    int r = min(m - 1, j + d - 1);

                    dp[i][j] += dp[i + 1][r];
                    if(l >= 0) {
                        dp[i][j] -= dp[i + 1][l];
                        dp[i][j] = (dp[i][j] + mod) % mod;
                    }
                }
            }

            if(j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }

        for(int j = 0; j < m; j++) {
            curr[j] = 0;
            if(s[i][j] == 'X') {
                int l = max(-1LL, j - d - 1);
                int r = min(m - 1, j + d);
                curr[j] = dp[i][r];
                if(l >= 0) {
                    curr[j] -= dp[i][l];
                    curr[j] = (curr[j] + mod) % mod;
                }
            }

            if(j > 0) {
                curr[j] = (curr[j] + curr[j - 1]) % mod;
            }
        }

        for(int j = 0; j < m; j++) {
            dp[i][j] = curr[j];
        }
    }
    
    cout << dp[0][m-1] << endl; 
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