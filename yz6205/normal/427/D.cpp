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
#define slog(format, ...) printf(format, __VA_ARGS__)
#else
#define see(...)
#define ses(...)
#define slog(format, ...)
#endif

template<class _Type>
void
logArray(_Type a[], int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << a[i] << ' ';
  std::cout << std::endl;
}

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

#include <bits/stdc++.h>

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

constexpr int N = 5005;
constexpr int M = 2;
constexpr int C = 26;

struct GSAM {
protected:
  struct Node {
    int next[C], link=-1, size[M], len=0, ref=0;
    Node () { memset(next, -1, sizeof(next)); memset(size, 0, sizeof(size)); }
  };

  Node p[N*M*2];
  static constexpr int root = 0;
  int last = root, cnt = root + 1, bel = 0;

public:
  void reset() { last = root; bel++; }
  void insert(std::size_t c) {
    { int ss = p[last].next[c];
      if (ss != -1 && p[ss].len == p[last].len + 1) {
        last = ss; p[ss].size[bel] = 1; return; } }
    int cur = cnt++;
    p[cur].len = p[last].len + 1;
    p[cur].size[bel] = 1;
    int pos = last;
    while (pos != -1) {
      if (p[pos].next[c] != -1) { break; }
      p[pos].next[c] = cur;
      pos = p[pos].link; }
    if (pos == -1) { p[cur].link = root; }
    else {
      int q = p[pos].next[c];
      if (p[q].len == p[pos].len + 1) {
        p[cur].link = q; }
      else {
        int clone = cnt++;
        memcpy(p[clone].next, p[q].next, sizeof(p[q].next));
        p[clone].link = p[q].link;
        p[clone].len = p[pos].len + 1;
        p[q].link = p[cur].link = clone;
        while (pos != -1 && p[pos].next[c] == q) {
          p[pos].next[c] = clone;
          pos = p[pos].link; } } }
    last = cur; }
  void build() {
    for (int i=1; i<cnt; ++i) { p[ p[i].link ].ref++; }
    std::queue<int> que; for (int i=0; i<cnt; ++i) if (p[i].ref == 0) { que.push(i); }
    while (!que.empty()) {
      int u = que.front(); que.pop();
      int fa = p[u].link;
      if (fa != -1) {
        for (int j=0; j<M; ++j) p[fa].size[j] += p[u].size[j];
        p[fa].ref--; if (p[fa].ref == 0) { que.push(fa); } } } }
  int find() {
    int res = std::numeric_limits<int>::max();
    for (int i=1; i<cnt; ++i) {
      if (p[i].size[0] == 1 && p[i].size[1] == 1) {
        checkMin(res, p[ p[i].link ].len + 1); } }
    return res; }
} sam;

void preInit() { } void init() { } void solve() {
  static char s[N];
  for (int i=0; i<2; ++i) { 
    scanf("%s", s); int l=std::strlen(s); 
    rep (i,l) { sam.insert(s[i] - 'a'); } 
    sam.reset(); }
  sam.build();
  int ans = sam.find();
  printf("%d\n", ans == std::numeric_limits<int>::max() ? -1 : ans);
}