# STL

## 0. 前言

STL是C++中的一个类库，提供常用的数据结构(如栈、队列等)和算法(如排序、查找等)。

灵活运用STL中的数据结构，可以帮助你有效解决很多算法问题。

简单记载STL中的常用内容。

参考：<https://cplusplus.com/reference/stl/> 。

<!-- more -->

## 1. stack

```c++
#include <stack>
```

栈。先进后出结构。

### 1.1. 创建

`stack<int> s`: 声明一个栈，以整型为基本单位。也可以用其它数据类型为基本单位，包括结构体类型。

### 1.2. 增

`s.push(num)`: 入栈

- 参数：num，与声明栈时的数据类型相同
- 返回值：无

### 1.3. 删

`s.pop()`: 出栈

- 参数：无
- 返回值：无

### 1.4. 查

`s.top()`: 获取栈顶元素

- 参数：无
- 返回值：栈顶元素的值，与声明栈时的数据类型相同

`s.empty()`: 判断栈是否为空

- 参数：无
- 返回值：bool类型，空为真，反之为假

`s.size()`: 获取栈长度

- 参数：无
- 返回值：栈中元素个数，数据类型为**无符号整型**（要注意：若 size()-1<0 ，则为无符号整型的最大值）

```c
#include<iostream>
#include<stack>
using namespace std;

int main() {
  stack<int> s; // 定义一个栈，基本单位为int类型
  s.push(1); // push一个元素进栈
  cout << s.size()-2 << endl; // 按常理 s.size()-2 应为-1
}
```

输出：`18446744073709551615`

## 2. queue

```c++
#include <queue>
```

队列。先进先出结构。

### 2.1. 创建

`queue<int> q`: 声明一个队列，以整型为基本单位。也可以用其它数据类型为基本单位，包括结构体类型。

### 2.2. 增

`q.push(num)`: 队尾进队列

- 参数：num，与声明队列时的数据类型相同
- 返回值：无

### 2.3. 删

`s.pop()`: 队头出队列

- 参数：无
- 返回值：无

### 2.4. 查

`q.front()`: 获取队头元素

- 参数：无
- 返回值：队头元素的值，与声明队列时的数据类型相同

`q.back()`: 获取队尾元素

- 参数：无
- 返回值：队尾元素的值，与声明队列时的数据类型相同

`q.empty()`: 判断队列是否为空

- 参数：无
- 返回值：bool类型，空为真，反之为假

`q.size()`: 获取队列长度

- 参数：无
- 返回值：队列中元素个数，数据类型为**无符号整型**(同上)

## 3. vector

```c++
#include <vector>
```

动态数组。

参考：<https://cplusplus.com/reference/vector/vector/>

优点：

- 动态数据个数
- 访问数据方便

缺点：

- 在中间插入删除不方便

### 3.1. 创建

`vector<int> v`: 声明一个vector(其存储空间是连续的，类似于动态数组)，以整型为基本单位。

**注意**：`vector v`的内存是分配在栈上的，而`v`中的元素是分配在堆上的。

```c++
// constructors used in the same order as described above:
vector<int> first;                               // empty vector of ints
vector<int> second(4,100);                       // four ints with value 100
vector<int> third(second.begin(),second.end());  // iterating through second
vector<int> fourth(third);                       // a copy of third

// the iterator constructor can also be used to construct from arrays:
int myints[] = {16,2,77,29};
vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int) );

vector<int> a = {1,2,3,4};
```

### 3.2. 增

- `v.insert()`：向某个指定位置插入元素，返回表示第一个新插入元素位置的迭代器。

```c++
vector<int> v{1,2};
v.insert(v.being()+1, 3); // {1,3,2}
v.insert(v.end(), 2, 5);  // {1,3,2,5,5}
array<int,3> test{7,8,9};
v.insert(v.end(), test.begin(), test.end()); // {1,3,2,5,5,7,8,9}
v.insert(v.end(), { 10,11 }); // {1,3,2,5,5,7,8,9,10,11}
```

- `v.emplace()`：类似insert，但每次只能插入一个元素。效率更高：emplace() 在插入元素时，是在容器的指定位置直接构造元素，而不是先单独生成，再将其复制（或移动）到容器中。

- `v.push_back()`：将元素追加到vector结尾，采用的是深拷贝，参考<https://blog.csdn.net/love_fdu_llp/article/details/51407613>。

- `v.emplace_back()`：将元素追加到vector结尾，效率更高。

### 3.3. 删

`pop_back()`: 删除容器尾部的元素

