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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int x, y;
  while (scanf("%d%d", &x, &y) >= 1) {
    int d = x * x + y * y;
    int c = 0;
    for (c = 0; c * c < d; c++);
    if (c * c == d || !x || !y) {
      printf("black\n");
      goto end;
    }
    c &= 1;
    if ((x > 0) != (y > 0)) c = !c;
    printf(c ? "black\n" : "white\n");
    
    end:;
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}