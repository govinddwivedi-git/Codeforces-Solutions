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

bool f(const vector<pair<int,int>>& v){
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            int r1=v[i].first, c1=v[i].second;
            int r2=v[j].first, c2=v[j].second;
            if(abs(r1-r2)+abs(c1-c2)==1){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    map<int, vector<pair<int,int>>> mpp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            mpp[arr[i][j]].push_back({i,j});
        }
    }
    int cnt=0, ans=0;
    for(auto &it: mpp){
        int cost = f(it.second) ? 1 : 2;
        cnt += cost;
        ans = max(ans, cost);
    }
    cout << cnt - ans << endl;
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