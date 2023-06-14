/*
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

示例：

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 

提示：

1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

class Trie {
private:
    bool isWord;
    vector<Trie*> childs;
public:
    Trie() {
        isWord = false;
        childs = vector<Trie*>(26, nullptr);
    }

    void insert(string word) {
        if (word.size() == 0) {
            isWord = true;
            return ;
        }

        int id = word[0]-'a';
        if (childs[id] == nullptr) {
            childs[id] = new Trie();
        }
        childs[id]->insert(word.substr(1));
    }

    bool search(string word) {
        if (word.size() == 0) return isWord;

        int id = word[0]-'a';
        if (childs[id] == nullptr) return false;
        return childs[id]->search(word.substr(1));
    }

    bool startsWith(string prefix) {
        if (prefix.size() == 0) return true;

        int id = prefix[0]-'a';
        if (childs[id] == nullptr) return false;
        return childs[id]->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */