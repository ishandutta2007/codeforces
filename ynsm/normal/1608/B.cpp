#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int k, c[N];
int n, a, b;

void solve() {
  k = 0;
  scanf("%d%d%d", &n, &a, &b);
  swap(a, b);
  if (a == b + 1) {
    if (a + b > n - 2) {
      printf("-1\n");
      return;
    }
    int l = 1, r = n;
    for (int i = 0; i < a; i++) {
      c[k++] = r--;
      c[k++] = l++;
    }
    while (l <= r)
      c[k++] = l++;
    for (int i = 0; i < k; i++)
      printf("%d ", c[i]);
    printf("\n");
    return;
  }
  if (a == b - 1) {
    if (a + b > n - 2) {
      printf("-1\n");
      return;
    }
    int l = 1, r = n;
    for (int i = 0; i < b; i++) {
      c[k++] = l++;
      c[k++] = r--;
    }
    while (l <= r)
      c[k++] = r--;
    for (int i = 0; i < k; i++)
      printf("%d ", c[i]);
    printf("\n");
    return;
  }
  if(a == b){
    if (a + b > n - 2) {
      printf("-1\n");
      return;
    }
    int l = 1, r = n;
    for (int i = 0; i < b; i++) {
      c[k++] = r--;
      c[k++] = l++;
    }
    while (l <= r)
      c[k++] = r--;
    for (int i = 0; i < k; i++)
      printf("%d ", c[i]);
    printf("\n");
    return;
  }
  printf("-1\n");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}