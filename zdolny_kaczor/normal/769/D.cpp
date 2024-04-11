# include <bits/stdc++.h>
using namespace std;
const int MN = 1 << 14;
long long cou[MN];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector <int> poss;
  for (int i = 0; i < MN; ++i)
    if (__builtin_popcount(i) == k)
      poss.push_back(i);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    cou[x]++;
  }
  long long ans = 0;
  for (int i = 0; i < MN; ++i) {
    for (auto c : poss)
      ans += cou[i] * cou[i ^ c];
  }
  if (k == 0)
    ans -= n;
  ans /= 2;
  printf("%lld\n", ans);
}