`v.clear()`: 清空vector

- 参数：无
- 返回值：无

### 3.4. 改

`v[n] = 1`: 与数组元素赋值方式相同

`v1 = v2`: 将数组v1赋值给数组v2

### 3.5. 比较

`v1 == v2`: 判断两个数组是否相等。此外 `!=`、`<`、`<=`、`>`、`>=` 也可以使用

### 3.5. 查

`v[n]`: 获取下标为n的元素

`v.size()`

`v.empty()`

### 3.6. 遍历

`v.begin()`

- 参数：无
- 返回值：指向vector首地址的指针

`v.end()`

- 参数：无
- 返回值：指向vector**最后一个元素的下一个位置**的指针

```c
vector<int> v;
vector<int>::iterator it;
for(it = v.begin(); it != v.end(); it++){
  cout << *it << endl;
}
```

## 4. list

<https://cplusplus.com/reference/list/list/>

```c++
#include <list>
```

内部实现：双向链表。

优点：

- 中间插入删除方便
- 动态数据个数

缺点：

- 访问数据不方便

### 4.1. 创建

`list<int> l`

### 4.2. 增

`l.push_back(num)`: 在链表尾部增加一个元素

- 参数：与定义时相同的数据类型
- 返回值：无

`l.push_front(num)`: 在开始位置增加一个元素。参数同上

`l.insert(iter, num)`: 在指定位置插入元素

- 参数：
  - iter: 迭代器 `list<int>::iterator it`
  - num: 定义链表时指定的数据类型的变量
- 返回值：无

### 4.3. 删

`l.pop_back()`: 删除末尾的元素

`l.pop_front()`: 删除第一个元素

`l.erase(iter)`: 删除指定位置的元素

- 参数：
  - iter: 迭代器，类型为`list<int>::iterator it`
- 返回值：无

`l.clear()`: 清空

### 4.4. 查

`l.front()`

`l.back()`

`l.empty()`

`l.size()`

### 4.5. 遍历

`l.begin()`

`l.end()`

```c
list<int> l;
list<int>::iterator it;
for(it = l.begin(); it != l.end(); it++){
  cout << *it << endl;
}
```

### 4.6. 排序

`l.sort()` \ `l.sort(cmp)`: 排序，cmp是自定义的排序函数。示例：

```c
#include<iostream>
#include<list>
using namespace std;

class A{
  public:
  int a,b;
  A(int t1,int t2) {a=t1,b=t2;}
  bool operator < (const A temp) const {return a < temp.a;}
};

int main() {
  list<A> list_a;
  A a1(1,2), a2(4,6), a3(2,8);
  list_a.push_back(a1);
  list_a.push_back(a2);
  list_a.push_back(a3);

  list_a.sort(); // 排序操作

  list<A>::iterator it;
  it = list_a.begin();
  for(int i=0;i<3;i++) {cout<<it->a<<endl; it++;}

  return 0;
}
```

## 5. map

<https://cplusplus.com/reference/map/map/>

```c++
#include <map>
```

有序键值对。

内部实现：红黑树，插入、删除、查找的时间复杂度都是 O(logn)。

### 5.1. 创建

`map<string, int> people`: 键值类型都可以是结构体。但是，需要**重载比较运算符**（因为map内部需要排序），如下：

```c
struct Node {
  int x;
  int y;
  bool operator < (const Node n) const {
    return x < n.x || (x == n.x && y < n.y);
  }
};

map<Node, int> nodes;
nodes[Node{1,2}] = 1;
```

`map`中的元素都是`pair<const K, T>`类型的，`pair`类型可以通过`first`成员访问键、`second`成员访问值。

### 5.2. 增

`people["dou"] = 20`: 运算符重载。当使用`["dou"]`时，若`"dou"`不存在，则会创建键值对：`"dou":0`。然后，将20设为`"dou"`的值。

`people.insert(make_pair("Bill", 48))`: 插入一个**不存在的**键值对。

- 参数：

  - `pair<K, T>`: 一个键值对，K类型为映射定义时的键类型、T类型为映射定义时的值类型。

- 返回值：

  - `pair<map<string, int>::iterator, bool>`: `pair`对象的`first`成员是一个迭代器，它要么指向插入元素，要么指向阻止插入的元素（元素已存在）；`second`成员是布尔值，表示是否成功，即该键是否存在。

示例：

