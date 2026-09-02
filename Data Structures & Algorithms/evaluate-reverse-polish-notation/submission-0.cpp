class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+") {
                int b = result.top(); result.pop();
                int a = result.top(); result.pop();
                result.push(a + b);
            }
            else if(tokens[i] == "-") {
                int b = result.top(); result.pop();
                int a = result.top(); result.pop();
                result.push(a - b);
            }
            else if(tokens[i] == "*") {
                int b = result.top(); result.pop();
                int a = result.top(); result.pop();
                result.push(a * b);
            }
            else if(tokens[i] == "/") {
                int b = result.top(); result.pop();
                int a = result.top(); result.pop();
                result.push(a / b);
            }
            else {
                result.push(stoi(tokens[i]));
            }
        }
        
        return result.top();
    }
};