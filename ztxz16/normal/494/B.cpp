#include <cstdio>
#include <cstring>
#define N_Max 123456
#define MOD 1000000007
#define LL long long

using namespace std;

char s[N_Max], t[N_Max];
int f[N_Max];
LL dp[N_Max], sum[N_Max];

void init() {
    scanf("%s", s);
    scanf("%s", t);
}

void getfail() {
    int m = strlen(t);
    f[0] = 0;
    f[1] = 0;

    for (int i = 1; i < m; i++) {
        int j = f[i];

        while (j>1 && t[i] != t[j])  j = f[j];
        f[i+1] = (t[i] == t[j] ? j+1: j);
    }
}

void solve() {
    getfail();

    int j = 0, maxj = 0, n = strlen(s), m = strlen(t);
    dp[0] = 1;
    sum[0] = 1;

    for (int i = 0; i < n; i++) {
        while (j && s[i] != t[j]) j = f[j];
        if (s[i] == t[j])  j++;
        if (j == m) {
            maxj = i-m+2;
            j = f[j];
        }

        dp[i+1] += dp[i] + (maxj ? sum[maxj-1]:0);
        if (dp[i+1] > MOD)  dp[i+1] -= MOD;

        sum[i+1] = sum[i]+dp[i+1];
        if (sum[i+1] > MOD) sum[i+1] -= MOD;
    }
    
    printf("%I64d\n", (((dp[n]-1)%MOD+MOD)%MOD));
}

int main() {
    init();
    solve();
}