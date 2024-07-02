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

int counter(int n)
{
    int coins[] = {15, 6, 3, 1};
    int total = 0;
    for (int coin : coins)
    {
        total += n / coin;
        n %= coin;
    }
    return total;
}

int32_t main()
{
    fast

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // int f = n/15;
        // int r = n%15;
        // int t = r/10;
        // r = r % 10;
        // int s = r/6;
        // r = r % 6;
        // int th = r/3;
        // r = r % 3;
        // int o = r/1;

        // cout << f+t+s+th+o << endl;

        if (n < 10)
        {
            cout << counter(n) << endl;
        }
        else if (n < 20)
        {
            cout << min(counter(n), counter(n - 10) + 1) << endl;
        }
        else
        {
            cout << min({counter(n), counter(n - 10) + 1, counter(n - 20) + 2}) << endl;
        }
    }
    return 0;
}