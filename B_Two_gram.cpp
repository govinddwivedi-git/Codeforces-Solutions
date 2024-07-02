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

    int n;
    cin >> n; 
    string s;
    cin >> s;
    int max =  0;
    string ans  = "";
    if(n==2) cout << s << endl;
    else{
        for(int i=0;i<n-1;i++){
            string t;
            int cnt=1;
            t.pb(s[i]);
            t.pb(s[i+1]);
            for(int j=i+1;j<n;j++){
                string temp = s.substr(j,2);
                if(temp==t) cnt++; 
            }
            if(cnt>max){
                ans = t;
                max = cnt;
            }
        }
        cout << ans << endl;
    }

    return 0;
}