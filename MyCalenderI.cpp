// Considering Two cases
// records:  |......|       {x.first, x.end}
// input:         |.....|   {start, end}
// input:  |....|           {start, end}
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // for(auto x : myvec){
        //     if(x.first < end && start < x.second) return false;
        // }
        // myvec.push_back({start, end});
        // return true;
        //
        // Or using set
        //
        auto x = myset.lower_bound({start, end});
        if(x != myset.end() && x->first < end) return false;
        if(x != myset.begin()){
            // myset is initially non-empty()
            x--;
            if(x->second > start){
                // |---x_prev---|,  |---x---|
                //          |-----|     {start, end}
                return false;
            }
        }
        myset.insert({start, end});
        return true;
    }
private:
    // vector<pair<int, int>> myvec;
    // Or using set
    set<pair<int, int>> myset;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
