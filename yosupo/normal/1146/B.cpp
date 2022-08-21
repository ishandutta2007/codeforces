#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

string make_t(string s) {
    string t = s;
    for (char c : s) {
        if (c != 'a') t += c;
    }
    return t;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    int n = int(s.size()), nac = 0;
    for (char c : s) if (c != 'a') nac++;

    nac /= 2;

    int m = n;
    while (nac) {
        if (s[m - 1] != 'a') nac--;
        m--;
    }

    if (s == make_t(s.substr(0, m))) {
        cout << s.substr(0, m) << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}