#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;

struct Trie {
    char c;
    vector<Trie> v;
    Trie(string s) {
        c = s[0];
        if (s.size() > 1) {
            v.push_back(Trie(s.substr(1)));
        }
    }
    void add(string s) {
        if (!s.size()) return;
        for (auto &t: v) {
            if (t.c == s[0]) {
                t.add(s.substr(1));
                return;
            }
        }
        v.push_back(Trie(s));
    }
    bool f[2];
    void calc() {
        if (!v.size()) {
            f[0] = false; f[1] = true;
            return;
        }
        f[0] = f[1] = false;
        for (auto &t: v) {
            t.calc();
            f[0] |= !t.f[0];
            f[1] |= !t.f[1];
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Trie t("$");
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.add(s);
    }
    t.calc();
    if (!t.f[0] || (!t.f[1] && k%2 == 0)) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}