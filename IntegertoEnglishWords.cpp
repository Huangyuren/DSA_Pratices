class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return solver(num).substr(1);
    }
private:
    vector<string> ones = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",\
                           "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string solver(int n){
        if(n >= 1000000000){
            return solver(n/1000000000) + " Billion" + solver(n % 1000000000);
        }
        if(n >= 1000000){
            return solver(n/1000000) + " Million" + solver(n % 1000000);
        }
        if(n >= 1000){
            return solver(n/1000) + " Thousand" + solver(n % 1000);
        }
        if(n>=100){
            return solver(n/100) + " Hundred" + solver(n % 100);
        }
        if(n>=20){
            return " " + tens[n / 10] + solver(n % 10);
        }
        if(n >= 1){
            return " " + ones[n];
        }
        return "";
    }
};