```c
pair<string, int> peo = make_pair("Bill", 48); // c++11: auto peo = make_pair("Bill", 48);
pair<map<string, int>::iterator, bool> ret_pr = people.insert(peo); // c++11: auto ret_pr = people.insert(peo);
cout << ret_pr.first->first << " " << ret_pr.first->second << " " << ret_pr.second << "\n";
```

### 5.3. 删

`people.erase(key)`: 删除键对应的键值对

- 参数：
  - key: 键类型的变量
- 返回值：所移除元素的个数，map 容器的返回值只可能是 0 或 1。

### 5.4. 改

`people[key] = newValue`: 将新值赋给对应的键。**如果键不存在，将创建该键值对**。

### 5.5. 查

`people[key]`: 返回键对应的值

`people.count(key)`: 返回该键对应元素的个数，map 容器的返回值只可能是 0 或 1 。

`people.find(key)`: 返回指向该元素的迭代器 `map<K, T>::iterator` ，若不存在则指向`people.end()`。

`lower_bound(key)`: 返回一个迭代器 `map<K, T>::iterator` ，指向键值 `>= key` 的第一个元素。

`upper_bound(key)`: 返回一个迭代器，指向键值 `> key` 的第一个元素。

### 5.6. 遍历

两种方式：

```c
for (map<string, int>::iterator it=people.begin(); it!=people.end(); it++) {
  cout << it->first << ": " << it->second <<endl;
}
// c++11支持
for (const auto& p : people) {
  cout << p.first << ": " << p.second <<endl;
}
```

## 6. set

```c++
#include <set>
```

有序集合。

内部实现：红黑树。插入删除的时间复杂度为$O(logn)$，查询的时间复杂度为$O(logn)$。

### 6.1. 创建

`set<int> int_set`: 元素类型可以是结构体。但是，需要**重载比较运算符**（因为set内部需要排序），如下：

```c
struct Node {
  int x;
  int y;
  bool operator < (const Node n) const {
    return x < n.x || (x == n.x && y < n.y);
  }
};

set<Node> node_set;
```

**注意**：重载比较运算时，要考虑结构体中的每一个元素。

### 6.2. 增

`node_set.insert(Node{1, 2})`: 增加不存在的元素

- 参数：
  - `Node{1, 2}`: 符合定义类型的元素
- 返回值：`pair<set<Node>::iterator, bool>`

示例：

```c
pair<set<Node>::iterator, bool> pr = node_set.insert(Node{1, 2});
cout << pr.first->x << "," << pr.first->y << " " << pr.second << endl;
```

### 6.3. 删

`node_set.erase()`: 删除迭代器指定位置的元素，或与对象匹配的元素。如下：

```c
node_set.erase(Node{1,2});

if (node_set.count(Node{2,2})) {
  cout << "(2,2) node was found!\n";
  set<Node>::iterator it = node_set.find(Node{2,2});
  node_set.erase(it);
}
```

`node_set.clear()`: 清空

### 6.4. 查

`node_set.find(Node{1,2})`: 若未找到该元素，则返回`node_set.end()`。

`node_set.count(Node{2,2})`: 返回匹配的元素个数，0或1。

### 6.5. 遍历

```c
for (set<Node>::iterator it=node_set.begin(); it!=node_set.end(); it++) {
  cout << it->x << "," << it->y <<endl;
}
```

## 7. priority_queue

```c++
#include <queue>
```

优先队列。元素被赋予优先级，当访问/删除元素时，具有最高优先级的元素最先被访问/删除。

内部实现：堆。插入的时间复杂度为$O(logN)$，访问头元素的时间复杂度为$O(1)$，删除头元素的时间复杂度为$O(logN)$。

参考：[https://blog.csdn.net/CerberuX/article/details/51762357](https://blog.csdn.net/CerberuX/article/details/51762357)

### 7.1. 创建

通过结构体重载运算符，自定义比较级：

```cpp
struct Node {
    int priority;
    int value;
    bool operator < (const Node &a) const {
        return priority < a.priority; // 大顶堆（默认），反之则是小顶堆
    }
};

priority_queue<Node> q; // 类型必须是 Node 。类型若是 Node* 重载运算符不生效
```

通过结构体定义比较级：

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val; // 小顶堆
    }
};

