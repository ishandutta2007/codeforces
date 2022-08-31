//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL




#include <algorithm>

#include <array>

#include <cassert>

#include <complex>

#include <cstdio>

#include <bitset>

#include <cstring>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

int n;

void init() {
    cin >> n;
}

V<string> query(int l, int r) {
    if (l == r) return {};
    cout << "? " << l + 1 << " " << r << endl;
    int di = r - l;
    int c = (di + 1) * di / 2;
    V<string> ans;
    for (int i = 0; i < c; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans.push_back(s);
    }
    return ans;
}

void answer(string s) {
    cout << "! " << s << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    if (n == 1) {
        auto v = query(0, 1);
        answer(v[0]);
    }

    int l = n / 2;
    string ans(n, '$');
    {
        auto q0 = query(0, l);
        auto q1 = query(1, l);
        V<string> q2;
        {
            multiset<string> st{q0.begin(), q0.end()};
            for (auto s: q1) st.erase(st.find(s));
            q2 = V<string>{st.begin(), st.end()};
        }
        sort(q2.begin(), q2.end(), [&](const string& s, const string& t) {
            return s.size() < t.size();
        });

        for (int i = 0; i < l; i++) {
            multiset<char> st{q2[i].begin(), q2[i].end()};
            assert(int(st.size()) == i + 1);
            for (int j = 0; j < i; j++) {
                st.erase(st.find(ans[j]));
            }
            ans[i] = *st.begin();
        }

//        answer(ans);
    }

    auto q = query(0, n);
    VV<string> vs(n + 1);
    for (auto s: q) {
        vs[s.size()].push_back(s);
    }

    for (int r = n - 1; r >= l; r--) {
        int mc = n - r + 1;
        V<int> cnt(26);
        for (auto s: vs[r]) {
            for (auto c: s) {
                cnt[c - 'a']++;
            }
        }
        for (int i = 0; i < n; i++) {
            char c = ans[i];
            if (c == '$') continue;
            int di = min(i, n - 1 - i) + 1;
            cnt[c - 'a'] -= min(di, mc);
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % mc) {
                ans[r] = char(i + 'a');
                break;
            }
        }
    }

    answer(ans);
    return 0;
}