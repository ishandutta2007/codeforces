#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    int co[100100] = {};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 1; j*j <= a; j++) {
            if (a % j == 0) {
                co[j]++;
                if (j*j != a) co[a/j]++;
            }
        }
    }
    int ans = 1;
    for (int i = 2; i < 100100; i++) {
        ans = max(ans, co[i]);
    }
    cout << ans << endl;
    return 0;

}