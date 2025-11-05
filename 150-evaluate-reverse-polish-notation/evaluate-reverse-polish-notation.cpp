class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;

        for (int i = 0; i < tokens.size(); i++) {
            
            if (tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "-") {
                int valOne = stck.top();
                stck.pop();
                int valTwo = stck.top();
                stck.pop();

                if (tokens[i] == "+") {
                    stck.push(valOne + valTwo);
                } else if (tokens[i] == "-") {
                    stck.push(valTwo - valOne);
                } else if (tokens[i] == "/") {
                    stck.push(valTwo / valOne);
                } else if (tokens[i] == "*") {
                    stck.push(valOne * valTwo);
                }
            } else {
                stck.push(stoi(tokens[i]));
            }
        }
        return stck.top();
    }
};