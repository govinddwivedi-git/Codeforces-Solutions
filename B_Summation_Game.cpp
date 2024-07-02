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

int sum(int a[],int n){
    int res = 0;
    rep(i,n) res+=a[i];
    return res;
}


int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        int n,k,x;
        cin >> n >> k >> x;
        vec v(n+1,0);
        for(int i=1;i<=n;i++) cin >> v[i];
        sort(all(v));

        int psum[n+1];
        psum[0]=0;
        for(int i=1;i<=n;i++){
            psum[i] = v[i] + psum[i-1];
        }

        int ans = INT_MIN;
        for(int i=n;i>=0;i--){
            int ch = n-i;
            if(ch>k) break;

            int r = min(i,x);
            int sum = (psum[i-r] - (psum[i]-psum[i-r]));

            ans = max(ans,sum);
        }

        cout << ans << endl;
        
    }
    return 0;
}