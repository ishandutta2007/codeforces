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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

const int N = 7001;

bitset<N> v[100005];
bitset<N> divs[N], muls[N];
//bitset<N> tmp;
char res[1000005];

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  vi good(N);
  good[1] = 1;
  for (int i = 2; i < good.size(); ++i) {
    for (int j = 1; j < i; ++j) if (i % j == 0) {
      good[i] ^= good[j];
    }
//    if (i < 100) cerr << i << ' ' << good[i] << endl;
  }
  for (int i = 1; i < N; ++i) for (int j = i; j < N; j += i) {
    divs[j].set(i);
    if (good[j / i]) muls[i].set(j);
  }
  int n, q;
  scanf("%d%d", &n, &q);
  int it = 0;
  for (int test = 0; test < q; ++test) {
    int type, x, y, z, val;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d", &x, &val);
      --x;
      v[x] = divs[val];
    } else if (type == 2) {
      scanf("%d%d%d", &x, &y, &z);
      --x; --y; --z;
      v[x] = v[z] ^ v[y];
    } else if (type == 3) {
      scanf("%d%d%d", &x, &y, &z);
      --x; --y; --z;
//      for (int i = 1; i <= 6; ++i) cerr << v[z][i]; cerr << endl;
//      for (int i = 1; i <= 6; ++i) cerr << v[y][i]; cerr << endl;
      v[x] = v[z] & v[y];
//      for (int i = 1; i <= 6; ++i) cerr << v[x][i]; cerr << endl;
    } else {
      scanf("%d%d", &x, &val);
      --x;
      res[it] = '0' + (v[x] & muls[val]).count() % 2;
      ++it;
    }
  }
  res[it] = '\0';
  printf("%s\n", res);
  return 0;
}