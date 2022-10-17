#include <bits/stdc++.h>
const int N = 1.5e5 + 5;
int n, a[N], p[N];
long long ans[N];
struct node {
  int v1, v2, cv, cnt;
  int t1, t2;
  long long sum;
  inline void tag1(int v) {
    v1 += v;
    t1 += v;
    sum += 1ll * v * cv;
  }
  inline void tag2(int v) {
    v1 += v;
    v2 += v;
    t2 += v;
    sum += 1ll * v * cnt;
  }
} t[N << 2];
int L, R, pos, v;
inline void pushup(int p) {
  int x = p << 1, y = p << 1 | 1;
  if (t[x].v1 == t[y].v1) {
    t[p].v1 = t[x].v1;
    t[p].cv = t[x].cv + t[y].cv;
    t[p].v2 = std::max(t[x].v2, t[y].v2);
  } else {
    if (t[x].v1 < t[y].v1) {
      std::swap(x, y);
    }
    t[p].v1 = t[x].v1;
    t[p].cv = t[x].cv;
    t[p].v2 = std::max(t[x].v2, t[y].v1);
  }
  t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
  t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
}
void build(int p = 1, int l = 1, int r = n) {
  t[p].t1 = t[p].t2 = t[p].cnt = t[p].cv = 0;
  t[p].v1 = t[p].v2 = t[p].sum = 0;
  if (l != r) {
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
  }
}
inline void pushdown(int p) {
  int l = p << 1, r = p << 1 | 1;
  if (t[p].t1) {
    int max = std::max(t[l].v1, t[r].v1);
    if (t[l].v1 == max) {
      t[l].tag1(t[p].t1);
    }
    if (t[r].v1 == max) {
      t[r].tag1(t[p].t1);
    }
    t[p].t1 = 0;
  }
  if (t[p].t2) {
    t[l].tag2(t[p].t2);
    t[r].tag2(t[p].t2);
    t[p].t2 = 0;
  }
}
void change(int p = 1, int l = 1, int r = n) {
  if (t[p].v1 <= v) {
    return;
  }
  if (l >= L && r <= R && t[p].v2 <= v) {
    t[p].tag1(v - t[p].v1);
    return;
  }
  pushdown(p);
  int mid = l + r >> 1;
  if (mid >= L) {
    change(p << 1, l, mid);
  } 
  if (mid < R) {
    change(p << 1 | 1, mid + 1, r);
  }
  pushup(p);
}
void add(int p = 1, int l = 1, int r = n) {
  if (l >= L && r <= R) {
    t[p].tag2(1);
    return;
  }
  pushdown(p);
  int mid = l + r >> 1; 
  if (mid >= L) {
    add(p << 1, l, mid);
  } 
  if (mid < R) {
    add(p << 1 | 1, mid + 1, r);
  }
  pushup(p);
}
int query(int p = 1, int l = 1, int r = n) {
  if (l >= L && r <= R) {
    return t[p].cnt;
  }
  int mid = l + r >> 1;
  if (mid >= L && mid < R) {
    return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
  } else if (mid >= L) {
    return query(p << 1, l, mid);
  } else {
    return query(p << 1 | 1, mid + 1, r);
  }
}
void activate(int p = 1, int l = 1, int r = n) {
  if (l == r) {
    t[p].cnt = t[p].cv = 1;
    t[p].v1 = t[p].sum = v;
    return;
  }
  pushdown(p);
  int mid = l + r >> 1;
  if (mid >= pos) {
    activate(p << 1, l, mid);
  } else {
    activate(p << 1 | 1, mid + 1, r);
  }
  pushup(p);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  auto process = [&]() {
    build();
    for (int i = 1; i <= n; ++i) {
      p[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      int pos = p[i];
      L = 1, R = pos;
      v = query();
      change();
      L = pos, R = n;
      add();
      ::pos = pos, v = i;
      activate();
      ans[i] += t[1].sum;
    }
  };
  process();
  std::reverse(a + 1, a + n + 1);
  process();
  for (int i = 1; i <= n; ++i) {
    printf("%lld\n", ans[i] - 1ll * i * i);
  }
  return 0;
}