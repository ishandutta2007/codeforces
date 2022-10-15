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

vi GetFactors (const vii & primeFactors, const vi & maxPows) {
  // in primeFactors: (p_i, k_i), in maxPows: p_i^{k_i}
  int m = primeFactors.size();
  vi curPows(m);
  ll curFactor = 1;
  vi factors;
  while (true) {
    factors.push_back(curFactor);
    int i;
    for (i = 0; i < m && curPows[i] == primeFactors[i].second; i++) {
      curFactor /= maxPows[i];
      curPows[i] = 0;
    }
    if (i == m)
      break;
    curFactor *= primeFactors[i].first;
    ++curPows[i];
  }
  return factors;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, mod;
  cin >> n >> mod;
  vi res(n + 1), s(n + 1), s1(n + 1), erat(n + 1);
  for (int i = 0; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i) 
    for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
  res[1] = s[1] = 1;
  vi divs, maxpw;
  vii pw;
  for (int i = 2; i < res.size(); ++i) {
    int x = i;
    pw.clear();
    maxpw.clear();
    while (x > 1) {
      int p = erat[x];
      pw.emplace_back(p, 1);
      maxpw.push_back(p);
      x /= p;
      while (x % p == 0) {
        x /= p;
        maxpw.back() *= p;
        pw.back().second++;
      }
    }
    divs = GetFactors(pw, maxpw);
    ll cur = s1[i - 1] + 1;
    for (int x : divs) if (x > 1 && x < i) {
      cur += res[i / x] - res[(i - 1) / x];
    }
    s1[i] = (cur % mod + mod) % mod;
    res[i] = (s[i - 1] + s1[i]) % mod;
    s[i] = (s[i - 1] + res[i]) % mod;
  }
  cout << res[n] << endl;
  return 0;
}