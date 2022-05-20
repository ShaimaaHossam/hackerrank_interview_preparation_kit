using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int start = 0;
        int end = nums.size()-1;
        
        while(i<=end && start <end){
            if(nums[i] == 0){
                nums[i] = nums[start];
                nums[start] = 0;
                start++;
                i++;
            }
            else if(nums[i] == 2){
                nums[i] = nums[end];
                nums[end] = 2;
                end--;
            }
            else{
                i++;
            }
        }
    }
    
    
};