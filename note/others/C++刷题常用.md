# C++刷题常用

## 1. 最大值/最小值/无穷大

最大值/最小值：

```c++
#include <climits>

INT_MIN
INT_MAX
LLONG_MIN
LLONG_MAX
```

无穷大：

```C++
#define INF 0x3f3f3f3f
#define INF 0x7fffffff
```

常用 `0x3f3f3f3f` 表示，好处在于：

- 10^9
- 两个无穷大相加不会溢出
- 每个字节都相同，可用memset初始化

## 2. 求较大值较小值函数

```c++
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
```

## 3. 数组初始化

使用memset初始化。需注意：以 **字节** 为单位赋值。因此对于int数组，初始化0、-1、0x3f后，数组元素的值分别是0、0xffffffff、0x3f3f3f3f，而初始化1后，数组元素就变为0x01010101。

```c++
#include <string.h>

int a[10];
memset(a, 0, sizeof(a)); // sizeof函数参数为数组时，返回整个数组所占的字节数
```

vector初始化：

```c++
// m*n，每个元素的值为1
vector<vector<int>> mat(m, vector<int>(n, 1));
```

## 4. 字符/字符串读取

读取字符：

- `scanf("%c", &c)`与`getchar(c)`，两者相同，读取一个字符（第一个），按下回车输入才结束；

读取字符串：

- `scanf("%s", s)`，遇到空字符（空格等）输入结束。

- `gets(char*)`，可读空字符，遇到回车结束。

- `cin.getline(char* , int [, char ])`，可读空字符，遇回车结束。

- `getline(std::cin, string)`，可读空字符，遇到回车结束。

## 5. 处理方向

上下左右前进：

```c++
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

for (int i = 0; i < 4; i++) {
    int newx = x + dirs[i][0], newy = y + dirs[i][1];
    if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
        ...
    }
}
```

螺旋前进：

```c++
int dirs[4][2] = {{0,1},{0,1},{1,0},{0,-1}}; // 螺旋：右下左上

vector<vector<int>> mat(m, vector<int>(n, -1));
int x = 0, y = 0, d = 0;
while (未到达终点，可以通过已走过点的数量来判断) {
    int newx = x + dirs[d][0], newy = y + dirs[d][1];
    // 若下一个点达到边界，或者已经走过，则改变方向
    if (newx < 0 || newx >= m || newy < 0 || newy >= n || mat[newx][newy] != -1) {
        d = (d+1)%4;
    }
    x = x + dirs[d][0];
    y = y + dirs[d][1];
}
```

## 6. 判断区间重叠

区间i：`[il, ir)`

区间j：`[jl, jr)`

两个区间重叠有4种情况：2种相交，2种包含。快速判断区间是否重叠代码如下：

```c++
if (il < jr && ir > jl) {
    ...
}
```

## 7. 隐式类型转换

```c++
int a, b;
long long c = 1ll * a * b;
```

前面乘上 `1ll` ，可以让相乘过程转换为 long long 相乘，而非 int 相乘。若是 int 相乘，则会先将结果保存在 int 中，再赋给 long long，会产生截断。

## 8. 四舍五入

```c
#include <cmath>

round(2.5);
```

## 9. 字符串和数值相互转换

数值转字符串：

```c++
// c++11标准增加了全局函数std::to_string，可转换整型和浮点型
string s = to_string(123) // s="123"
```

字符串转数值：

```c++
#include <string>
// std::stoi/stol/stoll
int a = stoi("123");

// atoi
string s = "123";
int a = atoi(s.c_str());
```

## 10. lambda 表达式

```c++
// 定义
[capture list](parameter list) -> return_type {
    function body
}

// 普通函数
auto f = [&](int i, int mask, bool limit, bool zero) -> int {
    ...
}

// 函数递归
// #include <functional>
function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool limit, bool zero) -> int {
    ...
    dfs(...)
    ...
}
```
