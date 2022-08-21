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
    ll n, m;
    cin >> n >> m; n--; m--;
    int a = 0, b = 0;
    ll n2 = n, m2 = m;
    while (n2) {
        a++;
        n2 /= 7;
    }
    while (m2) {
        b++;
        m2 /= 7;
    }
    a = max(a, 1);
    b = max(b, 1);
    if (7 < a+b) {
        printf("0\n");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int x = i, y = j;
            bool used[7] = {};
            bool A = true;
            for (int f = 0; f < a; f++) {
                if (used[x%7]) {
                    A = false;
                    break;
                }
                used[x%7] = true;
                x /= 7;
            }
            for (int f = 0; f < b; f++) {
                if (used[y%7]) {
                    A = false;
                    break;
                }
                used[y%7] = true;
                y /= 7;
            }
            if (A) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}