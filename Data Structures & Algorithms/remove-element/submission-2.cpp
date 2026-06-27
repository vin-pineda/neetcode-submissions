class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
        Input: nums = [3,2,2,3], val = 3
        Output: k = 2, nums = [2,2,_,_]
        */
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == val) nums[i] = nums[--n];
            else i++;
        }
        return n;
    }
};