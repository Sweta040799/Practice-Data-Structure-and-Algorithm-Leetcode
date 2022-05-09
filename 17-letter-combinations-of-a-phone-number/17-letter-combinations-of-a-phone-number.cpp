class Solution {
public:
    const vector<string> chr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void Combinations(string &digits, int curr, vector<string>& ans, string &temp){
        if(curr == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i <chr[digits[curr] - '0'].size(); i++){
            temp += chr[digits[curr] - '0'][i];
            Combinations(digits, curr + 1 ,ans, temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        vector<string> ans;
        string temp = "";
            
        Combinations(digits, 0, ans, temp);
        return ans;
    }
};