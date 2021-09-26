/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 *
 * https://leetcode-cn.com/problems/max-number-of-k-sum-pairs/description/
 *
 * algorithms
 * Medium (49.73%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 13.8K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * You are given an integer array nums and an integer k.
 * 
 * In one operation, you can pick two numbers from the array whose sum equals k
 * and remove them from the array.
 * 
 * Return the maximum number of operations you can perform on the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 5
 * Output: 2
 * Explanation: Starting with nums = [1,2,3,4]:
 * - Remove numbers 1 and 4, then nums = [2,3]
 * - Remove numbers 2 and 3, then nums = []
 * There are no more pairs that sum up to 5, hence a total of 2 operations.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,1,3,4,3], k = 6
 * Output: 1
 * Explanation: Starting with nums = [3,1,3,4,3]:
 * - Remove the first two 3's, then nums = [1,4,3]
 * There are no more pairs that sum up to 6, hence a total of 1 operation.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> map_nums;
        for(auto i:nums)
        {
            if(map_nums[i] > 0)
            {
                map_nums[i]--;
                sum++;
            }
            else
            {
                map_nums[k-i]++;
            }
        }
        return sum;
    }
};
// @lc code=end

