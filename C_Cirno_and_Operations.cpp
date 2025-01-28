#include <bits/stdc++.h>
using namespace std;


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


#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl


using vec = vector<int>;
using pii = pair<int, int>;
using mapi = map<int, int>;
using si = set<int>;

const int mod = 1e9 + 7;


const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 
const int N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vec a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> curr = a;
    int maxi = accumulate(all(a), 0LL);
    
    while (curr.size() > 1) {
        
        vector<int> diff(curr.size() - 1);
        for (int i = 0; i < curr.size() - 1; i++) {
            diff[i] = curr[i+1] - curr[i];
        }
        int diffSum = accumulate(all(diff), 0LL);
        maxi = max(maxi, diffSum);
        
        
        reverse(curr.begin(), curr.end());
        vector<int> revDiff(curr.size() - 1);
        for (int i = 0; i < curr.size() - 1; i++) {
            revDiff[i] = curr[i+1] - curr[i];
        }
        int revDiffSum = accumulate(all(revDiff), 0LL);
        maxi = max(maxi, revDiffSum);
        
        curr = (diffSum > revDiffSum) ? diff : revDiff;
    }
    
    cout << maxi << endl;
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