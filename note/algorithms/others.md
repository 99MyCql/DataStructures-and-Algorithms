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
