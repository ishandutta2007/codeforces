#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

void calc(string s) {
    V<string> res;
    for (int ph = 0; ph < 3; ph++) {
        int n = int(s.size());
        ll sm = 0;
        string t;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            sm += c - '0';
            t += c;
            if (i != n-1) t += "+";
        }
        res.push_back(t);
        s = to_string(sm);
    }
    if (s.size() > 1) return;
    for (auto t: res) {
        cout << t << endl;
    }
    exit(0);
}

void calc2(string s) {
    V<string> res;
    for (int ph = 0; ph < 3; ph++) {
        int n = int(s.size());
        int m = -2;
        if (ph == 0) m = rand_int(0, n-2);
        ll sm = 0;
        string t;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (i != m) sm += c - '0';
            else sm += 10 * (c - '0');
            t += c;
            if (i != n-1 && i != m) t += "+";
        }
        res.push_back(t);
        s = to_string(sm);
    }
    if (s.size() > 1) return;
    for (auto t: res) {
        cout << t << endl;
    }
    exit(0);
}

void calc3(string s) {
    V<string> res;
    for (int ph = 0; ph < 3; ph++) {
        int n = int(s.size());
        ll sm = 0;
        string t;
        bool bf = false;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            bool f = rand_int(0, 100) == 0;
            if (i == n-1 || bf) f = false;
            bf = f;
            if (!f) sm += c - '0';
            else sm += 10 * (c - '0');
            t += c;
            if (i != n-1 && !f) t += "+";
        }
        res.push_back(t);
        s = to_string(sm);
    }
    if (s.size() > 1) return;
    for (auto t: res) {
        cout << t << endl;
    }
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int dummy;
    string s;
    cin >> dummy >> s;

    calc(s);
    for (int i = 0; i < 3; i++) calc2(s);
    while (true) {
        calc3(s);
    }
    return 0;
}