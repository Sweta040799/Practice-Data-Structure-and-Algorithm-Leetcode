class MyStack {
public:
 
    queue<int> q;

    int peek = -1;   
    
    MyStack() {
       
    }
    
    void push(int x) {
         peek = x;
        q.push(x);
    }
    
    
    int pop() {
        
       int n = q.size();
       n-=1; 
       while(n--){
          peek = q.front();    
           q.push(peek);
           q.pop();
       } 
        
       int ret = q.front();    
        q.pop();               
        
        return ret;
        
    }
    
    int top() {
        
     return peek ;
        
    }
    
    
    bool empty() {
        
        return q.size()==0;
    }
};