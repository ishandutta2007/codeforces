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
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

void upd(vi & v) {
    for (int i = 0; i + 2 < v.size(); ++i) {
        int d = min(v[i], v[i+1]);
        v[i] -= d;
        v[i+1] -= d;
        v[i+2] += d;
    }
//    while (v.size() && v.back() == 0)
//        v.pop_back();
}

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vi v1(100000 + 3);
    for (int i = 0; i < s.size(); ++i)
        v1[i] = s[i] - '0';
    upd(v1);
    cin >> s;
    reverse(s.begin(), s.end());
    vi v2(v1.size());
    for (int i = 0; i < s.size(); ++i)
        v2[i] = s[i] - '0';
    upd(v2);
/*    if (v1.size() < v2.size()) {
        cout << "<\n";
        return 0;
    }
    if (v1.size() > v2.size()) {
        cout << ">\n";
        return 0;
    }
    for (int i = (int)v1.size()-1; i >= 0; --i) {
        int d = min(v1[i], v2[i]);
        v1[i] -= d;
        v2[i] -= d;
    }*/
    for (int i = (int)v1.size()-1; i >= 0; --i) {
        int d = min(v1[i], v2[i]);
        v1[i] -= d;
        v2[i] -= d;
        if (i >= 2) {
            if (v2[i] >= 100000) {
                cout << "<\n";
                return 0;
            }
            if (v1[i] >= 100000) {
                cout << ">\n";
                return 0;
            }
            v1[i-2] += v1[i];
            v1[i-1] += v1[i];
            v2[i-2] += v2[i];
            v2[i-1] += v2[i];
        }
    }
    if (v1[0] == v2[0] && v1[1] == v2[1]) {
        cout << "=\n";
        return 0;
    }
    double q = (1. + sqrt(5.)) / 2.;
    double x1 = v1[0] + v1[1]*q;
    double x2 = v2[0] + v2[1]*q;
    if (x1 < x2) {
        cout << "<\n";
    } else {
        cout << ">\n";
    }
    return 0;
}