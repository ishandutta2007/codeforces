// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 10005;
int n, q;
#define ls (u << 1)
#define rs (u << 1 | 1)
vector <int> adj[N << 2];
void update(int u, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    adj[u].push_back(x);
    return ;
  }
  int mid = l + r >> 1;
  if (ql <= mid) update(ls, l, mid, ql, qr, x);
  if (qr > mid) update(rs, mid + 1, r, ql, qr, x);
}
bitset <N> ans(0); 
void dfs(int u, int l, int r, bitset <N> A) {
  for (auto v: adj[u]) A |= A << v;
  if (l == r) {
    ans |= A;
    return ; 
  } 
  int mid = l + r >> 1;
  dfs(ls, l, mid, A);
  dfs(rs, mid + 1, r, A);
}

int main() {
  scanf("%d%d", &n, &q);
  for (rint i = 1; i <= q; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    update(1, 1, n, l, r, x);
  }
  bitset <N> C(1);
  dfs(1, 1, n, C);
  
  vector <int> rans;
  int cnt = 0;
  for (rint i = 1; i <= n; i++) {
    if (ans[i]) {
      cnt++;
      rans.push_back(i);
    }
  }
  printf("%d\n", cnt);
  for (auto v: rans) {
    printf("%d ", v);
  }
  puts("");
}