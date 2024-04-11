#include <bits/stdc++.h>
const int N = 3e5 + 5, L = 19, K = 1e6 + 5;
int n, k, a[N], max[N][L], pos[N][L], sum[N], cnt[K];
long long ans;
inline int query(int l, int r) {
  int t = log(r - l + 1) / log(2);
  if (max[l][t] < max[r - (1 << t) + 1][t]) {
    return pos[r - (1 << t) + 1][t];
  } else {
    return pos[l][t];
  }
}
void solve(int l, int r) {
  if (l > r) {
    return;
  }
  int mid = query(l, r);
  int x = a[mid] % k;
  if (mid - l < r - mid) {
    solve(l, mid - 1);
    for (int i = l; i < mid; ++i) {
      --cnt[sum[i]];
    }
    solve(mid + 1, r);
    for (int i = l; i <= mid; ++i) {
      ans += sum[i - 1] == sum[mid - 1] && i != mid;
      ans += cnt[(sum[i - 1] + x) % k];
    }
    for (int i = l; i <= mid; ++i) {
      ++cnt[sum[i]];
    }
  } else {
    solve(mid + 1, r);
    for (int i = mid + 1; i <= r; ++i) {
      --cnt[sum[i]];
    }
    solve(l, mid - 1);
    --cnt[sum[mid - 1]];
    ++cnt[sum[l - 1]];
    for (int i = mid; i <= r; ++i) {
      ans += sum[i] == sum[mid] && i != mid;
      ans += cnt[(sum[i] - x + k) % k];
    }
    ++cnt[sum[mid - 1]];
    --cnt[sum[l - 1]];
    for (int i = mid; i <= r; ++i) {
      ++cnt[sum[i]];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    sum[i] = (sum[i - 1] + a[i]) % k; 
    max[i][0] = a[i];
    pos[i][0] = i;
  }
  for (int k = 1; k < L; ++k) {
    for (int i = 1; i <= n - (1 << k) + 1; ++i) {
      if (max[i][k - 1] < max[i + (1 << k - 1)][k - 1]) {
        max[i][k] = max[i + (1 << k - 1)][k - 1];
        pos[i][k] = pos[i + (1 << k - 1)][k - 1];
      } else {
        max[i][k] = max[i][k - 1];
        pos[i][k] = pos[i][k - 1];
      }
    }
  } 
  solve(1, n);
  std::cout << ans << "\n";
  return 0;
}