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
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[x].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    vector<int> topoSort;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        topoSort.push_back(node);
        for(auto child : adj[node]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    
    if(cnt != n) {
        cout << -1 << endl;
        return;
    }
    
    vector<int> dp(n + 1, 1);

    for(auto &node : topoSort) {
        for(auto child : adj[node]) {
            if(node < child) {
                dp[child] = max(dp[child], dp[node]);
            } 
            else {
                dp[child] = max(dp[child], dp[node] + 1);
            }
        }
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
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