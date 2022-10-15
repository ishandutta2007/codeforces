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

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string bla(s2.size(), '#');
    s1 = bla + s1 + bla;
    int best = 0, mi = s2.size();
    for (int i = 0; i +s2.size() <= s1.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < s2.size(); ++j) if (s1[i + j] != s2[j])
            ++cnt;
        if (mi > cnt)
            mi = cnt;
    }
    cout << mi << endl;
    return 0;
}