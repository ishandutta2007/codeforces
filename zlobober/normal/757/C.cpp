#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <map>
using namespace std;

const int N = 1000500;

typedef unsigned long long hsh;

hsh myrand() {
    hsh res = 0;
    for (int i = 0; i < 4; i++)
        res <<= 15, res ^= rand();
    return res;
}

const int MOD = 1000 * 1000 * 1000 + 7;

typedef long long llong;

inline int mul(int a, int b) {
    return ((llong)a) * b % MOD;
}

llong fact(int k) {
    llong ans = 1;
    for (int i = 1; i <= k; i++)
        ans = mul(ans, i);
    return ans;
}

hsh H[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        map<int, int> cnt;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        map<int, hsh> cnts;
        for (const auto& pr : cnt)
            cnts[pr.second] = myrand();
        for (const auto& pr : cnt) {
            auto it = cnts.find(pr.second);
            assert(it != cnts.end());
            H[pr.first] ^= it->second;
        }
    }
    map<hsh, int> byH;
    for (int i = 1; i <= m; i++) {
        byH[H[i]]++;
    }
    int ans = 1;
    for (const auto& pr : byH) {
        ans = mul(ans, fact(pr.second));
    }
    printf("%d\n", ans);
}