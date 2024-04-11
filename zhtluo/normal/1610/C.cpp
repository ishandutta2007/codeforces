#include <bits/stdc++.h>

int N;
int people[210000][2];

bool valid(int m) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (people[i][1] >= cnt && people[i][0] + cnt + 1 >= m)
            ++cnt;
    }
    return cnt >= m;
}

int main() {
    int T; scanf("%d", &T); while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            int a, b; scanf("%d%d", &a, &b);
            people[i][0] = a;
            people[i][1] = b;
        }
        int ans = 0, l = 0, r = N;
        while (l <= r) {
            int m = (l + r) / 2;
            if (valid(m)) {
                ans = m, l = m + 1;
            } else {
                r = m - 1;
            }
        }
        printf("%d\n", ans);
    }
}