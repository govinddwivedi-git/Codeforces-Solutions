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
    int n;
    cin >> n;
    int d;
    cin >> d;
    
    vector<int> ans;
    ans.pb(1); 

    if(n > 2) {
        ans.pb(3);
    } 
    
    else {
        if((2*d) % 3 == 0) ans.pb(3);
    }

    if(d == 5) ans.pb(5);

    if(n > 2) {
        ans.pb(7);
    } 
    else {
        if(d == 7) ans.pb(7);
    }

    if(n >= 6) {
        ans.pb(9);
    } 
    else {
        int rem;
        if(n == 2) rem = 2;
        else if(n == 3) rem = 6;
        else if(n == 4) rem = 6;
        else rem = 3; 
        int pr = (rem * (d % 9)) % 9;
        if(pr == 0) ans.pb(9);
    }

    sort(all(ans));
    for(auto &x : ans) cout << x << " ";
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