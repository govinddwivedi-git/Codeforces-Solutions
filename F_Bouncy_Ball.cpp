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


void solve(){
    int n,m,i1,j1,i2,j2; string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    i1--; j1--; i2--; j2--;

    int dx = 0, dy = 0;
    if(d == "DR"){ dx=1; dy=1; }
    else if(d == "DL"){ dx=1; dy=-1; }
    else if(d == "UR"){ dx=-1; dy=1; }
    else{ dx=-1; dy=-1; }

    set<array<int,4>> visited;
    int bounces=0, x=i1, y=j1;
    while(true){
        if(x==i2 && y==j2){
            cout<<bounces<<"\n";
            return;
        }
        if(!visited.insert({x,y,dx,dy}).second){
            cout<<"-1\n";
            return;
        }
        int nx = x + dx, ny = y + dy;
        bool rowOut = (nx<0 || nx>=n), colOut = (ny<0 || ny>=m);
        if(rowOut && colOut){
            dx=-dx; dy=-dy; bounces++;
            nx = x + dx; ny = y + dy;
        }
        else if(rowOut){
            dx=-dx; bounces++;
            nx = x + dx;
        }
        else if(colOut){
            dy=-dy; bounces++;
            ny = y + dy;
        }
        x=nx; y=ny;
    }
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