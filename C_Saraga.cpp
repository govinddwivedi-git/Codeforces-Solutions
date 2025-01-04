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

void solve()
{
    string S, T;
    cin >> S >> T;

    int n = S.size(), m = T.size();
    vec prefix(26, INT_MAX);
    vec suffix(26, INT_MAX);

    for (int i = 0; i < n; ++i)
    {
        int c = S[i] - 'a';
        if (i > 0)
        {
            prefix[c] = min(prefix[c], i + 1);
        }
    }

    for (int i = m - 1; i >= 0; --i)
    {
        int c = T[i] - 'a';
        if (i < m - 1)
        {
            suffix[c] = min(suffix[c], m - i);
        }
    }

    string result = "";
    int mn = INT_MAX;

    for (int c = 0; c < 26; ++c)
    {
        if (prefix[c] != INT_MAX && suffix[c] != INT_MAX)
        {
            int total = prefix[c] + suffix[c] - 1;
            if (total < mn)
            {
                mn = total;
                result = S.substr(0, prefix[c]) + T.substr(m - suffix[c] + 1);
            }
        }
    }

    if (result.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
}

int32_t main()
{
    fast

        int t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }
    return 0;
}