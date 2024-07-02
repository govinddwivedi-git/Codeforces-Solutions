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
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        int d;
        cin >> d;
        vec v(n);
        rep(i,n) cin >> v[i];
        //sort(all(v),greater<int>());

        sort(all(v));

        // 50 60 70 80 90 100

        // int cnt = 1;
        // int ans=0;


        // int wins = 0;
        // int totalpower = 0;
        // int cnt = 0;
        // rep(i,n){
        //     totalpower += v[i];
        //     cnt++;

        //     if(totalpower - v[i] * (cnt - 1) > d){
        //         wins++;
        //         totalpower = 0;
        //         cnt  = 0;
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(v[i]*cnt>d){
        //         ans++;
        //         cnt=1;
        //     }
        //     else cnt++;
        // }

        // for(int i=n-1;i>=0;){
        //     if(d%v[i]!=0)
        //     i-=ceil(d/(v[i]*1.0));
        //     else
        //     i-=((d/(v[i]))+1);
        //     if(i>=-1) ans++;
        // }
        d++;

        int b = 0;

        int x = 0;
        int ans = 0;

        for(int i=n-1;i>=b;i--){
            x = (d + v[i] - 1) / (v[i]);
            b += x-1;
            if(b > i) break;
            ans++;

        }
        
        
        cout << ans << endl;
        
    }
    return 0;
}