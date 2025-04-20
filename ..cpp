class Solution {
public:
    // New helper function: computes number of distinct arrangements for the given multiset.
    long long countPermutations(const vector<int>& counts, const vector<long long>& fact) {
        int total = 0;
        for (int c : counts) total += c;
        long long res = fact[total];
        for (int c : counts)
            res /= fact[c];
        return res;
    }
    
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        
        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if(freq[i] & 1) { oddCount++; oddChar = i; }
        }
        if(oddCount > 1) return "";
        
        // Build half counts.
        vector<int> halfCount(26, 0);
        int halfLength = 0;
        for (int i = 0; i < 26; i++){
            halfCount[i] = freq[i] / 2;
            halfLength += halfCount[i];
        }
        
        // Precompute factorials up to halfLength.
        vector<long long> fact(halfLength + 1, 1);
        for (int i = 1; i <= halfLength; i++)
            fact[i] = fact[i - 1] * i;
        
        long long total = countPermutations(halfCount, fact);
        if(total < k) return "";
        
        // Construct half string lexicographically.
        string half = "";
        for (int pos = 0; pos < halfLength; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if(halfCount[ch] > 0) {
                    halfCount[ch]--; 
                    long long ways = countPermutations(halfCount, fact);
                    if(ways >= k) {
                        half.push_back('a' + ch);
                        break;
                    } else {
                        k -= ways;
                        halfCount[ch]++; // restore count
                    }
                }
            }
        }
        
        // Form the final palindrome.
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        string middle = (oddCount == 1) ? string(1, 'a' + oddChar) : "";
        return half + middle + rev_half;
    }
};