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
    int n, k;
    cin >> n >> k;

    vector<int> req(n), has(n);
    for(auto &i : req) cin >> i;
    for(auto &i : has) cin >> i;

    int start = 0;
    int end = k + *max_element(has.begin(), has.end());;
    int ans = 0;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        int extra = 0;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(req[i] != 0 && mid > LLONG_MAX / req[i]) {
                flag = true;
                break;
            }
            int need = mid * req[i];
            int ex = max(0ll, need - has[i]);
            if(extra > LLONG_MAX - ex) {
                flag = true;
                break;
            }
            extra += ex;
        }

        if(extra <= k && !flag) {
            ans = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << ans << endl;
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;

}