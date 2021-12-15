# C++刷题常用

## 1. int无穷大

常用 `0x3f3f3f3f` 表示无穷大，好处在于：

- 10^9

- 两个无穷大相加不会溢出

- 每个字节都相同，可用memset初始化

```C++
#define INF 0x3f3f3f3f
#define INF 0x7fffffff

```

## 2. 最大最小值

```c++
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
```

## 3. 数组初始化

使用memset初始化，需注意：

- 以**字节** 为单位赋值。因此对于int数组，初始化0、-1、0x3f后，数组元素分别是0、-1、0x3f3f3f3f，而初始化1后，数组元素就变为0x01010101。

sizeof函数参数为数组时，返回整个数组所占的字节数。

```c++
#include <string.h>

int a[10];
memset(a, 0, sizeof(a));
```

## 4. 字符/字符串读取

读取字符：

- `scanf("%c", &c)`与`getchar(c)`，两者相同，读取一个字符（第一个），按下回车输入才结束；

读取字符串：

- `scanf("%s", s)`，遇到空字符（空格等）输入结束。

- `gets(char*)`，可读空字符，遇到回车结束。

- `cin.getline(char* , int [, char ])`，可读空字符，遇回车结束。

- `getline(std::cin, string)`，可读空字符，遇到回车结束。
