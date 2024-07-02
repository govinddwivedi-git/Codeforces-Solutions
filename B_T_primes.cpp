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
const int N = 1e6 + 50;

int32_t main()
{
    fast

    // int n;
    // cin >> n;
    // vector<bool> sieve(N + 1, true);
    // sieve[0] = sieve[1] = false;
    // for (int i = 2; i * i <= N; i++)
    // {
    //     if (sieve[i])
    //     {
    //         for (int j = i * i; j <= N; j += i)
    //         {
    //             sieve[j] = false;
    //         }
    //     }
    // }
    // while (n--)
    // {
    //     int x;
    //     cin >> x;
    //     int sq = sqrtl(x);
    //     if(sqrtl(x)!=sq) cout << "NO" << endl;
    //     else{
    //         if(sieve[sq]) cout << "YES" << endl;
    //         else cout << "NO" << endl;

    //     }
    // }

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int sq = sqrtl(x);
        bool b = true;
        for(int i=2;i*i<=sq;i++){
            if(sq%i==0){
                b = false;
                break;
            }
        }
        if(sqrtl(x)==2) cout << "YES" << endl;
        else if(b && sq==sqrtl(x) && x>1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}