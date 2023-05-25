
class Solution {
public:
    long long evaluate(const string& st) {
        int n = st.size();
        long long a = 0, x = 0, y = 0;
        char op = '+';
        
        for (int i = 0; i < n; ++i) {
            char c = st[i];
            
            if (isdigit(c)) {
                y = y * 10 + (c - '0');
            }
            
            if (!isdigit(c) || i == n - 1) {
                if (op == '+') {
                    a += x;
                    x = y;
                } else if (op == '-') {
                    a += x;
                    x = -y;
                } else if (op == '*') {
                    x *= y;
                }
                
                op = c;
                y = 0;
            }
        }
        
        return a + x;
    }
    
    void generateExpressions(vector<string>& res, string& st, int target, int pos, string& expr) {
        if (pos == st.size()) {
            if (evaluate(expr) == target) {
                res.push_back(expr);
            }
            return;
        }
        
        for (int i = pos; i < st.size(); ++i) {
            if (i != pos && st[pos] == '0') {
                break;  // Avoid leading zeros
            }
            
            string num = st.substr(pos, i - pos + 1);
            
            if (pos == 0) {
                expr += num;
                generateExpressions(res, st, target, i + 1, expr);
                expr = expr.substr(0, expr.size() - num.size());
            } else {
                expr.push_back('+');
                expr += num;
                generateExpressions(res, st, target, i + 1, expr);
                expr = expr.substr(0, expr.size() - num.size() - 1);
                
                expr.push_back('-');
                expr += num;
                generateExpressions(res, st, target, i + 1, expr);
                expr = expr.substr(0, expr.size() - num.size() - 1);
                
                expr.push_back('*');
                expr += num;
                generateExpressions(res, st, target, i + 1, expr);
                expr = expr.substr(0, expr.size() - num.size() - 1);
            }
        }
    }
    
    vector<string> addOperators(string st, int t) {
        vector<string> res;
        string expr;
        generateExpressions(res, st, t, 0, expr);
        return res;
    }
};
