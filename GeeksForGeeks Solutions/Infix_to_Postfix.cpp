#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int precedence(char c){
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if(c == '+' || c == '-') return 1;
        return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string str = "";
        for(char i:s){
            if(isalnum(i)){
                str+=i;
            }else if(i == '('){
                    st.push(i);
            }else if(i == ')'){
                while(!st.empty() && st.top() != '('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && precedence(st.top()) >= precedence(i) && !(i == '^' && st.top() == '^') ){
                    str+=st.top();
                    st.pop();
                }
                st.push(i);
            }
            
        }
        
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        
        return str;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    string s1 = "a+b*c";
    cout << "Infix: " << s1 << endl;
    cout << "Postfix: " << sol.infixToPostfix(s1) << " (Expected: abc*+)\n\n";

    cout << "===== Test Case 2 =====\n";
    string s2 = "(a+b)*c";
    cout << "Infix: " << s2 << endl;
    cout << "Postfix: " << sol.infixToPostfix(s2) << " (Expected: ab+c*)\n\n";

    cout << "===== Test Case 3 =====\n";
    string s3 = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << s3 << endl;
    cout << "Postfix: " << sol.infixToPostfix(s3) 
         << " (Expected: abcd^e-fgh*+^*+i-)\n\n";

    cout << "===== Test Case 4 =====\n";
    string s4 = "A*(B+C)/D";
    cout << "Infix: " << s4 << endl;
    cout << "Postfix: " << sol.infixToPostfix(s4) << " (Expected: ABC+*D/)\n\n";

    cout << "===== Test Case 5 (Exponent Right Associative) =====\n";
    string s5 = "a^b^c";
    cout << "Infix: " << s5 << endl;
    cout << "Postfix: " << sol.infixToPostfix(s5) << " (Expected: abc^^)\n\n";

    cout << "===== Test Case 6 =====\n";
    string s6 = "((a+t)*((b+(a+c))^(c+d)))";
    cout << "Infix: " << s6 << endl;
    cout << "Postfix: " << sol.infixToPostfix(s6) << endl;

    return 0;
}
