/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] Super Egg Drop
 *
 * https://leetcode-cn.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (29.16%)
 * Likes:    686
 * Dislikes: 0
 * Total Accepted:    50.9K
 * Total Submissions: 174.7K
 * Testcase Example:  '1\n2'
 *
 * You are given k identical eggs and you have access to a building with n
 * floors labeled from 1 to n.
 * 
 * You know that there exists a floor f where 0 <= f <= n such that any egg
 * dropped at a floor higher than f will break, and any egg dropped at or below
 * floor f will not break.
 * 
 * Each move, you may take an unbroken egg and drop it from any floor x (where
 * 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the
 * egg does not break, you may reuse it in future moves.
 * 
 * Return the minimum number of moves that you need to determine with certainty
 * what the value of f is.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 1, n = 2
 * Output: 2
 * Explanation: 
 * Drop the egg from floor 1. If it breaks, we know that f = 0.
 * Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
 * If it does not break, then we know f = 2.
 * Hence, we need at minimum 2 moves to determine with certainty what the value
 * of f is.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 2, n = 6
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 3, n = 14
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= 100
 * 1 <= n <= 10^4
 * 
 * 
 */
// dp(1,x)=x
// 假设扔了x次
// 最多检测楼层 dp(k,x) = dp(k,x-1) + 1 + dp(k-1, x-1)

// @lc code=start
class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[k+1][n+1];
        for(int j = 0; j<=n; ++j)
        {
            dp[1][j] = j;
            dp[0][j] = 0;
        }
        for(int i = 0; i<=k; ++i)
        {
            dp[i][0] = 0;
        }
        int x=1;
        for(x=1;x<=n;++x)
        {
            for(int i=1;i<=k;++i)
            {
                dp[i][x] = dp[i][x-1]+1+dp[i-1][x-1];
                // cout<< i << " " << x << " " << dp[i][x]<<endl;
                if(dp[i][x]>=n)
                    return x;
            }
        }
        return x;
    }
};
// @lc code=end

