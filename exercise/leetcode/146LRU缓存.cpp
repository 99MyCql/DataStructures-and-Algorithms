/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <unordered_map>

using namespace std;

struct Node {
    int key, value;
    Node* pre;
    Node* next;
    Node(int k, int v, Node* p, Node* n) : key(k), value(v), pre(p), next(n) {}
};

class LRUCache {
public:
    int capacity;
    int count;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->count = 0;
        this->head = new Node(0, 0, nullptr, nullptr);
        this->tail = new Node(0, 0, nullptr, nullptr);
        this->head->next = this->tail;
        this->tail->pre = this->head;
    }

    int get(int key) {
        if (map.count(key) == 0) {
            return -1;
        }

        Node* p = map[key];
        Node* pre = p->pre;
        Node* next = p->next;
        pre->next = next;
        next->pre = pre;

        p->next = this->head->next;
        p->pre = this->head;
        this->head->next->pre = p;
        this->head->next = p;

        return p->value;
    }

    void put(int key, int value) {
        if (map.count(key) == 0) {
            if (this->count == this->capacity && this->capacity > 0) {
                Node* p = this->tail->pre;
                p->pre->next = this->tail;
                this->tail->pre = p->pre;
                map.erase(p->key);
                delete p;
            } else {
                this->count++;
            }

            Node* p = new Node(key, value, nullptr, nullptr);
            p->pre = this->head;
            p->next = this->head->next;
            this->head->next->pre = p;
            this->head->next = p;
            map[key] = p;
        } else {
            Node* p = map[key];
            p->value = value;

            Node* pre = p->pre;
            Node* next = p->next;
            pre->next = next;
            next->pre = pre;

            p->next = this->head->next;
            p->pre = this->head;
            this->head->next->pre = p;
            this->head->next = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */