#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll long long 
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int ans=0;
    for(auto it:mp){
        if(it.second==2) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    fast
int t;
cin>>t;
while(t--){
solve();


}
   return 0;
}