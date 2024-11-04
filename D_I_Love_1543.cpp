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
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<char>> a(n, vector<char>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            if (x != '\n')
                a[i].pb(x);
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int sr = 0;
    int sc = 0;
    int er = n - 1;
    int ec = m - 1;

    int cnt = n * m;
    vector<string> ans;
    while (cnt > 0)
    {
        string temp = "";
        for (int i = sc; i <= ec && cnt; i++)
        {
            temp += a[sr][i];
            cnt--;
        }
        sr++;
        for (int i = sr; i <= er && cnt; i++)
        {
            temp += a[i][ec];
            cnt--;
        }
        ec--;
        for (int i = ec; i >= sc && cnt; i--)
        {
            temp += a[er][i];
            cnt--;
        }
        er--;
        for (int i = er; i >= sr && cnt; i--)
        {
            temp += a[i][sc];
            cnt--;
        }
        sc++;
        ans.pb(temp);
    }
    int res = 0;
    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        string temp = ans[i];
        // cout<<temp<<endl;
        int len = temp.size();
        int j = 0;
        for (j = 0; j < len - 3; j++)
        {
            if ((temp[j] == '1') && (temp[j + 1] == '5') && (temp[j + 2] == '4') && (temp[j + 3] == '3'))
            {
                res++;
            }
        }

        while (j < len)
        {
            if ((temp.substr(j) + temp.substr(0, 4 - (len - j))) == "1543")
            {
                res++;
            }
            j++;
        }
        // string st=(temp.substr(j) + temp.substr(0,4-(len-j)))

        // cout << res << endl;
    }
    cout << res << endl;
    // for(int i=0;i<ans.size();i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
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