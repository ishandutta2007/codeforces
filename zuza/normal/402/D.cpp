#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
bool is_prime(int x) {
  if (x <= 1) return false;
  for (int i = 2; i*i <= x; ++i)
    if (x%i == 0) return false;
  return true;
}

int sum_exp(int x) {
  static vector<int> P;
  if (P.empty()) {
    for (int i = 2; i*i <= int(1e9); ++i)
      if (is_prime(i))
        P.push_back(i);
  }

  int sum = 0;
  for (int p : P) {
    while (x%p == 0) {
      ++sum;
      x /= p;
    }
  }
  if (x > 1) { ++sum; x = 1; }

  return sum;
}

vector<int> B;

int get_score(int x) {
  int sum = 0;
  for (int b : B) {
    while (x%b == 0) {
      --sum;
      x /= b;
    }
  }

  return sum + sum_exp(x);
}

int main(void)
{
  int n, n_b; scanf("%d %d", &n, &n_b);
  vector<int> A(n), G(n);

  int g = 0;
  REP(i, n) {
    scanf("%d", &A[i]);
    g = gcd(g, A[i]);
    G[i] = g;
  }
  REP(i, n_b) {
    int b; scanf("%d", &b);
    B.push_back(b);
  }

  int kill_score = 0;
  int sol = 0;

  for (int i = n-1; i >= 0; --i) {
    int score = get_score(G[i]);
    if (score < kill_score) {
      kill_score = score;
    }
    sol += get_score(A[i]) - kill_score;
  }

  printf("%d\n", sol);
  return 0;
}