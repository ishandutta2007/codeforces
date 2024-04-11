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

int main() {
    vi erat(1e7+3, 0);
    for (int i = 0; i < erat.size(); ++i)
        erat[i] = i;
    erat[0] = erat[1] = 1;
    for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i) {
        for (int j = i * i; j < erat.size(); j += i)
            erat[j] = i;
    }
    int a, n;
    cin >> a >> n;
    ll ans = 0;
    for (int i = a; i < a + n; ++i) {
        int sq = 1, cur = i;
        while (cur > 1) {
            int p = erat[cur], mul = 1, k = 0;
            while (cur % p == 0) {
                cur /= p;
                mul *= p;
                ++k;
            }
            if (k % 2)
                mul /= p;
            sq *= mul;
        }
        ans += i / sq;
    }
    cout << ans << endl;
    return 0;
}