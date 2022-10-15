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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    vi c(26);
    for (int i = 0; i < n; ++i) ++c[s[i] - 'a'];
    string t = s;
    bool ok = 0;
    for (int i = 0; i < 26; ++i) {
      if (c[i] == 1) {
        for (int j = 1; j < n; ++j) if (t[j] == 'a' + i) {
          swap(t[0], t[j]);
          sort(t.begin() + 1, t.end());
          break;
        }
        ok = 1;
        break;
      }
      if (c[i] == n) {
        ok = 1;
        break;
      }
    }
    if (!ok) {
      for (int i = 0; i < 26; ++i) if (c[i]) {
        t.assign(n, 0);
        char a = i + 'a';
        t[0] = a;
        if (2 + 2 * (c[i] - 2) <= n) {
//          cerr << test << "here\n";
          for (int j = 0; j < c[i] - 1; ++j) t[1 + 2 * j] = a;
          int it = c[i];
          for (int j = 0; j < n; ++j) if (t[j] != a) {
            t[j] = s[it++];
          }
        } else {
          for (int i1 = i + 1; i1 < 26; ++i1) if (c[i1]) {
            char b = i1 + 'a';
            if (c[i] + c[i1] == n) {
              for (int j = 1; j < n; ++j) {
                if (j < 1 + c[i1]) t[j] = b;
                else t[j] = a;
              }
            } else {
              int pos = 1;
              t[pos++] = b;
              for (int j = 0; j < c[i] - 1; ++j) t[pos++] = a;
              int begc = c[i] + c[i1];
              t[pos++] = s[begc];
              for (int j = 0; j < c[i1] - 1; ++j) t[pos++] = b;
              for (int it = begc + 1; it < n; ++it) t[pos++] = s[it];
            }
            break;
          }
        }
        break;
      }
    }
    cout << t << '\n';
  }
  return 0;
}