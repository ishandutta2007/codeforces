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
//const int mod = ;

vi used;

void send(int x) {
  used[x] = 1;
  cout << x + 1 << endl;
  fflush(stdout);
}

int read() {
  int x;
  cin >> x;
  --x;
  used[x] = 1;
  return x;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  used.assign(2 * n, 0);
  vi p(2 * n);
  for (int i = 0; i < (int)p.size(); ++i) {
    cin >> p[i];
  }
  vi bad(2 * n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    bad[a] = b;
    bad[b] = a;
  }
  int move;
  cin >> move;
  for (int t = 0; t < 2 * n; ++t, move = move == 1 ? 2 : 1) {
    if (move == 1) {
      bool moved = false;
      for (int i = 0; i < (int)p.size(); ++i) if (!used[i] && bad[i] != -1 && used[bad[i]]) {
        send(i);
        moved = true;
        break;
      }
      if (moved) {
        continue;
      }
      for (int i = 0; i < (int)p.size(); ++i) if (!used[i] && bad[i] != -1 && p[i] > p[bad[i]]) {
        send(i);
        moved = true;
        break;
      }
      if (moved) {
        continue;
      }
      int ma = -1, best = 0;
      for (int i = 0; i < (int)p.size(); ++i) if (!used[i] && p[i] >= ma) {
        ma = p[i];
        best = i;
      }
      send(best);
    } else {
      read();
    }
  }
  return 0;
}