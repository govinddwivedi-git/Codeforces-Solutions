#include <bits/stdc++.h>
using namespace std;
int cnt(string &s){
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]<='z' && s[i]>='a') count++;
    }
    return count;
}

int CNT(string &s){
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]<='Z' && s[i]>='A') count++;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s ;
    cin >> s;
    if(cnt(s)>=CNT(s)){
        for(int i=0;i<s.length();i++){
            s[i]=tolower(s[i]);
        }
        cout << s << endl;
    }
    else{
        for(int i=0;i<s.length();i++){
            s[i]=toupper(s[i]);
        }
        cout << s << endl;
    }

    
    return 0;
}