class Solution {
public:
    bool isValid(string s) {

        stack<char> opener;
        for(int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                opener.push(s[i]);
                break;

                case ')':
                if (opener.empty() || opener.top() != '(') return false;
                opener.pop();
                break;

                case ']':
                if (opener.empty() || opener.top() != '[') return false;
                opener.pop();
                break;

                case '}':
                if (opener.empty() || opener.top() != '{') return false;
                opener.pop();
                break;
            }
        }

        return opener.empty();    
            
    }
};