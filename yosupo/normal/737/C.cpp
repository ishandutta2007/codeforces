#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }


const int MN = 200200;
int n, s;
int a[MN];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> s; s--;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    if (a[s]) {
        a[s] = 0;
        ans++;
    }
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        if (!a[i]) {
            a[i] = n;
        }
    }
    sort(a, a+n);
    int L = 0, R = n-1;
    for (int d = 0; d < n; d++) {
        if (a[L] == d) {
            while (L < n && a[L] == d) L++;
        } else {
            ans++;
            R--;
        }
        if (R < L) {
            cout << ans << endl;
            break;
        }
    }
    return 0;
}