# include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> cou;
int get(int x) {
  auto it = cou.find(x);
  if (it == cou.end())
    return 0;
  return it->second;
}
char in[1000010];
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", in);
    int mask = 0;
    for (int j = 0; in[j]; ++j)
      mask ^= 1 << (in[j] - 'a');
    ans += get(mask);
    for (int b = 0; b < 26; ++b)
      ans += get(mask ^ (1 << b));
    cou[mask]++;
  }
  printf("%lld\n", ans);
}