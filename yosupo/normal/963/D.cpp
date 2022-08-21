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

template<class Str>
struct SA {
    Str s;
    V<int> sa, rsa, lcp;
    SA() {}
    SA(Str s, V<int> sa) : s(s), sa(sa) {
        int n = int(s.size());
        // make rsa
        rsa = V<int>(n+1);
        for (int i = 0; i <= n; i++) {
            rsa[sa[i]] = i;
        }
        // make lcp
        lcp = V<int>(n);
        int h = 0;
        for (int i = 0; i < n; i++) {
            int j = sa[rsa[i]-1];
            if (h > 0) h--;
            for (; j+h < n && i+h < n; h++) {
                if (s[j+h] != s[i+h]) break;
            }
            lcp[rsa[i]-1] = h;
        }
    }
};

template<class Str>
V<int> sa_is(Str s, int B = 200) {
    int n = int(s.size());
    V<int> sa(n+1);
    if (n == 0) return sa;

    for (int i = 0; i < n; i++) s[i]++;
    s.push_back(0); B++;

    V<bool> ls(n+1);
    ls[n] = true;
    for (int i = n-1; i >= 0; i--) {
        ls[i] = (s[i] == s[i+1]) ? ls[i+1] : (s[i] < s[i+1]);
    }
    V<int> sum_l(B+1), sum_s(B+1);
    for (int i = 0; i <= n; i++) {
        if (!ls[i]) sum_s[s[i]]++;
        else sum_l[s[i]+1]++;
    }
    for (int i = 0; i < B; i++) {
        sum_l[i+1] += sum_s[i];
        sum_s[i+1] += sum_l[i+1];
    }
    
    auto induce = [&](V<int> &lms){
        fill(begin(sa), end(sa), -1);
        auto buf0 = sum_s;
        for (auto d: lms) {
            sa[buf0[s[d]]++] = d;
        }
        auto buf1 = sum_l;
        for (int i = 0; i <= n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v-1]) {
                sa[buf1[s[v-1]]++] = v-1;
            }
        }
        auto buf2 = sum_l;
        for (int i = n; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v-1]) {
                sa[--buf2[s[v-1]+1]] = v-1;
            }
        }
    };

    V<int> lms, lms_map(n+1, -1);
    for (int i = 1; i <= n; i++) {
        if (!ls[i-1] && ls[i]) {
            lms_map[i] = int(lms.size());
            lms.push_back(i);
        }
    }

    induce(lms);

    if (lms.size() >= 2) {
        int m = int(lms.size())-1;
        V<int> lms2;
        for (int v: sa) {
            if (lms_map[v] != -1) lms2.push_back(v);
        }
        int rec_n = 1;
        V<int> rec_s(m);
        rec_s[lms_map[lms2[1]]] = 1;
        for (int i = 2; i <= m; i++) {
            int l = lms2[i-1], r = lms2[i];
            int nl = lms[lms_map[l]+1], nr = lms[lms_map[r]+1];
            if (nl-l != nr-r) rec_n++;
            else {
                while (l <= nl) {
                    if (s[l] != s[r]) {
                        rec_n++;
                        break;
                    }
                    l++; r++;
                }                
            }
            rec_s[lms_map[lms2[i]]] = rec_n;
        }
        
        V<int> nx_lms;
        auto ch_sa = sa_is(rec_s, rec_n);
        for (int d: ch_sa) {
            nx_lms.push_back(lms[d]);
        }
        induce(nx_lms);
    }

    return sa;
}

// t,O(|t|logn)
template<class Str>
array<int, 2> find(SA<Str> &sa, string t) {
    int n = (int)sa.s.size(), m = (int)t.size();
    array<int, 2> ans;
    int l, r;

    l = 0, r = n+1;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (sa.s.compare(sa.sa[md], m, t) < 0) {
            l = md;
        } else {
            r = md;
        }
    }
    ans[0] = r;

    l = 0, r = n+1;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (sa.s.compare(sa.sa[md], m, t) <= 0) {
            l = md;
        } else {
            r = md;
        }
    }
    ans[1] = r;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    string s;
    cin >> s;
//    for (int i = 0; i < TEN(5); i++) s += "a";
    SA<string> sa = SA<string>(s, sa_is(s));

    int q;
    cin >> q;
//    q = 420;
    for (int ph = 0; ph < q; ph++) {
        int k; string m;
        cin >> k >> m;
//        k = 1;
//        for (int i = 0; i <= ph; i++) m += "a";
        auto u = find(sa, m);
//        cout << u[0] << " " << u[1] << endl;
        V<int> v;
        for (int i = u[0]; i < u[1]; i++) {
            v.push_back(sa.sa[i]);
        }        
        sort(begin(v), end(v));
        int n = int(v.size());
        if (n < k) {
            cout << -1 << endl;
            continue;
        }
        int ans = TEN(9);
        for (int i = 0; i <= n-k; i++) {
            ans = min(ans, v[i+k-1] - v[i] + int(m.size()));
        }
        cout << ans << endl;
    }
    return 0;
}