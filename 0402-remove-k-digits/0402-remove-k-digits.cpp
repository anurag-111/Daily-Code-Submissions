class Solution {
    public :
        string removeKdigits(string num, int k) {
            stack<char> numStack;
            // string result = "";
            int size = num.length();

            if(k >= size) {
                return "0";
            }

            for(int i = 0; i < size; i++) {
                while((!numStack.empty()) && (numStack.top() > num[i]) && (k > 0)) {
                    numStack.pop();
                    k--;
                }
                
                if(!numStack.empty() || num[i] != '0') {
                    numStack.push(num[i]);
                }
            }

            while(!numStack.empty() && k > 0) {
                numStack.pop();
                k--;
            }
            
            if (numStack.empty()) {
                return "0";
            }

            while(!numStack.empty()) {
                num[size - 1] = numStack.top();
                numStack.pop();
                size--;
            }

            return num.substr(size);
        }
};