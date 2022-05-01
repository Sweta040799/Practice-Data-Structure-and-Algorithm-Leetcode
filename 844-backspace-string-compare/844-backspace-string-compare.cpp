class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk;
        for(int i = 0 ;i < s.size() ; i++){
            if(s[i] != '#')
                stk.push(s[i]);
            if(s[i] == '#' && !stk.empty())
                stk.pop();
        }
        stack<char> st;
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i] != '#')
                st.push(t[i]);
            if(t[i] == '#' && !st.empty())
                st.pop();
        }
        return (stk == st);
    }
};