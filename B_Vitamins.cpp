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

#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

using vec = vector<int>;
using pii=pair<int,int>;
using mapi=map<int,int>;
using si=set<int>;

const int mod = 1e9+7;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const int N=2e5+5;

bool isABCSubsequence(const string &s) {
    string target = "ABC";
    int j = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target[j]) {
            j++; 
        }
        if (j == target.size()) {
            return true; 
        }
    }
    return false; 
}

int getMin(vector<pair<string,int>> &v) {
    if(v.empty()) return LLONG_MAX;
    sort(all(v), [](auto &x, auto &y){
        if(x.ff == y.ff) return x.ss < y.ss;
        return x.ff < y.ff;
    });
    return v[0].ss;
}

void solve(){
    int nn;
    cin >> nn;
    vector<pair<string,int>> a,b,c,ab,bc,ac,abc;

    for(int i = 0; i < nn; i++) {
        int n;
        string s;
        cin >> n >> s;
        int m = s.size();

        if(m == 1) {
            if(s == "A") a.pb({s, n});
            if(s == "B") b.pb({s, n});
            if(s == "C") c.pb({s, n});
        }
        if(m == 2) {
            sort(all(s)); 
            if (s == "AB") ab.pb({s, n});
            if (s == "BC") bc.pb({s, n});
            if (s == "AC") ac.pb({s, n}); 
        }
        if(m == 3) {
            sort(all(s)); 
            abc.pb({s, n});        
        }
    }

    int total = 0;
    string temp = "";
    int ans = INT_MAX;

    if(!a.empty()) { total += getMin(a); temp += "A"; }
    if(!b.empty()) { total += getMin(b); temp += "B"; }
    if(!c.empty()) { total += getMin(c); temp += "C"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!ab.empty()) { total += getMin(ab); temp += "AB"; }
    if(!c.empty()) { total += getMin(c); temp += "C"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!bc.empty()) { total += getMin(bc); temp += "BC"; }
    if(!a.empty()) { total += getMin(a); temp += "A"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!ac.empty()) { total += getMin(ac); temp += "AC"; }
    if(!b.empty()) { total += getMin(b); temp += "B"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!ab.empty()) { total += getMin(ab); temp += "AB"; }
    if(!bc.empty()) { total += getMin(bc); temp += "BC"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!ac.empty()) { total += getMin(ac); temp += "AC"; }
    if(!bc.empty()) { total += getMin(bc); temp += "BC"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!ac.empty()) { total += getMin(ac); temp += "AC"; }
    if(!ab.empty()) { total += getMin(ab); temp += "AB"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);
    temp = ""; total = 0;

    if(!abc.empty()) { total += getMin(abc); temp += "ABC"; }
    sort(all(temp)); if(isABCSubsequence(temp)) ans = min(ans, total);

    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main(){
    fast
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
