/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (48.23%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    26.5K
 * Total Submissions: 54.9K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 *
 *
 *
 * Example:
 *
 *
 * Input
 *
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 *
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 500
 * word in addWord consists lower-case English letters.
 * word in search consist of  '.' or lower-case English letters.
 * At most 50000 calls will be made to addWord and search.
 *
 *
 */

// @lc code=start
class WordDictionary {
private:
    unordered_map<string, vector<string>> dic;
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    void addWord(string word) {
        dic[word].push_back(word);
    }

    bool search(string word) {
        auto it = dic.find(word);
        if (it == dic.end()) {
            return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

