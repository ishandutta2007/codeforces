#include <bits/stdc++.h>
using namespace std;
const int N = 666666, K = 10;
int n, a[N], b[N], x = -1e9, y = -1e9, A, B;
char s[N];
inline bool check(int mid) {
  int la = a[n] + 1, ra = 0, lb = b[n] + 1, rb = 0;
  for (int i = 0; i <= a[n]; ++i) {
    if (max(i - a[1], a[n] - i) <= mid) {
      la = min(la, i);
      ra = max(ra, i);
    }
  }
  for (int i = 0; i <= b[n]; ++i) {
    if (max(i - b[1], b[n] - i) <= mid) {
      lb = min(lb, i);
      rb = max(rb, i);
    }
  }
  if (la > ra && lb > rb) {
    return false;
  }
  if (la == ra && la == 0 && lb == rb && lb == 0) {
    return false;
  }
  for (int i = la - rb; i <= ra - lb; ++i) {
    if (i + x <= mid && -i + y <= mid) {
      if (i <= ra - rb) {        
        A = la + (i - (la - rb));
        B = rb;
      } else {
        A = ra; 
        B = rb - (i - (ra - rb));
      }
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int j = 1; j <= len; ++j) {
      a[i] += s[j] == 'B';
      b[i] += s[j] == 'N';
    }
    x = max(x, b[i] - a[i]);
    y = max(y, a[i] - b[i]);
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int l = 0, r = 1e9, ans;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= A; ++i) {
    printf("B");
  }
  for (int i = 1; i <= B; ++i) {
    printf("N");
  }
  return 0;
}