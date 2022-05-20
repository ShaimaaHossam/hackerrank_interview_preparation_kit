class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mapp;
        vector<int> result;
        
        for(int i =0; i<nums.size(); i++){
            int temp = target - nums[i];
            
            if(mapp.find(temp) != mapp.end()){
                //found
                
                result.push_back(mapp.find(temp)->second);
                result.push_back(i);
                break;
            }
            else{
                mapp[nums[i]] = i;
            }
        }
        return result;
    }
};