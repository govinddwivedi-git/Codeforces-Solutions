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
    int m;
    cin >> m;
    vec v(n);
    rep(i, n){
        cin >> v[i];
    }
    vec a(n);
    rep(i, n){
        cin >> a[i];
    }
    
    map<int, vector<pii>> mpp;
    rep(i, n){
        int cx = v[i], r = a[i];
        for(int y = -r; y <= r; y++){
            int rem = r * r - y * y;
            int d = (int)floor(sqrt(rem));
            mpp[y].push_back({cx - d, cx + d});
        }
    }
    
    int ans = 0;
    for(auto &p : mpp){
        auto &arr = p.second;
        sort(arr.begin(), arr.end());
        int left = arr[0].first;
        int right = arr[0].second;
        for(auto &i : arr){
            int l = i.first;
            int r = i.second;
            if(l > right + 1){
                ans += (right - left + 1);
                left = l;
                right = r;
            } 
            else {
                right = max(right, r);
            }
        }
        ans += (right - left + 1);
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