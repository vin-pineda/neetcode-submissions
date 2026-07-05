class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy(nums1.begin(), nums1.begin() + m);
        int k = 0, j = 0, i = 0;
        while (k < m + n) {
            if (j >= n || (i < m && nums1_copy[i] <= nums2[j])) nums1[k++] = nums1_copy[i++];
            else nums1[k++] = nums2[j++];
        }
    }
};