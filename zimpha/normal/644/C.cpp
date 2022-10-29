#include <bits/stdc++.h>
using namespace std;

struct MyCmp {
  bool operator() (const string &a, const string &b) const {
    return a.size() == b.size() ? a < b : a.size() < b.size();
  }
};

typedef set<string, MyCmp> Set;

map<Set, vector<string>> mp;
map<string, Set> query;
char buf[100000];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    string h, q;
    int cnt = 0;
    for (int j = 0; buf[j]; ++j) {
      if (buf[j] == '/') ++cnt;
      if (cnt <= 2) h += buf[j];
      else q += buf[j];
    }
    query[h].insert(q);
  }
  for (auto &x: query) {
    mp[x.second].push_back(x.first);
  }
  vector<vector<string>> ret;
  for (auto &x: mp) {
    if (x.second.size() > 1) ret.push_back(x.second);
  }
  printf("%d\n", (int)ret.size());
  for (auto &x: ret) {
    for (auto &s: x) printf("%s ", s.c_str());
    puts("");
  }
  return 0;
}