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
    int x, n, m;
    cin >> x >> n >> m;

    auto f1 = [&](int x, int n, int m){
        while((n+m) > 0 && x > 1){
            if(x % 2 == 0){
                if(m > 0){ m--; }
                else { n--; }
                x /= 2;
            } 
            else {
                if(n > 0){
                    n--;
                    x /= 2;
                } 
                else {
                    m--;
                    x = (x + 1)/2;
                }
            }
        }
        if(x == 1 && n > 0){
            x = 0;
        }
        return x;
    };

    auto f2 = [&](int x, int n, int m){
        while((n+m) > 0 && x > 1){
            if(x % 2 == 1 && m > 0){
                m--;
                x = (x + 1) / 2; 
            } 
            else if(x % 2 == 1 && n > 0){
                n--;
                x /= 2;
            } 
            else {
                if(n > 0){ n--; } 
                else { m--; }
                x /= 2;
            }
        }
        
        if(x == 1 && n > 0){
            x = 0;
        }
        return x;
    };

    int mn = f1(x, n, m);
    int mx = f2(x, n, m);
    cout << mn << " " << mx << endl;
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