struct Node{
    Node *links[26];
    bool flag = false;
    
    bool isContainsKey(char ch){
        return (links[ch - 'a'] != NULL);
    } 
    
    void putKey(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* getKey(char ch){
        return links[ch - 'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->isContainsKey(word[i])){
                node->putKey(word[i], new Node()); 
            }
            node = node->getKey(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(int i = 0; i < word.size(); i++){
            if(!node->isContainsKey(word[i]))
                return false;
            
            node = node->getKey(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(int i = 0; i < prefix.size(); i++){
            if(!node->isContainsKey(prefix[i]))
                return false;
            
            node = node->getKey(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */