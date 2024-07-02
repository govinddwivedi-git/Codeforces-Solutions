#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int first = n*a;
    int second = (ceil(n/(float)m))*b;
    int three = (n/m)*b + (n - m*(n/m))*a;
    int mini = min(first,min(second,three));
    cout << mini << endl;
    return 0;
}

 