class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i=0; i<nums.size(); i++){

            // skip the duplicate values for fixed
             if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int fixed = nums[i];
    
            int left = i+1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = fixed + nums[left] + nums[right];
                if(sum<0){
                    left++;
                }
                else if(sum>0){
                    right--;
                }
                else{
                    result.push_back({fixed, nums[left], nums[right]});
                    left++; 
                    right--;

                    // skip the duplicate values for left
                    while(left<right && nums[left] == nums[left-1]){
                        left++;
                    }
                    // skip the duplicate values for right
                    while(left<right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
        
            }
        }
        return result;
        
    }
};


