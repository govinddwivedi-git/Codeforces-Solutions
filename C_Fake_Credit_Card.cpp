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
        // int n;
        // cin >> n;
        int n;
        cin >> n;
        // string s = to_string(number);
        // int n = s.size();
        // char y = s[n-1];
        // int res = y-'0';
        // string str = "";
        // debug(res);
        // for(int i=0;i<n-1;i++){
        //     str += s[i];
        // }
        // 
        // for(int i=n-1;i>=0;i--){
        //     int x = (int)(str[i]-'0');
        //     debug(x);
        //     sum = (sum%10 + ((x%10)*2)%10)%10; 
        // }

        // if(sum == res) cout << "YES" << endl;
        // else cout << "NO" << endl;
        // // cout<<number<<endl;


        int y = n%10;
        int sum = 0;

        vec v;
        while(n>0){
            v.pb(n%10);
            n /= 10;
        }


        for(int i=1;i<v.size();i++){
            // int x = n%10;
            if(i&1){
                int res = 2*v[i];
                while(res>0){
                    int d = res%10;
                    res /= 10;
                    sum = (sum + (d%10))%10; 
                }

                
            }

            else{
                int res = v[i];
                while(res>0){
                    int d = res%10;
                    res /= 10;
                    sum = (sum + (d%10))%10; 
                
                }
            }
            // n /= 10; 
        }

        if(y == (10-(sum%10))%10) cout << "YES" << endl;
        else cout <<"NO" << endl;

        

        
    }
    return 0;
}