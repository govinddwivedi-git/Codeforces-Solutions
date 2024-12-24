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

int check(vec &a, vec &b, int mid, int k) {
    int cnt = 0;
    int n = a.size();
    int m = 0;
    for(int i=0; i<n; i++){
        if(mid <= b[i]){
            cnt++;
            if(mid > a[i]) m++;
        }
    }
    // cout << "here" << endl;
    return m <= k ? cnt : -1;
}


void solve(){
    int n, k;
    cin >> n >> k;

    vec a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    int mx = *max_element(all(b));

    int low = 1;
    int hi = mx, ans = 0;
    while(low <= hi){
        int mid = (low+hi)/2;
        int cnt = check(a,b,mid,k);
        if(cnt != -1){
            ans = max(ans, mid*cnt);
            low = mid + 1;
        } 
        else hi = mid - 1;
        
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