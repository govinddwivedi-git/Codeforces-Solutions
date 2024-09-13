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
    // cin.ignore();
    int k;
    cin >> k;
    int n,m;
    cin >> n >> m;
    vec a(n);
    vec b(m);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,m){
        cin >> b[i];
    }
    // rep(i,n) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // rep(i,m) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    
    int cnt0 = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == 0) {
            cnt0++;
        }
    }
    for(int i=0;i<m;i++) {
        if(b[i] == 0) {
            cnt0++;
        }
    }
    int maxi = *max_element(all(a));
    int maxj = *max_element(all(b));
    int mx = max(maxi,maxj);

    // cout << cnt0 << endl;

    if(mx > k+cnt0) {
        cout << -1 << endl;
        return;
    }
    vec v(n+m);
    for(int i=m-1;i>=0;i--) {
        if(b[i] == 0) {
            v[n+i] = 0;
            cnt0--;
        }
        else {
            if(b[i] > cnt0 + k ) {
                v[i+n] = b[i];
            }
        }
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