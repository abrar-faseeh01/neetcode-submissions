class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // If s1 is longer than s2, it's impossible to find a permutation.
        if(s1.size() > s2.size()){
            return false;
        }

        int windowLen = s1.size();
        int left = 0;

        // Frequency of characters in s1.
        vector<int> freq(26, 0);

        // Frequency of characters in the current window of s2.
        vector<int> windowFreq(26, 0);

        // Build the frequency array for s1.
        for(char c : s1){
            freq[c - 'a']++;
        }

        for(int right = 0; right < s2.size(); right++){

            // Add the current character to the window.
            windowFreq[s2[right] - 'a']++;

            // If the window becomes larger than required,
            // remove the leftmost character.
            if(right - left + 1 > windowLen){
                windowFreq[s2[left] - 'a']--;
                left++;
            }

            // Compare the frequency arrays when the window
            // reaches the required size.
            if(right - left + 1 == windowLen){

                if(windowFreq == freq){
                    return true;
                }

            }
        }

        // No permutation found.
        return false;
    }
};