#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

vi f(const string& s) {
  vi v(1, 1);
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) ++v.back();
    else v.push_back(1);
  }
  return v;
}

int solve(string a, string b) {
  string a0 = a, b0 = b;
  for (int i = 0; i < a.size(); ++i) a[i] -= 'a';
  for (int i = 0; i < b.size(); ++i) b[i] -= 'a';
  vi v1 = f(a), v2 = f(b);
  if (v1.size() == 1 && v2.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  int mi = 1e9, l1 = 0, l2 = 0, l3 = 0, l4 = 0;
  const int L = 4;
  for (int i1 = 0; i1 <= v1.size(); ++i1) {
    for (int i2 = 0; i2 <= v2.size(); ++i2) {
      if (i1 > L && i2 > L) break;
      char sa = a[0] ^ (i1 % 2);
      char sb = b[0] ^ (i2 % 2);
      char na = (i2 > 0 ? b[0] : sa);
      char nb = (i1 > 0 ? a[0] : sb);
      int len1 = (int)v1.size() + i2 - i1 - (i1 != (int)v1.size() && i2 && sa == (sb ^ 1));
      int len2 = (int)v2.size() + i1 - i2 - (i2 != (int)v2.size() && i1 && sb == (sa ^ 1));
      if (na == nb) {
        if (i1 > L || i2 > L) continue;
        for (int j1 = 0; j1 <= len1; ++j1) {
          for (int j2 = 0; j2 <= len2; ++j2) {
            if (j1 > L && j2 > L) break;
            char sa1 = na ^ (j1 % 2);
            char sb1 = nb ^ (j2 % 2);
            char na1 = (j2 > 0 ? nb : sa1);
            char nb1 = (j1 > 0 ? na : sb1);
            int len3 = len1 + j2 - j1 - (j1 != len1 && j2 && sa1 == (sb1 ^ 1));
            int len4 = len2 + j1 - j2 - (j2 != len2 && j1 && sb1 == (sa1 ^ 1));
            if (na1 != nb1) {
              int cur = 2 + max(len3, len4) - 1;
              if (cur < mi) {
                mi = cur;
                l1 = i1;
                l2 = i2;
                l3 = j1;
                l4 = j2;
              }
            }
          }
        }
      } else {
        int cur = (i1 + i2 != 0) + max(len1, len2) - 1;
        if (cur < mi) {
          mi = cur;
          l1 = i1;
          l2 = i2;
          l3 = 0;
          l4 = 0;
        }
      }
    }
  }
  if (a0.size() + b0.size() < 20) {
    for (int i = 0; i < a.size(); ++i) for (int j = 0; j < b.size(); ++j) {
      string a2 = b.substr(0, j) + a.substr(i);
      string b2 = a.substr(0, i) + b.substr(j);
      for (int i3 = 0; i3 < a2.size(); ++i3) for (int j3 = 0; j3 < b2.size(); ++j3) {
        string a1 = a2;//b2.substr(0, j3) + a2.substr(i3);
        string b1 = b2;//a2.substr(0, i3) + b2.substr(j3);
        vi v1 = f(a1), v2 = f(b1);
        for (int i1 = 0; i1 <= v1.size(); ++i1) {
          for (int i2 = 0; i2 <= v2.size(); ++i2) {
            if (i1 > L && i2 > L) break;
            char sa = a1[0] ^ (i1 % 2);
            char sb = b1[0] ^ (i2 % 2);
            char na = (i2 > 0 ? b1[0] : sa);
            char nb = (i1 > 0 ? a1[0] : sb);
            if (na == nb) continue;
            int len1 = (int)v1.size() + i2 - i1 - (i1 != (int)v1.size() && i2 && sa == (sb ^ 1));
            int len2 = (int)v2.size() + i1 - i2 - (i2 != (int)v2.size() && i1 && sb == (sa ^ 1));
            int cur = (i1 + i2 != 0) + max(len1, len2) - 1;
            if (cur + 1 < mi) cerr << mi << ' ' << cur + 1 << ' ' << a0 << ' ' << b0 << ' ' << i << ' ' << j << endl;
            assert (cur + 1 >= mi);
          }
        }
      }
    }
  }
  vii res;
  if (l1 || l2) {
    int len1 = 0, len2 = 0;
    for (int i = 0; i < l1; ++i) len1 += v1[i];
    for (int i = 0; i < l2; ++i) len2 += v2[i];
    res.emplace_back(len1, len2);
    string olda = a, oldb = b;
    a = oldb.substr(0, len2) + olda.substr(len1);
    b = olda.substr(0, len1) + oldb.substr(len2);
    v1 = f(a);
    v2 = f(b);
    if (l3 || l4) {
      int len1 = 0, len2 = 0;
      for (int i = 0; i < l3; ++i) len1 += v1[i];
      for (int i = 0; i < l4; ++i) len2 += v2[i];
      res.emplace_back(len1, len2);
      string olda = a, oldb = b;
      a = oldb.substr(0, len2) + olda.substr(len1);
      b = olda.substr(0, len1) + oldb.substr(len2);
      v1 = f(a);
      v2 = f(b);
    }
  }
  assert(a[0] != b[0]);
  reverse(v1.begin(), v1.end());
  reverse(v2.begin(), v2.end());
  while (v1.size() > 1 || v2.size() > 1) {
    res.emplace_back(v1.back(), v2.back());
    v1.pop_back();
    v2.pop_back();
    if (v1.empty()) v1.push_back(res.back().second);
    else v1.back() += res.back().second;
    if (v2.empty()) v2.push_back(res.back().first);
    else v2.back() += res.back().first;
  }
  cout << res.size() << endl;
  for (pii p : res) {
    cout << p.first << ' ' << p.second << endl;
  }
//if (mi != (int)res.size()) cerr << mi << endl;
  assert((int)res.size() == mi);
  if (a0.size() + b0.size() < 100) {
    for (pii p : res) {
      assert(p.first >= 0 && p.second >= 0 && p.first <= (int)a0.size() && p.second <= (int)b0.size());
      string olda = a0, oldb = b0;
      a0 = oldb.substr(0, p.second) + olda.substr(p.first);
      b0 = olda.substr(0, p.first) + oldb.substr(p.second);
    }
    for (int i = 0; i + 1 < a0.size(); ++i) assert(a0[i] == a0[i + 1]);
    for (int i = 0; i + 1 < b0.size(); ++i) assert(b0[i] == b0[i + 1]);
  }
  return res.size();
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  const int N = 7;
  if (0) for (int n1 = 1; n1 <= N; ++n1) for (int n2 = 1; n2 <= N; ++n2) {
    string a(n1, 'a'), b(n2, 'a');
    for (int m1 = 0; m1 < (1 << n1); ++m1) for (int m2 = 0; m2 < (1 << n2); ++m2) {
      for (int i = 0; i < a.size(); ++i) a[i] = (m1 & (1 << i)) ? 'b' : 'a';
      for (int i = 0; i < b.size(); ++i) b[i] = (m2 & (1 << i)) ? 'b' : 'a';
//      cerr << a << ' ' << b << endl;
      solve(a, b);
    }
/*    for (int test = 1; test <= 10000; ++test) {
      for (int i = 0; i < a.size(); ++i) a[i] = 'a' + rand() % 2;
      for (int i = 0; i < b.size(); ++i) b[i] = 'a' + rand() % 2;
//      cerr << a << ' ' << b << endl;
      solve(a, b);
    }*/
  }
  string a, b;
  cin >> a >> b;
  solve(a, b);
  return 0;
}