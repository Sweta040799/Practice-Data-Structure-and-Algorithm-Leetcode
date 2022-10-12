class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;
    queue<int> temp;
    
    void push(int x) {
      q.push(x);  
    }
    
    int pop() {
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return res;
    }
    
    int top() {
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int res = q.front();
        temp.push(q.front());
        q.pop();
        
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return res;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */