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
    vector<int> nums(n);
    rep(i, n) cin >> nums[i];
     vector<int> pmax(n + 1, INT_MIN / 2);
        for (int i = 0; i < n; i++) {
            pmax[i + 1] = max(pmax[i], nums[i]);
        }
        
        vector<int> smin(n + 1, INT_MAX / 2);
        for (int i = n - 1; i >= 0; i--) {
            smin[i] = min(smin[i + 1], nums[i]);
        }
        
        vector<int> ans(n);
        int start = 0;
        for(int k = 0; k < n - 1; k++) {
            if (pmax[k + 1] <= smin[k + 1]) {
                int mx = INT_MIN;
                for (int j = start; j <= k; j++) {
                    mx = max(mx, nums[j]);
                }
                for (int j = start; j <= k; j++) {
                    ans[j] = mx;
                }
                start = k + 1;
            }
        }
        int mx = INT_MIN;
        for(int j = start; j < n; j++) {
            mx = max(mx, nums[j]);
        }
        for (int j = start; j < n; j++) {
            ans[j] = mx;
        }
        for(int i = 0; i < n; i++) {
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