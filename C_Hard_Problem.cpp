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


void solve(){
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int sum = 0;
    if(a == m && b == m) {
        cout << 2*m << endl;
        return;
    }

    if(a < m) {
        int diff = m - a;
        if(b < m) {
            int diff2 = m - b;
            if(diff + diff2 >= c) {
                cout << a+b+c << endl;
                return;
            }
            else {
                cout << a + b + diff + diff2 << endl;
                return;
            }
        }
        else {
            if(diff >= c) {
                cout << a + m + c << endl;
                return;
            }
            else {
                cout << a + m + diff << endl;
                return;
            }
        }
    }

    else {
        if(b < m) {
            int diff2 = m - b;
            if(diff2 >= c) {
                cout << m + b + c << endl;
                return;
            }
            else {
                cout << m + b + diff2 << endl;
                return;
            }
        }
        else {
            cout << 2 * m << endl;
            return;
        }
    }

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