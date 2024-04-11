#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, K = 30;
int n, q;
multiset<int> nums[K];
long long sum[N]; 

int main() {
  cin >> q;
  while (q--) {
    int x;
    char c;
    cin >> c >> x;
    int p = 31 - __builtin_clz(x);
    if (c == '+') {
      ++n;
      nums[p].insert(x);
      sum[p] += x;
    } else {
      --n;
      nums[p].erase(nums[p].find(x));
      sum[p] -= x;
    }
    int ans = n;
    long long cur = 0;
    for (int i = 0; i < K; ++i) {
      if (nums[i].empty()) {
        continue;
      }
      int x = *nums[i].begin();
      if (cur * 2 < x) {
        --ans;
      }
      cur += sum[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}