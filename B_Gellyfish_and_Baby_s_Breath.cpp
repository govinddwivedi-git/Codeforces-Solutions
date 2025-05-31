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

const int mod = 998244353;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;


void solve(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    vector<int> pow2(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    vector<int> powp(n), powq(n);
    rep(i, n) {
        powp[i] = pow2[p[i]];
        powq[i] = pow2[q[i]];
    }

    int mxp = p[0], idx1 = 0;
    int mxq = q[0], idx2 = 0;

    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        if(i > 0 && p[i] > mxp) {
            mxp = p[i];
            idx1 = i;
        }
        if(i > 0 && q[i] > mxq) {
            mxq = q[i];
            idx2 = i;
        }

        int a1 = p[idx1];
        int b1 = q[i - idx1];
        int a2 = p[i - idx2];
        int b2 = q[idx2];

        int c1 = (powp[idx1] + powq[i - idx1]) % mod;
        int c2 = (powp[i - idx2] + powq[idx2]) % mod;

        int temp;
        if(max(a1, b1) > max(a2, b2)) {
            temp = c1;
        } 
        else if(max(a1, b1) < max(a2, b2)) {
            temp = c2;
        } 
        else {
            temp = (min(a1, b1) > min(a2, b2)) ? c1 : c2;
        }
        ans.push_back(temp);
    }

    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
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