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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if(u < v) {
            if(x < y) {
                adj[u].pb(v);
                indegree[v]++;
            } else {
                adj[v].pb(u);
                indegree[u]++;
            }
        }

        else {
            if(x < y) {
                adj[v].pb(u);
                indegree[u]++;
            } else {
                adj[u].pb(v);
                indegree[v]++;
            }
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.pb(node);
        for(auto child : adj[node]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    vector<int> mapping(n);
    for(int i = 0; i < n; i++) {
        mapping[topo[i] - 1] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        cout << mapping[i] << " ";
    }
    cout << endl;

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