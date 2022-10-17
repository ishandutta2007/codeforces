#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int n, k, a[maxn];
vector<int> ans;

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);

  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += a[i];
  if (sum % k != 0) {
    puts("No");
    return 0;
  }
  sum /= k;

  int x = 0, pre = 0;
  for (int i = 1; i <= n; ++i) {
    x += a[i];
    if (x > sum) {
      puts("No");
      return 0;
    }
    if (x == sum) {
      ans.push_back(i - pre);
      x = 0, pre = i;
    }
  }
  puts("Yes");
  for (int i = 1; i <= k; ++i)
    printf("%d ", ans[i - 1]);

  return 0;
}