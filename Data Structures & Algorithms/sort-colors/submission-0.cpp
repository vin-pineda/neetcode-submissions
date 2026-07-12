class Solution {
public:
    void sortColors(vector<int>& nums) {
        helper(nums, 0, nums.size() - 1);
    }

private:
    void helper(vector<int>& nums, int s, int e) {
        if(e - s + 1 <= 1) return;

        int pivot = nums[e], left = s;

        for(int i = s; i < e; i++) {
            if (nums[i] < pivot) swap(nums[left++], nums[i]);
        }

        nums[e] = nums[left];
        nums[left] = pivot;

        helper(nums, s, left - 1); helper (nums, left + 1, e);
    }
};