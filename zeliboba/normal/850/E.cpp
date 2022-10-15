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
const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;

const int MAXN = (1 << 20);

typedef vector<ll> polynomial;

void fft(polynomial &a, int low, int high)
{
	if(low == high - 1)
    return;

  int len = (high - low) / 2, mid = low + len;
  fft(a, low, mid);
  fft(a, mid, high);

  for(int i = low; i < mid; i++)
  {
    auto x1 = a[i];
    auto x2 = a[i + len];

    a[i] = (x1 - x2) % mod;
    a[i + len] = (x1 + x2) % mod;
  }
}

void inv_fft(polynomial &a, int low, int high)
{
  if(low == high - 1)
    return;

  int len = (high - low) / 2, mid = low + len;

  for(int i = low; i < mid; i++)
  {
    auto y1 = a[i];
    auto y2 = a[i + len];

    a[i] = (y1 + y2) * inv2 % mod;
    a[i + len] = (y2 - y1) * inv2 % mod;
  }

  inv_fft(a, low, mid);
  inv_fft(a, mid, high);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi popc(1 << n);
  for (int i = 1; i < popc.size(); ++i) {
    popc[i] = popc[i/2] + i % 2;
  }
  string s;
  cin >> s;
  ll res = 0;
  polynomial A(1 << n);
  for (int i = 0; i < s.size(); ++i) {
    s[i] -= '0';
    A[i] = s[i];
  }
  fft(A, 0, A.size());
  for(int i = 0; i < A.size(); i++)
    A[i] = A[i] * A[i] % mod;
  inv_fft(A, 0, A.size());
  for (int i = 0; i < A.size(); ++i) {
    res = (res + A[i] % mod * (1LL << (n - popc[i]))) % mod;
  }
/*  for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) if (s[i] && s[j]) {
    res += (1 << (n -__builtin_popcount(i ^ j)));
  }*/
  cout << 3 * (res % mod + mod) % mod << endl;
  return 0;
}