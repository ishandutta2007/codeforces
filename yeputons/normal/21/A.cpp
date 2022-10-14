#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

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

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF 2000000000
#define mp make_pair
#define pb push_back

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#endif

bool checkCh(char c) {
  if ((c >= 'a') && (c <= 'z')) return true;
  if ((c >= 'A') && (c <= 'Z')) return true;
  if ((c >= '0') && (c <= '9')) return true;
  if (c == '_') return true;
  return false;
}
bool check_username(string s) {
  if ((s.length() <= 0) || (s.length() > 16)) return false;
  for (int i = 0; i < s.length(); i++) {
    if (!checkCh(s[i])) return false;
  }
  return true;
}
bool check_hostname(string s) {
  if ((s.length() <= 0) || (s.length() > 32)) return false;
  string w = "";
  for (int i = 0; i < s.length(); i++) {
    if (checkCh(s[i])) {
      w += s[i];
      continue;
    }
    if (s[i] != '.') return false;
    if ((w.length() <= 0) || (w.length() > 16)) return false;
    w = "";
  }
  if ((w.length() <= 0) || (w.length() > 16)) return false;
  return true;
}

char buf[101];
int main() {
  while (scanf("%s", buf) >= 1) {
    bool good = true;
    int state = 0;

    int l = 0;
    string tkn = "";
    for (int i = 0; good && buf[i]; i++) {
      switch (state) {
        case 0:
          if (buf[i] == '@') {
            good = good & check_username(tkn);
            tkn = ""; state++;
            continue;
          }
          else
            tkn += buf[i];            
          break;
        case 1:
          if (buf[i] == '/') {
            good = good && check_hostname(tkn);
            tkn = ""; state++;
          } else
            tkn += buf[i];
          break;
        case 2:
          tkn += buf[i];
          break;
      }
    }
    if (state < 1) good = false;
    else {
      switch (state) {
        case 1:
          good = good && check_hostname(tkn);
          break;
        case 2:
          good = good && check_username(tkn);
          break;
      }
    }
    printf(good ? "YES\n" : "NO\n");
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}