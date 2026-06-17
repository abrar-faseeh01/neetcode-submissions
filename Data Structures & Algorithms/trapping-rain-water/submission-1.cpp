class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight  = height[right];
        int waterTrapped = 0;

        while(left < right){
            // Process the side with the smaller maximum wall
            if(maxLeft < maxRight){
                left++;
                maxLeft = max(maxLeft, height[left]);
                waterTrapped += maxLeft - height[left];
            }

            else{
                right--;
                maxRight = max(maxRight, height[right]);
                waterTrapped += maxRight - height[right];
            }
        }
        return waterTrapped;

    }
};



   
