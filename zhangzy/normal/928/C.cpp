#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Item {
  string name;
  int ver;
  bool operator < (const Item &b) const {
    return ver != b.ver ? ver > b.ver : name < b.name;
  }
};

const int maxn = 1000;

int n;
Item a[maxn];
map<Item, int> id;
map<string, int> ans;
vector<Item> g[maxn];
int st[maxn], top;
int st2[maxn], top2;
bool vis[maxn];

bool cmp(int i, int j) {
  return a[i].ver > a[j].ver;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char s[11];
    scanf("%s%d", s, &a[i].ver);
    a[i].name = s;
    id[a[i]] = i;
    int m;
    scanf("%d", &m);
    while (m--) {
      Item b;
      scanf("%s%d", s, &b.ver);
      b.name = s;
      g[i].push_back(b);
    }
  }

  ans.insert({a[0].name, a[0].ver});
  st[top++] = 0;
  vis[0] = true;
  while (top) {
    top2 = 0;
    for (int i = 0; i < top; ++i) {
      int u = st[i];
      for (Item b : g[u]) {
        int v = id[b];
        if (!vis[v]) {
          vis[v] = true;
          st2[top2++] = v;
        }
      }
    }
    sort(st2, st2 + top2, cmp);
    top = 0;
    for (int i = 0; i < top2; ++i) {
      int u = st2[i];
      if (!ans.count(a[u].name)) {
        st[top++] = u;
        ans.insert({a[u].name, a[u].ver});
      }
    }
  }
  printf("%d\n", (int)ans.size() - 1);
  for (auto x : ans) {
    if (x.first == a[0].name) continue;
    printf("%s %d\n", x.first.c_str(), x.second);
  }
  return 0;
}