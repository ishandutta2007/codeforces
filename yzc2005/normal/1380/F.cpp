#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int mod = 998244353;

int n, m;
char s[N];
#define mid (l + r >> 1)
#define ls p << 1
#define rs p << 1 | 1
int t[N << 2][2][2];
void pushup(int p) {
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      t[p][i][j] = (1ll * t[ls][i][0] * t[rs][0][j] + 1ll * t[ls][i][1] * t[rs][1][j]) % mod; 
}
void work(int p, int x) {
  t[p][0][0] = s[x] + 1;
  t[p][0][1] = 1;
  if (s[x - 1] == 1) t[p][1][0] = 9 - s[x];
  else t[p][1][0] = 0; 
} 
void build(int p, int l, int r) {
  if(l == r) return work(p, l);
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(p);
}
void update(int p, int l, int r, int x) {
  if(l == r) return work(p, l);
  if(mid >= x) update(ls, l, mid, x);
  else update(rs, mid + 1, r, x);
  pushup(p);
}

int main() {
  scanf("%d%d%s", &n, &m, s + 1);
  for (int i = 1; i <= n; ++i) s[i] -= '0';
  build(1, 1, n);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    s[x] = y;
    if(x != n) update(1, 1, n, x + 1);
    update(1, 1, n, x);
    printf("%d\n", t[1][0][0]);
  }
}