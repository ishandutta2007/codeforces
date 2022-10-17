#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long a[400005];
inline unsigned long long kkktql(long long t) {//
    long long i;
    unsigned long long ans = 0;
    for (i = 1; i * i <= t; ++i) {
        if (t % i == 0) ans += 2;
    }
    return (i - 1) * (i - 1) == t ? (ans - 1) : ans;//
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1) {
        cout << kkktql(a[1]) << endl;
        return 0;
    }
    long long gcd = __gcd(a[1], a[2]);
    for (int i = 3; i <= n; ++i) {
        gcd = __gcd(gcd, a[i]);//gcd
    }
    cout << kkktql(gcd) << endl;
    return 0;
}