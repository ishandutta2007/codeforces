#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

char buf[11];
int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    map<string, int> m;
    int ba = -1; string bn = "";
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      if (m.find(buf) == m.end()) {
	m.insert(mp(buf, 1));
      } else
	m.find(buf)->second++;
      if (m.find(buf)->second > ba) {
	ba = m.find(buf)->second;
	bn = m.find(buf)->first;
      }
    }
    printf("%s\n", bn.c_str());
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}