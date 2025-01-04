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
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].ff >> v[i].ss;
    }


    vec cons(n);
    for(int i = 0; i < n; i++){
        cons[i] = v[i].ss*n - v[i].ss;
    }

    vector<pii> p(n);
    for(int i = 0; i < n; i++){
        p[i] = {v[i].ff - v[i].ss, cons[i]};
    }

    sort(all(p),greater<pii>());

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += p[i].ff * i + p[i].ss;
    }

    cout << ans << endl;

    




    // sort(all(v), [&](pii a, pii b){
    //     if(a.first == b.first) return a.second < b.second;
    //     return a.first > b.first;
    // });

    // int ans = 0;
    // for(int i = 0; i < n; i++){
    //     ans += v[i].ff * i + v[i].ss * (n - i - 1);
    // }
    // // cout << ans << endl;

    // sort(all(v), [&](pii a, pii b){
    //     if(a.second == b.second) return a.first > b.first;
    //     return a.second < b.second;
    // });


    // int ans2 = 0;
    // for(int i = 0; i < n; i++){
    //     ans2 += v[i].ff * i + v[i].ss * (n - i - 1);
    // }

    // cout << min(ans, ans2) << endl;



    
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