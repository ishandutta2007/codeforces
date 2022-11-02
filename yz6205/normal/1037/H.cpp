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

template<class _Type>
void
logArray(_Type a[], int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << a[i] << ' ';
  std::cout << std::endl;
}

#else

#define see(...)
#define ses(...)
#define slog(format, ...)
template<class _Type>
void
logArray(_Type a[], int n)
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
#ifndef SAFE_PTR_H_ 
#define SAFE_PTR_H_ 1

template <typename T>
struct safe_ptr {
protected:
  T* ptr; 
public:
  static T fall_back;
  safe_ptr (T* ptr=nullptr) : ptr(ptr) {}
  inline T* null() { return &fall_back; }
  inline safe_ptr& operator = (T* const unsure_ptr) { ptr = unsure_ptr; return *this; }
  inline T* operator -> () const { if (ptr == nullptr) { return &fall_back; } return ptr; }
  inline explicit operator T* () const { return ptr; }
  inline operator bool () const { return ptr != &fall_back; }
  inline bool operator == (const safe_ptr<T> B) const { return ptr == B.ptr; }
  inline void release() { delete ptr; ptr = nullptr; }
  inline T& operator * () const { return *ptr; }
};

template <typename T> T safe_ptr<T>::fall_back;

#endif /* SAFE_PTR_H */

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

constexpr int N = 100005;
constexpr int C = 26;

namespace STree {
struct Node { Node *l, *r; };
int g_n;
Node pool[N*40]; std::size_t pool_top = 0;
inline Node* newNode() { return &pool[pool_top++]; }
void _modify(Node *&u, int l, int r, int p) {
  if (u == nullptr) { u = newNode(); }
  if (l == r) { return; }
  int mid = (l + r) / 2;
  if (p <= mid) { _modify(u->l, l, mid, p); }
  else { _modify(u->r, mid+1, r, p); } }
void merge(Node *&u, Node *&v) {
  if (v == nullptr) { return; }
  if (u == nullptr) { u = v; return; }
  Node *c = newNode(); *c = *u; u = c;
  merge(u->l, v->l); merge(u->r, v->r); }
bool _query(Node *&u, int sl, int sr, int l, int r) {
  if (u == nullptr || sl > sr) { return 0; }
  if (sl <= l && r <= sr) { return 1; }
  int mid = (l + r) / 2;
  if (sl > mid) { return _query(u->r, sl, sr, mid+1, r); }
  else if (sr <= mid) { return _query(u->l, sl, sr, l, mid); }
  else { return _query(u->l, sl, sr, l, mid) || _query(u->r, sl, sr, mid+1, r); } }

void init(int _g_n) { g_n = _g_n; }
void modify(Node *&u, int p) { _modify(u,0,g_n,p); }
bool query(Node *&u, int l, int r) { return _query(u,l,r,0,g_n); }
} /* STree */ 

struct SAM {
  struct Node {
    int next[C], link=-1, len=0, pos=0, ref=0; STree::Node* pset;
    Node() { memset(next, -1, sizeof(next)); } };

  static constexpr int root = 0;
  int last = root, cnt = root + 1;
  Node p[N*2];

  void insert(std::size_t c) {
    int cur = cnt++; p[cur].len = p[last].len + 1; p[cur].pos = p[cur].len;
    int pos = last;
    while (pos != -1 && p[pos].next[c] == -1) {
      p[pos].next[c] = cur; pos = p[pos].link; }
    if (pos == -1) { p[cur].link = root; }
    else {
      int q = p[pos].next[c];
      if (p[q].len == p[pos].len + 1) { p[cur].link = q; }
      else {
        int clone = cnt++;
        p[clone] = p[q]; p[clone].len = p[pos].len + 1; p[clone].pos = -1;
        p[cur].link = p[q].link = clone;
        while (pos != -1 && p[pos].next[c] == q) {
          p[pos].next[c] = clone; pos = p[pos].link; } } }
    last = cur; }

  void build() {
    rep (i,cnt) if (p[i].pos != -1) { STree::modify(p[i].pset,p[i].pos); }
    repa (i,cnt-1) p[p[i].link].ref++;
    std::queue<int> que; rep (i,cnt) if (p[i].ref == 0) que.push(i); 
    while (!que.empty()) {
      int u = que.front(), fa=p[u].link; que.pop();
      if (p[u].link == -1) { continue; }
      STree::merge(p[fa].pset, p[u].pset); p[fa].ref--;
      if (p[fa].ref == 0) { que.push(fa); } } }

  typedef int State;
  static constexpr State start() { return root; }
  bool hasNext(State u, std::size_t c, int l, int r) {
    int v = p[u].next[c]; if (v == -1) { return false; }
    return STree::query(p[v].pset, l, r); }
  inline State getNext(State u, std::size_t c) { return p[u].next[c]; }
} sam;

char s[N * 2]; int n;

void preInit() { } void init() {
  scanf("%s", s); n = std::strlen(s); STree::init(n);
  rep (i,n) sam.insert(s[i] - 'a'); sam.build();
} void solve() {
  int q; scanf("%d", &q);
  while (q--) {
    int l, r; scanf("%d%d%s", &l, &r, s); 
    int n = std::strlen(s); s[n] = '`'; n++; s[n] = '\0';
    int last_pos = -1, last_char = '\0';
    SAM::State pos = SAM::start();
    rep (i,n) {
      repi (j, s[i]-'a'+1, 'z'-'a') {
        if (sam.hasNext(pos, j, l, r)) {
          last_pos = i; last_char = 'a' + j; break; } }
      if (i != n-1 && sam.hasNext(pos, s[i]-'a', l, r)) {
        pos = sam.getNext(pos, s[i]-'a'); }
      else { break; } 
      l++; }
    if (last_pos == -1) { puts("-1"); }
    else { s[last_pos] = '\0'; printf("%s%c\n", s, last_char); } }
}