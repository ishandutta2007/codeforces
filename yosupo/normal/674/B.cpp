#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 4 or k <= n) {
        printf("-1\n");
        return 0;
    }
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    set<int> s;
    s.insert(a); s.insert(b); s.insert(c); s.insert(d);

    /// first
    printf("%d %d ", a, c);
    for (int i = 1; i <= n; i++) {
        if (s.count(i)) continue;
        printf("%d ", i);
    }
    printf("%d %d\n", d, b);

    /// second
    printf("%d %d ", c, a);
    for (int i = 1; i <= n; i++) {
        if (s.count(i)) continue;
        printf("%d ", i);
    }
    printf("%d %d\n", b, d);

    return 0;
}