class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0, result = 0;
        for (int num: nums) {
            if (num == 1) temp++;
            result = max(temp, result);
            if (num == 0) temp = 0;
        }
        
        return result;
    }
};