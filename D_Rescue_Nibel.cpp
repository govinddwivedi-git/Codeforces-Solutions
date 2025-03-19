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
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
    }
    vector<pair<int,int>> v;
    for(auto &it: a){
        v.push_back({it.ff, +1});
        v.push_back({it.ss+1, -1});
    }
    sort(v.begin(), v.end(), [](auto a, auto b){
        if(a.first == b.first) return a.second > b.second; 
        return a.first < b.first;
    });
    
    int maxN = n;
    vector<int> fact(maxN+1), invfact(maxN+1);
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    auto modexp = [&](int base, int exp) -> int {
        int res = 1;
        while(exp){
            if(exp & 1) res = (int)((1LL * res * base) % mod);
            base = (int)((1LL * base * base) % mod);
            exp /= 2;
        }
        return res;
    };
    invfact[maxN] = modexp(fact[maxN], mod - 2);
    for(int i = maxN; i > 0; i--){
        invfact[i-1] = (int)((1LL * invfact[i] * i) % mod);
    }
    auto nCr = [&](int n, int r) -> int {
        if(r < 0 || r > n) return 0;
        int res = (int)((1LL * fact[n] * invfact[r]) % mod);
        res = (int)((1LL * res * invfact[n - r]) % mod);
        return res;
    };
    int active = 0;
    long long ans = 0;
    for(auto &e: v){
        if(e.second == 1){
            active++;
            if(active >= k)
                ans = (ans + nCr(active-1, k-1)) % mod;
        } 
        else {
            active--;
        }
    }
    cout << ans << endl;
}


int32_t main(){
    fast

    int t = 1;
    // cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}