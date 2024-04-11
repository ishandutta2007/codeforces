// Copyright (C) 2020 JacderZhang
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef LOG_H_
#define LOG_H_ 1

#ifdef __LOCALE__

#include <iostream>
template<typename T>
void
__ses(T a)
{
  std::cout << a << " ";
}
template<typename T, typename... Args>
void
__ses(T a, Args... b)
{
  std::cout << a << " ";
  __ses(b...);
}
#define ses(...)                                                               \
  {                                                                            \
    std::cout << #__VA_ARGS__ << " = ";                                        \
    __ses(__VA_ARGS__);                                                        \
  }
#define see(...)                                                               \
  {                                                                            \
    ses(__VA_ARGS__);                                                          \
    std::cout << std::endl;                                                    \
  }
#define slog(format, ...) printf(format "\n", __VA_ARGS__)

static constexpr char __log_space[] = " ";
template<typename _ForwardIterator>
void
logArray(_ForwardIterator __begin, _ForwardIterator __end, const char* __sep = 0)
{
  if (__sep == 0) {
    __sep = __log_space;
  }
  while (__begin != __end) {
    std::cout << *__begin << *__sep;
    ++__begin;
  }
  std::cout << std::endl;
}

#else

#define see(...)
#define ses(...)
#define slog(format, ...)
template<typename _ForwardIterator>
void
logArray(_ForwardIterator __begin, _ForwardIterator __end, const char* __sep = 0)
{}

#endif

#endif /* LOG_H_ */
#ifndef LOOP_H_
#define LOOP_H_ 1

#define repe(a, b) for (int a = 0; a < (int)b.size(); a++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repa(i, n) for (int i = 1; i <= n; i++)
#define repi(i, a, b) for (int i = a; i <= b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)

#endif /* LOOP_H_ */
#ifndef BASE_H_
#define BASE_H_ 1

template<class T>
inline bool
checkMin(T& a, T b)
{
  return (a > b ? a = b, 1 : 0);
}
template<class T>
inline bool
checkMax(T& a, T b)
{
  return (a < b ? a = b, 1 : 0);
}

#endif /* BASE_H_ */
// #include "/home/jack/code/creats/STree.h"
// #include "/home/jack/code/creats/Tree.h"
// #include "/home/jack/code/creats/Graph.h"
// #include "/home/jack/code/creats/Intm.h"
// #include "/home/jack/code/Math/Poly/main.h"

#include <bits/stdc++.h>

// #define MULTIPLE_TEST_CASES_WITH_T
// #define MULTIPLE_TEST_CASES_WITHOUT_T
#ifndef _BODY_MAIN
#define _BODY_MAIN 1

#ifndef CUSTOM_MAIN
void
preInit();
void
init();
void
solve();
int32_t
main()
{
  preInit();
#ifdef MULTIPLE_TEST_CASES_WITH_T
  int T;
#ifdef SCANNER_H_
  T = sc.nextInt();
#else
  scanf("%d", &T);
#endif /* SCANNER_H_ */
  while (T--) {
    init();
    solve();
  }
#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T
  while (1) {
    try {
      init();
    } catch (bool t) {
      return 0;
    }
    solve();
  }
#else
  init();
  solve();
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */
#endif /* MULTIPLE_TEST_CASES_WITH_T */
  return 0;
}
#endif /* CUSTOM_MAIN */

#endif /* _BODY_MAIN */
// #define int long long

/** My code begins here **/

constexpr int N = 500005;
constexpr int M = 50005;
constexpr int C = 26;
constexpr int B = 18;

namespace STree {
struct Node {
  Node *l=nullptr, *r=nullptr; int max=0, id=0;
  void pushUp() { max = 0;
    if (l != nullptr) { if (checkMax(max, l->max)) { id = l->id; } } 
    if (r != nullptr) { if (checkMax(max, r->max)) { id = r->id; } } }
}; Node p[M * 40];

int g_l, g_r;
Node* newNode() {
  static std::size_t cnt = 0;
  return &p[cnt++]; }
void __modify(int p, int l, int r, int val, Node* &u) {
  if (u == nullptr) { u = newNode(); }
  if (l == r) { u->max += val; u->id = l; return; }
  int mid = (l + r) / 2;
  if (p <= mid) { __modify(p, l, mid, val, u->l); }
  else { __modify(p, mid+1, r, val, u->r); } 
  u->pushUp(); }
void __merge(Node* &u, Node* &v) {
  if (v == nullptr) { return; }
  if (u == nullptr) { u = v; return; }
  Node* nu = newNode(); *nu = *u; u = nu;
  if (u->l == nullptr && u->r == nullptr) { u->max += v->max; }
  else { __merge(u->l, v->l); __merge(u->r, v->r); u->pushUp(); } }
std::pair<int, int> __query(int sl, int sr, int l, int r, Node* u) {
  if (sl <= l && r <= sr) { return std::make_pair(u->max, -u->id); }
  std::pair<int, int> res(0, -sl); int mid = (l + r) / 2;
  if (sl <= mid && u->l != nullptr) { checkMax(res, __query(sl, sr, l, mid, u->l)); }
  if (sr > mid && u->r != nullptr) { checkMax(res, __query(sl, sr, mid+1, r, u->r)); }
  return res; }

void init(int n) { g_l = 1; g_r = n; }
void modify(Node* &u, int p, int val) { __modify(p, g_l, g_r, val, u); }
void merge(Node* &u, Node* &v) { __merge(u, v); }
std::pair<int,int> query(Node* u, int sl, int sr) { return __query(sl, sr, g_l, g_r, u); }

} /* namespace STree */

