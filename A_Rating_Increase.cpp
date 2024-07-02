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
vec push(int n){
    vec v;
    while(n>0){
        v.pb(n%10);
        n /= 10;
    }
    reverse(all(v));
    return v;
}

int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string a = "";
        string b;
        bool b1 = true;
        int n = s.size();
        for(int i=0;i<n-1;i++){
            a += s[i];
            b=s.substr(i+1,n-(i+1));
            if(b[0]=='0') continue;
            else{
                if(stoi(a) < stoi(b)){
                    b1=false;
                    cout << a << " " << b << endl;
                    break;
                }
            }

        }
        if(b1) cout << -1 << endl;
       

    }
    return 0;
}