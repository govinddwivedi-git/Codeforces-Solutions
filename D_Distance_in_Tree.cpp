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

void func(vector<vector<int>> &dp, int node, int parent, vector<vector<int>> &adj , int k, int &ans) {

    dp[node][0] = 1;
    for(auto &v  : adj[node]) {
        if(parent == v) continue;
        func(dp, v, node, adj, k, ans);

        
        for(int i = 0; i < k; i++) {
            ans += (dp[node][i] * dp[v][k - i - 1]);
        }

        for(int i = 1; i <= k; i++) {
            dp[node][i] += dp[v][i - 1];
        }
        
    }

    

}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int> (k + 1));
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    func(dp, 1, -1, adj, k, ans);

    cout << ans << endl;
    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}