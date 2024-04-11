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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
vector<string> vs;
vi cur;
vi primes;
int lb[1000000];
int n, res;
int pw10[7];

void rec(int i) {
//    cerr << lb[cur[i]] << " " << cur[i] + pw10[n - i] << endl;
/*    if (i == n - 1) {
        res += lb[cur[i] + pw10[n - i]] - lb[cur[i]];
        return;
    }*/
    for (int j = lb[cur[i]]; j < primes.size() && primes[j] < cur[i] + pw10[n - i]; ++j) {
        int p = primes[j];
        if (i == n - 2) {
            int t = cur[n - 1] + 10 * (p % 10);
            res += lb[t + 10] - lb[t];
            continue;
        }
        vi dig(n - i);
        for (int d = 0; d < n - i; ++d) {
            dig[d] = p % 10;
            p /= 10;
            cur[n - d - 1] += pw10[n - i - 1] * dig[d];
        }
        rec(i + 1);
        for (int d = 0; d < n - i; ++d) {
            cur[n - d - 1] -= pw10[n - i - 1] * dig[d];
        }
    }
}

int main() {
    memset(lb, 0, sizeof(lb));
    pw10[0] = 1;
    for (int i = 1; i < 7; ++i)
        pw10[i] = 10 * pw10[i - 1];
    vector<int> erat(1e6, 1);
    erat[0] = erat[1] = 0;
    for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
        for (int j = i * i; j < erat.size(); j += i)
            erat[j] = 0;
    }
    for (int i = 2; i < erat.size(); ++i) if (erat[i])
        primes.push_back(i);
    for (int i = 1; i < primes.size(); ++i) {
        for (int j = primes[i - 1] + 1; j <= primes[i]; ++j)
            lb[j] = i;
    }
    for (int j = primes.back() + 1; j < 1000000; ++j)
        lb[j] = primes.size();
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        string s;
        cin >> s;
        n = s.size();
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        res = 0;
        cur.assign(n, 0);
        for (int i = 1; i < n; ++i)
            cur[i] += pw10[n - 1] * (s[i] - '0');
        if (n == 2) {
            cout << lb[cur[1] + 10] - lb[cur[1]] << endl;
            continue;
        }
 //       cerr << cur[1] << endl;
        rec(1);
        cout << res << endl;
    }
    return 0;
}