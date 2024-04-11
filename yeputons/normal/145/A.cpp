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

const int MAXL = 1e5;
char a[MAXL + 1];
char b[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s%s", a, b) >= 1) {
    int l = strlen(a);

    int ans = 0;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < l; i++)
      if (a[i] != b[i]) {
        if (a[i] == '4') c1++;
        else c2++;
      }
    printf("%d\n", max(c1, c2));
  }
  return 0;
}