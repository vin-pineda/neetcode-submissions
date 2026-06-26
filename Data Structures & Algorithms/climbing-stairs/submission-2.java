class Solution {
    public int climbStairs(int n) {
        //Base Case -> start computing distinct ways to climb top
        if (n==0 || n==1) return 1;
        //Example:2 -> climbStairs(1) = 1 + climbStairs(0) = 1. Output = 1+1 = 2
        return climbStairs(n-1) + climbStairs(n-2);
    }
}
