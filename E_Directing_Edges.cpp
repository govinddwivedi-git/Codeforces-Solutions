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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i = 0; i < m; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        edges[i] = {t, x, y};
    }
    
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> undirected;
    vector<int> indegree(n + 1);
    vector<int> topoSort;
    vector<vector<int>> ans;

    for(auto &e : edges) {
        int t = e[0], u = e[1], v = e[2];
        if(t == 0) undirected.push_back({u , v});
        else {
            adj[u].push_back(v);
            indegree[v]++;
            ans.push_back({u, v});
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i); 
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topoSort.push_back(u);
        for(auto &v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    if(topoSort.size() != n) {
        cout << "NO" << endl;
        return;
    }

    vector<int> order(n + 1);
    for(int i = 0; i < n; i++) {
        order[topoSort[i]] = i;
    }

    for(auto &it : undirected) {
        int u = it[0], v = it[1];
        if(order[u] < order[v]) {
            ans.push_back({u, v});
        }
        else ans.push_back({v , u});
        
    }  

    cout << "YES" << endl;
    for(auto &it : ans) {
        int u = it[0], v = it[1];
        cout << u << " " << v << endl;
        
    }    


    

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