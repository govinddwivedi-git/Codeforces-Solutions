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

int dfs(vector<vector<int>> &adj, vector<int> &isCat, int prev, int cnt, int m, int node, int parent) {


    if(prev && isCat[node]) {
        cnt++;
        if(cnt > m) return 0;
    }
    else cnt = isCat[node];
    int leaf = 1;
    int ans = 0;
    for(auto &v : adj[node]) {
        if(v != parent) {
            leaf = 0;
            ans += dfs(adj, isCat, isCat[node], cnt, m, v, node);
        }
    }

    if(leaf) return 1;
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> isCat(n + 1);
    for(int i = 1; i <=n; i++) cin >> isCat[i];
    vector<vec> adj(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    cout << dfs(adj, isCat, 0, 0, m, 1, -1);
}


int32_t main(){
    fast

    int t = 1;
    // cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}