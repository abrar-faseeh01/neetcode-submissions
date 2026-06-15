class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            
            // check and skip non-alphanumeric character
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            // Ensuring the case insensitivity comparing left and right
            if( tolower(s[left]) == tolower(s[right])){
                left++;
                right--;
        }
        else {
            return false;
            }
        }
          return true;
    }
};

