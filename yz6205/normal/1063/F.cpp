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

#include <iostream>
#include <utility>

template<class __TyFirst, class __TySecond>
std::ostream&
operator<<(std::ostream& out, const std::pair<__TyFirst, __TySecond>& o)
{
  out << "(" << o.first << "," << o.second << ")";
  return out;
}

#ifdef __LOCALE__

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
logArray(_ForwardIterator __begin,
         _ForwardIterator __end,
         const char* __sep = 0)
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
logArray(_ForwardIterator __begin,
         _ForwardIterator __end,
         const char* __sep = 0)
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
constexpr int B = 20;
constexpr int C = 26;

struct SAM {
  struct Node {
    int link=-1, next[C], len=0;
    std::vector<int> e; int fa[B], dl, dr;
    Node () { memset(next, -1, sizeof(next)); }
  } p[N * 2];

  static constexpr int root = 0;
  int last = root, cnt = last + 1, dfn=0;
  int pos[N], pos_top = 0;

  void insert(std::size_t c) {
    int cur = pos[pos_top++] = cnt++;
    p[cur].len = p[last].len + 1;
    int pos = last;
    while (pos != -1 && p[pos].next[c] == -1) {
      p[pos].next[c] = cur; pos = p[pos].link; }
    if (pos == -1) { p[cur].link = root; }
    else { int q = p[pos].next[c];
      if (p[q].len == p[pos].len + 1) { 
        p[cur].link = q; }
      else {
        int clone = cnt++;
        p[clone] = p[q];
        p[clone].len = p[pos].len + 1;
        p[q].link = p[cur].link = clone;
        while (pos != -1 && p[pos].next[c] == q) {
          p[pos].next[c] = clone; pos = p[pos].link; } } }
    last = cur; }
  void build() {
    repa (i,cnt-1) p[p[i].link].e.push_back(i); }
  void dfs(int u = root) {
    p[u].dl = dfn++; p[u].fa[0] = p[u].link;
    rep (i,B-1) if (p[u].fa[i] != -1) { p[u].fa[i+1] = p[ p[u].fa[i] ].fa[i]; }
    for (int v: p[u].e) { dfs(v); }
    p[u].dr = dfn - 1; }
  int jump(int pos, int len) {
    repb (i,B-1,0) if (p[pos].fa[i] != -1 && p[p[pos].fa[i]].len >= len) {
      pos = p[pos].fa[i]; } 
    return pos; }
} SAM;

struct STree {
public:
  void init(int l, int r) { g_l = l; g_r = r; }
  void modify(int pos, int val) { __modify(g_l, g_r, pos, val, root); }
  int query(int l, int r) { return __query(l, r, g_l, g_r, root); }

private:
  struct Node {
    int val;
    void pushUp(const Node& a, const Node& b) {
      val = std::max(a.val, b.val); }
  } p[N * 8];
  static constexpr int root = 1;
  int g_l, g_r;
  
  void __modify(int l, int r, int pos, int val, int u) {
    if (l == r) { p[u].val = val; return; }
    int mid = (l + r) / 2;
    if (pos <= mid) { __modify(l, mid, pos, val, u+u); }
    else { __modify(mid+1,r, pos, val, u+u+1); }
    p[u].pushUp(p[u+u], p[u+u+1]); }
  int __query(int sl, int sr, int l, int r, int u) {
    if (sl <= l && r <= sr) { return p[u].val; }
    int mid = (l + r) / 2;
    if (sr <= mid) { return __query(sl, sr, l, mid, u+u); }
    if (sl > mid) { return __query(sl, sr, mid+1, r, u+u+1); }
    return std::max(__query(sl,sr, l,mid, u+u), __query(sl,sr, mid+1,r, u+u+1)); }
} St;

char s[N];
int dp[N], n;

void preInit() { } void init() {
  scanf("%d", &n); scanf("%s", s); std::reverse(s, s+n);
  rep (i,n) SAM.insert(s[i] - 'a'); SAM.build(); SAM.dfs(); 
  St.init(0, SAM.cnt - 1);
} void solve() {
  see(s);
  dp[0] = 1;
  int left = 0;
  auto check = [](int pos, int len) {
    int pos0 = SAM.jump(SAM.pos[pos - 1], len - 1);
    int pos1 = SAM.jump(SAM.pos[pos], len - 1);
    return St.query(SAM.p[pos0].dl, SAM.p[pos0].dr) + 1 >= len ||
           St.query(SAM.p[pos1].dl, SAM.p[pos1].dr) + 1 >= len; };
  repa (i,n-1) {
    dp[i] = dp[i-1] + 1;
    while (!check(i, dp[i])) {
      dp[i]--; St.modify(SAM.p[ SAM.pos[left] ].dl, dp[left]); 
      left++; } }
  logArray(dp, dp+n);
  printf("%d\n", *std::max_element(dp, dp+n)); 
}