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

const int s = 1000000;
vi v(s+1);

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[x] = 1;
        if (v[s+1-x])
            ++cnt;
    }
    vi y;
    for (int i = 1; i <= s; ++i) {
        if (!v[i] && v[s+1-i]) {
            y.push_back(i);
        }
        if (!v[i] && !v[s+1-i] && cnt) {
            --cnt;
            v[i] = v[s+1-i] = 1;
            y.push_back(i);
            y.push_back(s+1-i);
        }
    }
    printf("%d\n", (int)y.size());
    for (int i = 0; i < y.size(); ++i)
        printf("%d ", y[i]);
    return 0;
}