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

// int cnt(string s){
//     int d = 0;
//     int base = 1;

//     for(int i = s.length() - 1; i >= 0; i--) {
//         if (s[i] == '1') {
//             d += base;
//         }
//         base *= 2;
//     }
//     return d;
// }


int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,f;
        cin >> s >> f;
        if(s==f) cout << 0 << endl;
        else{
            // int s1 = count(all(s),'1');
            // int s0 = count(all(s),'0');
            // int f1 = count(all(s),'1');
            // int f0 = count(all(s),'0');
            int count1 =0;
            int count2 =0;


            // int sp = cnt(s);
            // int fp = cnt(f);
            // cout << sp << fp << endl;
            
            rep(i,n){
                if(s[i]=='0' && f[i]=='1') count1++;
            }
            rep(i,n){
                if(s[i]=='1' && f[i]=='0') count2++;
            }
            cout << max(count1,count2) << endl;
            
        }
        
    }
    return 0;
}