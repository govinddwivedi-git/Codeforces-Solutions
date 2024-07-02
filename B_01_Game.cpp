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


int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int zeros = 0, ones = 0;
        for(char c : s){
            if(c == '0') zeros++;
            else ones++;
        }

        // 0001 <- ALice bhai chalenge
        // 00 <- Bob bhai chalenge lekin chal nhi sakte 
        // ALice jeet gya 
        // DA print hoga

        // 000111 <- ALice bhai chalenge
        // 0011 <- Bob bhai chalenge
        // 01 <- Alice bhai chalenge 
        // Bob bhai haar gye
        // DA print hoga. 

        // 000011 <- ALice bhai chalenge
        // 0001 <- Bob bhai chalenge
        // 00 <- Alice bhai chalenge lekin chal nhi payenge 
        // Bob jeet jayega
        // NET print hoga

        bool alice = (min(zeros, ones) % 2 == 1);
        if(alice) cout << "DA" << endl;
        else cout << "NET" << endl;


        
    }
    return 0;
}