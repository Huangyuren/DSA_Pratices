// We only store for each snap_id's informations
// How to store this records? Using map by map
class SnapshotArray {
public:
    SnapshotArray(int length) {
        snap_id = 0;
        // Should also initialize map, for cases such as snap(), snap(), get(3, 1)
        for(int i=0; i<length; i++){
            mymap[i][snap_id] = 0;
        }
    }
    
    void set(int index, int val) {
        mymap[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        map<int, int>::iterator x = mymap[index].upper_bound(snap_id);
        // upper_bound() will return "next" iterator of map[snap_id], so we need to x-- to get correct iterator
        // see http://www.cplusplus.com/reference/map/map/upper_bound/
        x--;
        return x->second;
    }
private:
    map<int, map<int, int>> mymap; // (index, (snap_id, value))
    int snap_id;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
