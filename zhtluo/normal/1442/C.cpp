#include <bits/stdc++.h>

const long long MOD = 998244353;
const int SIZE = 26;

int N, M;
long long dij[210000][SIZE];
long long p2[210000];
std::vector<std::pair<int, int>> edge[210000];
std::priority_queue<std::pair<long long, std::pair<int, int>>> pq;

std::pair<int, long long> dij2[510000];
std::priority_queue<std::pair<std::pair<int, long long>, int>> pq2;

std::pair<int, long long> neg(std::pair<int, long long> a) {
    return std::make_pair(-a.first, -a.second);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        edge[u].push_back(std::make_pair(v, 0));
        edge[v].push_back(std::make_pair(u, 1));
    }
    for (int i = 1; i <= N; ++i) for(int j = 0; j < SIZE; ++j) dij[i][j] = MOD - 1;
    dij[1][0] = 0;
    pq.push(std::make_pair(0, std::make_pair(1, 0)));
    while (!pq.empty()) {
        long long d = -pq.top().first;
        int u = pq.top().second.first, t = pq.top().second.second;
        pq.pop();
        if (d != dij[u][t]) continue;
        for (auto &e: edge[u]) {
            if (e.second ^ (t & 1)) {
                if (t + 1 < SIZE) {
                    int nu = e.first, nt = t + 1;
                    long long nd = d + 1 + (1ll << t);
                    if (nd < dij[nu][nt]) {
                        dij[nu][nt] = nd;
                        pq.push(std::make_pair(-nd, std::make_pair(nu, nt)));
                    }
                }
            } else {
                int nu = e.first, nt = t;
                long long nd = d + 1;
                if (nd < dij[nu][nt]) {
                    dij[nu][nt] = nd;
                    pq.push(std::make_pair(-nd, std::make_pair(nu, nt)));
                }
            }
        }
    }
    long long res = MOD - 1;
    for (int i = 0; i < SIZE; ++i) res = std::min(res, dij[N][i]);
    if (res < MOD - 1) {
        printf("%lld\n", res);
        return 0;
    }
    p2[0] = 1;
    for (int i = 1; i < 210000; ++i) p2[i] = p2[i - 1] * 2 % MOD;
    for (int i = 1; i <= N; ++i) {
        if (dij[i][SIZE - 1] < MOD - 1) {
            dij2[i << 1 | 1] = std::make_pair(SIZE - 1, dij[i][SIZE - 1]);
            pq2.push(std::make_pair(neg(dij2[i << 1 | 1]), i << 1 | 1));
        } else
            dij2[i << 1 | 1] = std::make_pair(MOD - 2, 0);
        if (dij[i][SIZE - 2] < MOD - 1) {
            dij2[i << 1] = std::make_pair(SIZE - 2, dij[i][SIZE - 2]);
            pq2.push(std::make_pair(neg(dij2[i << 1]), i << 1));
        } else
            dij2[i << 1] = std::make_pair(MOD - 1, 0);
    }
    while (!pq2.empty()) {
        std::pair<int, long long> d = neg(pq2.top().first);
        int u = pq2.top().second;
        pq2.pop();
        if (d != dij2[u]) continue;
        for (auto &e: edge[u >> 1]) {
            if (e.second ^ (d.first & 1)) {
                int nu = (e.first << 1) | ((d.first & 1) ^ 1);
                std::pair<int, long long> nd = std::make_pair(d.first + 1, (d.second + p2[d.first] + 1) % MOD);
                if (nd < dij2[nu]) {
                    dij2[nu] = nd;
                    pq2.push(std::make_pair(neg(nd), nu));
                }
            } else {
                int nu = (e.first << 1) | (d.first & 1);
                std::pair<int, long long> nd = std::make_pair(d.first, (d.second + 1) % MOD);
                if (nd < dij2[nu]) {
                    dij2[nu] = nd;
                    pq2.push(std::make_pair(neg(nd), nu));
                }
            }
        }
    }
    if (dij2[N << 1].first < dij2[N << 1 | 1].first)
        printf("%lld\n", dij2[N << 1].second);
    else
        printf("%lld\n", dij2[N << 1 | 1].second);
}