User
string stringMirror(string str) {
    char last = str[0];
    string tmp, ans1, ans2;
    tmp += str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] < last) {
            last = str[i];
            tmp += last;
        } else {
            break;
        }
    }
    ans1 += tmp;
    reverse(tmp.begin(), tmp.end());
    ans1 += tmp;
    tmp = "";
    tmp += str[0];
    last = str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] <= last) {
            last = str[i];
            tmp += last;
        } else {
            break;
        }
    }
    ans2 += tmp;
    reverse(tmp.begin(), tmp.end());
    ans2 += tmp;
    if (ans1 <= ans2) {
        return ans1;
    } else {
        return ans2;
    }
}
