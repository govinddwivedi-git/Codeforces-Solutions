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

bool check(double mid, vector<pair<double, double>> &arr, int T) {
    double water = 0;
    double txwater = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].second + water <= mid) {
            txwater = arr[i].first * arr[i].second + txwater;
            water += arr[i].second;
        }
        else {
            double rem = mid - water;
            water += rem;
            txwater = txwater + arr[i].first * rem;
            break;
        }
    }
    bool b1 = (txwater / water) <= T + 1e-12;

    water = 0;
    txwater = 0;
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(arr[i].second + water <= mid) {
            txwater = arr[i].first * arr[i].second + txwater;
            water += arr[i].second;
        }
        else {
            double rem = mid - water;
            water += rem;
            txwater = txwater + arr[i].first * rem;
            break;
        }
    }
    bool b2 = (txwater / water) >= T - 1e-12;
    return b1 && b2;

}

bool check(long double mid, vector<pair<long double, long double>> &arr, int T) {
    long double water = 0;
    long double txwater = 0;
    long double target = mid * T;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].second + water <= mid) {
            txwater = arr[i].first * arr[i].second + txwater;
            water += arr[i].second;
        }
        else {
            long double rem = mid - water;
            water += rem;
            txwater = txwater + arr[i].first * rem;
            break;
        }
    }
    bool b1 = (txwater) <= target;

    water = 0;
    txwater = 0;
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(arr[i].second + water <= mid) {
            txwater = arr[i].first * arr[i].second + txwater;
            water += arr[i].second;
        }
        else {
            long double rem = mid - water;
            water += rem;
            txwater = txwater + arr[i].first * rem;
            break;
        }
    }
    bool b2 = (txwater) >= target;
    return b1 && b2;
}

void solve(){
    int n, T;
    cin >> n >> T;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> t(n);
    for(int &i : t) cin >> i;

    long double sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    vector<pair<long double, long double>> arr(n);
    for(int i = 0; i < n; i++) arr[i] = { (long double)t[i], (long double)a[i] };

    sort(arr.begin(), arr.end());

    long double start = 0.0, end = sum;
    for(int iter = 0; iter < 200; iter++) {
        long double mid = (start + end) / 2;
        if(check(mid, arr, T)) start = mid;
        else end = mid;
    }

    cout << fixed << setprecision(30) << end << endl;
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