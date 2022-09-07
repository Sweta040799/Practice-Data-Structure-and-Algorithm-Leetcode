class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* left; 
            Node* right;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }  
    };
    
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    void deleteNode(Node* node){
        node->left->right = node->right;
        node->right->left = node->left;
    }
    
    void addNode(Node* temp){
        Node* res = head->right;
        temp->left = head;
        temp->right = res;
        head->right = temp;
        res->left = temp;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        
        Node* temp = mp[key];
        deleteNode(temp);
        addNode(temp);
        
        return temp->val;
    }
    
    void put(int key, int value) {
        bool flag = mp.find(key) == mp.end();
        if(!flag){
            Node* prev_node = mp[key];
            deleteNode(prev_node);
            mp.erase(key);
        }
        else if(capacity == mp.size()){
            mp.erase(tail->left->key);
            deleteNode(tail->left);
        }
        
        Node* temp = new Node(key, value);
        addNode(temp);
        mp[key] = head->right;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */