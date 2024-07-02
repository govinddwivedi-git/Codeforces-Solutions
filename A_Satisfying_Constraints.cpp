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
        int n;
        cin>>n;
        int a[n],b[n];
        for( int i=0;i<n;i++){
            cin>>a[i];
            cin>>b[i];
        }
        int j=INT_MAX,k=-1;
        for(int i=0;i<n;i++){
            if(a[i]==1) {
                if(b[i]>=k) k=b[i];
            }
            else if(a[i]==2) {
                if(b[i]<=j) j=b[i];
            }
        }
        int count=j-k+1;
        for(int i=0;i<n;i++){
            if(a[i]==3 && b[i]>=k && j>=b[i])  count--;
        }
        if(count<0) count=0;
        cout<<count<<endl;
    }
    return 0;
}