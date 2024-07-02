#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   char ch;
   int cnt =0;
   string str = "hello";
   int i = 0;
   while(cin >> ch){
        if(str[i]==ch){
            cnt++;
            i++;
        }
   }
   if(cnt==5) cout << "YES";
   else cout << "NO";
    return 0;
}