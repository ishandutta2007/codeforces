#include <bits/stdc++.h>
using namespace std;

inline void up(int &x, int y) {x < y ? x = y : 0;}
inline void down(int &x, int y) {x > y ? x = y : 0;}

typedef pair<int, int> pr;
typedef long long ll;

const int N = 2e5 + 5, K = 18;
int n, m, X, a[N], b[N], lg[N], stk[N], c[N];
vector<pr> mdf[N];
pr x[N], y[N];
ll ans;

struct ST {
  int st[K][N];
  
  void build(int *a, int n) {
    for (int i = 0; i <= n; ++i) st[0][i] = a[i];
    for (int k = 1; k < K; ++k)
      for (int i = 0; i + (1 << k) - 1 <= n; ++i)
        st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  }
  
  inline int query(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
  }
} A, B;

inline void modify(int p, int x) {
  for (; p < N; p += p & -p) c[p] += x;
}
inline int query(int p) {
  if (p <= 0) return 0;
  int res = 0;
  for (; p; p -= p & -p) res += c[p];
  return res;
}
inline int query(int l, int r) {
  return query(r) - query(l - 1);
}

void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  solve(l, mid), solve(mid + 1, r);
  vector<pr> cur;
  for (int i = mid + 1; i <= r; ++i) 
    for (auto p : mdf[i]) cur.emplace_back(p);
  sort(x + l, x + mid + 1, [&](pr x, pr y) {
    return x.second < y.second;
  });
  int j = 0;
  for (int i = l; i <= mid; ++i) {
    while (j < cur.size() && x[i].second + cur[j].first > X)
      modify(cur[j++].second, 1);
    ans += query(X - x[i].first + 1, N - 1);
  }
  for (--j; ~j; --j) modify(cur[j].second, -1);
}

int main() {
  for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
  scanf("%d%d%d", &n, &m, &X);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]); 
    x[i].first = a[i], x[i].second = 1e9;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    y[i].first = b[i], y[i].second = 1e9;
  }
  a[0] = a[n + 1] = b[0] = b[m + 1] = X;
  A.build(a, n + 1), B.build(b, m + 1);
  
  int top = 0;
  for (int i = 1; i <= n; ++i) {
    while (top && a[stk[top]] > a[i]) --top;
    down(x[i].second, A.query(stk[top], i));
    stk[++top] = i;
  }
  stk[top = 0] = n + 1;
  for (int i = n; i; --i) {
    while (top && a[stk[top]] >= a[i]) --top;
    down(x[i].second, A.query(i, stk[top]));
    stk[++top] = i;
  }
  stk[top = 0] = 0;
  for (int i = 1; i <= m; ++i) {
    while (top && b[stk[top]] > b[i]) --top;
    down(y[i].second, B.query(stk[top], i));
    stk[++top] = i;
  }
  stk[top = 0] = m + 1;
  for (int i = m; i; --i) {
    while (top && b[stk[top]] >= b[i]) --top;
    down(y[i].second, B.query(i, stk[top]));
    stk[++top] = i;
  }
  sort(x + 1, x + n + 1), sort(y + 1, y + m + 1);
  for (int i = n, j = 1; i; --i)     
    while (j <= m && x[i].first + y[j].first <= X) 
      mdf[i + 1].emplace_back(y[j++]);
  solve(1, n + 1);
  printf("%lld\n", ans);
  return 0;
}