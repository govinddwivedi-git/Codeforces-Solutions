#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define pb push_back
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
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

int dp[105][3][10005];

int f(int ind, int cap, vec &a, int sum, int x, int y)
{
    if (cap == 0)
    {
        if (sum >= x && sum <= y)
            return 1;
        return 0;
    }
    if (ind < 0)
        return 0;

    if (dp[ind][cap][sum] != -1)
        return dp[ind][cap][sum];

    int nt = f(ind - 1, cap, a, sum, x, y);
    int t = f(ind - 1, cap - 1, a, sum - a[ind], x, y);

    return dp[ind][cap][sum] = t + nt;
}

int countPairs(vector<int> &arr, int target)
{
    // Your code here
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    int res = 0;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (arr[i] + arr[j] < target)
        {
            res += j - i;
            i++;
        }
        else
            j--;
    }

    return res;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = accumulate(all(a), 0LL);
    int L = sum - y;
    int R = sum - x;

    sort(all(a));

    int cnt = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int low = lower_bound(a.begin() + i + 1, a.end(), L - a[i]) - a.begin();
    //     int high = upper_bound(a.begin() + i + 1, a.end(), R - a[i]) - a.begin();
    //     cnt += (high - low);
    // }

    int cntL = countPairs(a, L);
    int cntR = countPairs(a, R+1);

    cnt = cntR - cntL;

    cout << cnt << endl;
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
