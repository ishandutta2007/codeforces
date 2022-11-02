#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int n, nex[N][2], f[N], ans, st, ed, d[N], id[N];

char s[N];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    st = 1, ed = n;

    while (st <= n && s[st] == '0') {
        st++;
    }

    while (ed && s[ed] == '0') {
        ed--;
    }

    if (st > ed) {
        printf("%d\n", n);
        exit(0);
    }

    for (int i = ed; i >= st; i--) {
        nex[i][1] = s[i + 1] == '1' ? i + 1 : nex[i + 1][1];
    }   

    for (int i = st; i <= ed; i++) {
        if (s[i] == '0') {
            d[i] = s[i - 1] == '0' ? d[i - 1] + 1 : 1;
        }
    }

    for (int i = ed; i; i--) {
        nex[i][0] = id[d[i] + 1];
        id[d[i]] = i; 
    }

    f[st] = 1;

    for (int i = st; i <= ed; i++) {
        for (int j = 0; j < 2; j++) {
            if (nex[i][j]) {
                f[nex[i][j]] = (f[nex[i][j]] + f[i])%mod;
            }
        }

        if (s[i] == '1') {
            ans = (ans + f[i])%mod;
        }
    }

    ans = 1ll*st*ans%mod*(n - ed + 1)%mod;

    printf("%d\n", (ans%mod + mod)%mod);
}