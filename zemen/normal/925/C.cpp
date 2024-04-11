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
const int N = 1e6 + 100;
const int K = 61;

int n;
int64 x[N];

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
    }
    vector<char> used(n, false);
    vector<int64> a;
    for (int i = K - 1; i >= 0; i--) {
        vector<int64> b;
        int cur = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (x[j] & (1ll << i))) {
                while (cur < len(a) && cur != -1 && !(a[cur] & (1ll << i))) {
                    b.pb(a[cur++]);
                }
                if (cur < len(a)) {
                    if (cur != -1) {
                        b.pb(a[cur]);
                    }
                    cur++;
                    b.pb(x[j]);
                    used[j] = true;
                } else {
                    puts("No");
                    return 0;
                }
            }
        }
        while (cur < len(a)) {
            if (cur != -1) {
                b.pb(a[cur]);
            }
            cur++;
        }
        a = move(b);
    }
    puts("Yes");
    for (auto i : a) {
        printf("%lld ", i);
    }
    puts("");
    return 0;
}