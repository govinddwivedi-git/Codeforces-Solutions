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
    int k;
    cin >> k;
    vec v(n);
    rep(i, n) cin >> v[i];
    // if(v[0] == 1 && v[1] != 1) {
    //     cout << 2 << endl;
    //     return;
    // }

    if(k == n) {
        int x = 1;
        for(int i = 1; i < v.size();i+=2) {
            if(v[i] != x) {
                cout << x << endl;
                return;
            }
            x++;
        }
        cout << x << endl;
        return;
    }
    int x = k - 1;
    int r = n - x;
    for(int i = 1; i < r; i++) {
        if(v[i] != 1) {
            cout << 1 << endl;
            return;
        }
        
    }

    if(v[r] != 1) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
    // int p = 2;
    // for(int i = 1; i < r; i++) {
    //     if(v[i] != 1) {
    //         cout << 2 << endl;
    //         return;
    //     }
    // }

    // cout << p << endl;
    // int p = 0;
    // for(int i = r; i < n; i+=2) {
    //     b.pb(v[i]);
    //     p++;  
    // }

    // b.pb(0);

    // for(int i = 0; i < b.size(); i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // return;

    

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