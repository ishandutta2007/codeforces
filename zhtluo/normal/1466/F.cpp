#include <bits/stdc++.h>

const long long MOD = 1E9 + 7;

int N, M;
std::vector<std::pair<int, int>> pq;
int anc[510000];
int inf[510000];
std::vector<int> ans;

int find(int x) {
    if (x == anc[x]) return x;
    return anc[x] = find(anc[x]);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0, k, u, v; i < N; ++i) {
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d", &u);
            pq.push_back(std::make_pair(u, u));
        } else {
            scanf("%d%d", &u, &v);
            pq.push_back(std::make_pair(u, v));
        }
    }
    for (int i = 0; i <= M; ++i) anc[i] = i, inf[i] = -1;
    for (int i = 0; i < N; ++i) {
        int x = pq[i].first, y = pq[i].second;
        int fx = find(x), fy = find(y);
        if (inf[fx] >= 0 && inf[fy] >= 0) continue;
        if (fx != fy) {
            ans.push_back(i);
            anc[fx] = fy;
            inf[fy] = std::max(inf[fx], inf[fy]);
        } else {
            if (inf[fx] < 0 && x == y) {
                ans.push_back(i);
                inf[fx] = i;
            }
        }
    }
    long long res = 1;
    for (int i = 0; i < ans.size(); ++i) res = res * 2 % MOD;
    printf("%d %d\n", (int) res, (int) ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i] + 1, " \n"[i + 1 == ans.size()]);
}