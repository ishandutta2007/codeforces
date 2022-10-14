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

const char *ns[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
const int cnt = 5;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    n--;
    ll cl = 1;
    while (n >= cl * cnt) {
      n -= cl * cnt;
      cl *= 2;
    }
    n /= cl;
    printf("%s\n", ns[n]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}