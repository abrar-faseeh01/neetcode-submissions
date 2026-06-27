// SOLUTION 1 TIME COMPLEXITY O(m+n)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // If s1 is longer than s2, it's impossible to find a permutation.
        if(s1.size() > s2.size()){
            return false;
        }

        int windowLen = s1.size();
        int left = 0;

        // Store the frequency of characters in s1.
        unordered_map<char, int> freq;
        for(char c : s1){
            freq[c]++;
        }

        // Store the frequency of characters in the current window of s2.
        unordered_map<char, int> windowFreq;

        for(int right = 0; right < s2.size(); right++){

            // Add the current character to the window.
            windowFreq[s2[right]]++;

            // If the window becomes larger than required,
            // remove the leftmost character.
            if(right - left + 1 > windowLen){

                windowFreq[s2[left]]--;

                // Remove the key completely if its frequency becomes 0.
                if(windowFreq[s2[left]] == 0){
                    windowFreq.erase(s2[left]);
                }

                left++;
            }

            // Compare the maps only when the window size is exactly equal
            // to the length of s1.
            if(right - left + 1 == windowLen){

                if(windowFreq == freq){
                    return true;
                }

            }
        }

        // No permutation was found.
        return false;
    }
};