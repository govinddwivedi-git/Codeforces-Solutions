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
    vec v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    cout << v[0] << " ";
    set<int> s;
    s.insert(v[0]);
    int cnt = 1;
    for(int i = 1;i<n;i++){
        if(s.find(v[i]) == s.end()){
            s.insert(v[i]);
            cout << v[i] << " ";
        }
        else {
            while(s.find(cnt) != s.end()) cnt++;
            cout << cnt << " ";
            s.insert(cnt);
            cnt++;
        }
    }
    cout << endl;

    // vec hash(n+1, 0);
    // int m = n+1;
    
    // vec ans;
    // ans.push_back(v[0]);
    // hash[v[0]]++;
    // int maxi = 0;
    // maxi = max(maxi, hash[v[0]]);
    // for(int i=1;i<n;i++) {
    //     if(hash[v[i-1]] > hash[v[i]] + 1) {
    //         if(hash[v[i]] + 1 < maxi) {
    //             ans[i-1] = v[i];
    //             hash[v[i]]++;
    //         }
    //         else ans[i-1] = m + i;
    //         hash[v[i-1]]--;
    //     }
        
    //     ans.push_back(v[i]);
    //     hash[v[i]]++;

    //     maxi = max(maxi, hash[v[i]]);
        
    // }

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