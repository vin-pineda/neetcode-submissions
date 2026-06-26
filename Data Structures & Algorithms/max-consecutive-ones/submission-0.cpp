class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0, result = 0;
        for (int num: nums) {
            if (num == 0) {
                result = max(result, temp);
                temp = 0;
            }
            else temp++;
        }
        return max(result, temp);
    }
};