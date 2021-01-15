class Solution {
public:
    string decodeString(string s) {
        int start=0;
        return decodeutil(s, start);
    }
    string decodeutil(string input, int& pos){
        string res="";
        while(pos < input.length() && input[pos] != ']'){
            if(isdigit(input[pos])){
                string tmp="";
                string digit="";
                while(isdigit(input[pos])){
                    digit += input[pos];
                    pos++;
                }
                pos++;
                int num = stoi(digit);
                tmp = decodeutil(input, pos);
                for(int i=0; i<num; i++){
                    res += tmp;
                }
                pos++;
            }
            else
            {
                res += input[pos];
                pos++;
            }
        }
        return res;
    }
};
