#include <bits/stdc++.h>
using namespace std;

// Macros and constants
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


void solve(){
    int n;
    cin >> n;
    if(n == 3){
        cout << "! 1 2 3" << endl;
        cout.flush();
        return;
    }
    
    int a = 1, b = 2, c = 3;
    int q = 0;
    int ch = 0;  
    bool k = false;
    
    while(q < 75 && !k){
        cout << "? " << a << " " << b << " " << c << endl;
        cout.flush();
        q++;
        
        int r;
        cin >> r;
        if(r == -1) exit(0);
        if(r == 0){
            k = true;
            break; 
        }
        
        int pt = r;
        bool f = false;
       
        cout << "? " << pt << " " << b << " " << c << endl;
        cout.flush();
        q++;
        cin >> r;
        if(r == -1) exit(0);
        if(r == 0){
            a = pt;
            f = true;
            k = true; 
        }
        
        if(!f && q < 75){
            cout << "? " << a << " " << pt << " " << c << endl;
            cout.flush();
            q++;
            cin >> r;
            if(r == -1) exit(0);
            if(r == 0){
                b = pt;
                f = true;
                k = true;
            }
        }
        
        if(!f && q < 75){
            cout << "? " << a << " " << b << " " << pt << endl;
            cout.flush();
            q++;
            cin >> r;
            if(r == -1) exit(0);
            if(r == 0){
                c = pt;
                f = true;
                k = true;
            }
        }
        
        if(!f){
            if(ch == 0){
                a = pt;
            }
            else if(ch == 1){
                b = pt;
            } 
            else{
                c = pt;
            }
            ch = (ch + 1) % 3;
        }
    }
    
    cout << "! " << a << " " << b << " " << c << endl;
    cout.flush();
}


int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}