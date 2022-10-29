#include <bits/stdc++.h>
using LL = long long;

struct AhoCorasick {
  static const int MAXL = 3e5 * 20, C = 26;
  struct node {
    node *go[C], *link;
    LL cnt;
  } pool[MAXL];
  int sz;
  node* alloc() {
    //memset(&pool[sz], 0, sizeof(pool[sz]));
    return &pool[sz++];
  }
  void init() {
    sz = 0;
  }
  void ins(node *rt, const char *s) {
    node *p = rt;
    for (int i = 0; s[i]; ++i) {
      int o = s[i] - 'a';
      if (!p->go[o]) p->go[o] = alloc();
      p = p->go[o];
    }
    p->cnt++;
  }
  void build(node *rt) {
    std::queue<node*> queue;
    for (int o = 0; o < C; ++o) {
      if (rt->go[o]) {
        rt->go[o]->link = rt;
        queue.push(rt->go[o]);
      } else {
        rt->go[o] = rt;
      }
    }
    for (; !queue.empty(); queue.pop()) {
      node* u = queue.front();
      u->cnt += u->link->cnt;
      for (int o = 0; o < C; ++o) {
        if (u->go[o]) {
          u->go[o]->link = u->link->go[o];
          queue.push(u->go[o]);
        } else {
          u->go[o] = u->link->go[o];
        }
      }
    }
  }
  LL find(node *rt, const char *s) {
    node *p = rt;
    LL ret = 0;
    for (int i = 0; s[i]; ++i) {
      int o = s[i] - 'a';
      p = p->go[o];
      ret += p->cnt;
    }
    return ret;
  }
} umr;

std::vector<std::string> pat;

struct trie {
  AhoCorasick::node *rt;
  std::vector<int> u;
  void merge(const trie &rhs) {
    rt = umr.alloc();
    for (auto &s: u) {
      umr.ins(rt, pat[s].c_str());
    }
    for (auto &s: rhs.u) {
      umr.ins(rt, pat[s].c_str());
      u.push_back(s);
    }
    umr.build(rt);
  }
  void merge(int s) {
    rt = umr.alloc();
    u.push_back(s);
    umr.ins(rt, pat[s].c_str());
    umr.build(rt);
  }
  LL ask(const char s[]) {
    return umr.find(rt, s);
  }
  int size() {
    return u.size();
  }
};

void ins(std::vector<trie> &T, char s[]) {
  pat.push_back(s);
  trie now;
  now.merge(pat.size() - 1);
  while (!T.empty() && now.size() == T.back().size()) {
    now.merge(T.back());
    T.pop_back();
  }
  T.push_back(now);
}

LL ask(std::vector<trie> &T, char s[]) {
  if (T.empty()) return 0;
  LL ret = 0;
  for (auto &x: T) {
    ret += x.ask(s);
  }
  return ret;
}

char s[300010];

void run() {
  int m;
  scanf("%d", &m);
  std::vector<trie> add, sub;
  for (int i = 0; i < m; ++i) {
    int op;
    scanf("%d%s", &op, s);
    if (op == 1) ins(add, s);
    else if (op == 2) ins(sub, s);
    else std::cout << ask(add, s) - ask(sub, s) << std::endl;
  }
}

int main() {
  run();
  return 0;
}