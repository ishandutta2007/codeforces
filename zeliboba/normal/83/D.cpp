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
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = 2; i * i <= k; ++i)
        if (!(k % i)) {
            cout << 0 << endl;
            return 0;
        }
    b /= k;
    a = (a + k - 1) / k;
    if (a > b) {
        cout << 0 << endl;
        return 0;
    }
    if (b < k) {
        if (a > 1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    vector<char> erat(k, 1);
    erat[0] = erat[1] = 0;
    for (int i = 2; i * i < erat.size(); ++i) if (erat[i])
        for (int j = i * i; j < erat.size(); j += i)
            erat[j] = 0;
    vi primes;
    for (int i = 2; i < erat.size(); ++i) if (erat[i])
        primes.push_back(i);
    if (primes.size() < 22) {
        ll res = 0;
        for (int mask = 0; mask < (1 << primes.size()); ++mask) {
            ll prod = 1;
            int zn = 1;
            for (int i = 0; i < primes.size(); ++i) if (mask & (1 << i)) {
                prod *= primes[i];
                zn *= -1;
            }
            res += zn * (b / prod - (a - 1) / prod);
        }
        cout << res << endl;
//        cerr << "case 1\n";
    } else {
        vector<char> skip(b + 1, 1);
        for (int it = 0; it < primes.size(); ++it) {
            for (int i = 0; i < skip.size(); i += primes[it])
                skip[i] = 0;
        }
        int cnt = 0;
        for (int i = a; i <= b; ++i) if (skip[i])
            ++cnt;
        cout << cnt << endl;
    }
    return 0;
}