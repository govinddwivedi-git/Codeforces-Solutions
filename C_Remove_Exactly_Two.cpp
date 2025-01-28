#include <bits/stdc++.h>
using namespace std;


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


#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl


using vec = vector<int>;
using pii=pair<int,int>;
using mapi=map<int,int>;
using si=set<int>;

const int mod = 1e9+7;


const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  
const int N=2e5+5;


void solve(){
    int n;
    cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 1, mans = 0;
    multiset<int> sdeg(deg.begin(), deg.end());
    
    for(int i = 0; i < n; i++){
        ans = deg[i];
        vector<int> removed_vals;
        
        
        
        sdeg.erase(sdeg.find(deg[i]));
        removed_vals.push_back(deg[i]);
        
        
        for(int v : adj[i]){
            sdeg.erase(sdeg.find(deg[v]));
            removed_vals.push_back(deg[v]);
        }
        
        int mx = -1;
        if(!sdeg.empty()){
            mx = *sdeg.rbegin();
        }
        
        for(int v : adj[i]){
            mx = max(mx, deg[v]-1);
        }
        
        
        for(int val : removed_vals){
            sdeg.insert(val);
        }
        
        mans = max(ans + mx - 1, mans);
    }
    
    cout << mans << endl;
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