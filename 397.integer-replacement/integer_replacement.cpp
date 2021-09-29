/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] Integer Replacement
 *
 * https://leetcode-cn.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (37.77%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 40.8K
 * Testcase Example:  '8'
 *
 * Given a positive integer n, you can apply one of the following
 * operations:
 * 
 * 
 * If n is even, replace n with n / 2.
 * If n is odd, replace n with either n + 1 or n - 1.
 * 
 * 
 * Return the minimum number of operations needed for n to become 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 8
 * Output: 3
 * Explanation: 8 -> 4 -> 2 -> 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 7
 * Output: 4
 * Explanation: 7 -> 8 -> 4 -> 2 -> 1
 * or 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 4
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        if(2147483647==n)
        {
            return 32;
        }
        int count = 0;
        while(1!=n)
        {
            if(3==n)
            {
                count = count+2;
                break;
            }
            if(n%2 == 0)
            {    
                n=n>>1;
                count++;
            }
            else
            {
                n=(n+1)>>2;
                count=count+3;
            }
        }
        return count;
    }
};
// @lc code=end

