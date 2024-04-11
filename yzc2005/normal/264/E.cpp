#include <bits/stdc++.h>
const int N = 255555;
int n, m, px[N], py[N], dp[N];
struct SegmentTree {
  int max[N << 2];
  void modify(int p, int l, int r, int pos, int val) {
    if (l == r) {
      max[p] = val;
      return;
    }
    int mid = l + r >> 1;
    if (mid >= pos) {
      modify(p << 1, l, mid, pos, val);
    } else {
      modify(p << 1 | 1, mid + 1, r, pos, val);
    }
    max[p] = std::max(max[p << 1], max[p << 1 | 1]);
  }
  int query(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return max[p];
    int mid = l + r >> 1, res = 0;
    if (mid >= ll) {
      res = std::max(res, query(p << 1, l, mid, ll, rr));
    }
    if (mid < rr) {
      res = std::max(res, query(p << 1 | 1, mid + 1, r, ll, rr));
    }
    return res;
  }
} tx, ty;
void update(int x, int z) {
  dp[x] = z;
  int y = py[x];
  tx.modify(1, 1, n, x, z);
  ty.modify(1, 1, N - 1, y, z);
}
int main() {
  scanf("%d%d", &n, &m);
  std::set<int> pos;
  for (int tt = m; tt; --tt) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      y += tt;
      pos.insert(x);
      py[x] = y;
      px[y] = x;
      std::vector<int> mdf;
      for (int i = y - 9; i <= y; ++i) {
        if (px[i]) {
          mdf.push_back(px[i]);
          update(px[i], 0);          
        }
      }
      std::reverse(mdf.begin(), mdf.end());
      for (auto x : mdf) {
        int val = tx.query(1, 1, n, x + 1, n);
        update(x, val + 1);
      }
    } else {
      int where;
      scanf("%d", &where);
      std::vector<int> mdf;
      int x, y;
      while (where--) {
        x = *pos.begin();
        pos.erase(x);
        mdf.push_back(x);
        update(x, 0);
      }
      y = py[x];
      pos.erase(x);
      py[x] = 0;
      px[y] = 0;
      mdf.pop_back();
      std::reverse(mdf.begin(), mdf.end());
      for (auto x : mdf) {
        int val = ty.query(1, 1, N - 1, py[x] + 1, N - 1);
        update(x, val + 1);
        pos.insert(x);
      }
    }
    printf("%d\n", tx.max[1]);
  }
  return 0;
}