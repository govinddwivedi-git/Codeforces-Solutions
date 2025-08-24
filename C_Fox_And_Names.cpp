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
    vector<string> arr(n);
    for(auto &i : arr) cin >> i;
    vector<vector<int>> adj(26);
    vector<int> indegree(26);

    for(int i = 0; i < n - 1; i++) {
        string str1 = arr[i];
        string str2 = arr[i + 1];
        int len = min(str1.size(), str2.size());

        bool found = false;
        for(int j = 0; j < len; j++) {
            if(str1[j] != str2[j]) {
                int u = str1[j] - 'a', v = str2[j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
                found = true;
                break;
            }

        }
        
        if(!found && str1.size() > str2.size()) {
            cout << "Impossible" << endl;
            return;
        }
    }

    queue<int> q;
    for(int i = 0; i < 26; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<char> topoSort;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topoSort.push_back(u +'a');
        for(auto &v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    if(topoSort.size() != 26) {
        cout << "Impossible" << endl;
        return;
    }

    for(auto &ch : topoSort) cout << ch;
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