/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (42.77%)
 * Likes:    1264
 * Dislikes: 0
 * Total Accepted:    268.7K
 * Total Submissions: 628K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        for(int i = 0; i != nums.size(); ++i)
        {
            if(i > max)
                return false;
            max = i+nums[i]>max ? i+nums[i] : max;
        }
        return true;
    }
};
// @lc code=end

