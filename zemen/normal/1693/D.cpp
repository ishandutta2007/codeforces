#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

//bool decinc(vector<int> p) {
  //int n = (int) p.size();
  //for (int mask = 0; mask < (1 << n); ++mask) {
    //int mn = n, mx = -1;
    //bool fail = false;
    //for (int i = 0; i < n; ++i) {
      //if (mask & (1 << i)) {
        //if (mx < p[i]) {
          //mx = p[i];
        //} else {
          //fail = true;
        //}
      //} else {
        //if (mn > p[i]) {
          //mn = p[i];
        //} else {
          //fail = true;
        //}
      //}
    //}
    //if (!fail) {
      //return true;
    //}
  //}
  //return false;
//}

//void pre() {
  //int n = 5;
  //vector<int> p(n);
  //iota(p.begin(), p.end(), 0);
  //do {
    //if (!decinc(p)) {
      //for (int x : p) {
        //cerr << x << ' ';
      //}
      //cerr << '\n';
    //}
  //} while (next_permutation(p.begin(), p.end()));
//}

const int base = 1 << 18;
const int inf = 1e9;
vector<int> st(base * 2, inf);
set<int> vals[base];

void update(int v) {
  while (v > 1) {
    v /= 2;
    st[v] = min(st[v * 2], st[v * 2 + 1]);
  }
}

void add_pair(int x, int y) {
  vals[x].insert(y);
  int v = x + base;
  st[v] = *vals[x].begin();
  update(v);
}

void del_pair(int x, int y) {
  assert(vals[x].erase(y));
  int v = x + base;
  st[v] = vals[x].empty() ? inf : *vals[x].begin();
  update(v);
}

int get_min(int l, int r, int v = 1, int cl = 0, int cr = base) {
  if (l <= cl && cr <= r) {
    return st[v];
  }
  if (r <= cl || cr <= l) {
    return inf;
  }
  int cc = (cl + cr) / 2;
  return min(get_min(l, r, v * 2, cl, cc), get_min(l, r, v * 2 + 1, cc, cr));
}

vector<int> solve(const vector<int>& p) {
  int n = (int) p.size();

  vector<int> nx(n, n), pr(n, -1);
  vector<pair<int, int>> st{{n, -1}};
  for (int i = 0; i < n; ++i) {
    while (st.back().first < p[i]) {
      nx[st.back().second] = i;
      st.pop_back();
    }
    st.emplace_back(p[i], i);
  }
  st = {{-1, n}};
  for (int i = n - 1; i >= 0; --i) {
    while (st.back().first > p[i]) {
      pr[st.back().second] = i;
      st.pop_back();
    }
    st.emplace_back(p[i], i);
  }
  //for (int i = 0; i < n; ++i) {
    //cerr << p[i] << ' ';
  //}
  //cerr << '\n';
  //for (int i = 0; i < n; ++i) {
    //cerr << pr[i] << ' ';
  //}
  //cerr << '\n';
  //for (int i = 0; i < n; ++i) {
    //cerr << nx[i] << ' ';
  //}
  //cerr << '\n';

  vector<int> res(n);
  int l = 0, r = 0;

  auto inc_r = [&]() {
    add_pair(p[r], nx[r]);
    ++r;
  };

  auto inc_l = [&]() {
    del_pair(p[l], nx[l]);
    ++l;
  };

  while (l < n) {
    while (r < n) {
      int c = pr[r];
      int b = get_min(p[r], n);
      if (b < c) {
        break;
      }
      inc_r();
    }
    res[l] = r;
    inc_l();
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  auto s1 = solve(p);
  for (int i = 0; i < n; ++i) {
    p[i] = n - 1 - p[i];
  }
  auto s2 = solve(p);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    int cur = min(s1[i], s2[i]) - i;
    //cerr << s1[i] << ' ' << s2[i] << '\n';
    res += cur;
  }
  cout << res << '\n';
}