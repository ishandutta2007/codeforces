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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 1 || n <= 3) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 4) {
        if (k != 3) {
            cout << -1 << endl;
            return 0;
        }
        cout << 3 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 3 << " " << 4 << endl;
        return 0;
    }
    if (k == 2) {
        cout << n-1 << endl;
        for (int i = 0; i < n-1; i++) {
            cout << i+1 << " " << i+2 << endl;
        }
        return 0;
    }
    if (k == 3) {
        cout << n-1 << endl;
        cout << 1 << " " << 2 << endl;
        for (int i = 2; i <= n; i++) {
            if (i == 3) continue;
            cout << i << " " << 3 << endl;
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}