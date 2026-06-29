class Solution {
   public:
    string minWindow(string s, string t) {
        // If t is longer than s, no valid window can exist.
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> need;    // map for t
        unordered_map<char, int> window;  // map for window

        // count the frequency of each character in t
        for (char c : t) {
            need[c]++;
        }

        int required = need.size();  // calculating how many requirements should be satisfied
        int satisfied = 0;  // only increase when a character first reaches its required frequency

        int left = 0;

        // Variables to store the best (minimum) window.
        int minLen = INT_MAX;
        int startIndex = 0;

        for (int right = 0; right < s.size(); right++) {
            window[s[right]]++;

            // If the current character is required and it has just reached
            // its required frequency, then one more requirement is satisfied.
            if (need.find(s[right]) != need.end() && window[s[right]] == need[s[right]]) {
                satisfied++;
            }

            // If all requirements are satisfied,
            // try shrinking the window.
            while (satisfied == required) {
                int windowLen = right - left + 1;
                // Update the minimum window.
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = left;
                }

                // Remove the leftmost character from the window
                window[s[left]]--;

                // If removing it breaks one of the requirements,
                // the window is no longer valid.
                if (need.find(s[left]) != need.end() && window[s[left]] < need[s[left]]) {
                    satisfied--;
                }

                // now shrink the window
                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }
        // Return the smallest valid window.
        return s.substr(startIndex, minLen);
    }
};
