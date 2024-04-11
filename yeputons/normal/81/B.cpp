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

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

enum LexemType {
  INTEGER = 1, COMMA = 2, DOTS = 3
};
struct Lexem {
  LexemType ty;
  string val;
  Lexem(const string &_val) : ty(INTEGER), val(_val) {}
  Lexem(LexemType _ty, const string &_val) : ty(_ty), val(_val) {}
};

vector<Lexem> lexer(const string &s) {
  string cur = "";
  vector<Lexem> res;
  for (int i = 0; i <= s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      cur += s[i];
    } else {
      if (cur.length()) {
        res.pb(Lexem(cur));
        cur = "";
      }
      switch (s[i]) {
      case ',': res.pb(Lexem(COMMA, ",")); break;
      case '.': res.pb(Lexem(DOTS, "...")); i += 2; break;
      }
    }
  }
  return res;
}

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (;;) {
    memset(buf, 0, sizeof buf);
    fgets(buf, sizeof buf, stdin);
    if (!buf[0]) break;
    string s = buf;
    vector<Lexem> ls = lexer(s);
    eprintf("%d\n", ls.size());

    bool wassp = false;
    for (int i = 0; i < ls.size(); i++) {
      if (i && !wassp) {
        if (ls[i].ty == DOTS || (ls[i].ty == INTEGER && ls[i - 1].ty == INTEGER))
          printf(" ");
      }
      printf("%s", ls[i].val.c_str());
      if (ls[i].ty == COMMA && i + 1 < ls.size()) {
        printf(" ");
        wassp = true;
      } else
        wassp = false;
    }
    printf("\n");
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}