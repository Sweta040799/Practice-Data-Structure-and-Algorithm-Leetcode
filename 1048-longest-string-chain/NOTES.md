​<h1>Algorithm: Dynamic Programming</h1>
<h2>Type: Longest Increasing Subsequence</h2>

<h3>Recursive Code:</h3>

```
class Solution {
public:
    bool isPoss(string a, string b){
        // cout<<a<<" "<<b<<endl;
        int i = 0, j = 0, cnt = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                cnt++;
                j++;
            }
        }
    
        cnt += b.size() - j;
        cnt += a.size() - i;
        // cout<<i<<endl;
        return (cnt == 1);
    }
    int Recur(vector<string>& words, int prev, int curr){
        if(curr == words.size())
            return 0;
        
        int left = 0, right = 0;
        if(prev == -1 || isPoss(words[prev],words[curr]))
            left = 1 + Recur(words, curr, curr + 1);
        
        right = Recur(words, prev, curr + 1);
        
        return max(left,right);
    }
    int longestStrChain(vector<string>& words) {
        auto comp = [](string &a, string &b){
            if(a.size() == b.size())
                return (a < b);
            return (a.size() < b.size());
        };
        sort(words.begin(),words.end(),comp);
        return Recur(words, -1, 0);
    }
};
```

<h3>Memoized + Space Optimized</h3>

```
class Solution {
public:
    int dp[1001];
    bool isPoss(string a, string b){
        int i = 0, j = 0, cnt = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                cnt++;
                j++;
            }
        }
    
        cnt += b.size() - j + a.size() - i;

        return (cnt == 1);
    }
    int Recur(vector<string>& words, int prev, int curr){
        if(curr == words.size())
            return 0;
        
        if(prev != -1 && dp[prev] != 0)
            return dp[prev];
        
        int left = 0, right = 0;
        if(prev == -1 || isPoss(words[prev],words[curr]))
            left = 1 + Recur(words, curr, curr + 1);
        
        right = Recur(words, prev, curr + 1);
        
        if(prev != -1)
            return dp[prev] = max(left,right);
        
        return max(left,right);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp, 0, sizeof(dp));
        auto comp = [](string &a, string &b){
            if(a.size() == b.size())
                return (a < b);
            return (a.size() < b.size());
        };
        sort(words.begin(),words.end(),comp);
        return Recur(words, -1, 0);
    }
};
```

<h3>Tabulation + Space Optimized</h3>

```
class Solution {
public:
    bool isPoss(string a, string b){
        int i = 0, j = 0, cnt = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                cnt++;
                j++;
            }
        }
    
        cnt += b.size() - j + a.size() - i;

        return (cnt == 1);
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size(),mx = 1;
        vector<int> dp(n + 1, 1);
        auto comp = [](string &a, string &b){
            if(a.size() == b.size())
                return (a < b);
            return (a.size() < b.size());
        };
        sort(words.begin(),words.end(),comp);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPoss(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            
            mx = max(mx,dp[i]);
        }
        
        return mx;
    }
};
```
