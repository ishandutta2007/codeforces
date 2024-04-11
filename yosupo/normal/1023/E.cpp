#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

const bool DEBUG = false;

int n;

V<string> g;

bool query(int r_mi, int c_mi, int r_ma, int c_ma) {
    if (r_mi < 0 || n <= r_mi) return false;
    if (c_mi < 0 || n <= c_mi) return false;
    if (r_ma < 0 || n <= r_ma) return false;
    if (c_ma < 0 || n <= c_ma) return false;
    if (!DEBUG) {
        r_mi++;
        c_mi++;
        r_ma++;
        c_ma++;
        cout << "? " << r_mi << " " << c_mi << " " << r_ma << " " << c_ma << endl;
        string res;
        cin >> res;
        return res == "YES";
    } else {
        VV<int> dp(n+1, V<int>(n+1, false));
        dp[r_ma][c_ma] = true;
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                dp[i][j] = dp[i][j] || dp[i+1][j] || dp[i][j+1];
                if (g[i][j] == '#') dp[i][j] = false;
            }
        }
        cout << "WOW: " << dp[r_mi][c_mi] << endl;
        return dp[r_mi][c_mi];
    }
}

void answer(string s) {
    cout << "! " << s << endl;
    exit(0);
}

int main() {
    cin >> n;

    if (DEBUG) {
        g = V<string>(n);
        for (int i = 0; i < n; i++) cin >> g[i];
    }

    assert(query(0, 0, n-1, n-1));
    int r, c;
    r = 0; c = 0;

    string s1, s2;
    for (int ph = 0; ph < n-1; ph++) {
        if (query(r+1, c, n-1, n-1)) r++, s1 += "D";
        else c++, s1 += "R";
    }

    r = n-1; c = n-1;
    for (int ph = 0; ph < n-1; ph++) {
        if (query(0, 0, r, c-1)) c--, s2 += "R";
        else r--, s2 += "D";
    }
    reverse(s2.begin(), s2.end());

    answer(s1 + s2);
    return 0;
}