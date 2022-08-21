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
    int now = 0;
    for (int i = 0; i < n; i++) {
        int d; string s;
        cin >> d >> s;
        if (s == "North") {
            now -= d;
        } else if (s == "South") {
            now += d;
        } else {
            if (now == 0 || now == 20000) {
                cout << "NO" << endl;
                return 0;
            }
        }
        if (now < 0 || 20000 < now) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (now) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}