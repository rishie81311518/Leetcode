class MyStack {
public:
    MyStack() {
    }
    
    queue<int> q;
    void push(int x) {
      q.push(x);
      int s = q.size();
      for (int i = 1; i<s;i++){
        q.push(q.front());
        q.pop();
      }
        
    }
    
    int pop() {
        if (empty()){
            return -1;
        }
       int poppedValue = q.front();
       q.pop();
      return poppedValue;
        
    }
    
    int top() {
        if (empty()){
            return -1;
        }
        return q.front();
        
    }
    
    bool empty() {
   return q.empty();
        
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