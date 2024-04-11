#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    string res = "ROY";
    const char* tmp = "GBIV";
    for (int i = 0; res.length() < n; i = (i + 1) % 4)
      res += tmp[i];
    printf("%s\n", res.c_str());
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}