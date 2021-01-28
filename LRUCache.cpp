class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> mymap; // store key-pair(value, list iterator)
    list<int> mylist; // store key
    int _capacity;
    void updateLRU(int key, int value){
        list<int>::iterator it = mymap[key].second;
        mylist.erase(it);
        mylist.push_front(key);
        mymap[key].second = mylist.begin();
        mymap[key].first = value;
        return;
    }
    void evict(){
        mymap.erase(mylist.back());
        mylist.pop_back();
        return;
    }
    // void printlist(int getorput){
    //     if(getorput==1)
    //         printf("get: ");
    //     else    
    //         printf("put: ");
    //     for(list<int>::iterator tmp=mylist.begin(); tmp!=mylist.end(); tmp++){
    //         printf("Element: %d, ", *tmp);
    //     }
    //     printf("\n");
    // }
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(mymap.find(key) == mymap.end()) return -1;
        updateLRU(key, mymap[key].first);
        return mymap[key].first;
    }
    
    void put(int key, int value) {
        if(mymap.find(key) == mymap.end()){
            if(mymap.size()+1 > _capacity){
                evict();
            }
            mylist.push_front(key);
            mymap[key] = make_pair(value, mylist.begin());
        }
        else
        {
            updateLRU(key, value);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