priority_queue<ListNode*, vector<ListNode*>, cmp> q;
```

通过函数自定义比较级：

```c++
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
```

### 7.2. 增

`q.push(node)`：在堆的最后加入元素，然后向上筛选

### 7.3. 删

`q.pop()`：取出堆的根结点，然后最后一个元素上位，并向下筛选

### 7.4. 查

`q.top()`

`q.size()`

`q.empty()`

## 8. deque

```c++
#include <deque>
```

双向队列，头尾都可以进行插入 `push` 、删除 `pop` 操作。

内部实现：连续空间，头尾都可以增长。头尾插入删除的时间复杂度为$O(1)$，中间插入删除的时间复杂度为$O(n)$，访问元素的时间复杂度为$O(1)$。

### 8.1. 创建

```cpp
deque<int> my_dq1;      // 创建栈上实例
deque<int> my_dq2(10);  // 有10个元素的双向队列
deque<string> words {"one", "two", "three"};              // 有3个元素，依次为 one two three
deque<string> words_part {begin(words), begin(words)+1};  // words的第1个元素，到第2个元素
```

### 8.2. 增

`my_deque.push_back(elem)`: 在容器尾部添加一个数据

`my_deque.push_front(elem)`: 在容器头部插入一个数据

`my_deque.insert(pos, elem)`: 在pos位置（迭代器）插入一个elem元素的拷贝，返回新数据的位置

`my_deque.insert(pos, n, elem)`: 在pos位置插入n个elem数据，无返回值

`my_deque.insert(pos, beg, end)`: 在pos位置插入`[beg,end)`区间（迭代器）的数据，无返回值

### 8.3. 删

`my_deque.pop_back()`: 删除容器最后一个数据

`my_deque.pop_front()`: 删除容器第一个数据

`my_deque.erase(beg, end)`: 删除`[beg,end)`区间的数据，返回下一个数据的位置

`my_deque.erase(pos)`: 删除pos位置的数据，返回下一个数据的位置

`my_deque.clear()`: 移除容器的所有数据

### 8.4. 改

`my_deque.at(id) = elem`: 修改索引id所指的数据，如果id越界，抛出out_of_range

`my_deque[id] = elem`: 修改索引id所指的数据，如果id越界，不抛出异常，直接出错

### 8.5. 查

`my_deque.front()`: 返回第一个元素

`my_deque.back()`: 返回最后一个元素

`my_deque.at(id)`: 返回索引id所指的数据，如果id越界，抛出out_of_range

`my_deque[id]`: 返回索引id所指的数据，如果id越界，不抛出异常，直接出错

`my_deque.begin()`: 返回容器中第一个元素的迭代器

`my_deque.end()`: 返回容器中最后一个元素之后的迭代器

`my_deque.size()`: 返回容器中元素的个数

`my_deque.empty()`: 判断容器是否为空

## 9. string

```c++
#include <string>
```

<https://cplusplus.com/reference/string/string/>

- `string substr(size_t pos = 0, size_t len = npos)`: 返回子串。注意：第二个参数为长度！！！

## 10. multiset

```c++
#include <set>
```

<https://cplusplus.com/reference/set/multiset/>

- 改：
  - `insert`
  - `erase`
  - `swap`
  - `clear`
- 查：
  - `find`
  - `count`
  - `lower_bound(key) -> iterator`: 获取指向第一个大于等于 key 的元素的迭代器，不存在则返回 end() 。
  - `upper_bound(key) -> iterator`

## 11. pair

```c++
#include <utility>
```

```c++
pair<int, string> p(1, "abc");
pair<int, string> p = make_pair(1, "abc");
cout << p.first << p.second << endl;
tie(age, name) = p;
```

## 12. algorithm

```c++
#include <algorithm>
```

### sort

```c++
int a[n];
sort(a, a+n);

vector<int> v(n); // 创建有n个元素的vector

// 第三个参数为Lambda表达式（C++11新特性）
sort(v.begin(), v.end(), [&](const int &a, const int &b) {
    return a < b;
});

// 排序指定区间
sort(v.begin()+i, v.end())
```

### reverse

```c++
int a[10] = {};
reverse(a,a+5); // 翻转0-5

vector<int> a = {1,2,3,4,5};
reverse(a.begin(), a.end());

string s = "abc";
reverse(s.begin(), s.end());
```

### 二分

```c++
int a[9];
bool b = binary_search(a, a+9, 4); // 查找某个元素是否出现
int i = lower_bound(a, a+9, 4) - a; // 查找第一个 大于或等于 某个元素的位置，返回值是指针或iterator
int i = upper_bound(a, a+9, 4) - a; // 查找第一个大于某个元素的位置，返回值是指针或iterator

vector<int> v(9);
bool b = binary_search(v.begin(), v.end(), 4);
int i = lower_bound(v.begin(), v.end(), 4) - v.begin();
int i = upper_bound(v.begin(), v.end(), 4) - v.begin();
```
