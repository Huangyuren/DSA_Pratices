class Solution {
public:
    string intToRoman(int num) {
        // We have to create four arrays based on decimal orderings
        vector<string> marr = {"", "M", "MM", "MMM"};
        vector<string> carr = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> xarr = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> iarr = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return marr[num/1000] + carr[(num%1000) / 100] + xarr[(num%100) / 10] + iarr[num % 10];
    }
};
