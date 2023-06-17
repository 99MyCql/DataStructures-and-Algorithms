# Others

## 找最大的两个值

```c++
int max = 0, sec_max = 0, max_p = 0, sec_max_p = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
        // 比最大值大，更新最大值和次大值
        sec_max = max;
        sec_max_p = max_p;
        max = arr[i];
        max_p = i;
    } else if (arr[i] > sec_max) {
        // 比最大值小但比次大值大，更新次大值
        sec_max = arr[i];
        sec_max_p = i;
    }
}
```

## 最少交换次数

## 字典序算法

参考：[下一个排列算法详解：思路+推导+步骤，看不懂算我输！](https://leetcode.cn/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/)

给定序列的其中一种排列，求基于字典序的下一种排列。

算法步骤：

1. **从后向前** 查找第一个 相邻升序 的元素对，满足 `A[i] < A[i+1]` ，此时 `[i+1,end)` 必然是降序的。如果找不到这样的元素对，说明 `[begin,end)` 为降序顺序，则跳转到步骤4。
2. 在 `[i+1,end)` 中 **从后向前** 查找第一个满足 `A[i] < A[j]` 的 j。
3. 将 `A[i]` 与 `A[j]` 交换。
4. 可以断定这时 `[i+1,end)` 必然是降序，逆置 `[i+1,end)`，使其升序。
