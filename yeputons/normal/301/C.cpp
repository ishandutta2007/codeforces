#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

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

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  for (int i = 0; i < 10; i++)
    printf("??%d>>%d??\n", i, i);

  for (int i = 0; i < 9; i++)
    printf("%d%s<>%d\n", i, "??", i + 1);
  printf("9%s>>?0\n", "??");
  for (int i = 0; i < 9; i++)
    printf("%d?<>%d\n", i, i + 1);
  printf("9?>>?0\n");
  printf("?0<>10\n");

  for (int i = 0; i < 10; i++)
    printf("%d>>%d??\n", i, i);
  return 0;
}