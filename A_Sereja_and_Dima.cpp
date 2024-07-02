// ! Taken HINT.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sums = 0;
    int sumd = 0;

    int start = 0;
    int end = n - 1;
    bool serejaTurn = true;

    while (start <= end) {
        if (v[start] > v[end]) {
            // Sereja's turn
            if (serejaTurn) {
                sums += v[start];
            }
            else {
                sumd += v[start];
            }
            start++;
        }
        else {
            // Dima's turn
            if (serejaTurn) {
                sums += v[end];
            }
            else {
                sumd += v[end];
            }
            end--;
        }

        // Switch turns
        serejaTurn = !serejaTurn;
    }

    cout << sums << " " << sumd << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int sums = 0;
    int sumd = 0;
    
    int start = 0;
    int end = n-1;
    while(start<=end){
        if(v[end]>v[start] && start<=end) sums += v[end--];
        else sums += v[start++];
        if(v[end]>v[start] && start<=end) sumd += v[end--];
        else sumd += v[start++];
    }
    cout << sums << " " << sumd << endl;
    return 0;
} 
*/
