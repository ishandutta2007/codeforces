#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;

int n, m, cl, ce, v;

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> cl >> ce >> v;
    vector<int> a(cl), b(ce);
    for (int i = 0; i < cl; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < ce; i++) {
        scanf("%d", &b[i]);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) {
            printf("%d\n", abs(y1 - y2));
            continue;
        }
        int index1 = lower_bound(all(a), y1) - a.begin();
        int ans = inf;
        for (int j = max(0, index1 - 1); j <= index1 + 1 && j < a.size(); j++) {
            int curAns = abs(y1 - a[j]) + abs(x1 - x2) + abs(a[j] - y2);
            ans = min(ans, curAns);
        }
        int index2 = lower_bound(all(b), y1) - b.begin();
        for (int j = max(0, index2 - 1); j <= index2 + 1 && j < b.size(); j++) {
            int curAns = abs(y1 - b[j]) + (abs(x1 - x2) + v - 1) / v + abs(b[j] - y2);
            ans = min(ans, curAns);
        }
        printf("%d\n", ans);
    }
    return 0;
}