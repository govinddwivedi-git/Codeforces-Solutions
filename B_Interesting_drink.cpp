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

int binarySearch(vec v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    while (start <= end)
    {
        int mid = end + start / 2;
        if (v[mid] == key)
            return mid;
        else if (v[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int32_t main()
{
    fast

    int n,q;
    cin >> n;
    vec v(n);
    rep(i, n) cin >> v[i];
    sort(all(v));
    cin >> q;
    vec p(q);
    rep(i, q)
    {
        int q;
        cin >> q;

        if (q < v[0])
        {
            cout << 0 << '\n';
        }

        else{
            int base = 0, end = n;
            while (end - base > 1)
            {
                int mid = (base + end) / 2;
                if (v[mid] > q)
                    end = mid;
                else
                    base = mid;
            }
            // 3 6 8 10 11
            // base end
            // 0     5
            // 2     5
            // 3     5
            // 3     4
            cout << base + 1 << '\n';
        }
    }

    return 0;
}