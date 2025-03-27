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

void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }
    // Build holds per row (grid is given from top to bottom)
    vector<vector<int>> holds(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j]=='X'){
                holds[i].push_back(j);
            }
        }
        if(holds[i].empty()){
            cout << 0 << endl;
            return;
        }
    }
    // Reverse rows so that R[0] = bottom row and R[n-1] = top row
    vector<vector<int>> R(n);
    for (int i = 0; i < n; i++){
        R[i] = holds[n-1-i];
    }
    // DP: dp[i][j] are ways for row R[i] ending at hold with column R[i][j]
    vector<vector<int>> dp(n);
    dp[0].resize(R[0].size(), 0);
    // Base (bottom row): choose one hold OR pick two holds if they satisfy horizontal reachability (distance <= d)
    for (int j = 0; j < (int)R[0].size(); j++){
        dp[0][j] = (dp[0][j] + 1) % mod; // one-hold selection
        for (int z = 0; z < (int)R[0].size(); z++){
            if(z==j) continue;
            if ( abs(R[0][j] - R[0][z]) <= d )
                dp[0][z] = (dp[0][z] + 1) % mod;
        }
    }
    
    // Process rows upward
    for (int i = 1; i < n; i++){
        dp[i].resize(R[i].size(), 0);
        // For each hold (last selected) in previous row R[i-1]
        for (int p = 0; p < (int)R[i-1].size(); p++){
            int ways = dp[i-1][p];
            if(!ways) continue;
            int prev_col = R[i-1][p];
            // Try all candidate first holds in current row R[i]
            for (int x = 0; x < (int)R[i].size(); x++){
                int cur_col = R[i][x];
                // Vertical move: row difference = 1; condition: sqrt(1+(prev_col-cur_col)^2) <= d
                if( 1 + (prev_col - cur_col) * (prev_col - cur_col) <= d * d ){
                    // Option 1: single hold selection in R[i] ending at cur_col
                    dp[i][x] = (dp[i][x] + ways) % mod;
                    // Option 2: two-hold selection, second hold must be reachable horizontally
                    for (int z = 0; z < (int)R[i].size(); z++){
                        if(z==x) continue;
                        if( abs(R[i][x] - R[i][z]) <= d )
                            dp[i][z] = (dp[i][z] + ways) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(auto v : dp[n-1])
        ans = (ans + v) % mod;
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