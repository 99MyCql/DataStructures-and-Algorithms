# 字符串匹配 - KMP算法

KMP是一种模式匹配算法，什么是模式匹配呢？就是，现有一个 **主串(S)** 和 **模式串(P)** ，要在主串中查找是否存在与模式串相等的子串（主串中任意连续字符组成的子序列）。

例如，有一个字符串为`ababcabcacbab`，我们想知道该字符串中有没有一个`abcac`的子串，这就叫模式匹配。

## 1. 普通模式匹配算法

普通的模式匹配，采用暴力算法，匹配的规则是：

1. 在主串的第i个位置，让pos=i，如果主串pos位置的字符等于模式串的第一个字符，则pos++，再与模式串的第二个字符进行匹配。
2. 如果又相等则继续向下匹配，直到匹配到模式串的结尾，就说明主串中存在该模式串；如果不相等，则停止匹配，回到主串中，并i++。
3. 然后再让pos=i，重复上述步骤，直到i到达主串结尾。

相应代码如下：

```c
#include<stdio.h>
#include<string.h>

int main() {
    char str[10000], pat[10000];
    printf("please push the main string:\n");
    scanf("%s", str);
    printf("please push the pattern:\n");
    scanf("%s", pat);
    int lenS = strlen(str), lenP = strlen(pat);

    // 从主串第一位置开始向后匹配，直到结尾
    for (int i = 0; i < lenS; i++) {
        int pos = i, j = 0;
        while (j < lenP) {
            // 如果主串pos位置与模式串的j位置相等，则都向后一位
            if (pat[j] == str[pos]) {
                j++;
                pos++;
            }
            // 否则中断与模式串的匹配
            else break;
        }
        // 判断与模式串是否完全匹配，若是则输出i位置
        if (pos-i == lenP) printf("\npattern start in %d", i);
    }
}
```

普通模式匹配算法，在每次匹配失败后，都需要从模式串 `0` 位重新开始，匹配主串 `i+1` 位。当遇到极端情况时，例如：主串为`000000000000000000001`，模式串为`0001`，每次匹配都需要遍历整个模式串。

综上，算法时间复杂度为 `O(n*m)` ，n为主串长度，m为模式串长度。

## 2. KMP模式匹配算法

参考：[如何更好地理解和掌握 KMP 算法? - 阮行止的回答 - 知乎](
https://www.zhihu.com/question/21923021/answer/1032665486)

KMP算法于1977年被提出，全称 Knuth–Morris–Pratt 算法，作者包括：Donald Knuth(K), James H. Morris(M), Vaughan Pratt(P)。

KMP的优势在于匹配失败后不需要从模式串 0 位重新开始，而是以一种**滑动**的方式匹配模式串。

### next数组

首先，我们假设对于**模式串**有一个`next`数组。

`next[j] = k` 表示：在模式串 `P[0...j]` 的子串中，前 k 个字符等于后 k 个字符，即 `P[0..k-1] == P[j-k-1...j]` ，同时 k 要求最大但不能等于 `j+1` 。

例1：`abcabd`模式串的`next`数组为`[0,0,0,1,2,0]`。其中，`next[4]=2` ，是因为在子串 `P[0...4]` 中 `P[0...1] == P[3...4] == "ab"` ，即前2个字符与后2个字符相等。

例2：`0001`模式串的`next`数组为`[0,1,2,0]`。其中，`next[2]=2`，是因为 `P[0...1] == P[1...2] == "00"` 。

### 利用next数组进行模式匹配

在普通模式匹配算法中，主串`pos`位与模式串`j`位不匹配时，主串回到`i+1`位与模式串`0`位重新进行匹配。

在KMP算法中，基于 `next` 数组：

1. 主串 `i` 位与模式串 `j` 位匹配时，`i++; j++`。
2. 主串 `i` 位与模式串 `j` 位不匹配时：
    1. 若 `j != 0` ，用主串 `i` 位与模式串 `next[j-1]` 位进行匹配，不需要回退到模式串的 `0` 位重新匹配了，即令 `j = next[j-1]` 。
    2. 若 `j == 0` ，则 `i++` 。

```c++
int i = 0, j = 0;
for (int i = 0; i < S.size(); i++) {
    while (j > 0 && S[i] != P[j]) j = next[j-1];
    if (S[i] == P[j]) j++;

    if (j == P.size()) {
        // 匹配成功
    }
}
```

可以看出，模式串以向前滑动的方式与主串进行匹配，这利用了 `next` 数组的特性：与模式串 `P[0...j]` 的子串中后 k 个字符匹配，一定与子串中前 k 个字符匹配。

综上，算法时间复杂度为 `O(n+m)` 。

### 快速构建next数组

剩下最后一个问题：如何构建next数组？

一种方式是暴力，对于 `next[i]` ，遍历 `P[0...i]` 的子串，找前缀与后缀相等的字符串的最大长度。但，这种方式时间复杂度为 `O(m^2)` 。

更优的方式是利用 next 数组本身的特性进行构建，与利用 next 数组进行模式匹配的算法相同。对于 `next[i]` ：

1. 若 `next[i-1]` 为0，则 `next[i]=0` 。
2. 若 `next[i-1]` 不为0，令 `x = next[i-1]` ：
    1. 若 `P[i] == P[x]` ，则 `next[i] = x+1` 。
    2. 若 `P[i] != P[x]` ，则令 `x = next[x-1]` 继续比较，直至 `x` 等于 0 。

```c++
next[0] = 0;
int x = 0;
for (int i = 1; i < next.size(); i++) {
    while (x > 0 && P[i] != P[x]) x = next[x-1];
    if (P[i] == P[x]) x++;
    next[i] = x;
}
```

时间复杂度为 `O(m)` 。

### 代码模板

```c
vector<int> kmp(string &S, string &P) {
    int n = S.size(), m = P.size();
    vector<int> next(m);
    int x = 0;
    for (int i = 1; i < next.size(); i++) {
        while (x > 0 && P[i] != P[x]) x = next[x-1];
        if (P[i] == P[x]) x++;
        next[i] = x;
    }

    vector<int> res;
    int i = 0, j = 0;
    for (int i = 0; i < S.size(); i++) {
        while (j > 0 && S[i] != P[j]) j = next[j-1];
        if (S[i] == P[j]) j++;

        if (j == P.size()) {
            res.push_back(i - m + 1);
            j = next[j-1];
        }
    }
    return res;
}
```
