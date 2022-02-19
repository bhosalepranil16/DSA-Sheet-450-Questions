class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1, ans;
        for(int i=1;i<nums.size();i++) {
            if(nums[res - 1] != nums[i]) {
                nums[res] = nums[i];
                res++;
            }
            else {
                ans = nums[i];
            }
        }
        return ans;
    }
};