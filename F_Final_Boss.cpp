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

int check(int h, int cnt, vector<pii> &v){
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        int uses = 1 + (cnt - 1) / v[i].second;
        sum += v[i].first * uses;
        if(sum >= h) return 1;
    }
    return sum >= h;
}

void solve(){
    int h,n;
    cin >> h >> n;
    vec a(n);
    rep(i,n) cin >> a[i];
    vec c(n,0);
    rep(i,n) cin >> c[i];
    // unordered_map<int,int> mp;
    // rep(i,n) mp[a[i]] = c[i];
    vector<pii> v(n);
    rep(i,n) v[i] = {a[i],c[i]};
    // sort(all(v));
    int cnt = 1;
    int start = 1;
    int end = h*(*max_element(all(c))*(*max_element(all(a))));
    int ans = 1e18;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(check(h,mid,v)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
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