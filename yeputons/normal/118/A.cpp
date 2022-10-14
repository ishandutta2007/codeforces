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

const int MAXL = 1024;
char s[MAXL + 1];

bool good(char c) {
  if (c == 'a') return false;
  if (c == 'e') return false;
  if (c == 'i') return false;
  if (c == 'o') return false;
  if (c == 'u') return false;
  if (c == 'y') return false;
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  while (scanf("%s", s) >= 1) {
    string res = "";
    for (int i = 0; s[i]; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
      if (good(s[i]))
        res += "." + string(1, s[i]);
    }
    printf("%s\n", res.c_str());
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}