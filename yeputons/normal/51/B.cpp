#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int eprintf(const char* format, ...) {
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

#define pb push_back
#define mp make_pair

typedef vector<int> vi;

string data;
int pos;
bool getString(const string &s) {
  int cpos = pos;
  for (int i = 0; i < s.length(); i++) {
    if (cpos >= data.length()) return false;
    if (data[cpos++] != s[i]) return false;
  }
  pos = cpos;
  return true;
}

vi sizes;
int getTable();

int getCell() {
  if (!getString("<td>")) return 0;
  if (!getString("</td>")) {
    int sz = getTable();
    assert(sz);
    sizes.pb(sz);
    assert(getString("</td>"));
  }
  return 1;
}

int getRow() {
  if (!getString("<tr>")) return 0;
  int ans = 0, x;
  for (;;) { x = getCell(); if (!x) break; ans += x; }
  assert(getString("</tr>"));
  return ans;
}

int getTable() {
  if (!getString("<table>")) return 0;
  int ans = 0, x;
  for (;;) { x = getRow(); if (!x) break; ans += x; }
  assert(getString("</table>"));
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  for (;;) {
    string s;
    bool cont = getline(cin, s) && s != "END";
    if (s == "END") s = "";
    data += s;
    if (!cont) {
      if (data.length()) {
        pos = 0;
        sizes = vi();
        sizes.pb(getTable());
        assert(pos == data.length());
        sort(sizes.begin(), sizes.end());
        for (int i = 0; i < sizes.size(); i++)
          printf("%d%c", sizes[i], "\n "[i + 1 < sizes.size()]);
      }

      #ifndef DEBUG
      break;
      #else
      if (!data.length()) break;
      #endif
      data = "";
    }
  }
  return 0;
}