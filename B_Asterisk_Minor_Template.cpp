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

    int t = 1;
    cin >> t;
    while(t--){
    string a, b;
        cin >> a >> b;
 
        
        if(a[0] == b[0]) {
            cout << "YES" << endl;
            cout << a[0] << "*" << endl;
        } 
        
        else if(a[a.size() - 1] == b[b.size() - 1]) {
            cout << "YES" << endl;
            cout << "*" << a[a.size() - 1] << endl;
        } 
      
        else {
            bool flag = false;
            for(int i = 0; i < a.size() - 1; i++) {
                for(int j = 0; j < b.size() - 1; j++) {
                    if(a[i] == b[j] && a[i + 1] == b[j + 1]) {
                        flag = true;
                        cout << "YES" << endl;
                        cout << "*" << a[i] << a[i + 1] << "*" << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag) cout << "NO" << endl;
        }
        
    }
    return 0;
}