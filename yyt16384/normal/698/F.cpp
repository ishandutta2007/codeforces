#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1000005;
const int MAXP = 80005;
const int MOD = 1000000007;

struct InState {
    int n;
    int a[MAXN];
};

struct OutState {
    int ans;
};

InState in;
OutState out;

void input()
{
    scanf("%d", &in.n);
    for (int i = 1; i <= in.n; i++) {
        scanf("%d", &in.a[i]);
    }
}

void solve()
{
    static bool flag[MAXN];
    static int minpf[MAXN];
    static int minpfpw[MAXN];
    static int primes[MAXP];
    int primen = 0;
    memset(flag + 1, 0, in.n * sizeof(*flag));
    minpf[1] = 1;
    minpfpw[1] = 1;
    for (int i = 2; i <= in.n; i++) {
        if (!flag[i]) {
            minpf[i] = i;
            minpfpw[i] = i;
            primes[primen++] = i;
        }
        for (int j = 0; j < primen && i * primes[j] <= in.n; j++) {
            flag[i * primes[j]] = true;
            minpf[i * primes[j]] = primes[j];
            if (i % primes[j]) {
                minpfpw[i * primes[j]] = primes[j];
            } else {
                minpfpw[i * primes[j]] = primes[j] * minpfpw[i];
                break;
            }
        }
    }
    static int rad[MAXN];
    rad[1] = 1;
    for (int i = 2; i <= in.n; i++) {
        rad[i] = rad[i / minpfpw[i]] * minpf[i];
    }
    static int maxpf[MAXN];
    maxpf[1] = 1;
    for (int i = 2; i <= in.n; i++) {
        if (minpfpw[i] == i) {
            maxpf[i] = minpf[i];
        } else {
            maxpf[i] = maxpf[i / minpfpw[i]];
        }
    }
    static int w[MAXN];
    w[1] = 1;
    for (int i = 0, p = 1; i < primen; i++) {
        if (in.n / primes[i] != in.n / p) {
            p = primes[i];
        }
        w[primes[i]] = 2 * p > in.n ? 1 : p;
    }
    for (int i = 2; i <= in.n; i++) {
        if (flag[i]) {
            w[i] = w[i / minpfpw[i]] * w[minpf[i]];
        }
    }
    static int pos[MAXN];
    static int invpos[MAXN];
    memset(pos + 1, 0, in.n * sizeof(*pos));
    memset(invpos + 1, 0, in.n * sizeof(*invpos));
    for (int i = 1; i <= in.n; i++) {
        if (!in.a[i]) {
            continue;
        }
        if (w[in.a[i]] != w[i]) {
            out.ans = 0;
            return;
        }
        int u = maxpf[i];
        int v = maxpf[in.a[i]];
        if (pos[u] && pos[u] != v) {
            out.ans = 0;
            return;
        }
        pos[u] = v;
        if (invpos[v] && invpos[v] != u) {
            out.ans = 0;
            return;
        }
        invpos[v] = u;
    }
    static int cnt1[MAXN];
    memset(cnt1 + 1, 0, in.n * sizeof(*cnt1));
    for (int i = 1; i <= in.n; i++) {
        if (!in.a[i]) {
            cnt1[rad[i]]++;
        }
    }
    static int cnt2[MAXN];
    memset(cnt2 + 1, 0, in.n * sizeof(*cnt2));
    for (int i = 1; i <= in.n; i++) {
        if (!flag[i] && !pos[i]) {
            cnt2[w[i]]++;
        }
    }
    static int fac[MAXN];
    fac[0] = 1;
    for (int i = 1; i <= in.n; i++) {
        fac[i] = (long long)fac[i - 1] * i % MOD;
    }
    int ans = 1;
    for (int i = 1; i <= in.n; i++) {
        ans = (long long)ans * fac[cnt1[i]] % MOD;
        ans = (long long)ans * fac[cnt2[i]] % MOD;
    }
    out.ans = ans;
}

void output()
{
    printf("%d\n", out.ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("698F.in", "r", stdin);
    freopen("698F.out", "w", stdout);
#endif

    input();
    solve();
    output();

#ifndef ONLINE_JUDGE
    fclose(stdin); fclose(stdout);
#endif
    return 0;
}