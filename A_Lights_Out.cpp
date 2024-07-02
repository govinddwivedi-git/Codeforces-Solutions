#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> v(3, vector<int>(3, 1)); 
    vector<vector<int>> b(3, vector<int>(3));

    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> b[i][j];
        }
    }

    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (b[i][j] % 2 == 1) { 
                v[i][j] = !v[i][j]; 
                if (i > 0) v[i-1][j] = !v[i-1][j]; 
                if (i < 2) v[i+1][j] = !v[i+1][j]; 
                if (j > 0) v[i][j-1] = !v[i][j-1];
                if (j < 2) v[i][j+1] = !v[i][j+1]; 
            }
        }
    }

    
    for (const auto &row : v) {
        for (int val : row) {
            cout << val;
        }
        cout << endl;
    }

    return 0;
}
