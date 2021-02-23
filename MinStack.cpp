class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if(x <= min){ // "=" in case of duplicated min elements inserted
            myvec.push_back(min); // Store second largest element
            min = x;
        }
        myvec.push_back(x); // Otherwise, simply pushing back
        return;
    }
    
    void pop() {
        int tmp = myvec.back();
        myvec.pop_back();
        if(tmp == min){
            min = myvec.back();
            myvec.pop_back();// Additional pop back for second largest
        }
        return;
    }
    
    int top() {
        return myvec.back();
    }
    
    int getMin() {
        return min;
    }
private:
    int min;
    vector<int> myvec; // Implement min stack using single vector
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
