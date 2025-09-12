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


void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> cost(n, vector<int>(k, LLONG_MAX));
    for (int t = 1; t <= k; t++) {
        queue<int> q;
        vector<int> dist(n, -1);
        for (int i = 0; i < n; i++) {
            if (arr[i] == t) {
                q.push(i);
                dist[i] = 0;
                cost[i][t-1] = 0;
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    cost[v][t-1] = dist[v];
                    q.push(v);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        nth_element(cost[i].begin(), cost[i].begin() + s, cost[i].end());
        long long sum = 0;
        for (int j = 0; j < s; j++) sum += cost[i][j];
        cout << sum << " ";
    }
    cout << endl;


    
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