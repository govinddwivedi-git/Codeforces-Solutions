#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t;
    cin >> t;
    while(t--) {
        long long int a, b;
        cin >> a >> b;
        cout << min(min(a, b), (a + b) / 3) << "\n";
    }

    return 0;
}