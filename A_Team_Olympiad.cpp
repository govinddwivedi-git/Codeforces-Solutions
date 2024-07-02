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

    int n;
    cin >> n;
    vec v(n),v1,v2,v3;
    rep(i,n){
            
        cin >> v[i];   
        if(v[i] == 1 ) v1.push_back(i)  ;
        else if(v[i] == 2 ) v2.push_back(i)  ;
        else if(v[i] == 3 ) v3.push_back(i)  ;
    };
    //sort(all(v));
    // 1 1 1 2 2 3 3 
    int count1  = 0, count2 = 0, count3 = 0;
    count1 = count(all(v),1);
    count2 = count(all(v),2);
    count3 = count(all(v),3);
    int minig = mini(count1,count2,count3);
    cout << mini(count1,count2,count3) << endl;

    rep(i,minig){
        if(minig==0) break;
        cout << v1[i]+1 << " " << v2[i]+1 << " " << v3[i]+1 << endl; 
    }
    
    
    

     
    return 0;
}