#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],i;
        for(i=0;i<n;i++) cin>>arr[i];
        int ans=0;
        for(i=0;i<n/2;i++)
        {
            ans=__gcd(abs(arr[i]-arr[n-i-1]),ans);
        }
        cout<<ans<<endl;
    }
}