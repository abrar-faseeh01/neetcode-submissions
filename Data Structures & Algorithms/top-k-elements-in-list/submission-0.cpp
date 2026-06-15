class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int n : nums){
            mp[n]++;
        }

        vector<vector<int>> bucket(nums.size() +1);

       for(auto& p : mp){
        int num = p.first;
        int count = p.second;
        bucket[count].push_back(num);
       }

       vector<int> result;
       for(int i = bucket.size() - 1; i>=0; i--){
        for(int n: bucket[i]){
            result.push_back(n);
            if(result.size() == k){
                return result;
            }
        }
       }
        return {};
    }
};