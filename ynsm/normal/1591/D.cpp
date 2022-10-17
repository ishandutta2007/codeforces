#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], b[N];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  int ans = 0;
  sort(b + 1, b + 1 + n);
  for (int i = 2; i <= n; i++)
    if (b[i] == b[i - 1]) {
      printf("YES\n");
      return;
    }
  for (int i = 1; i <= n; i++) {
    if (a[i] <= n)
      ans++;
    for (int j = i; a[j] <= n; j = a[j] - n)
      ans++, a[j] += n;
  }
  if (ans & 1)
    printf("NO\n");
  else
    printf("YES\n");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}