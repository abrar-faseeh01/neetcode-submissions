class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> seen;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            while (seen.find(s[right]) != seen.end()) {  
                // character found. find the first pos of it and remove everything from start to that duplicate character
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
