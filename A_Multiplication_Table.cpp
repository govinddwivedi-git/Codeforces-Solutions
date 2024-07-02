#include <bits/stdc++.h>
using namespace std;

int countDivisors(int n,int x) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= n; i++) { 
        if (x % i == 0 && x/i <= n){ 
           cnt++;
        } 
    } 
    return cnt; 
} 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int x;
    cin >> x;
    int res = countDivisors(n,x);
    cout << res;
    

    return 0;
}