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

bool vowel(char c) {
  char s[] = { c, 0 };
  return strstr("aeiou", s) != 0;
}

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  vi cnt(3);
  for (int i = 0; i < 3; i++) {
    fgets(buf, sizeof buf, stdin);
    for (int i2 = 0; buf[i2]; i2++)
      if (vowel(buf[i2])) cnt[i]++;
  }
  printf(cnt[0] == 5 && cnt[1] == 7 && cnt[2] == 5 ? "YES\n" : "NO\n");
  return 0;
}