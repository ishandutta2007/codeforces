#include <bits/stdc++.h>

int T, N;
long long W;
long long w[2100000];
int ord[2100000];

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  scanf("%d", &T);
  while (T--) {
    scanf("%d%lld", &N, &W);
    for (int i = 0; i < N; ++i) scanf("%lld", &w[i]), ord[i] = i;
    std::sort(ord, ord + N, [&](int a, int b) { return w[a] > w[b]; });
    long long sum = 0; std::vector<int> ans;
    for (int i = 0; i < N && sum < (W + 1) / 2; ++i) if (sum + w[ord[i]] <= W) {
      sum += w[ord[i]]; ans.push_back(ord[i]);
    }
    if (sum < (W + 1) / 2) puts ("-1");
    else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < (int)ans.size(); ++i) printf("%d%c", ans[i] + 1, " \n"[i + 1 == N]);
    }
  }
}