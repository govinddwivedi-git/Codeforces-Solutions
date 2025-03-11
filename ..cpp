class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();
            vector<bool> vis(n, false);
            int cnt = 0;
            
            for (int i = 0; i < n; i++) {
                bool b = false;
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && baskets[j] >= fruits[i]) {
                        vis[j] = true;
                        b = true;
                        break;
                    }
                }
                if (!b) {
                    cnt++;
                }
            }
            
            return cnt;
        }
    };
    ©leetcode