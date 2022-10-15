#include <cstdio>
#include <cstdlib>
#include <cassert>
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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

bool smerat[20000];
const int N = 5000000;
bool berat[N];

int main() {
    int l, r;
    cin >> l >> r;
    memset(smerat, 0, sizeof(smerat));
    smerat[0] = smerat[1] = 1;
    int lim = sqrt(r) + 2;
    for (int i = 2; i * i <= lim; ++i) if (!smerat[i])
        for (int j = i * i; j <= lim; j += i)
            smerat[j] = 1;
    vi primes;
    for (int i = 0; i <= lim; ++i) if (!smerat[i])
        primes.push_back(i);
    int cnt = 0;
    if (l <= 2 && 2 <= r)
        ++cnt;
    while (l % 4 != 1)
        ++l;
    for (int t = 0; t < (r - l + N) / N; ++t) {
//        cerr << t << endl;
        memset(berat, 0, sizeof(berat));
        int b = l + t * N;
        for (int it = 0; it < primes.size(); ++it) {
            int p = primes[it];
            int add = p - b % p;
            if (add == p)
                add = 0;
            for (int j = b + add; j < b + N; j += p) if (j != p)
                berat[j - b] = 1;
        }
        for (int i = max(b, 5); i <= r && i < b + N; i += 4) if (!berat[i - b]) {
//            cerr << i << endl;
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}