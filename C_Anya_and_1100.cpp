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

bool check (int pos, int n, string &s) {
    if (pos < 0 || pos + 3 >= n) return false;
    return s.substr(pos, 4) == "1100";
}


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    string x = "1100";
    int cnt = 0;
    for (int i = 0; i <= n - 4; i++) {
        if (check(i,n,s)) cnt++;
    }
    int q;
    cin >> q;
    while(q--) {
        int i,v;
        cin >> i >> v;
        i--;
        for (int j = i - 3; j <= i; j++) {
            if(check(j,n,s)) cnt--;
        }
        // if(s.size() < 4){
        //     cout << "NO" << endl;
        //     continue;
        // }
        s[i] = v + '0';
        for (int j = i - 3; j <= i; j++) {
            if (check(j,n,s)) cnt++;
        }
        // if(s.find(x) == string::npos){
        //     cout << "NO" << endl;
        // }
        // else{
        //     cout << "YES" << endl;
        // }

        cout << (cnt > 0 ? "YES" : "NO") << endl;
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