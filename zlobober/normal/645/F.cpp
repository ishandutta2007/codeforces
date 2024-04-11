#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1000500;
vector<int> divs[N];

int cnk[N];

int F[N];
int iF[N];

int k;

const int MOD = 1000 * 1000 * 1000 + 7;

inline int add(int a, int b) {
    int s = a + b;
    if (s >= MOD)
        s -= MOD;
    return s;
}

inline int sub(int a, int b) {
    int s = a - b;
    if (s < 0)
        s += MOD;
    return s;
}

inline int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

int powmod(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1)
            res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

int inv(int x) {
    return powmod(x, MOD - 2);
}

bool is_square[N];
int mob[N];
int coef[N];

int mymod(int x) {
    if (x < 0)
        x += MOD;
    return x;
}

void init() {
    for (int x = 1; x < N; x++) {
        for (int y = x; y < N; y += x) {
            divs[y].push_back(x);
        }
    }
    F[0] = 1;
    iF[0] = 1;
    for (int i = 1; i < N; i++) {
        F[i] = mul(F[i - 1], i);
        iF[i] = inv(F[i]);
    }
    for (int i = k; i < N; i++) {
        cnk[i] = mul(F[i], iF[k]);
        cnk[i] = mul(cnk[i], iF[i - k]);
    }
    for (int i = 0; i * i < N; i++)
        is_square[i * i] = true;
    for (int i = 1; i < N; i++) {
        mob[i] = 1;
        for (int d : divs[i]) {
            if (d != 1 && is_square[d])
                mob[i] = 0;
        }
        if (mob[i] == 0)
            continue;
        assert(!divs[i].empty() && (divs[i].size() & (divs[i].size() - 1)) == 0);
        mob[i] = 1 - 2 * (__builtin_popcount((divs[i].size() - 1)) % 2);
    }
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            coef[j] = add(coef[j], mymod(mob[j / i] * i));
        }
    }

    eprintf("init finished\n");
}

int vec[N];
int cnt[N];

int cur = 0;
void add(int x) {
    for (int y : divs[x]) {
        cur = sub(cur, mul(coef[y], vec[y]));
        cnt[y]++;
        vec[y] = cnk[cnt[y]];
        cur = add(cur, mul(coef[y], vec[y]));
    }
}

int main() {
    int n, q;
    scanf("%d %d %d", &n, &k, &q);
    init();
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        add(a);
    }
    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);
        add(a);
        cur = cur % MOD + MOD;
        cur %= MOD;
        printf("%d\n", cur);
    }
    return 0;
}