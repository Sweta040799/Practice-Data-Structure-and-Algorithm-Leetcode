/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
    
        deque<Node*> dq,copy;
        dq.push_back(root);
        int len = 1;
        while(len > 0){
            int cnt = 0;
            copy = dq;
            for(int i = 0 ; i < len ; i++){
                Node* temp = dq.front();
                dq.pop_front();
                if(temp->left != NULL){
                    dq.push_back(temp->left);
                    cnt++;
                }
                if(temp->right != NULL){
                    dq.push_back(temp->right);
                    cnt++;
                }
            }
            Node* prev = NULL;
            while(len--){
                Node* curr = copy.back();
                // cout<<curr->val<<" ";
                copy.pop_back();
                curr->next = prev;
                prev = curr;
            }
            // cout<<'\n';
            len = cnt;
        }
       return root; 
    }
};