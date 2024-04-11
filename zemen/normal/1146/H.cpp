#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct pt {
  ll x, y;

  pt operator+(const pt& p) const { return pt{x + p.x, y + p.y}; }
  pt operator-(const pt& p) const { return pt{x - p.x, y - p.y}; }
  ll operator*(const pt& p) const { return x * p.x + y * p.y; }
  ll operator%(const pt& p) const { return x * p.y - y * p.x; }
  bool operator==(const pt& p) const { return x == p.x && y == p.y; }

  bool up() const { return y == 0 ? x > 0 : y > 0; }

  pt rot() { return pt{-y, x}; }
};
istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

int n;
vector<pt> p;

const int maxn = 305;
int ins[maxn][maxn];

bool in1(int i, int j, int k) {
  if (p[i] % p[j] < 0) {
    swap(i, j);
  }
  if (p[i] % p[k] <= 0 || p[k] % p[j] <= 0) {
    return false;
  }
  if ((p[j] - p[i]) % (p[k] - p[i]) <= 0) {
    return false;
  }
  return true;
}

int in2(int i, int j, int k) {
  int res = ins[i][j];
  if (in1(i, j, k)) {
    if (p[i] % p[j] > 0) {
      --res;
    } else {
      ++res;
    }
  }
  return res;
}

int cnt_inside(int i, int j, int k) {
  if ((p[j] - p[i]) % (p[k] - p[i]) < 0) {
    return cnt_inside(i, k, j);
  }
  int res = in2(i, j, k) + in2(j, k, i) + in2(k, i, j);
  assert(res >= 0 && res <= n);
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("h.in", "r", stdin));
#endif
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  mt19937 rnd(random_device{}());
  pt sh{1, 1};
  while (true) {
    sh = pt{ll(rnd() % int(1e6) + 1), ll(rnd() % int(1e6) + 1)};
    bool fail = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && (p[i] + sh) % (p[j] + sh) == 0) {
          fail = true;
          break;
        }
      }
      if (fail) {
        break;
      }
    }
    if (!fail) {
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = p[i] + sh;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == i) {
        continue;
      }
      if (p[i] % p[j] < 0) {
        continue;
      }
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) {
          continue;
        }
        if (!in1(i, j, k)) {
          continue;
        }
        ins[i][j]++;
        ins[j][i]--;
      }
    }
  }

  ll N = n;
  ll tot = N * (N - 1) * (N - 2) * (N - 3) * (N - 4) / 120;

  ll c3 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < j; ++k) {
        int ins = cnt_inside(i, j, k);
        c3 += ins * (ins - 1) / 2;
      }
    }
  }
  ll c4 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int w0[2] = {0, 0};
      int w1[2] = {0, 0};
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) {
          continue;
        }
        int ins = cnt_inside(i, j, k);
        int side = (p[j] - p[i]) % (p[k] - p[i]) > 0;
        w0[side]++;
        w1[side] += ins;
      }
      c4 += w0[0] * w1[1] + w0[1] * w1[0];
    }
  }
  c4 -= 4 * c3;
  assert(c4 % 2 == 0);
  c4 /= 2;

  cout << tot - c3 - c4 << '\n';
}