#include <bits/stdc++.h>

int T;
int N, M, K;
std::unordered_set<int> edge[210000];
int deg[210000];
std::queue<int> qu;

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      edge[u].insert(v);
      edge[v].insert(u);
    }
    for (int i = 1; i <= N; ++i) {
      deg[i] = (int)edge[i].size();
      if (deg[i] < K) qu.push(i);
    }
    while (!qu.empty()) {
      int i = qu.front(); qu.pop();
      if (deg[i] == K - 1) {
        static std::vector<int> vec;
        vec.push_back(i);
        for (int e: edge[i]) if (deg[e] >= K - 1) vec.push_back(e);
        if ((int) vec.size () == K) {
          int flag = 1;
          for (int u = 0; u < (int)vec.size() && flag; ++u)
            for (int v = u + 1; v < (int)vec.size() && flag; ++v) {
              if (edge[vec[u]].find(vec[v]) == edge[vec[u]].end()) {
                flag = 0;
              }
            }
          if (flag) {
            puts ("2");
            for (int u: vec) printf("%d ", u);
            puts("");
            vec.clear();
            goto end;
          }
        }
        vec.clear();
      }
      for (int e: edge[i]) {
        edge[e].erase(i);
        if (--deg[e] == K - 1) qu.push(e);
      }
      deg[i] = 0; edge[i].clear();
    }
    static std::vector <int> ans;
    for (int i = 1; i <= N; ++i) if (deg[i] >= K) ans.push_back(i);
    if (!ans.empty()) {
      printf ("1 %d\n", (int)ans.size());
      for (int i: ans) printf("%d ", i);
      puts("");
    } else
      puts("-1");
    ans.clear();
end:;
    while (!qu.empty()) qu.pop();
    for (int i = 1; i <= N; ++i) edge[i].clear();
  }
}