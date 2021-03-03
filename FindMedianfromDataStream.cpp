// Maintain two sorted heap(priority heap)
// Elements in both heaps have no duplication, so push must followed by pop, and so on
// small is a max-heap, so that its top stores the intermediate value of both heaps.
// large is a min-heap(in terms of abs), and all of its elements are larger than small(abs(large[i])).
// This design enables median be elegantly located either at top of large or top of small.
// Amazing design
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top() * -1);
        small.pop();
        if(small.size() < large.size()){
            small.push(large.top() * -1);
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()){
            return small.top();
        }
        return (small.top() - large.top())/2.0; // substraction since elements of large are all negative
    }
private:
    priority_queue<int> small, large; // By default is less, which is max-heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
