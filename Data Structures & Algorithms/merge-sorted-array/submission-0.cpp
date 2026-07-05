class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copy(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0, k = 0;
        while (k < m + n) {
            if (j >= n || (i < m && copy[i] <= nums2[j])) nums1[k++] = copy[i++];
            else nums1[k++] = nums2[j++];
        }
    }
};