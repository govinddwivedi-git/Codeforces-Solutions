#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
#define pb push_back
// #define mp make_pair
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
    int m = n * (n - 1) / 2;
    vector<int> b(m);
    for(auto &i : b) cin >> i;
    
    sort(all(b));
    
    vector<int> a;
    int skip = n - 1;
    for(int i = 0; i < m; ) {
        a.push_back(b[i]);
        i += skip;
        skip--;
    }
    
    // The problem guarantees a solution exists. A simple way to construct the last
    // element of 'a' is to use the largest value found in 'b', which will be one of
    // the largest elements in 'a'. Appending it ensures 'a' has size 'n'.
    a.push_back(b.back());

    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
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