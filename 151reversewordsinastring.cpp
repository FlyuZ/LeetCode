class Solution {
public:
  void reverseWords(string &s) {
    stack<string> st;
    string t = "";
    for (auto c : s) {
      if (c == ' ' && !t.empty()) {
        st.push(t);
        t = "";
      } else if (c != ' ') {
        t += c;
      }
    }
    if (!t.empty())
      st.push(t);
    s = "";
    while (!st.empty()) {
      t = st.top();
      st.pop();
      s += t;
      s += " ";
    }
    s = s.substr(0, s.size() - 1);
  }
};
