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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
const int MOD = 1000000007;

long long mpow (long long x, int n) {
    long long res = 1;
    while (n) {
        if (n % 2)
            res = (res * x) % MOD;
        n /= 2;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    long long res = 1;
    for (int i = 0; i < n - 1; ++i) {
        res = (res * (2 * n - 1 - i)) % MOD;
        res = (res * mpow(i + 1, MOD - 2)) % MOD;
    }
    res = (res * 2 - n) % MOD;
    cout << (res + MOD) % MOD << endl;
    return 0;
}