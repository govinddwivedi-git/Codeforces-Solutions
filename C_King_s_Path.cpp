#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
#define pb push_back
// #define mp make_pair
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


void solve(){
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n; 
    cin >> n;
    map<int, vector<pair<int,int>>> allowed;
    for(int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        allowed[r - 1].push_back({a - 1, b - 1});
    }
    // Sort intervals for each row for binary search
    for(auto &row : allowed) {
        sort(row.second.begin(), row.second.end());
    }

    queue<array<int, 3>> q;
    q.push({x0 - 1, y0 - 1, 0});
    unordered_set<long long> vis;
    vis.insert(((long long)(x0 - 1) << 32) | (y0 - 1));

    while(!q.empty()) {
        auto f = q.front();
        q.pop();
        int x = f[0], y = f[1], steps = f[2];
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int row = x + i;
                int col = y + j;
                if(row < 0 || col < 0) continue;
                if(allowed.count(row)) {
                    // Binary search for interval
                    auto &intervals = allowed[row];
                    auto it = lower_bound(intervals.begin(), intervals.end(), make_pair(col, col),
                        [](const pair<int,int>& a, const pair<int,int>& b){
                            return a.second < b.first;
                        });
                    bool ok = false;
                    if(it != intervals.end() && col >= it->first && col <= it->second) ok = true;
                    else if(it != intervals.begin()) {
                        --it;
                        if(col >= it->first && col <= it->second) ok = true;
                    }
                    long long key = ((long long)row << 32) | col;
                    if(ok && !vis.count(key)) {
                        if(row == x1 - 1 && col == y1 - 1) {
                            cout << steps + 1 << endl;
                            return;
                        }
                        q.push({row, col, steps + 1});
                        vis.insert(key);
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}