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

const int MOD = 998244353;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;


void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    
    vector<int> power2(n+5, 1), invPow2(n+5, 1);
    auto modExp = [&](int base, int exp) -> int {
        int res = 1;
        while(exp){
            if(exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    };
    int inv2 = modExp(2, MOD-2);
    for (int i = 1; i < n+5; i++){
        power2[i] = (power2[i-1] * 2) % MOD;
        invPow2[i] = (invPow2[i-1] * inv2) % MOD;
    }
    
    int curr2 = 0; 
    int cum1 = 0; 
    int count1 = 0; 
    int res = 0;
    
    for(auto x : a){
        if(x == 1){
            cum1 = (cum1 + invPow2[curr2]) % MOD;
            count1++;
        }
        else if(x == 2){
            curr2++;
        }
        else if(x == 3){
            int add = ((long long)power2[curr2] * cum1 % MOD - count1) % MOD;
            if(add < 0) add += MOD;
            res = (res + add) % MOD;
        }
    }
    cout << res % MOD << endl;
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