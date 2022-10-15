#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<long long> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

const int MOD = 1000000007;

long long mpow (long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

long long inv (long long a) {
    return mpow(a, MOD - 2);
}

vi fac(2000, 1);

long long cc(int i, int n) {
    long long res = (fac[n] * inv(fac[i])) % MOD;
    return (res * inv(fac[n - i])) % MOD;
}

int main() {
    int m;
    cin >> m;
    vi x(m), y(m);
    int sumx = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        sumx += x[i];
    }
    for (int i = 0; i < m; ++i)
        cin >> y[i];
    long long res = 1;
    fac.assign(2000, 1);
    for (int i = 1; i < fac.size(); ++i)
        fac[i] = (i * fac[i - 1]) % MOD;
    res = fac[sumx];
    for (int i = 0; i < m; ++i)
        res = (res * inv(fac[x[i]])) % MOD;
    vector<vi> f(m + 1, vi(1001, 0));
    vector<vi> c(sumx + 1, vi(sumx + 1, 0));
    for (int i = 0; i < c.size(); ++i)
        for (int j = i; j < c.size(); ++j) {
            c[i][j] = cc(i, j);
        }
    f[0][0] = 1;
//    cout << res << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j + x[i] < f[i].size(); ++j) if (f[i][j] != 0) {
            for (int l = max((long long)0, j + x[i] - y[i]); l <= j + x[i]; ++l) {
//                cout << i << " " << j << " " << l << " " << f[i][j] << " " << j + x[i] << " " << c(l, j + x[i]) << endl;
                f[i + 1][l] = (f[i + 1][l] + f[i][j] * c[l][j + x[i]]) % MOD;
            }
//            cout << f[i][j] << endl;
        }
//        cout << endl;
    }
    cout << ((f[m][0] * res) % MOD + MOD) % MOD << endl;
    return 0;
}