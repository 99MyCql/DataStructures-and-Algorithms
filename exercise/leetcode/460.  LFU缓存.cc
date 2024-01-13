#include <unordered_map>

using namespace std;

struct Node {
    int key, val, freq = 1;
    Node *prev, *next;
    Node(int k = 0, int v = 0) : key(k), val(v), prev(nullptr), next(nullptr) {}
};


class LFUCache {
private:
    int capacity;
    int min_freq;
    unordered_map<int, Node*> key2node;
    unordered_map<int, Node*> freq2list;

    Node* newList() {
        Node *head = new Node();
        head->prev = head;
        head->next = head;
        return head;
    }

    void insertNode(Node *node) {
        // printf("insert: %d to freq(%d)\n", node->key, node->freq);
        if (freq2list.find(node->freq) == freq2list.end()) {
            freq2list[node->freq] = newList();
        }
        Node *head = freq2list[node->freq];
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node) {
        // printf("remove:%d from freq(%d)\n", node->key, node->freq);
        node->next->prev = node->prev;
        node->prev->next = node->next;
        if (freq2list[node->freq]->next == freq2list[node->freq]) {
            freq2list.erase(node->freq);
        }
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 0;
    }

    int get(int key) {
        // printf("get:%d\n", key);
        if (key2node.find(key) == key2node.end()) return -1;

        Node *node = key2node[key];
        removeNode(node);
        // 如果删除结点后所在链表也被删除，且这个链表的频率等于最小频率
        if (freq2list.find(node->freq) == freq2list.end() && node->freq == min_freq) {
            min_freq++;
        }

        node->freq++;
        insertNode(node);

        return node->val;
    }

    void put(int key, int value) {
        // printf("put:%d\n", key);
        if (get(key) != -1) {
            key2node[key]->val = value;
            return;
        }

        if (key2node.size() == capacity) {
            // 删除 min_freq 链表中的尾结点
            Node *oldNode = freq2list[min_freq]->prev;
            key2node.erase(oldNode->key);
            removeNode(oldNode);
            delete oldNode;
        }

        Node *node = new Node(key, value);
        key2node[key] = node;
        insertNode(node);
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */