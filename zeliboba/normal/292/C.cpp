#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vi was(10);

bool isgood(int t) {
    if (t == 0) {
        return was[0];
    }
    while (t) {
        if (!was[t%10])
            return 0;
        t /= 10;
    }
    return 1;
}

string str(int t) {
    string s;
    if (t == 0)
        return "0";
    while (t) {
        s += (char)('0' + t%10);
        t /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool check (string s) {
    int l = s.size();
//    if (s == "78190209187") 
//        cerr << "here\n";
    for (int i = 0; 2*i < s.size(); ++i) if (s[i] != s[l-1-i])
        return 0;
    vi cnt(10);
//    if (s == "78190209187") 
//        cerr << "here\n";
    for (int i = 0; i < s.size(); ++i)
        cnt[s[i]-'0']++;
    for (int i = 0; i < 10; ++i) {
        if (was[i] && (cnt[i] == 0))
            return 0;
        if (!was[i] && (cnt[i] != 0))
            return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        was[a[i]] = 1;
    }
    if (n > 6) {
        cout << 0 << endl;
        return 0;
    }
    vi good;
    vector<string> gs;
    for (int i = 0; i < 256; ++i) if (isgood(i)) {
        good.push_back(i);
        gs.push_back(str(i));
//        cerr << str(i) << endl;
    }
    vector<string> out;
    for (int i1 = 0; i1 < good.size(); ++i1) for (int i4 = 0; i4 < good.size(); ++i4) {
        bool ok = 1;
        int l1 = gs[i1].size(), l4 = gs[i4].size();
        int l0 = min(l1, l4);
        for (int i = 0; i < l0; ++i) if (gs[i1][i] != gs[i4][l4-1-i]) {
            ok = 0;
            break;
        }
        if (!ok)
            continue;
        for (int i2 = 0; i2 < good.size(); ++i2) {
            int l2 = gs[i2].size();
            if (l1 + l2 + l4 + 3 < 2*n-1)
                continue;
            int l12 = min(l1+l2, l4);
            string s = gs[i1] + gs[i2];
//            if (s == "78190" && gs[i4] == "187")
//                cerr << "here\n";
            bool ok1 = 1;
            for (int i = l0; i < l12; ++i) if (s[i] != gs[i4][l4-1-i]) {
                ok1 = 0;
                break;
            }
            if (!ok1)
                continue;
//            if (s == "78190" && gs[i4] == "187")
//                cerr << "here\n";
            for (int i3 = 0; i3 < good.size(); ++i3) {
                string s1 = s + gs[i3]+gs[i4];
                if (check(s1)) {
                    out.push_back(gs[i1] + "." + gs[i2] + "." + gs[i3] + "." + gs[i4]);
                }
            }
        }
    }
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); ++i)
        cout << out[i] << endl;
    return 0;
}