class MyStack {
public:
    MyStack() {
        
    }
    vector<int> v;
    
    void push(int x) {
      v.push_back(x);  
    }
    
    int pop() {
        int temp = v[v.size() - 1];
        v.pop_back();
       return temp; 
    }
    
    int top() {
        return v[v.size() - 1];
    }
    
    bool empty() {
        return v.size() == 0;
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