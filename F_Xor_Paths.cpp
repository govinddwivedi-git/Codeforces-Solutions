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

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=45;

vector<vector<map<int,int>>> mpp(N,vector<map<int,int>>(N));
int ans = 0;

void h1(vector<vec> &arr, int mid, int cnt, int xr, int i, int j){
    if(i >= arr.size() || j >= arr[0].size()) return;
    xr ^= arr[i][j];
    if(cnt == mid) {
        mpp[i][j][xr]++;
        return;
    }

    h1(arr, mid, cnt + 1, xr, i + 1, j);
    h1(arr, mid, cnt + 1, xr, i, j + 1);
}

void h2(vector<vec> &arr, int mid, int cnt, int xr, int i, int j, int k){
    if(i < 0 || j < 0) return;
    // xr ^= arr[i][j];
    if(cnt == ((arr.size() + arr[0].size() - 2) - mid)) {
        ans += mpp[i][j][k ^ xr];
        return;
    }

    h2(arr, mid, cnt + 1, xr ^ arr[i][j], i - 1, j, k);
    h2(arr, mid, cnt + 1, xr ^ arr[i][j], i, j - 1, k);
}

void solve(){
   
    ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mpp[i][j].clear();
   
    int n,m,k;
    cin >> n >> m >> k;

    vector<vec> arr(n, vec(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin >> arr[i][j];

    int mid = (n + m - 2) / 2;

    h1(arr, mid, 0, 0, 0, 0);
    h2(arr, mid, 0, 0, n-1, m-1, k);

    cout << ans << endl;
}


int32_t main(){
    fast

    int t = 1;
    // cin >> t;
    while(t--){


        solve();


    }
    return 0;
}