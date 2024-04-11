#include <bits/stdc++.h>

char arr[10][10] = {
        "1110111",
        "0010010",
        "1011101",
        "1011011",
        "0111010",
        "1101011",
        "1101111",
        "1010010",
        "1111111",
        "1111011"
};

int val[10];
int dp[2100][2100];
int dval[2100];
char ans[2100];
char c[10];

int main() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (arr[i][j] == '1') val[i] |= 1 << j;
        }
    }
    int N, K;
    scanf("%d%d ", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s ", c);
        for (int j = 0; j < 7; ++j)
            if (c[j] == '1') dval[i] |= 1 << j;
    }
    dp[N][0] = 1;
    for (int i = N - 1; i >= 0; --i) {
        for (int t = 0; t < 10; ++t) {
            if ((val[t] & dval[i]) == dval[i]) {
                int diff = __builtin_popcount(val[t] ^ dval[i]);
                for (int j = diff; j <= K; ++j)
                    dp[i][j] |= dp[i + 1][j - diff];
            }
        }
    }
    if (dp[0][K]) {
        int cur = K;
        for (int i = 0; i < N; ++i) {
            for (int t = 9; t >= 0; --t) {
                if ((val[t] & dval[i]) == dval[i]) {
                    int diff = __builtin_popcount(val[t] ^ dval[i]);
                    if (dp[i + 1][cur - diff]) {
                        ans[i] = '0' + t;
                        cur = cur - diff;
                        break;
                    }
                }
            }
        }
        puts(ans);
    } else {
        puts("-1");
    }
}