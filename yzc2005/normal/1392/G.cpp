#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 1000005, K = 21;
int n, m, k, a[N], b[N];
char s[K], t[K];
int pos[K], rev[K];
int lef[1 << K], rig[1 << K], len[1 << K];
int main() {
  read(n), read(m), read(k);
  scanf("%s%s", s, t);
  int res = k;
  for (int i = 0; i < k; ++i) {
    s[i] -= '0';
    t[i] -= '0';
    res -= s[i] + t[i];
  }
  for (int i = 1; i <= n; ++i) {
    read(a[i]), read(b[i]);
    --a[i];
    --b[i];
  }
  memset(lef, 0x3f, sizeof(lef));
  auto work = [&](char *s, bool tp) {
    for (int i = 0; i < k; ++i) {
      pos[i] = i;
    }
    for (int i = 0; i <= n; ++i) {
      for (int i = 0; i < k; ++i) {
        rev[pos[i]] = i;
      }
      auto get = [&](char *s) {
        int x = 0;
        for (int i = 0; i < k; ++i) {
          (x <<= 1) |= s[rev[i]];
        }
        return x;
      };
      if (!tp) {
        lef[get(s)] = min(lef[get(s)], i);
      } else {
        rig[get(s)] = i;
      }
      swap(pos[a[i + 1]], pos[b[i + 1]]);
    }
  }; 
  work(s, 0);
  work(t, 1);
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < 1 << k; ++j) {
      if (j >> i & 1) {
        lef[j ^ (1 << i)] = min(lef[j ^ (1 << i)], lef[j]);
        rig[j ^ (1 << i)] = max(rig[j ^ (1 << i)], rig[j]);
      }
    }
  }
  for (int i = 0; i < 1 << k; ++i) {
    len[i] = len[i >> 1] + (i & 1);
    if (lef[i] + m <= rig[i]) {
      if (len[ans] < len[i]) {
        ans = i;
      }
    }
  }
  printf("%d\n%d %d\n", len[ans] * 2 + res, lef[ans] + 1, rig[ans]);
  return 0;
}