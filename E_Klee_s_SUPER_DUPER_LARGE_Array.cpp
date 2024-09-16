#include <bits/stdc++.h>
#define int long long
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
#define rrep(i, s, n) for (int i = n - 1; i >= s; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define scin(str) getline(cin, str)

// Debugging Macros
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

// Aliases and Types
using vec = vector<int>;
using pii = pair<int, int>;
using mapi = map<int, int>;
using si = set<int>;

const int mod = 1e9 + 7;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every grid problem!!
const int N = 2e5 + 5;

int fun(int a, int b)
{
    return abs(a - b);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int c = (k * (k - 1) / 2) + ((n + k) * (n + k - 1) / 2);
    // int i = (sqrtl(s));
    // cout << min(fun(i * (i + 1), s), fun((i + 1) * (i + 2), s)) << endl; // This is direct formula

    int s = k;
    int e = k + n - 1;
    int ans = 1e18;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if ((mid * (mid + 1)) <= c)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    s = e;
    cout << min(abs(s * (s + 1) - c), abs((s + 1) * (s + 2) - c)) << endl;
}

int32_t main()
{
    fast

        int t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }
    return 0;
}