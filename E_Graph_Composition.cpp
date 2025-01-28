#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll id = 0;
void dfs(ll node, vector<ll> &used, vector<ll> G[], vector<ll> &c)
{
    used[node] = 1;

    c[node] = id;

    for (auto u : G[node])
    {
        if (used[u] == 0)
        {
            dfs(u, used, G, c);
        }
        else
        {
        }
    }
}

void dfs2(ll node, vector<ll> &used, vector<ll> F2[])
{
    used[node] = 1;
    // cout<<node<<"\n";

    for (auto u : F2[node])
    { // RRRRR
        if (used[u] == 0)
        {
            dfs2(u, used, F2);
        }
    }
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        id = 0;
        vector<pair<int, int>> f, g;
        ll n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<ll> G[n + 1];
        ll p = 0;
        vector<ll> F2[n + 1];
        vector<ll> used(n + 1, 0);
        vector<ll> c(n + 1, 0);
        for (ll i = 0; i < m1; i++)
        {
            ll x, y;
            cin >> x >> y;
            f.push_back({x, y});
        }
        for (ll i = 0; i < m2; i++)
        {
            ll x, y;
            cin >> x >> y; // cout<<x<<" "<<y<<"\n";
            G[x].push_back(y);
            G[y].push_back(x);
            g.push_back({x, y});
        }
        // Do DFS on Graph G
        // So you get c[i] == component number of node i in graph G
        for (int i = 1; i <= n; i++)
        {
            if (used[i] == 0)
            {
                id++;
                dfs(i, used, G, c);
            }
        }
        // dfs(1,used,G);

        // now we remove edges from F which should be removed
        // left over graph will make graph F2;
        // we will then analyze groups of F2;
        // which all have same id;
        for (ll i = 0; i < m1; i++)
        {
            ll x = f[i].first;
            ll y = f[i].second;
            if (c[x] == c[y])
            { // cout<<"lol";
                F2[x].push_back(y);
                F2[y].push_back(x);
            }
            else
            {
                p++;
            }
        }
        vector<ll> used2(n + 1, 0);
        unordered_map<ll, ll> count;
        // now do DFS on F2; to analyze groups of F2 all having same id;
        // because all bad edges have been removed;
        for (int i = 1; i <= n; i++)
        {

            if (used2[i] == 0)
            {
                ll iz = c[i]; // cout<<iz<<"\n";
                count[iz]++;
                dfs2(i, used2, F2);
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            // for each component id; check how many
            // groups are there for this id in F2;
            // it is confirmed that all such groups; have same id in them;
            if (count[i] >= 1)
            {
                p = p + count[i] - 1;
            }
        }
        cout << p;
        cout << "\n";
    }

    return 0;
}
