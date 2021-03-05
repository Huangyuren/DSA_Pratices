// Utilizing Trie data structure (prefix tree) to search for a set of strings
// Trie is efficient in searching bunches of strings
// We will firstly construct a prefix tree with all words inside
// This prefix tree will be read only
// We can obtain a set of valid strings through looking up from this tree
class TrieNode {
public:
    vector<TrieNode*> children; // children map
    bool isendword; // to justify is end or not
    TrieNode() : isendword(false), children(vector<TrieNode*>(26, nullptr)) {}; // children with 26 chars
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}; // Declare a new trie node as initialization
    TrieNode* getroot() {return root;}
    void insert(string word){
        TrieNode* parent = root;
        for(char c : word){
            int tmpindex = c - 'a';
            if(parent->children[tmpindex] == nullptr){
                parent->children[tmpindex] = new TrieNode(); // create new TrieNode
            }
            parent = parent->children[tmpindex];
        }
        parent->isendword = true; // after walking through whole word, we can mark as isend = true
        return;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        Trie* mytrie = new Trie();
        for(string x : words){
            mytrie->insert(x);
        }
        TrieNode* treeroot = mytrie->getroot();
        unordered_set<string> myset;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                string currstr = ""; // Incrementally generate out a string
                dfs(board, i, j, treeroot, currstr, myset);
            }
        }
        vector<string> res;
        for(string x : myset){
            res.push_back(x);
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* treeroot, string currstr, unordered_set<string>& myset){
        if(row>=0 && row<m && col>=0 && col<n && board[row][col] != '*'){
            currstr += board[row][col];
            if(treeroot->children[board[row][col]-'a'] != nullptr){
                treeroot = treeroot->children[board[row][col]-'a'];
                if(treeroot->isendword){
                    myset.insert(currstr);
                    // return; 
                    // cannot return; since this will miss ["oa", "oaa"] (function early stopped at "oa" when finding "oaa")
                }
                char backup = board[row][col];
                board[row][col] = '*';
                dfs(board, row-1, col, treeroot, currstr, myset);
                dfs(board, row, col+1, treeroot, currstr, myset);
                dfs(board, row+1, col, treeroot, currstr, myset);
                dfs(board, row, col-1, treeroot, currstr, myset);
                board[row][col] = backup;
            }
            currstr.pop_back();
        }
        return;
    }
private:
    int m, n;
};
