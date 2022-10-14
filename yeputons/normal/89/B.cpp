#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

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

bool is_breaker(char c) {
  if (!c) return true;
  char s[2] = { c, 0 };
  return strstr("\n\r\t .,()", s) != 0;
}
vector<string> tokenize(const char *s) {
  string cur = "";
  vector<string> res;
  for (int i = 0;; i++) {
    if (is_breaker(s[i])) {
      if (cur.length())
        res.pb(cur);
      cur = "";
    } else
      cur += s[i];
    if (!s[i]) break;
  }
  return res;
}

int pint(const string &s) {
  int res = 0;
  for (int i = 0; i < s.length(); i++) {
    assert('0' <= s[i] && s[i] <= '9');
    res = res * 10 + s[i] - '0';
  }
  return res;
}

enum WidgetType { BOX, HBOX, VBOX };
class Widget {
  ll w, h;
  ll border, spacing;
  vector<Widget*> childs;
  WidgetType ty;
  bool calced;

  public:
  Widget(WidgetType _ty) : w(-1), h(-1), border(0), spacing(0), ty(_ty), calced(false) {}
  Widget(ll _w, ll _h) : w(_w), h(_h), ty(BOX), calced(true) {}
  void calc() {
    if (calced) return;
    assert(ty != BOX);
    if (!sz(childs)) { w = h = 0; return; }

    w = 0; h = 0;
    for (int i = 0; i < sz(childs); i++) {
      childs[i]->calc();
      if (ty == HBOX) {
        w += childs[i]->width();
        h = max(h, childs[i]->height());
      } else {
        w = max(w, childs[i]->width());
        h += childs[i]->height();
      }
    }
    int add_w = (sz(childs) - 1) * spacing + 2 * border;
    int add_h = 2 * border;
    if (ty == VBOX) swap(add_w, add_h);
    w += add_w;
    h += add_h;
    calced = true;
  }

  void addChild(Widget *w) { assert(ty != BOX); childs.pb(w); }
  ll width() { return w; }
  ll height() { return h; }
  void setSpacing(int _s) { spacing = _s; }
  void setBorder(int _b) { border = _b; }
};

char buf[65536];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d ", &n) >= 1) {
    map<string, int> names;
    vector<Widget> ws;
    ws.reserve(n);

    for (int i = 0; i < n; i++) {
      fgets(buf, sizeof buf, stdin);
      vector<string> tks = tokenize(buf);

      if (tks[0] == "Widget") {
        assert(!names.count(tks[1]));
        names[tks[1]] = sz(ws);
        ws.pb(Widget(pint(tks[2]), pint(tks[3])));
      } else if (tks[0] == "HBox" || tks[0] == "VBox") {
        assert(!names.count(tks[1]));
        names[tks[1]] = sz(ws);
        ws.pb(Widget(tks[0] == "HBox" ? HBOX : VBOX));
      } else if (tks[1] == "pack") {
        int where = names[tks[0]];
        int who = names[tks[2]];
        assert(0 <= where && where < sz(ws));
        assert(0 <= who && who < sz(ws));
        ws[where].addChild(&ws[who]);
      } else if (tks[1] == "set_border") {
        ws[names[tks[0]]].setBorder(pint(tks[2]));
      } else if (tks[1] == "set_spacing") {
        ws[names[tks[0]]].setSpacing(pint(tks[2]));
      } else
        assert(false);
    }
    for (map<string, int>::iterator it = names.begin(); it != names.end(); it++) {
      Widget *w = &ws[it->second];
      w->calc();
      printf("%s %I64d %I64d\n", it->first.c_str(), w->width(), w->height());
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}