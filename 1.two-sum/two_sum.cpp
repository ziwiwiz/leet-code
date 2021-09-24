#include <iostream>
#include <vector>
#include <unordered_map>
#include <gtest/gtest.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (51.55%)
 * Likes:    11567
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 4.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        vector<int> res;
        for(int i=0; i!=nums.size(); ++i)
        {
            if(temp.find(nums[i])!=temp.end())
            {
                res.push_back(temp[nums[i]]);
                res.push_back(i);
                break;
            }
            else
            {
                temp.insert(pair<int, int>(target-nums[i],i));
            }
        }
        return res;
    }
};
// @lc code=end

TEST(test_Solution, twoSum)
{
    Solution s;
    vector<int> nums{2,7,11,15};
    int target = 9;
    vector<int> x{0,1};
    vector<int> y = s.twoSum(nums, target);
    ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";
    for (int i = 0; i < x.size(); ++i)
    {
        ASSERT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}
