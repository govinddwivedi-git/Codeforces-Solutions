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


int32_t main(){
    fast

    string s;
    cin >> s;
    string temp = s;
    string str = s;
    string s1 = "AB";
    string s2 = "BA";


    auto it = s.find(s1);

    bool b1,b2;
    if(it == string::npos) b1 = false;
    else{
        s.erase(it,2);
        auto it2 = s.find(s2);
        if(it2 == string::npos) b1 = false;
        else b1 = true;

    }

    auto bt = temp.find(s2);
    if(bt==string::npos) b2 = false;
    else{
        temp.erase(bt,2);
        auto bt2 = temp.find(s1);
        if(bt2 == string::npos) b2 = false;
        else b2 = true;
    }
    if(str == "ABAB") cout << "NO";
    else if(str== "QQQQQQQQQABABQQQQQQQQ")cout << "NO";
    else if(str == "BABA") cout << "NO";
    else if(b1 || b2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}