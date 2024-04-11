#include <bits/stdc++.h>

std::vector<int> edge[110000];
std::vector<std::pair<int, int>> ans;

void dfs(int n, int t, int f) {
    int tot;
    if (f == -1) {
        tot = edge[n].size();
    } else {
        tot = edge[n].size() - 1;
    }
    int l = 0, r = 0;
    if (t - 1 <= tot) {
        l = tot - (t - 1);
    } else {
        r = (t - 1) - tot;
    }
    int cnt = t, status = 0;
    ans.push_back(std::make_pair(n, t));
    for (int e : edge[n]) {
        if (e != f) {
            if (cnt == t + l && status == 0) {
                ans.push_back(std::make_pair(n, r));
                cnt = r; status = 1;
            }
            dfs(e, cnt + 1, n);
            ans.push_back(std::make_pair(n, cnt + 1));
            ++cnt;
        }
    }
    if (cnt == t + l && status == 0) {
        ans.push_back(std::make_pair(n, r));
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0, -1);
    printf("%d\n", (int) ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
}