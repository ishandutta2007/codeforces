#include <bits/stdc++.h>

int N, M, K;
int C[510000], U[510000], V[510000];
std::vector<int> edge[510000];
std::vector<std::pair<int, int>> edge_n[510000];
int col[510000], block[510000], bsize = 0, fa[510000];
int fc[510000];
std::set<int> bad;
std::map<std::pair<int, int>, std::vector<int>> iter;
std::set<std::pair<int, int>> bad_pair;
std::vector<int> vec;

void dfs(int u) {
    for (auto &v: edge[u]) {
        if (!col[v] && C[v] == C[u]) {
            col[v] = -col[u];
            block[v] = block[u];
            dfs(v);
        }
    }
}

void dfsf(int u) {
    for (auto &v: edge_n[u]) {
        if (!fc[v.first]) {
            fc[v.first] = -fc[u] * v.second;
            dfsf(v.first);
        }
    }
}

std::pair<int, int> make_unpair(int a, int b) {
    return std::make_pair(std::min(a, b), std::max(a, b));
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) scanf("%d", &C[i]);
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &U[i], &V[i]);
        edge[U[i]].push_back(V[i]); edge[V[i]].push_back(U[i]);
    }
    for (int i = 1; i <= N; ++i) if (col[i] == 0) {
        col[i] = 1; block[i] = bsize; fa[bsize++] = C[i]; dfs(i);
    }
    for (int i = 1; i <= M; ++i) {
        if (block[U[i]] == block[V[i]]) {
            if (col[U[i]] == col[V[i]]) bad.insert(C[U[i]]);
        } else {
            iter[make_unpair(C[U[i]], C[V[i]])].push_back(i);
        }
    }
    int cnt = 1;
    for (auto &it: iter) {
        vec.clear();
        for (auto &e: it.second) {
            vec.push_back(block[U[e]]);
            vec.push_back(block[V[e]]);
        }
        std::sort(vec.begin(), vec.end());
        vec.resize(std::unique(vec.begin(), vec.end()) - vec.begin());
        for (auto &e: it.second) {
            int f = std::lower_bound(vec.begin(), vec.end(), block[U[e]]) - vec.begin();
            int s = std::lower_bound(vec.begin(), vec.end(), block[V[e]]) - vec.begin();
            edge_n[f].push_back(std::make_pair(s, col[U[e]] * col[V[e]]));
            edge_n[s].push_back(std::make_pair(f, col[U[e]] * col[V[e]]));
        }
        for (int i = 0; i < vec.size(); ++i) if (!fc[i]) {
            fc[i] = 1; dfsf(i);
        }
        for (auto &e: it.second) {
            int f = std::lower_bound(vec.begin(), vec.end(), block[U[e]]) - vec.begin();
            int s = std::lower_bound(vec.begin(), vec.end(), block[V[e]]) - vec.begin();
            if (fc[f] * fc[s] == col[U[e]] * col[V[e]]) {
                bad_pair.insert(it.first);
                break;
            }
        }
        std::fill(edge_n, edge_n + vec.size(), std::vector<std::pair<int, int>>());
        std::fill(fc, fc + vec.size(), 0);
    }
    long long bad_count = 0;
    for (auto &a: bad_pair) {
        if (bad.find(a.first) == bad.end() && bad.find(a.second) == bad.end())
            ++bad_count;
    }
    // printf("%d %lld\n", (int) bad.size(), bad_count);
    printf("%lld\n", 1ll * (K - bad.size()) * (K - bad.size() - 1) / 2 - bad_count);
}