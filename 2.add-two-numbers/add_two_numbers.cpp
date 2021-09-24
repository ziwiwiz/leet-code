#include <iostream>
#include <gtest/gtest.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (40.49%)
 * Likes:    6453
 * Dislikes: 0
 * Total Accepted:    903K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode head(0);
        ListNode* ptrsum = &head;
        int val = 0;
        while(l1 && l2)
        {
            val = val/10 + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            ptrsum->next = new ListNode(val % 10);
            ptrsum = ptrsum->next;
        }
        if(l1)
        {
            ptrsum->next = l1;
            val = val/10 + l1->val;
            while(val > 9)
            {
                if(l1->next==nullptr)
                {
                    l1->next = new ListNode(0);
                }
                l1->val = 0;
                l1 = l1->next;
                val = l1->val + 1;
            }
            l1->val = val;
        }
        else if(l2)
        {
            ptrsum->next = l2;
            val = val/10 + l2->val;
            while(val > 9)
            {
                if(l2->next==nullptr)
                {
                    l2->next = new ListNode(0);;
                }
                l2->val = 0;
                l2 = l2->next;
                val = l2->val + 1;
            }
            l2->val = val;
        }
        else if(val > 9)
        {
            ptrsum->next = new ListNode(1);
        }
        return head.next;
    }
};
// @lc code=end

ListNode* buildNode(const vector<int>& nums)
{
    ListNode head(0);
    ListNode* ptr = &head;
    for(auto i:nums)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    return head.next;
    // ListNode* res = nullptr;
    // for(auto it = nums.rbegin(); it != nums.rend(); ++it)
    // {
    //     res = new ListNode(*it, res);
    // }
    // return res;
}

void clearNode(ListNode* head)
{
    ListNode* node = head;
    while(node)
    {
        ListNode* del = node;
        node = node->next;
        delete del;
        del = nullptr;
    }
}

TEST(addTwoNumbers, example1)
{
    vector<int> nums1{2,4,3};
    vector<int> nums2{5,6,4};
    ListNode* l1 = buildNode(nums1);
    ListNode* l2 = buildNode(nums2);
    vector<int> nums3{7,0,8};
    ListNode* l3 = buildNode(nums3);
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res && l3)
    {
        // cout<<res->val<<":"<<l3->val<<endl;
        ASSERT_EQ(res->val, l3->val)<< "res is "<<res->val<<" and l3 is"<<l3->val;
        res = res->next;
        l3 = l3->next;
    }
    ASSERT_EQ(res, nullptr) << " res is not null";
    ASSERT_EQ(l3, nullptr) << " l3 is not null";
    clearNode(l1);
    clearNode(l2);
    clearNode(res);
}

TEST(addTwoNumbers, example2)
{
    vector<int> nums1{0};
    vector<int> nums2{0};
    ListNode* l1 = buildNode(nums1);
    ListNode* l2 = buildNode(nums2);
    vector<int> nums3{0};
    ListNode* l3 = buildNode(nums3);
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res && l3)
    {
        ASSERT_EQ(res->val, l3->val)<< "res is "<<res->val<<" and l3 is"<<l3->val;
        res = res->next;
        l3 = l3->next;
    }
    ASSERT_EQ(res, nullptr) << " res is not null";
    ASSERT_EQ(l3, nullptr) << " l3 is not null";
}

TEST(addTwoNumbers, example3)
{
    vector<int> nums1{9,9,9,9,9,9,9};
    vector<int> nums2{9,9,9,9};
    ListNode* l1 = buildNode(nums1);
    ListNode* l2 = buildNode(nums2);
    vector<int> nums3{8,9,9,9,0,0,0,1};
    ListNode* l3 = buildNode(nums3);
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res && l3)
    {
        ASSERT_EQ(res->val, l3->val)<< "res is "<<res->val<<" and l3 is"<<l3->val;
        res = res->next;
        l3 = l3->next;
    }
    ASSERT_EQ(res, nullptr) << " res is not null";
    ASSERT_EQ(l3, nullptr) << " l3 is not null";
}
