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
int res[N];
 
void solve(){
    map<int, int> use;
    int n,cnt=0;cin >> n;
    int pos = 1;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1) {
            pos = i;
        }
    }
 
    int mnn = 0, mxx = 0, mnpos = 0, mxpos = 0, mns = 0, mxs = 0;
    
    for (int i = pos - 1, x = 0, y = 0, s = 0; i >= 1; i--) {
        y = max(y + a[i], 0LL);
        x = min(x + a[i], 0LL);
        s = s + a[i];
        mnpos = min(mnpos, s);
        mxpos = max(mxpos, s);
        mnn = min(mnn, x);
        mxx = max(mxx, y);
        
    }
 
    for (int i = pos + 1, x = 0, y = 0, s = 0; i <= n; i++) {
        y = max(y + a[i], 0LL);
        x = min(x + a[i], 0LL);
        s = s + a[i];
        mns = min(mns, s);
        mxs = max(mxs, s);
        mnn = min(mnn, x);
        mxx = max(mxx, y);
    }
 
    for (int i = mnn; i <= mxx; i++) {
        if (!use[i]) {
            use[i] = 1;
            res[++cnt] = i;
        }
    }
    int k=mnpos + mns + a[pos],tk=mxpos + mxs + a[pos];
    for (int i = k; i <= tk; i++) {
        if (!use[i]) {
            use[i] = 1;
            res[++cnt] = i;
        }
    }
 
    sort(res + 1, res + cnt + 1);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
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