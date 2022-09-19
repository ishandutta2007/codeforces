# include <bits/stdc++.h>
using namespace std;
pair <int, int> a[1010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].second, &a[i].first);
    if (a[i].first < a[i].second)
      swap(a[i].first, a[i].second);
  }
  sort(a, a + n);
  vector <int> ans;
  int last = INT_MIN;
  for (int i = 0; i < n; ++i)
    if (a[i].second > last) {
      ans.push_back(a[i].first);
      last = a[i].first;
    }
  printf("%d\n", (int)ans.size());
  for (int c : ans)
    printf("%d ", c);
  printf("\n");
}