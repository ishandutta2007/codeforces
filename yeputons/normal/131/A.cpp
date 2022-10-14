#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

char s[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  while (scanf("%s", s) >= 1) {
    bool need = false;

    bool g = true;
    for (int i = 1; s[i]; i++)
      if (!(s[i] >= 'A' && s[i] <= 'Z')) {
        g = false;
        break;
      }
    if (g) need = true;

    if (need)
      for (int i = 0; s[i]; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
          s[i] += 'a' - 'A';
        else
          s[i] += 'A' - 'a';
    printf("%s\n", s);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}