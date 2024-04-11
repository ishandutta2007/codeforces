#include<iostream>
#include<algorithm>
using namespace std;

int main () {
    long long n, m;
    cin >> n >> m;
    long long res = n * m;
    for (int b = 1; b * b < m && b <= n; ++b)
        res -= (m - b * b);
    res *= 2;
    for (long long a = 1; a < min(2 * n, m + 1); ++a) {
        res -= max(0LL, min((2 * n - a + 1) / 2, (m / a + a % 2) / 2) - 1);
        if (a <= n && a * a <= m)
            res--;
    }
    cout << res << endl;
    return 0;
}