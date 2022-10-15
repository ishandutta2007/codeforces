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
typedef vector<string> vs;

int main() {
    vi erat(1000001, 1);
    erat[0] = erat[1] = 0;
    for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
        for (int j = i * i; j < erat.size(); j += i)
            erat[j] = 0;
    }
    int n;
    cin >> n;
    vi used(n + 1);
    vii out;
    for (int i = n; i > 2; --i) if (erat[i] && 2*i <= n) {
        vi v(1, i);
        used[i] = 1;
        for (int j = 3*i; j <= n; j += i) if (!used[j]) {
            used[j] = 1;
            if (v.empty()) {
                v.push_back(j);
            } else {
                out.push_back(pii(v[0], j));
                v.pop_back();
            }
        }
//        cerr << i << ' ' << v.size() << endl;
        if (v.size()) {
            used[2*i] = 1;
            out.push_back(pii(v[0], 2*i));
        }
    }
    vi rest;
    for (int i = 1; i <= n; ++i) if (!used[i] && (i % 2 == 0)) {
        rest.push_back(i);
    }
    for (int i = 1; i < rest.size(); i += 2) out.push_back(pii(rest[i], rest[i-1]));
    printf("%d\n", (int)out.size());
    for (int i = 0; i < out.size(); ++i)
        printf("%d %d\n", out[i].first, out[i].second);
    return 0;
}