struct GSAM {
  struct Node {
    int link=-1, next[C], len=0; STree::Node* pset;
    std::vector<int> e; int fa[B];
    Node() { memset(next,-1,sizeof(next)); } };

  Node p[M*2];
  static constexpr int root = 0;
  int last=root, cnt=last+1, gcnt=0;
  int s_pos[N], s_len[N];
  
  void reset() { last = root; gcnt++; }
  void insert(std::size_t c) {
    { int q = p[last].next[c];
      if (q != -1 && p[q].len == p[last].len + 1) {
        STree::modify(p[q].pset, gcnt, 1); last = p[last].next[c]; return; } }
    int cur = cnt++;
    p[cur].len = p[last].len + 1;
    int pos = last;
    while (pos != -1 && p[pos].next[c] == -1) {
      p[pos].next[c] = cur; pos = p[pos].link;  }
    if (pos == -1) { p[cur].link = root; }
    else { int q = p[pos].next[c];
      if (p[q].len == p[pos].len + 1) { p[cur].link = q; }
      else {
        int clone = cnt++;
        p[clone] = p[q]; p[clone].pset = nullptr;
        p[clone].len = p[pos].len + 1;
        p[q].link = p[cur].link = clone;
        while (pos != -1 && p[pos].next[c] == q) {
          p[pos].next[c] = clone; pos = p[pos].link; } } }
    STree::modify(p[cur].pset, gcnt, 1); last = cur; }

  void build() {
    repa (i,cnt-1) { p[p[i].link].e.push_back(i); } }    
  void dfs(int u = root) {
    p[u].fa[0] = p[u].link;
    rep (i,B-1) if (p[u].fa[i] != -1) { p[u].fa[i+1] = p[ p[u].fa[i] ].fa[i]; }
    for (int v: p[u].e) { dfs(v); STree::merge(p[u].pset, p[v].pset); } }

  void run(char* s) {
    std::size_t len = std::strlen(s);
    s_pos[0] = root; s_len[0] = 0;
    for (std::size_t i=0; i<len; ++i) {
      int pos = s_pos[i]; s_len[i + 1] = s_len[i];
      std::size_t c = s[i] - 'a';
      // see(i, c, pos, p[pos].next[c], s_len[i + 1]);
      while (pos != -1 && p[pos].next[c] == -1) {
        pos = p[pos].link; if (pos != -1) { s_len[i + 1] = p[pos].len; } }
      if (pos == -1) { s_pos[i + 1] = root; s_len[i + 1] = 0; }
      else { s_pos[i + 1] = p[pos].next[c]; s_len[i + 1]++; } } }
  int next(int pos, std::size_t c) {
    while (pos != -1 && p[pos].next[c] == -1) {
      pos = p[pos].link; }
    if (pos == -1) { return root; }
    return p[pos].next[c]; }
  int jump(int pos, int len) {
    repb (i,B-1,0) if (p[pos].fa[i] != -1) {
      if (p[ p[pos].fa[i] ].len >= len) {
        pos = p[pos].fa[i]; } }
    return pos; }

} GSAM;

char s[N], t[M];
int s_pos[N];

void preInit() { } void init() {
  scanf("%s", s); int m; scanf("%d", &m);
  STree::init(m);
  rep (i,m) {
    scanf("%s", t); int l = std::strlen(t);
    GSAM.reset(); rep (j,l) GSAM.insert(t[j] - 'a'); }
  GSAM.build(); GSAM.dfs(); GSAM.run(s);
} void solve() {
  int q; scanf("%d", &q);
  while (q--) {
    int l, r, s, t; scanf("%d%d%d%d", &s, &t, &l, &r);
    int len = r - l + 1; 
    int pos = GSAM.jump(GSAM.s_pos[r], len);
    // see(pos, GSAM.s_len[r]);
    if (GSAM.s_len[r] < len) {
      printf("%d %d\n", s, 0); continue; }
    auto res = STree::query(GSAM.p[pos].pset, s, t);
    printf("%d %d\n", -res.second, res.first); }
}