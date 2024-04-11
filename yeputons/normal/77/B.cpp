#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int b;
double calcSq(double r) {
  return r * r / 2;
}
double calc(double r) {
  return (calcSq(r) / 4 + b * r) / (2 * b);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int TC;
  scanf("%d", &TC);
  for (int TN = 0; TN < TC; TN++) {
    int a;
    scanf("%d%d", &a, &b);
    if (!b) {
      printf("1\n");
      continue;
    } else if (!a) {
      printf("0.5\n");
      continue;
    }

    double ans = 0;
    ans += calc(min(4 * b, a));
    ans += max(a - 4 * b, 0);
    printf("%.18lf\n", ans / a);
  }
  return 0;
}