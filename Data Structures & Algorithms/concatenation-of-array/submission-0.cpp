class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        if (nums.size() == 0) return {};
        if (nums.size() == 1) return {nums[0], nums[0]};
        vector<int> ans(2 * nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }
};