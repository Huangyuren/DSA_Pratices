class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char a : word){
            if(node->next.count(a) == 0) {
                node->next[a] = new Trie();
            }
            node = node->next[a];
        }
        node->wordbreak = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(char a : word){
            if(node->next.count(a) == 0){
                return false;
            }
            node = node->next[a];
        }
        return node->wordbreak;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { // since given prefix, should all be matched with this prefix.
        Trie* node = this;
        for(char a : prefix){
            if(node->next.count(a)==0) return false;
            node = node->next[a];
        }
        return true;
    }
private:
    map<char, Trie*> next = {}; // 26 chars
    bool wordbreak = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
