class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> stackS;
        vector<char> stackT;
        int n = s.size(), m = t.size();
        int i = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == '#' && !stackS.empty()) {
                stackS.pop_back();
            } else {
                if(s[i] != '#'){
                    stackS.push_back(s[i]);
                }
            }
        }

        for (i = 0; i < m; i++) {
            if (t[i] == '#' && !stackT.empty()) {
                stackT.pop_back();
            } else {
                if(t[i] != '#'){
                    stackT.push_back(t[i]);
                }
            }
        }

        if (stackS.size() != stackT.size()) {
            return false;
        }
        n = stackS.size();
        for (i = 0; i < n; i++) {
            if (stackS[i] != stackT[i]) {
                return false;
            }
        }

        return true;
    }
};