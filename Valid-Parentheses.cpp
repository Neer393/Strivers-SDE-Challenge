bool isValidParenthesis(string expression)
{
    stack<char>st;
    int len = expression.length();
    for(int i=0;i<len;i++){
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{'){
            st.push(expression[i]);
        }
        else if (expression[i] == ')') {
          if (st.empty() || st.top() != '(')
            return false;
          st.pop();
        }
        else if (expression[i] == '}') {
          if (st.empty() || st.top() != '{')
            return false;
          st.pop();
        }
        else if(expression[i]==']'){
            if(st.empty() || st.top()!='[') return false;
            st.pop();
        }
        else    return false;
    }
    return st.empty();
}
