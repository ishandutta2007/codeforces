#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

const int B = 256;

string mi(string s, string t) {
    if (s == "") return t;
    if (t == "") return s;
    if (s.size() < t.size()) return s;
    if (s.size() > t.size()) return t;
    return min(s, t);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    string e[B], t[B], f[B];

    f[0b00001111] = "x";
    f[0b00110011] = "y";
    f[0b01010101] = "z";

    int ok = 3, sm = 3;    
    while (true) {
        for (int i = 0; i < 256; i++) {
            if (f[255^i] == "") continue;            
            f[i] = mi(f[i], "!" + f[255^i]);
        }
        for (int i = 0; i < 256; i++) {
            if (e[i] == "") continue;            
            f[i] = mi(f[i], "(" + e[i] + ")");
        }

        for (int i = 0; i < 256; i++) {
            t[i] = mi(t[i], f[i]);
        }
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                int k = i & j;
                if (t[i] == "" || t[j] == "") continue;
                t[k] = mi(t[k], t[i] + "&" + t[j]);
            }
        }

        for (int i = 0; i < 256; i++) {
            e[i] = mi(e[i], t[i]);
        }
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                int k = i | j;
                if (e[i] == "" || e[j] == "") continue;
                e[k] = mi(e[k], e[i] + "|" + e[j]);
            }
        }

        int nok = 0, nsm = 0;
        for (int i = 0; i < 256; i++) {
            if (e[i] != "") {
                nok++;
                nsm += e[i].size();
            }
            if (t[i] != "") {
                nok++;
                nsm += t[i].size();
            }
            if (f[i] != "") {
                nok++;
                nsm += f[i].size();
            }
        }

//        cout << "REF " << nok << " " << nsm << endl;
        if (nok == ok && nsm == sm) break;
        ok = nok; sm = nsm;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int u = 0;
        for (int j = 0; j < 8; j++) {
            u += (t[7-j] - '0') * (1<<j);
        }
        cout << e[u] << endl;
    }
    return 0;
}