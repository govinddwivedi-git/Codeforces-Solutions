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


void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vec a(n);
    rep(i, n) cin >> a[i];
    vec hash(m+1, 0);
    vector<pair<pii,int>> op;
    rep(i, m){
        int x, y, d;
        cin >> x >> y >> d;
        op.pb({{--x,--y},d}); 
    }
    rep(i,k) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        hash[x]++;
        if(y+1 < m) hash[y+1]--;
    }

    for(int i = 1; i < m; i++){
        hash[i] += hash[i-1];
    }

    vec prefix(n+1, 0);
    for(int i = 0; i < m; i++){
        prefix[op[i].first.first] += op[i].second*hash[i];
        if(op[i].first.second < n) prefix[(op[i].first.second+1)] -= op[i].second*hash[i];
    }

    for(int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1];
    }

    for(int i = 0; i < n; i++){
        cout << a[i] + prefix[i] << " ";
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