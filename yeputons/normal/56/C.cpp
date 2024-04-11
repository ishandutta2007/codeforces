#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

struct Ret {
  multiset<string> ns;
  int ans;
  Ret() { ans = 0; ns = multiset<string>(); }
  Ret(string nm) { ans = 0; ns = multiset<string>(); ns.insert(nm); }
};

char buf[1024];
int pos;

Ret calc() {
  string nm = "";
  while (isalpha(buf[pos])) nm += buf[pos++];

  Ret res;
  while (buf[pos] == ',' || buf[pos] == ':') {
    pos++;
    Ret cur = calc();
    res.ans += cur.ans;
    res.ans += cur.ns.count(nm);
    for (multiset<string>::iterator it = cur.ns.begin(); it != cur.ns.end(); it++)
      res.ns.insert(*it);
  }

  assert(buf[pos] == '.');
  pos++; res.ns.insert(nm);
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%s", buf) >= 1) {
    pos = 0;
    Ret ret = calc();
    assert(!buf[pos]);
    printf("%d\n", ret.ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}