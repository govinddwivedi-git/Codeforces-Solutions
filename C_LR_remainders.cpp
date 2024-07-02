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
        int n,m;
        cin >> n >> m;
        vec v(n);
        vec mul(n);
        rep(i,n){
            cin >> v[i];
            
        }
        mul[0]=v[0];
        for(int i=1;i<n;i++){
            mul[i]=(mul[i-1]*v[i]);
        }
        string s;
        cin >> s;

        int num[n];
        num[0]= v[0];

        // int rev[n];
        // rev[n-1]=v[n-1];

        // for(int j=n-2;j>=0;j--){
        //     rev[j] = (rev[j+1] * v[j]);
        // }

        // for(int k=1;k<n;k++){
        //     num[k]= (v[k]*num[k-1]);
        // }


        cout << mul[n-1]%m << " ";

        // for(int i=0;i<n;i++){
        //     if(s[i]=='L'){
        //         cout << (mul[n-1]/num[i])%m<< " ";
        //         mul[n-1]/num[i];
        //     }
        //     else cout << (mul[n-1]/rev[i])%m << " ";
        // }

        int start = 0;
        int end = n-1;
        for(int i=0;i<n-1;i++){
            if(s[i]=='L'){
                cout <<  (mul[end] / v[start]) % m << " ";
                mul[n-1] /= v[start];
                start++;
            }
            else{
                cout <<( mul[n-1]/v[end])%m << " ";
                mul[n-1] /= v[end];
                end--;
            }
        }
        cout << endl;
        
    }
    return 0;
}