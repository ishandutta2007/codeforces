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

char s[100005], res1[100005], res2[100005];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    vi d1(10);
    for (int i = 0; i < n; ++i)
        d1[s[i] - '0']++;
    vi d2 = d1;
    int it = 0;
    res1[n] = res2[n] = '\0';
    int best = 1, bestzer = 0, ma = 0;
    for (int i = 1; i <= 5; ++i) if (d1[i] && d2[(10 - i) % 10]) {
        --d1[i]; --d2[(10 - i) % 10];
        int cnt = 1;
        for (int j = 0; j < 10; ++j)
            cnt += min(d1[j], d2[9 - j]);
        cnt += min(d1[0] - min(d1[0], d2[9]), d2[0] - min(d2[0], d1[9]));
        if (cnt > ma) {
            ma = cnt;
            best = i;
            bestzer = min(d1[0] - min(d1[0], d2[9]), d2[0] - min(d2[0], d1[9]));
        }
        ++d1[i]; ++d2[(10 - i) % 10];
    }
    bool ok = 0;
    for (; it < bestzer; ++it) {
        res1[n - 1 - it] = res2[n - 1 - it] = '0';
        --d1[0]; --d2[0];
    }
    for (int i = 0; i <= 5; ++i) if (d1[i] && d2[(10 - i) % 10] && i == best) {
        res1[n - 1 - it] = '0' + i;
        res2[n - 1 - it] = '0' + (10 - i) % 10;
        d1[i]--; d2[(10 - i) % 10]--;
        ok = 1;
        ++it;
        break;
    }
    if (ok) {
        for (int i = 0; i < 10; ++i) {
            while (d1[i] && d2[9 - i]) {
                res1[n - 1 - it] = '0' + i;
                res2[n - 1 - it] = '0' + 9 - i;
                d1[i]--; d2[9 - i]--;
                ++it;
            }
        }
    }
    int it2 = it;
    for (int i = 0; i < 10; ++i) {
        while (d1[i]) {
            res1[n - 1 - it] = '0' + i;
            d1[i]--;
            ++it;
        }
    }
    for (int i = 0; i < 10; ++i) {
        while (d2[i]) {
            res2[n - 1 - it2] = '0' + i;
            d2[i]--;
            ++it2;
        }
    }
    printf("%s\n%s\n", res1, res2);
    return 0;
}