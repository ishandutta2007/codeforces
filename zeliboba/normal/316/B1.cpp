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
    int n,x;
    cin >> n >> x;
    vi a(n + 1);
    vi was(n+1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        was[a[i]] = 1;
    }
    vi l;
    int t = 0;
    for (int i = 1; i <= n; ++i) if (!was[i]) {
        int cur = i;
        int cnt = 0;
        bool bob = false;
        while (cur) {
            ++cnt;
            if (cur == x) {
                bob = true;
                t = cnt;
            }
            cur = a[cur];
        }
        if (!bob)
            l.push_back(cnt);
        else
            t = cnt - t + 1;
    }
    vi sums(n + 1);
    sums[0] = 1;
    for (int i = 0; i < l.size(); ++i) {
        for (int j = n-l[i]; j >= 0; --j) if (sums[j])
            sums[j+l[i]] = 1;
    }
    for (int i = 0; i < sums.size(); ++i) if (sums[i])
        printf("%d\n", i + t);
    return 0;
}