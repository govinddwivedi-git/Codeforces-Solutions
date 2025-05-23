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

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    vec cost;
    vec k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cost.pb(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        k.pb(x);
    }
    vector<pair<int, pii>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int c = abs(a[i].ff - a[j].ff) + abs(a[i].ss - a[j].ss);
            edges.pb({c * (k[i] + k[j]), {i, j}});
        }
    }


    for(int i = 0; i < n; i++) {
        edges.push_back({cost[i], {i, n}});
    }

    // map<pii,int> mpp;
    // for(int i = 0; i < n; i++) {
    //     mpp[a[i]] = i;
    // }
    // unordered_map<int,pii> rmp;
    // for(int i = 0; i < n; i++) {
    //     rmp[i] = a[i];
    // }

    vector<int> built;
    int mini = INT_MAX;
    int initial = 0;
    for (int i = 0; i < n; i++)
    {
        if (cost[i] < mini)
        {
            mini = cost[i];
            initial = i;
        }
    }

    DisjointSet ds(n+1);
    sort(all(edges));

    vector<pii> conn;

    int ans = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)) {
            if(v == n) {
                built.push_back(u);
            } 
            else {
                conn.push_back({u, v});
            }
            ds.unionBySize(u, v);
            ans += wt;
        
        }
        
    }

    cout << ans << endl;
    cout << built.size() << endl;
    for (auto &it : built)
    {
        cout << it + 1 << " ";
    }
    cout << endl;
    cout << conn.size() << endl;
    for (auto &p : conn)
    {
        cout << p.first + 1 << " " << p.second + 1 << endl;
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