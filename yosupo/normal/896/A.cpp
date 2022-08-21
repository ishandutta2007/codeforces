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

const ll INF = TEN(18) + TEN(16);
string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1a = "What are you doing while sending \"";
string s1b = "\"? Are you busy? Will you send \"";
string s1c = "\"?";

V<ll> len;
char sea(int n, ll k) {
    if (len[n] <= k) return '.';
    if (n == 0) {
        return s0[k];
    }
    if (k < s1a.size()) {
        return s1a[k];
    }
    k -= s1a.size();
    if (k < len[n-1]) {
        return sea(n-1, k);
    }
    k -= len[n-1];
    if (k < s1b.size()) {
        return s1b[k];
    }
    k -= s1b.size();
    if (k < len[n-1]) {
        return sea(n-1, k);
    }
    k -= len[n-1];
    if (k < s1c.size()) {
        return s1c[k];
    }
    k -= s1c.size();
    assert(false);
}

int main() {
    len = V<ll>(200000);
    len[0] = int(s0.size());
    for (int i = 1; i < 200000; i++) {
        len[i] = 2*len[i-1] + s1a.size() + s1b.size() + s1c.size();
        len[i] = min(len[i], INF);
    }
    int q;
    cin >> q;
    string ans;
    for (int i = 0; i < q; i++) {
        int n; ll k;
        cin >> n >> k; k--;
        ans += sea(n, k);
    }
    cout << ans << endl;
/*    for (int i = 0; i < 300; i++) {
        cout << sea(1, i);
    }
    cout << endl;*/
    return 0;
}