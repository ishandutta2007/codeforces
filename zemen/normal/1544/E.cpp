#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

string solve(string s) {
  int n = (int) s.size();
  sort(s.begin(), s.end());
  {
    map<char, int> char_cnt;
    for (auto c : s) {
      char_cnt[c]++;
    }
    for (auto [a, cnt] : char_cnt) {
      if (cnt == 1) {
        string res;
        res += a;
        for (auto c : s) {
          if (c != a) {
            res += c;
          }
        }
        return res;
      }
    }
  }
  char a = s[0];
  int cnt = 0;
  for (auto c : s) {
    cnt += c == a;
  }
  if (cnt == n || cnt == 1) {
    return s;
  }
  if (cnt - 2 <= n - cnt) {
    string t = s.substr(cnt);
    string res(2, a);
    int used = 2;
    for (auto c : t) {
      res += c;
      if (used < cnt) {
        ++used;
        res += a;
      }
    }
    assert(used == cnt);
    return res;
  }
  char b = s[cnt];
  int cntb = 0;
  for (auto c : s) {
    cntb += c == b;
  }

  if (cnt + cntb == n) {
    string res;
    res += a;
    res += string(cntb, b);
    res += string(cnt - 1, a);
    return res;
  }

  string t = s.substr(cnt + cntb);
  string res;
  res += a;
  res += b;
  res += string(cnt - 1, a);
  res += t[0];
  res += string(cntb - 1, b);
  res += t.substr(1);
  return res;
}

string naive(string s) {
  int n = (int) s.size();
  sort(s.begin(), s.end());
  string best;
  int bestpi = n;

  do {
    vector<int> pi(n);
    int mx = 0;
    for (int i = 1; i < n; ++i) {
      int k = pi[i - 1];
      while (k > 0 && s[i] != s[k]) {
        k = pi[k - 1];
      }
      if (s[i] == s[k]) {
        ++k;
      }
      pi[i] = k;
      mx = max(mx, k);
    }
    if (mx < bestpi) {
      bestpi = mx;
      best = s;
    }
  } while (next_permutation(s.begin(), s.end()));

  return best;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  //mt19937 rnd(1337);
  //while (true) {
  for (int i = 0; i < tn; ++i) {
    string s;
    cin >> s;
    //int n = 1 + rnd() % 9;
    //int k = 1 + rnd() % (n + 3);
    //for (int i = 0; i < n; ++i) {
      //s += 'h' + rnd() % k;
    //}
    //cout << "test: " << n << ' ' << k << '\n';

    cout << solve(s) << '\n';
    //if (solve(s) != naive(s)) {
      //cout << naive(s) << '\n';
      //return 0;
    //}
    //cout << naive(s) << '\n';
  }
}