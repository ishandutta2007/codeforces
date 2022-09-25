#include <bits/stdc++.h>
using namespace std::chrono_literals;
using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

void fail() {
  cout << "NO\n";
  exit(0);
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  auto start = chrono::system_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> s1{0}, s2{1}, s3;
  int g1 = a[0], g2 = a[1], g3 = 0;
  for (int i = 2; i < n; ++i) {
    if (a[i] % g1 != 0) {
      s1.push_back(i);
      g1 = gcd(g1, a[i]);
    } else if (a[i] % g2 != 0) {
      s2.push_back(i);
      g2 = gcd(g2, a[i]);
    } else {
      s3.push_back(i);
      g3 = gcd(g3, a[i]);
    }
  }
  mt19937 rnd(1337);
  auto upd = [&](int i) {
    if (i == 1) {
      g1 = 0;
      for (auto x : s1) {
        g1 = gcd(g1, a[x]);
      }
    } else if (i == 2) {
      g2 = 0;
      for (auto x : s2) {
        g2 = gcd(g2, a[x]);
      }
    } else {
      g3 = 0;
      for (auto x : s3) {
        g3 = gcd(g3, a[x]);
      }
    }
  };
  auto check = [&] {
    int g = 0;
    for (auto x : s1) {
      g = gcd(g, a[x]);
    }
    assert(g == g1);

    g = 0;
    for (auto x : s2) {
      g = gcd(g, a[x]);
    }
    assert(g == g2);

    g = 0;
    for (auto x : s3) {
      g = gcd(g, a[x]);
    }
    assert(g == g3);
  };
  int counter = 0;
  bool tled = false;
  auto tl = [&]() {
    if (tled) {
      return true;
    }
    if (++counter == 100) {
      counter = 0;
      auto t = chrono::system_clock::now();
      if ((t - start) >= 300ms) {
        tled = true;
      }
    }
    return false;
  };
  while (g1 > 1 || g2 > 1) {
    if (tl()) {
      fail();
    }
    //check();
    if (g1 == 1) {
      swap(g1, g2);
      swap(s1, s2);
    }
    if (g3 % g1 != 0) {
      for (auto it = s3.begin(); it != s3.end(); ++it) {
        if (a[*it] % g1 != 0) {
          g1 = gcd(g1, a[*it]);
          s1.push_back(*it);
          s3.erase(it);
          break;
        }
      }
      upd(3);
      continue;
    }
    if (g2 % g1 == 0) {
      fail();
    }
    vector<int> cand;
    for (auto i : s2) {
      if (a[i] % g1 != 0) {
        cand.push_back(i);
      }
    }
    assert(!cand.empty());
    int id = cand[rnd() % cand.size()];
    s1.push_back(id);
    for (auto it = s2.begin(); it != s2.end(); ++it) {
      if (*it == id) {
        s2.erase(it);
        break;
      }
    }
    upd(1);
    upd(2);
    if (g2 == 0) {
      if (!s3.empty()) {
        s2.push_back(s3.back());
        s3.pop_back();
        upd(3);
      } else {
        s2.push_back(s1.front());
        s1.erase(s1.begin());
        upd(1);
      }
      upd(2);
    }
  }
  check();
  cout << "YES\n";
  vector<int> res(n, 2);
  for (int x : s1) {
    res[x] = 1;
  }
  for (int x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}