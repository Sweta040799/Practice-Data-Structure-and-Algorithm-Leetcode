class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
            else if(s[i] == '('){
                st.push(i);
            }
        }
        
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            
            s[temp] = '#';
        }
        
        cout<<s;
        
        s.erase(remove(s.begin(),s.end(),'#'),s.end());
        return s;
    }
};