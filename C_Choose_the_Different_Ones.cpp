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
        int n,m,k;
        cin >> n >> m >> k;
        // set<int> st;
        // for(int i=1;i<=n+m;i++){
        //     int x;
        //     cin>>x;
        //     st.insert(x);
        // }

        set<int> s;
        set<int> t;
        
        // for(int i=1;i<=k;i++){
        //     if(st.find(i)!=st.end()) s.insert(i); 
        // }


        vec a(n);
        vec b(m);
        rep(i,n){
            cin >> a[i];
            if(a[i]>=1 && a[i]<=k) s.insert(a[i]);
        }
        rep(i,m){
            cin >> b[i];
            if(b[i]>=1 && b[i]<=k) t.insert(b[i]);
        }
        bool b1 = true;
        if(s.size()<k/2 || t.size()<k/2) b1 = false;
        else{
            for(int i=1;i<=k;i++){
                if(s.find(i)==s.end() && t.find(i)== t.end()){
                    b1 = false;
                    break;
                }
            }
        }
        
        //sort(all(v));
        sort(all(a));
        sort(all(b));

        
        // for(int i=1;i<=k/2;i++){
        //     if((a[i]-1)==i) s.insert(i);
        // }
        // for(int i=1;i<=k/2;i++){
        //     if((b[i]-1)==i) s.insert(i);
        // }
        // for(int i=1;i<=k/2;i++){
        //     if(binary_search(all(b),i)) s.insert(i);
        // }
        // for(int i=1;i<=k/2;i++){
        //     if(binary_search(all(b),i)) s.insert(i);
        // }
        // int cnt1 = 0;
        // int cnt2 = 0;
        // int i=0;
        // while(cnt1<=k/2){
        //     if(binary_search(all(b),i)){
        //         s.insert(i);
        //         cnt1++;
        //     }
        //     i++;
        // }
        // int j=0;
        // while(cnt2<=k/2){
        //     if(binary_search(all(a),j)){
        //         s.insert(i);
        //         cnt1++;
        //     }
        //     j++;
        // }
        if(b1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}