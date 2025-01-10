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

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;

void dfs(int v) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

bool findPath(int v, int target, vector<int>& curr_path) {
    curr_path.push_back(v);
    if(v == target) return true;
    visited[v] = true;
    
    for(int u : adj[v]) {
        if(!visited[u]) {
            if(findPath(u, target, curr_path)) return true;
        }
    }
    
    curr_path.pop_back();
    return false;
}

int countComponents(int n, const vector<int>& removed) {
    visited.assign(n + 1, false);
    for(int x : removed) visited[x] = true;
    
    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            components++;
        }
    }
    return components;
}

void solve() {
    int n;
    cin >> n;
    
    adj.clear();
    adj.resize(n + 1);
    
    // Build the tree
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int maxComponents = 0;
    
    // Try all possible pairs of vertices
    for(int a = 1; a <= n; a++) {
        for(int b = a; b <= n; b++) {
            visited.assign(n + 1, false);
            vector<int> curr_path;
            findPath(a, b, curr_path);
            
            maxComponents = max(maxComponents, countComponents(n, curr_path));
        }
    }
    
    cout << maxComponents << endl;
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