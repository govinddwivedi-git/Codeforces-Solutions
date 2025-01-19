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
  
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    
    int maxi = 0;

    
    int a3 = a1 + a2;
    int fib1 = 0;
    if(a3 == a1 + a2) fib1++;
    if(a4 == a2 + a3) fib1++;
    if(a5 == a3 + a4) fib1++;
    maxi = max(maxi, fib1);



    a3 = a4 - a2;
    int fib2 = 0;
    if(a3 == a1 + a2) fib2++;
    if(a4 == a2 + a3) fib2++;
    if(a5 == a3 + a4) fib2++;
    maxi = max(maxi, fib2);



    a3 = a5 - a4;
    int fib3 = 0;
    if(a3 == a1 + a2) fib3++;
    if(a4 == a2 + a3) fib3++;
    if(a5 == a3 + a4) fib3++;
    maxi = max(maxi, fib3);
    


    cout << maxi << endl;
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