class Solution {
public:
    int calc_Score(string word, unordered_map<char, int>& mp, vector<int>& score){
        int cnt = 0;
        
        for(int i = 0; i < word.size(); i++){
            cnt += score[word[i] - 'a'];
            mp[word[i]]--;
        }
        
        return cnt;
    }
    bool isPoss(string word, unordered_map<char, int> mp){
        for(int i = 0; i < word.size(); i++){
            if(mp[word[i]] == 0)
                return false;
            mp[word[i]]--;
        }
        return true;
    }
    
    int recur(vector<string>& words, vector<int>& score, unordered_map<char, int> mp, int idx){
        if(idx == words.size()) return 0;
        
        int scores = 0, ans = 0;
        
        if(isPoss(words[idx] , mp)) {  
            unordered_map<char, int> dummy = mp;
            scores = calc_Score(words[idx], dummy, score);
            ans = max(scores + recur(words, score, dummy, idx + 1), recur(words, score, mp, idx + 1));
        }
        else
            ans += recur(words, score, mp, idx + 1);
        
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> mp;
        for(int i = 0; i < letters.size(); i++)
            mp[letters[i]]++;
        
        return recur(words, score, mp, 0);
    }
};