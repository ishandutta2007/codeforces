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

int main() {
    string s;
    cin >> s;
    ll add = 0;
    int cnt = 0;
    ll res = 1;
    vi was(10);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            if (i)
                ++add;
            else res = 9;
        }
        if (isupper(s[i])) {
            if (!was[s[i] - 'A'])
                ++cnt;
            was[s[i]-'A'] = 1;
        }
    }
    if (cnt) {
        if (isupper(s[0]))
            res *= 9;
        else res *= 10;
        for (int i = 1; i < cnt; ++i)
            res *= 10-i;
    }
    cout << res;
    for (int i = 0; i < add; ++i)
        printf("0");
    printf("\n");
    return 0;
}