#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
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

const ll p = 101;

vl mhash(const string & s) {
    vl res(s.size() + 1);
    for (int i = 0; i < s.size(); ++i)
        res[i + 1] = res[i] * p + s[i] - 'a' + 1;
    return res;
}

int main() {
    vl pw(2100, 1);
    for (int i = 1; i < pw.size(); ++i)
        pw[i] = pw[i - 1] * p;
    string s, s1, s2;
    vl diff, v,v1,v2;
    cin >> s >> s1 >> s2;
    int m = max(s1.size(), s2.size());
    v = mhash(s); v1 = mhash(s1); v2 = mhash(s2);
//    cerr << v[1] << " " << v[2] << " " << v[3] << endl;
    for (int i = 0; i < s.size(); ++i) for (int j = i + m - 1; j <= s.size(); ++j) {
//        cerr << i << " " << j << " " << v[i + s1.size()] - v[i] * pw[s1.size()] << " " << v1.back() << " " << v[j] - v[j - s2.size()] * pw[s2.size()] << " " << v2.back() << endl;
        if (v[i + s1.size()] - v[i] * pw[s1.size()] == v1.back() && 
                v[j + 1] - v[j + 1 - s2.size()] * pw[s2.size()] == v2.back())
            diff.push_back(v[j] - v[i] * pw[j - i]);
    }
    sort(diff.begin(), diff.end());
    int cnt = unique(diff.begin(), diff.end()) - diff.begin();
    cout << cnt << endl;
    return 0;
}