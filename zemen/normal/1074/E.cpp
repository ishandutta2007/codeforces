#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct pt {
  int x, y;
};

pt operator+(const pt& a, const pt& b) {
  return pt{a.x + b.x, a.y + b.y};
}

bool operator==(const pt& a, const pt& b) {
  return a.x == b.x && a.y == b.y;
}

ostream& operator<<(ostream& out, const pt& a) {
  return out << "{" << a.x << ", " << a.y << "}";
}

vector<vector<int>> a;
int N, M;

int& get(pt p) {
  return a[p.x][p.y];
}

vector<vector<int>> ops;

void out() {
  cerr << "=======================================\n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cerr.width(3);
      cerr << a[i][j] << ' ';
    }
    cerr << '\n';
  }
}

void apply(vector<pt> v) {
  vector<int> vals;
  for (auto p : v) {
    vals.push_back(get(p));
  }
  ops.push_back(vals);

  reverse(v.begin(), v.end());
  int first = get(v[0]);
  for (int i = 0; i + 1 < (int) v.size(); ++i) {
    get(v[i]) = get(v[i + 1]);
  }
  get(v.back()) = first;
  //out();
}

void sqrot(pt a, int num) {
  bool rev = false;
  if (num == 3) {
    rev = true;
    num = 1;
  }
  for (int i = 0; i < num; ++i) {
    vector<pt> v{a, a + pt{0, 1}, a + pt{1, 1}, a + pt{1, 0}};
    if (rev) {
      reverse(v.begin(), v.end());
    }
    apply(v);
  }
}

void step(pt& a, int dir) {
  if (dir == 0) {
    if (a.y == 0) {
      sqrot(a, 3);
    } else {
      sqrot(a + pt{0, -1}, 1);
    }
    ++a.x;
  } else if (dir == 1) {
    if (a.y == 0) {
      sqrot(a + pt{-1, 0}, 1);
    } else {
      sqrot(a + pt{-1, -1}, 3);
    }
    --a.x;
  } else if (dir == 2) {
    if (a.x == 0) {
      sqrot(a, 1);
    } else {
      sqrot(a + pt{-1, 0}, 3);
    }
    ++a.y;
  } else if (dir == 3) {
    if (a.x == 0) {
      sqrot(a + pt{0, -1}, 3);
    } else {
      sqrot(a + pt{-1, -1}, 1);
    }
    --a.y;
  }
}

void move_to(pt a, pt b, int n, int m) {
  while (a.x < min(b.x, n - 1)) {
    step(a, 0);
  }
  while (a.x > b.x) {
    step(a, 1);
  }
  while (a.y < min(b.y, m - 1)) {
    step(a, 2);
  }
  while (a.y > b.y) {
    step(a, 3);
  }
  while (a.x < b.x) {
    step(a, 0);
  }
  while (a.y < b.y) {
    step(a, 2);
  }
}

pt locate(int x, int y) {
  int h = x * M + y + 1;
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) a[i].size(); ++j) {
      if (a[i][j] == h) {
        return pt{i, j};
      }
    }
  }
  assert(false);
}

void reduce_n(int n, int m) {
  for (int j = m - 1; j >= 0; --j) {
    auto p = locate(n - 1, j);
    pt to{n - 1, j};
    if (j == 1) {
      to = pt{n - 1, 0};
    } else if (j == 0) {
      if (p == pt{n - 1, 1}) {
        sqrot(pt{n - 2, 0}, 3);
        sqrot(pt{n - 3, 0}, 3);
        sqrot(pt{n - 2, 0}, 1);
        p = locate(n - 1, j);
      }
      to = pt{n - 2, 0};
    }
    move_to(p, to, n - 1, m);
  }
  sqrot(pt{n - 2, 0}, 3);
  for (int j = 0; j < m - 1; ++j) {
    auto p = pt{n - 1, j};
    assert(locate(n - 1, j) == p);
  }
}

void reduce_m(int n, int m) {
  for (int j = n - 1; j >= 0; --j) {
    auto p = locate(j, m - 1);
    pt to{j, m - 1};
    if (j == 1) {
      to = pt{0, m - 1};
    } else if (j == 0) {
      if (p == pt{1, m - 1}) {
        sqrot(pt{0, m - 2}, 1);
        sqrot(pt{0, m - 3}, 1);
        sqrot(pt{0, m - 2}, 3);
        p = locate(j, m - 1);
      }
      to = pt{0, m - 2};
    }
    move_to(p, to, n, m - 1);
  }
  sqrot(pt{0, m - 2}, 1);
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  N = n, M = m;
  a.resize(n, vector<int>(m));
  mt19937 rr(random_device{}());
#ifdef LOCAL
  vector<int> p(n * m);
  iota(p.begin(), p.end(), 1);
  shuffle(p.begin(), p.end(), rr);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = p[i * m + j];
    }
  }
  out();
#else
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
#endif
  while (n > 3) {
    reduce_n(n, m);
    --n;
  }
  while (m > 3) {
    reduce_m(n, m);
    --m;
  }

  while (true) {
    reduce_n(3, 3);
    reduce_m(2, 3);

    pt z{0, 0};
    while (!(locate(0, 0) == z)) {
      sqrot(z, 1);
    }
    bool ok = true;
    for (int x : {0, 1}) {
      for (int y : {0, 1}) {
        if (!(locate(x, y) == pt{x, y})) {
          ok = false;
        }
      }
    }
    if (!ok) {
      for (int it = 0; it < 100; ++it) {
        int rx = rr() % 2;
        int ry = rr() % 2;
        sqrot(pt{rx, ry}, 1);
      }
    } else {
      break;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      pt p{i, j};
      assert(locate(i, j) == p);
    }
  }

  assert((int) ops.size() * 4 <= 1e5);
  cout << ops.size() << '\n';
#ifndef LOCAL
  for (auto o : ops) {
    cout << o.size();
    for (auto x : o) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
#endif
}