# include <bits/stdc++.h>
using namespace std;
int cou(const vector <int> & r, int sum) {
  int ans = 0;
  for (int i = r.size() - 1; i >= 0; --i) {
    if (sum <= 0) {
      return ans;
    }
    sum -= r[i];
    ans++;
  }
  if (sum <= 0)
    return ans;
  else return 1e7;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector <int> gaps;
  int g = 0;
  bool seen = false;
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    if (t >= 0) {
      if (!seen)
        k++;
      else
        g++;
    }
    else {
      seen = true;
      gaps.push_back(g);
      g = 0;
    }
  }
  sort(gaps.begin(), gaps.end());
  int a = gaps.empty() ? 0 : min(2 * cou(gaps, n - k) + 1, 2 * cou(gaps, n - k - g) + 2);
  if (a > 1e7)
    printf("-1\n");
  else
    printf("%d\n", a);
}