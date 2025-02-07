class Solution {
public:
    int minimumIncrements(vector<int>& arr, vector<int>& target) {
        int m = target.size();
        sort(target.begin(), target.end());
        int n = arr.size();
        int op = 1 << m;
        int cnt = 0;
        map<int,int> mp;
        for(int i = 0; i < m; i++) {
            int rem = INT_MIN;
            for(int j = 0; j < n; j++) {
                rem = max(rem, arr[j] % target[i]); 
                if(arr[j] % target[i] == 0) rem = arr[j];
            }
            for(auto it : mp) {
                rem = max(rem, it.second % target[i]);
                // cout << rem << endl;
            }
            mp[target[i]] = target[i] + rem;
            cout << rem << " ";
            cnt += (target[i]-rem);
        }
        return cnt;
        
    }
};©leetcode