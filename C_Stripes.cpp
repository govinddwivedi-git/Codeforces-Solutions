#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j;
    string str;
    cin>>t;
    char ch[8][8];
    while(t--)
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            cin>>ch[i][j];
        }
        for(i=0;i<8;i++)
        {
            str="";
            for(j=0;j<8;j++)
            str+=ch[i][j];
            if(str=="RRRRRRRR")
            break;
        }
        if(i==8)
        cout<<"B\n";
        else
        cout<<"R\n";
    }
}