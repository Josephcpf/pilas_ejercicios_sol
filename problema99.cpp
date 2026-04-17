int solve(const vector<string>& tokens) {
    Stack<int> st;

    for (const string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if      (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else               st.push(a / b);
        }
        else {
            st.push(stoi(t));
        }
    }

    return st.top();
}
