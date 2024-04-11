#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 4000000 + 10;
const int MOD = 51123987;

int u[MAXN], F[MAXN], N;
char S[MAXN];

//snu[]
//u[i]i/2
//babbaab.a.b.b.a.a
//u[]{1, 0, 3, 0, 1, 4, 1, 0, 1, 2, 1}
void manacher(const char *s, int u[], int n) {
	for (int i = 0; i < 2 * n; ++ i) u[i] = 0;
	for (int i = 0, j = 0, k; i < 2 * n; i += k, j = max(j - k, 0)) {
		while (i >= j && i + j + 1 < 2 * N && s[(i - j) >> 1] == s[(i + j + 1) >> 1]) ++ j;
		u[i] = j;
		for (k = 1; i >= k && u[i] >= k && u[i - k] != u[i] - k; ++ k) {
			u[i + k] = min(u[i - k], u[i] - k);
		}
	}
}

int main() {
    scanf("%d%s", &N, S);
    manacher(S, u, N);
    for (int i = 0, R; i < N; ++ i) {
        //center is s[i]
        R = u[i * 2] / 2;
        ++ F[i - R]; -- F[i + 1];
        //center is s[i], s[i + 1]
        R = u[i * 2 + 1] / 2;
        ++ F[i - R + 1]; -- F[i + 1];
    }
    for (int i = 1; i < N; ++ i) F[i] += F[i - 1];
    int ret = 0;
    for (int i = N - 1; i >= 0; -- i) {
        ret += ((LL)F[i] * (F[i] - 1) / 2) % MOD;;
        F[i] += F[i + 1];
        if (F[i] >= MOD) F[i] -= MOD;
        if (ret >= MOD) ret -= MOD;
    }
    for (int i = N - 1; i >= 0; -- i) {
        F[i] += F[i + 1];
        if (F[i] >= MOD) F[i] -= MOD;
    }
    for (int i = 0, d, l, r; i < N; ++ i) {
        //center is s[i]
        d = u[i * 2] / 2;
        if (d) {
            ret += F[i - d + 1] - F[i + 1] + MOD;
            ret -= F[i + 2] - F[i + d + 2] + MOD;
            ret %= MOD;
            if (ret < 0) ret += MOD;
            /*l = i - d + 1, r = i + d + 1;
            if (l <= r) ret += F[l] - F[r] + MOD;
            ret %= MOD;*/
        }
        //center is s[i], s[i + 1]
        d = u[i * 2 + 1] / 2;
        if (d) {
            ret += F[i - d + 2] - F[i + 2] + MOD;
            ret -= F[i + 2] - F[i + d + 2] + MOD;
            ret %= MOD;
            if (ret < 0) ret += MOD;
            /*l = i - d + 2, r = i + d + 1;
            if (l <= r) ret += F[l] - F[r] + MOD;
            ret %= MOD;*/
        }
    }
    printf("%d\n", ret);
    return 0;
}