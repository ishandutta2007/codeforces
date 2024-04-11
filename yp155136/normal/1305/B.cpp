#include <bits/stdc++.h>
using namespace std;

bool ok(string s) {
    stack<int> sta;
    for (char i: s) {
        if (i == '(') {
            sta.push(i);
        }
        else {
            if (!sta.empty()) {
                return true;
            }
        }
    }
    return false;
}

vector< vector<int> > ans;

const int N = 1006;

int a[N];
int pre[N];

void gao(string &s) {
    int n = (int)s.size();
    for (int i = 1; i <= n; ++i) {
        a[i] = (s[i - 1] == '(' ? 1 : 0);
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    int pos = -1;
    int mx = -1;
    int tot = pre[n];
    for (int i = 1; i <= n; ++i) {
        int val = min(pre[i], (n - i) - (tot - pre[i]));
        if (val > mx) {
            mx = val;
            pos = i;
        }
    }
    vector<int> ret;
    int left = mx;
    string t = "";
    for (int i = 1; i <= pos; ++i) {
        if (a[i] == 1 && left > 0) {
            ret.push_back(i);
            --left;
        }
        else {
            t += s[i - 1];
        }
    }
    left = mx;
    string tt = "";
    for (int i = n; i >= pos + 1; --i) {
        if (a[i] == 0 && left > 0) {
            ret.push_back(i);
            --left;
        }
        else {
            tt += s[i - 1];
        }
    }
    sort(ret.begin(), ret.end());
    reverse(tt.begin(), tt.end());
    ans.push_back(ret);
    s = t + tt;
}

int main () {
    string s; cin >> s;
    while (ok(s)) {
        gao(s);
    }
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i.size() << endl;
        for (int j: i) cout << j << ' '; cout << endl;
    }
}