/*
有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1
提示：

words.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-closest-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> word_map;
        for (int i = 0; i < words.size(); i++) {
            if (word_map.count(words[i]) == 0) word_map[words[i]] = vector<int>();
            word_map[words[i]].push_back(i);
        }
        for (auto v : word_map) {
            printf("%s:", v.first.c_str());
            for (int i = 0; i < v.second.size(); i++) {
                printf(" %d", v.second[i]);
            }
            printf("\n");
        }
        int min = 0x7fffffff;
        // for (int i = 0; i < word_map[word1].size(); i++) {
        //     int l = 0, r = word_map[word2].size();
        //     while (l < r) {
        //         int mid = (l+r)/2;
        //         if (word_map[word2][mid] >= word_map[word1][i]) r = mid;
        //         else l = mid+1;
        //     }
        //     if (l < word_map[word2].size() && abs(word_map[word2][l]-word_map[word1][i]) < min)
        //         min = abs(word_map[word2][l]-word_map[word1][i]);
        //     if (l-1 >= 0 && abs(word_map[word2][l-1]-word_map[word1][i]) < min)
        //         min = abs(word_map[word2][l-1]-word_map[word1][i]);
        // }
        int i = 0, j = 0;
        while (i < word_map[word1].size() && j < word_map[word2].size() &&
            word_map[word1][i] != word_map[word2][j]) {
            if (abs(word_map[word1][i]-word_map[word2][j]) < min)
                min = abs(word_map[word1][i]-word_map[word2][j]);
            if (word_map[word1][i] > word_map[word2][j]) j++;
            else i++;
        }
        return min;
    }
};