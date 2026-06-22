class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            // Add current character to the window
            freq[s[right]]++;
            // Update the highest frequency character in the window
            maxFreq = max(maxFreq, freq[s[right]]);

            int windowLen = right - left + 1;
            if (windowLen - maxFreq > k) {
                freq[s[left]]--;
                left++;
            } else {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};
