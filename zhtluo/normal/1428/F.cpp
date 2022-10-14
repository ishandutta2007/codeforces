#include <bits/stdc++.h>

int N;
char S[510000];
std::vector<std::pair<int, int>> loc;
std::vector<int> trak;
long long loss[510000];

int main() {
    scanf("%d %s", &N, S);
    loc.push_back(std::make_pair (-1, 0));
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (loc.back().first == -1)
                loc.back().first = i;
            loc.back().second++;
        } else {
            if (loc.back().first != -1)
                loc.push_back(std::make_pair (-1, 0));
        }
    }
    if (loc.back().first == -1) loc.pop_back();
    if (loc.empty()) {
        puts("0");
        return 0;
    }
    long long ans = 0, init = 0;
    {
        int cur = 0, curcur = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i] == '1') {
                ++curcur;
                cur = std::max(cur, curcur);
                init += cur;
            } else {
                curcur = 0;
                cur = std::max(cur, curcur);
                init += cur;
            }
        }
    }
    int nextind = loc.size() - 1;
    for (int i = N - 1; i >= 0; ) {
        if (S[i] == '0') {
            loss[i] = 0;
            --i;
        } else {
            for (int j = 0, k = (int) trak.size() - 1; j < loc[nextind].second; ++j) {
                while (k >= 0 && loc[trak[k]].second < j + 1) --k;
                // printf(":: %d\n", k);
                // if (k >= 0) printf(":: %d\n", loc[trak[k]].second);
                if (k < 0) {
                    loss[i - j] = N - 1 - (i - j) + 1;// + (j + 1);
                    // printf(": %d %d %d\n", N, i, j);
                } else {
                    loss[i - j] = loc[trak[k]].first + j - 1 - (i - j) + 1;// + loc[trak[0]].second;
                }
            }
            i -= loc[nextind].second;
            while (!trak.empty() && loc[trak.back()].second <= loc[nextind].second) trak.pop_back();
            trak.push_back(nextind);
            --nextind;
        }
    }
    // printf("%lld\n", init);
    // for (int i = 0; i < N; ++i)
    //     printf("%lld\n", loss[i]);
    for (int i = 0; i < N; ++i) {
        ans += init;
        init = init - loss[i];
    }
    printf("%lld\n", ans);
}