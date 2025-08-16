#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
// #define pb push_back
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

bool check(int b, int s, int c, int mid, int nb, int ns, int nc, int pb, int ps, int pc, int r) {
    int cb = max(0LL, b * mid - nb) * pb;
    int cs = max(0LL, s * mid - ns) * ps;
    int cc = max(0LL, c * mid - nc) * pc;
    int totalCost = cb + cs + cc;
    return totalCost <= r;

    
}

void solve(){
    string str;
    cin >> str;
    int n = str.size();
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int r;
    cin >> r;

    int b = 0, s = 0, c = 0;
    for(auto &ch : str) {
        if(ch == 'B') b++;
        else if(ch == 'S') s++;
        else c++;
    }
    
    int start = 0, end = 1e14;
    int ans = 0;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(check(b, s, c, mid, nb, ns, nc, pb, ps, pc, r)) {
            ans = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }

    cout << ans << endl;
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}



// ! Nearly O(1) solution

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string recipe;
//     cin >> recipe;
//     long long nb, ns, nc;
//     cin >> nb >> ns >> nc;
//     long long pb, ps, pc;
//     cin >> pb >> ps >> pc;
//     long long r;
//     cin >> r;

//     long long needB = 0, needS = 0, needC = 0;
//     for (char ch : recipe) {
//         if (ch == 'B') needB++;
//         else if (ch == 'S') needS++;
//         else if (ch == 'C') needC++;
//     }

//     long long burgers = 0;

//     // Make burgers using existing stock and buying missing parts
//     while (true) {
//         long long buyB = max(0LL, needB - nb);
//         long long buyS = max(0LL, needS - ns);
//         long long buyC = max(0LL, needC - nc);
//         long long cost = buyB * pb + buyS * ps + buyC * pc;

//         if (cost > r) break; // can't afford even one more burger

//         r -= cost;
//         nb -= needB - buyB;
//         ns -= needS - buyS;
//         nc -= needC - buyC;
//         burgers++;
//     }

//     // Now, if we have no stock left, jump directly
//     long long costPerBurger = needB * pb + needS * ps + needC * pc;
//     if (costPerBurger > 0) {
//         burgers += r / costPerBurger;
//     }

//     cout << burgers << "\n";
// }
