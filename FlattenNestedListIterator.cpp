/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// We should not copy whole content of input data structure for iterator
// However, just trying to iterate through the whole data structure
// next() should be ensured to get integer, so call hasNext() before next()
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        front.push(nestedList.begin());
        back.push(nestedList.end());
    }
    
    int next() {
        hasNext(); // avoid undefined behavior
        int res = front.top()->getInteger();
        front.top()++; // Since front(stack) stores iterator, so we ++ to move on the pointer
        return res;
    }
    
    bool hasNext() {
        while(front.size()){
            if(front.top() == back.top()){
                front.pop(); back.pop();
            }else{
                auto tmp = front.top();
                if(tmp->isInteger()) return true;
                front.top()++; // move on to next nest list or integer
                front.push(tmp->getList().begin()); // should call getList to obtain the nested list
                back.push(tmp->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> front, back;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
