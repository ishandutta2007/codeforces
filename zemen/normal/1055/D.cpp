#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int pi_go(const string& s, const vector<int>& pi, int k, char c) {
  while (k > 0 && s[k] != c) {
    k = pi[k - 1];
  }
  if (s[k] == c) {
    ++k;
  }
  return k;
}

vector<int> pi_function(const string& s) {
  vector<int> pi(s.size());
  for (int i = 1; i < (int) s.size(); ++i) {
    pi[i] = pi_go(s, pi, pi[i - 1], s[i]);
  }
  return pi;
}

int kmp(const string& s, const string& t, const vector<int>& pi) {
  vector<int> res;
  int k = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    k = pi_go(t, pi, k, s[i]);
    if (k == (int) t.size()) {
      return i - k + 1;
    }
  }
  return -1;
}

void fail() {
  cout << "NO\n";
  exit(0);
}

const int maxn = 3005;
string s[maxn];
string t[maxn];
int l[maxn];
int r[maxn];
bool eq[maxn];
char buf[maxn];

pair<string, string> find_diff(int id) {
  int n = (int) s[id].size();
  while (l[id] < n && s[id][l[id]] == t[id][l[id]]) {
    ++l[id];
  }
  if (l[id] == n) {
    return {"", ""};
  }
  r[id] = n;
  while (r[id] >= 0 && s[id][r[id]-1] == t[id][r[id]-1]) {
    --r[id];
  }
  return {s[id].substr(l[id], r[id] - l[id]), t[id].substr(l[id], r[id] - l[id])};
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    s[i] = buf;
  }
  pair<string, string> sdiff;
  int id = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    t[i] = buf;
    auto diff = find_diff(i);
    if (diff.first.empty()) {
      eq[i] = true;
      continue;
    }
    if (sdiff.first.empty()) {
      sdiff = diff;
      id = i;
    } else if (sdiff != diff) {
      fail();
    }
  }
  assert(!sdiff.first.empty());
  while (l[id] > 0) {
    char c = s[id][l[id]-1];
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (!eq[i] && (l[i] == 0 || s[i][l[i]-1] != c)) {
        ok = false;
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i) {
        --l[i];
      }
    } else {
      break;
    }
  }
  while (r[id] < (int) s[id].size()) {
    char c = s[id][r[id]];
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (!eq[i] && (r[i] == (int) s[i].size() || s[i][r[i]] != c)) {
        ok = false;
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i) {
        ++r[i];
      }
    } else {
      break;
    }
  }
  auto T = s[id].substr(l[id], r[id] - l[id]);
  auto pi = pi_function(T);
  for (int i = 0; i < n; ++i) {
    int pos = kmp(s[i], T, pi);
    if (eq[i]) {
      if (pos != -1) {
        fail();
      }
    } else {
      assert(pos != -1);
      if (pos < l[i]) {
        fail();
      }
    }
  }
  cout << "YES\n";
  cout << s[id].substr(l[id], r[id] - l[id]) << '\n' << t[id].substr(l[id], r[id] - l[id]) << '\n';
}