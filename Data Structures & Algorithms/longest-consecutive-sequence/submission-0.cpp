class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;

        for(int n : nums){
            s.insert(n);
        } 
        // Now s contains all unique elements from nums (duplicates removed).

        int longest_length = 0;

        for(int n : s){
            if(s.find(n-1) == s.end()){ // n has no predecessor, so it could be the start of a sequence
              int current = n;
              int length = 1;
              while(s.find(current+1) != s.end()){  // Count the length of the consecutive sequence starting from current
                  length+=1; 
                  current+=1; 
              }
      
              if(longest_length < length){
                longest_length = length;
              }

            }
        }
        return longest_length;
        
    }
};






