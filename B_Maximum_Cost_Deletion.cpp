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

// int count_operations(string s) {
//     // A variable to store the count
//     int count = 0;

//     // A loop to repeat the operation until the string is empty
//     while (!s.empty()) {
//         // A variable to store the length of the current substring
//         int len = 1;

//         // A loop to find the longest substring of equal characters
//         while (len < s.size() && s[len] == s[len - 1]) {
//             len++;
//         }

//         // Remove the substring from the string
//         s.erase(0, len);

//         // Increment the count
//         count++;
//     }

//     // Return the count
//     return count;
// }


int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if(a>=0 && b>=0) cout << s.length()*(a+b) << endl;
        else if(a<0 && b >=0) cout << s.length()*(a+b) << endl;
        else  if (b < 0){
            int count = 0;
            for(int i=1;i<=n;i++){
                if(s[i]!=s[i-1]) count++;
            }
            cout << a*s.length() + b*(count/2+1) << endl; 
        } 
        // int ans = a*n;
        // if(b>=0) cout << ans + b*n << endl;
        // else{
        //     int count = 0;
        //     for(int i=1;i<=n;i++){
        //         if(s[i]!=s[i-1]) count++;
        //     }
        //     count = count/2 +1;
        //     ans += b*count;
        //     cout << ans << endl;
        // }
        
        
    }
    return 0;
}