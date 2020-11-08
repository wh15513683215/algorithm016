// 总的思想就是 哈希双向链表
struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mymap;
   

public:
    LRUCache(int capacity) {
        this -> size = capacity;
        head = nullptr;
        tail = nullptr;
    }
// 获取缓冲区中 key 对应的 value
    
    int get(int key) {
        if (mymap.count(key) > 0) {
            Node* cur = mymap[key];
            int value = cur -> value;
            remove(cur);
            setHead(cur);
            return value;
        }
        return -1;
    }
  
// 将key-value值存入缓冲区
    void put(int key, int value) {
        // 1.当该 key 值存在
        if (mymap.count(key) > 0) {
            Node* cur = mymap[key];
            cur -> value = value;
            remove(cur);
            setHead(cur);
        } else {
            Node* node = new Node(key, value);
            if (mymap.size() >= size) {
                unordered_map<int, Node*>::iterator it = mymap.find(tail -> key);
                remove(tail);
                mymap.erase(it);
            }
            setHead(node);
            mymap[key] = node;
        }
    }     
       
   
    void remove(Node* cur) {
        if (cur == head)
           head = cur -> next;
        else if (cur == tail)
           tail = cur -> pre;
        else {
            cur -> pre -> next = cur -> next;
            cur -> next -> pre = cur -> pre; 
        }
    }
    // 删除当前节点
   
    void setHead(Node* cur) {
        cur -> next = head;
        if (head != nullptr)
           head -> pre = cur;
        head = cur;
        if (tail == nullptr)
           tail = head;
    }
   
}; //自己写双向链表

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};  //官方的虚拟头和尾

class LRUCache {
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            int res = (*mp[key]).second;
            l.erase(mp[key]);
            l.push_front(make_pair(key, res));
            mp[key] = l.begin();
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            l.erase(mp[key]);
            l.push_front(make_pair(key, value));
            mp[key] = l.begin();
        }
        else
        {
            if(l.size() == cap)
            {
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front(make_pair(key, value));
            mp[key] = l.begin();
        }
    }
}; //直接用List








