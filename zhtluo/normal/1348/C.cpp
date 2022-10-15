#include <bits/stdc++.h>

char str[110000];
int cnt[30], f[30];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, K;
        scanf("%d%d", &N, &K);
        scanf(" %s", str);
        std::sort(str, str + N);
        std::fill(cnt, cnt + 26, 0);
        for (int i = 0; i < N; ++i) ++cnt[str[i] - 'a'];
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            sum += cnt[i];
            if (sum < K) continue;
            printf("%c", i + 'a');
            if (sum - cnt[i] > 0) {
                break;
            }
            cnt[i] -= K;
            int tp = 0, ttp = 0, tsum = 0;
            for (int j = 0; j < 26; ++j) {
                tp += (cnt[j] > 0);
                if (cnt[j] > 0) ttp = j, tsum = cnt[j];
            }
            if (tp == 1) {
                for (int j = 0; j < (tsum + K - 1) / K; ++j)
                    printf("%c", ttp + 'a');
            } else {
                for (int j = 0; j < 26; ++j)
                    for (int k = 0; k < cnt[j]; ++k)
                        printf("%c", j + 'a');
            }
            break;
        }
        puts("");
    }
    return 0;
}