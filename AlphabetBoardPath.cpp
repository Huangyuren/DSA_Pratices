class Solution {
public:
    string alphabetBoardPath(string target) {
        int n = target.size();
        vector<pair<int, int>> graph(n);
        for(int i=0; i<n; i++){
            if(target[i] != 'z'){
                int curr = target[i] - 'a';
                int row = curr / 5;
                int col = curr % 5;
                graph[i] = {row, col};
            }
            else
            {
                graph[i] = {5, 0};
            }
        }
        string res = "";
        int rowspan = 0, colspan = 0;
        for(int i=0; i<n; i++){
            if(i){
                rowspan = graph[i].first - graph[i-1].first;
                colspan = graph[i].second - graph[i-1].second;
            }else{
                rowspan = graph[i].first;
                colspan = graph[i].second;
            }
            // Edge case "z" handling
            // A simple strategy is to move up before moving right
            // Move left before moving down, this can easily solve "z" situation
            if(rowspan < 0){
                for(int j=rowspan; j<0; j++) res += "U";
            }
            if(colspan < 0){
                for(int j=colspan; j<0; j++) res += "L";
            }
            if(rowspan > 0){
                for(int j=0; j<rowspan; j++) res += "D";
            }
            if(colspan > 0){
                for(int j=0; j<colspan; j++) res += "R";
            }
            res += "!";
        }
        return res;
    }
};
