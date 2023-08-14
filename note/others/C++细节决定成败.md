# 细节决定成败

## 边界判断在前，逻辑判断在后

错误做法，会触发越界：

```c
while (nums[j] == nums[p] && j < len) j++;
```

正确做法：

```c
while (j < len && nums[j] == nums[p]) j++;
```

## long long 最大值

0x7fffffffffffffff 或 LLONG_MAX

## 运算符优先级

乘除/取余 > 加减 > 左移/右移 > 大于/小于/等于逻辑比较 > 位运算 > 与或逻辑运算

示例：

```C++
(a & b) != 0; // 此处位运算必须加括号
```

## 重载运算符对指针不生效

示例：

```c++
struct Node {
    int val;
    bool operator < (const Node &i) const {
        return val > i.val;
    }
};

priority_queue<Node*> q; // 比较的是指针，重载运算符不生效
priority_queue<Node> q;  // 生效
```

## iterator也要判断边界

iterator需要判断边界，如果 `it == xxx.begin()` 就不要再 `it--` 了。

```c++
set<int> s;
s.insert(1);
multiset<int>::iterator it = s.lower_bound(1);
it--; // 超出边界
``
