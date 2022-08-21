#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;

using P = pair<int, int>;


/**
 * Suffix Array
 */

namespace SuffixArray {
    template<class T>
    void induce(int n, const T s[], bool ls[], int sa[], int l_basm[], int B) {
        int buf[B+10];
        copy_n(l_basm, B+1, buf);
        for (int i = 0; i <= n; i++) {
            if (sa[i] >= 1 && !ls[sa[i]-1]) {
                int bc = s[sa[i]-1];
                sa[buf[bc]++] = sa[i]-1;
            }
        }

        copy_n(l_basm, B+1, buf);
        for (int i = n; i > 0; i--) {
            if (sa[i] >= 1 && ls[sa[i]-1]) {
                int bc = s[sa[i]-1];
                sa[--buf[bc+1]] = sa[i]-1;
            }
        }
    }

    template<class T>
    void SA(int n, const T s[], int sa[], int B = 200) {
        bool ls[n+1]; //L:false S:true
        int l_ba[B+1], s_ba[B+1];
        fill_n(l_ba, B+1, 0); fill_n(s_ba, B+1, 0);
        ls[n] = true;
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1 || s[i] > s[i+1]) {
                ls[i] = false;
            } else if (s[i] < s[i+1]) {
                ls[i] = true;
            } else {
                ls[i] = ls[i+1];
            }
            if (!ls[i]) {
                l_ba[(int)s[i]]++;
            } else {
                s_ba[(int)s[i]]++;
            }
        }

        vector<int> v;
        int lms[n+1];
        fill_n(lms, n+1, -1);
        int c = 0;
        for (int i = 1; i < n; i++) {
            if (!ls[i-1] && ls[i]) {
                lms[i] = c++;
                v.push_back(i);
            }
        }
        
        int l_basm[B+1], s_basm[B+1];
        l_basm[0] = 1; s_basm[0] = 1+l_ba[0];
        for (int i = 1; i <= B; i++) {
            l_basm[i] = s_basm[i-1]+s_ba[i-1];
            s_basm[i] = l_basm[i]+l_ba[i];
        }

        if (v.size()) {
            vector<int> v2 = v;
            int buf[B+1];
            copy_n(s_basm, B+1, buf);
            fill_n(sa, n+1, -1);
            sa[0] = n;
            for (int i = 0; i < (int)v.size(); i++) {
                int c = s[v[i]];
                sa[buf[c]++] = v[i];
            }
            induce(n, s, ls, sa, l_basm, B);
            int c = 0;
            for (int i = 1; i <= n; i++) {
                if (lms[sa[i]] == -1) continue;
                v[c++] = sa[i];
            }

            int s2[v.size()];
            int sa2[v.size()+1];
            c = 0;
            s2[lms[v[0]]] = 0;
            for (int i = 1; i < (int)v.size(); i++) {
                int l = v[i-1], r = v[i];
                while (true) {
                    if (s[l] != s[r]) {
                        c++;
                        break;
                    }
                    l++; r++;
                    if (lms[l] != -1 || lms[r] != -1) {
                        if (lms[l] == -1 || lms[r] == -1) {
                            c++;
                        }
                        break;
                    }
                }
                s2[lms[v[i]]] = c;
            }
            SA(v.size(), s2, sa2, c);
            for (int i = 1; i <= (int)v.size(); i++) {
                v[i-1] = v2[sa2[i]];
            }
        }

        int buf[B+1];
        copy_n(s_basm, B+1, buf);

        fill_n(sa, n+1, -1);
        sa[0] = n;
        for (int i = 0; i < (int)v.size(); i++) {
            int c = s[v[i]];
            sa[buf[c]++] = v[i];
        }

        induce(n, s, ls, sa, l_basm, B);
    }

    template <class T>
    void LCP(int n, const T s[], const int sa[], int lcp[]) {
        int rsa[n+1];
        for (int i = 0; i <= n; i++) {
            rsa[sa[i]] = i;
        }
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
}


//    void SA(int n, const T s[], int sa[], int B = 200) {

const int MN = 2200;

int mt(string s, string t) {
    int n = min((int)s.size(), (int)t.size());
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) return i;
    }
    return n;
}

int main() {
    string s, sr;
    cin >> s; sr = s;
    reverse(sr.begin(), sr.end());
    int n = (int)s.size();
    static int ssa[MN], srsa[MN];
    SuffixArray::SA(n, s.c_str(), ssa);
    SuffixArray::SA(n, sr.c_str(), srsa);

    string t;
    cin >> t;
    int m = (int)t.size();

    vector<P> res;
    int p = 0;
    while (p < m) {
        int mi = 0;
        P mp;

        int nm;
        P np;

        int l = 0, r = n+1;
        while (r-l > 1) {
            int md = (l+r)/2;
            if (s.substr(ssa[md]) < t.substr(p)) {
                l = md;
            } else {
                r = md;
            }
        }

        nm = mt(s.substr(ssa[l]), t.substr(p));
        np = P(ssa[l]+1, ssa[l]+nm);
        if (mi < nm) {
            mi = nm;
            mp = np;
        }
        if (r < n+1) {
            nm = mt(s.substr(ssa[r]), t.substr(p));
            np = P(ssa[r]+1, ssa[r]+nm);
            if (mi < nm) {
                mi = nm;
                mp = np;
            }
        }

        l = 0, r = n+1;
        while (r-l > 1) {
            int md = (l+r)/2;
            if (sr.substr(srsa[md]) < t.substr(p)) {
                l = md;
            } else {
                r = md;
            }
        }
        nm = mt(sr.substr(srsa[l]), t.substr(p));
        np = P(srsa[l], srsa[l]+nm);
        np = P(n-np.first, n+1-np.second);
        if (mi < nm) {
            mi = nm;
            mp = np;
        }
        if (r < n+1) {
            nm = mt(sr.substr(srsa[r]), t.substr(p));
            np = P(srsa[r], srsa[r]+nm);
            np = P(n-np.first, n+1-np.second);
            if (mi < nm) {
                mi = nm;
                mp = np;
            }
        }

        if (mi == 0) {
            cout << -1 << endl;
            return 0;
        }
        p += mi;
        res.push_back(mp);
    }

    cout << res.size() << endl;
    for (P p: res) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}