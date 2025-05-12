#include <bits/stdc++.h>
using namespace std;

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
#define rrep(i,s,n) for(int i=n-1;i>=s;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define scin(str) getline(cin, str)

using vec = vector<int>;
using pii=pair<int,int>;
using mapi=map<int,int>;
using si=set<int>;

const int mod = 1e9+7;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const int N = 5005;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int m;
    cin >> m;
    vector<int> b(m+1);
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    vector<vector<int>> f(n+1, vector<int>(m+1, 0));
    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    
    for(int i = 1; i <= n; i++) {
        int fmax = 0, pos = 0;
        for(int j = 1; j <= m; j++) {
            f[i][j] = f[i-1][j];
            pre[i][j] = pre[i-1][j];
            
            if(a[i] == b[j]) {
                if(f[i][j] < fmax + 1) {
                    f[i][j] = fmax + 1;
                    pre[i][j] = pos;
                }
            }
            
            if(b[j] < a[i]) {
                if(f[i-1][j] > fmax) {
                    fmax = f[i-1][j];
                    pos = j;
                }
            }
        }
    }
    
    int res = 0, last = 0;
    for(int j = 1; j <= m; j++) {
        if(res < f[n][j]) {
            res = f[n][j];
            last = j;
        }
    }
    
    cout << res << endl;
    
    int i = n, j = last;
    vector<int> path;
    
    while(i > 0 && j > 0) {
        if(pre[i][j] != j) {
            path.push_back(b[j]);
        }
        j = pre[i][j];
        i--;
    }
    
    reverse(path.begin(), path.end());
    
    for(int k = 0; k < path.size(); k++) {
        cout << path[k] << (k < path.size()-1 ? " " : "\n");
    }
}

int32_t main(){
    fast

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}