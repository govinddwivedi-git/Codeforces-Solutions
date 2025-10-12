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
const int N=2e5+5;

int findUpperBound(vector<pair<int,int>> &arr, int k) {
    int n = arr.size();
    int start = 0, end = n - 1;
    int ans = n;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid].first <= k) start = mid + 1;
        else {
            ans = mid;
            end = mid - 1;
        }
    }

    return ans;

}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        if(arr[i] < i + 1) {
            v.push_back({arr[i], i + 1});
        }
    }

    sort(all(v));

    // for(auto &i : v) {
    //     cout << i.first << " " << i.second << endl;
    // } 

    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        int ind = findUpperBound(v, v[i].second);
        int cnt = v.size() - ind;
        ans += cnt;
    }

    cout << ans << endl;
    // cout << "\n";
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