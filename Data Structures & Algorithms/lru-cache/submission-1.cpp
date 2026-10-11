class Node{
public:    
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int val){
        key = k;
        value = val;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>cache;
    int cap;
    Node* right;
    Node* left;
    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
    void insert(Node* node){
        Node* prev = right->prev;

        prev->next = node;
        node->prev = prev;

        node->next = right;
        right->prev = node;
    }
    LRUCache(int capacity) {
        cache.clear();
        cap = capacity;
        right = new Node(0,0);
        left = new Node(0,0);
        left->next = right;
        right->prev= left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node* newnode = new Node(key,value);
        cache[key] = newnode;
        insert(newnode);

        if(cache.size()>cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
