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

const int maxi = 1000001;
vector<int> v(maxi, 0);  
int cnt = 0;            

bool check(vector<int>& a, int k, int x, vector<int>& v, int& cnt) {
    int n = a.size();
    int curr = 0; 
    int c = 0;    
    while(curr < n && c < k) {
        cnt++;       
        int missing = x;  
        bool found = false;
        
        for(int r = curr; r < n; r++) {
            if(a[r] < x && v[a[r]] != cnt) {
                v[a[r]] = cnt; 
                missing--;
            }
            if(missing == 0) {  
                c++;
                curr = r + 1;
                found = true;
                break;
            }
        }
        if(!found) break; 
    }
    
    return c >= k;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    
    int left = 0, right = maxi;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if(check(a, k, mid, v, cnt)) {  
            left = mid;
        } 
        else {
            right = mid - 1;
        }
    }
    
    cout << right << endl;
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