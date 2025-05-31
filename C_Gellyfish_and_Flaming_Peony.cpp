#include <bits/stdc++.h>
using namespace std;

// Macros and constants
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

// global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;


void solve(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    rep(i, n) cin >> arr[i];

    set<int> s(all(arr));
    if(s.size() == 1) { 
        cout << "0\n";
        return;
    }

    int g = arr[0];
    for(int i = 1; i < n; i++) {
        g = __gcd(g, arr[i]);
    }

    int cntg = 0; 
    for(int i = 0; i < n; i++) {
        if(arr[i] == g) cntg++;
    }

    if(cntg > 0) { 
        cout << (n - cntg) << endl;
        return;
    }

    vector<int> b(n);
        for(int i = 0; i < n; i++) {
            b[i] = arr[i] / (int)g; 
        }

        int mx = 5000;
        int val = n + 5;
        int temp[mx+1], temp2[mx+1];

        for(int x = 1; x <= mx; x++) {
            temp[x] = val;
        }

        for(int i = 0; i < n; i++) {
            for(int x = 1; x <= mx; x++) {
                temp2[x] = temp[x];
            }
            temp2[b[i]] = 1;
            for(int x = 1; x <= mx; x++) {
                if(temp[x] < val) {
                    int g2 = __gcd(x, b[i]);
                    temp2[g2] = min(temp2[g2], temp[x] + 1);
                }
            }
            for (int x = 1; x <= mx; x++) {
                temp[x] = temp2[x];
            }
        }

        int k = temp[1];
        
        int answer = (k - 1) + (n - 1);
        cout << answer << endl;
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