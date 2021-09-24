/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (65.66%)
 * Likes:    1057
 * Dislikes: 0
 * Total Accepted:    280.9K
 * Total Submissions: 427.8K
 * Testcase Example:  '3\n7'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 * Example 3:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 *
 * Example 4:
 *
 *
 * Input: m = 3, n = 3
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
 * It's guaranteed that the answer will be less than or equal to 2 * 10^9.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)
        {
            return uniquePaths(n, m);
        }
        int a[m];
        for(int i=0; i!=m; ++i)
        {
            a[i] = 1;
        }
        for(int i=1; i!=n; ++i)
        {
            int top = 1;
            for(int j=1; j!=m; ++j)
            {
                a[j] = top + a[j];
                top = a[j];
            }
        }
        return a[m-1];
        // C(m+n-2, m-1)
            

    }
};
// @lc code=end

