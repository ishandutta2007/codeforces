#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int f[55][55];
mt19937 rnd(1337);
int n, qs;

void gen() {
  qs = 0;
#ifdef LOCAL  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f[i][j] = rnd() % 2;
    }
  }
  f[0][0] = 1;
  f[n - 1][n - 1] = 0;
#endif
}

bool check(int x1, int y1, int x2, int y2, string s) {
  s += f[x1][y1];
  if (x1 == x2 && y1 == y2) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
  }
  if (x1 < x2 && check(x1 + 1, y1, x2, y2, s)) {
    return true;
  }
  if (y1 < y2 && check(x1, y1 + 1, x2, y2, s)) {
    return true;
  }
  return false;
}

bool inside(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

#ifdef LOCAL
bool ask(int x1, int y1, int x2, int y2) {
  assert(x1 <= x2 && y1 <= y2 && x1 + y1 + 2 <= x2 + y2);
  assert(inside(x1, y1) && inside(x2, y2));
  assert(++qs <= n * n);
  return check(x1, y1, x2, y2, "");
}
#else
bool ask(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
  int b;
  cin >> b;
  return b;
}
#endif

int a[55][55];

const int dx[] = {1, -1, 2, 0, -2, 0};
const int dy[] = {1, -1, 0, 2, 0, -2};

bool wrap_ask(int x1, int y1, int x2, int y2) {
  if (x1 + y1 > x2 + y2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  return ask(x1, y1, x2, y2);
}

void dfs(int x, int y) {
  assert(a[x][y] != -1);
  for (int dir = 0; dir < 6; ++dir) {
    int cx = x + dx[dir];
    int cy = y + dy[dir];
    if (!inside(cx, cy) || a[cx][cy] != -1) {
      continue;
    }
    a[cx][cy] = a[x][y] ^ (!wrap_ask(x, y, cx, cy));
    dfs(cx, cy);
  }
}

void recolor() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i + j) % 2) {
        a[i][j] ^= 1;
      }
    }
  }
}

void solve() {
  gen();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = -1;
    }
  }
  a[0][0] = 1;
  a[n - 1][n - 1] = 0;
  dfs(0, 0);
  dfs(n - 1, n - 1);
  a[0][1] = 0;
  dfs(0, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      assert(a[i][j] != -1);
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < n; ++j) {
      if (a[i][j + 1] != a[i + 1][j]) {
        int x1 = i, y1 = j, x2 = i + 1, y2 = j + 1;
        if (j == 0) {
          ++y2;
        } else {
          --y1;
        }
        bool cask = a[x1][y1] == a[x2][y2];
        if (ask(x1, y1, x2, y2) != cask) {
          recolor();
        }
        return;
      }
    }
  }

  for (int i = 0; i + 2 < n; ++i) {
    for (int j = 0; j + 2 < n; ++j) {
      if (a[i][j] != a[i + 2][j + 2]) {
        bool val = a[i + 1][j + 1] ^ (!(ask(i, j, i + 1, j + 2) || ask(i + 1, j, i + 2, j + 2)));
        int y = a[i + 1][j + 1] == a[i][j] ? j + 2 : j;
        if (a[i + 1][y] != val) {
          recolor();
        }
        return;
      }
    }
  }
  assert(false);
}

signed main() {
  cin >> n;
  while (true) {
    solve();
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << a[i][j];
#ifdef LOCAL
        assert(a[i][j] == f[i][j]);
#endif
      }
      cout << endl;
    }
#ifndef LOCAL
    break;
#endif
  }
}