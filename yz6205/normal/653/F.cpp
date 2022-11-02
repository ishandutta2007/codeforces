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
#define slog(format, ...) printf(format, __VA_ARGS__)

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

/** My code begins here **/

constexpr int N = 500005;
constexpr int C = 2;
char s[N]; int n;
int height[N];

struct QueryLower {
  int a[N], left_lower[N];
  void init(int _a[], int n) {
    memcpy(a, _a, sizeof(*a) * n);
    std::stack<int> upp;
    for (int i=0; i<n; ++i) {
      while (!upp.empty() && a[upp.top()] >= a[i]) { upp.pop(); }
      left_lower[i] = upp.empty() ? 0 : upp.top() + 1;
      upp.push(i); } }
} ql;

struct InterHit {
  int a[N], n;
  struct QueryType { int r, val, ans; };
  QueryType qs[N*2]; std::size_t qs_top = 0;
  int _cnt[N*2], *cnt=_cnt+N;
  
  void init(int _a[], int _n) {
    n = _n; memset(_cnt, 0, sizeof(_cnt));
    memcpy(a, _a, sizeof(*a) * n); }
  void regQuery(int l, int r, int val) {
    slog("REGISTER QUERY: l=%d, r=%d, val=%d\n", l,r,val);
    qs[qs_top++] = {l-1, val, -1};
    qs[qs_top++] = {r, val, 1}; }
  long long getAns() {
    std::sort(qs, qs+qs_top, [](QueryType a, QueryType b) { return a.r < b.r; });
    int pos = 0; while (pos<qs_top && qs[pos].r < 0) { qs[pos].ans = 0; pos++; }
    for (std::size_t i=0; i<n; ++i) {
      cnt[a[i]] ++;
      see(i, a[i], cnt[a[i]]);
      while (pos < qs_top && qs[pos].r <= i) {
        qs[pos].ans *= cnt[qs[pos].val]; pos++; } }
    long long res = 0;
    for (std::size_t i=0; i<qs_top; ++i) { 
      res += qs[i].ans; }
    return res; }
} hit;

struct SAM {
  struct Node {
    int next[C], link=-1, len=0, pos=0;
    Node () { memset(next, -1, sizeof(next)); }
  };

  Node p[N*2];
  static constexpr int root = 0;
  int last = root, cnt = root + 1;

  void insert(std::size_t c) {
    int cur = cnt++;
    p[cur].len = p[last].len + 1;
    p[cur].pos = p[cur].len;
    int pos = last;
    while (pos != -1) {
      if (p[pos].next[c] != -1) { break; }
      p[pos].next[c] = cur;
      pos = p[pos].link; }
    if (pos == -1) { p[cur].link = root; } 
    else {
      int q = p[pos].next[c];
      if (p[q].len == p[pos].len + 1) { p[cur].link = q; }
      else {
        int clone = cnt++;
        p[clone] = p[q];
        p[clone].len = p[pos].len + 1;
        p[cur].link = p[q].link = clone;
        while (pos != -1 && p[pos].next[c] == q) {
          p[pos].next[c] = clone;
          pos = p[pos].link; } } }
    last = cur; }

  long long solve() {
    for (int i=1; i<cnt; ++i) {
      int len = p[i].len, pos = p[i].pos;
      int l = pos - len, r = pos - p[ p[i].link ].len;
      // see(i,l,r,len, p[ p[i].link ].len);
      slog("distinguish interval is [1,%d] : %d\n", r, pos);
      checkMax(l, ql.left_lower[pos]);
      if (l >= r) { continue; }
      hit.regQuery(l, r-1, height[pos]); }
    return hit.getAns(); }
} sam;

void preInit() { } void init() {
  scanf("%d%s", &n, s); 
} void solve() {
  rep (i,n) height[i+1] = height[i] + (s[i] == '(' ? 1 : -1);
  logArray(height,n+1);
  ql.init(height, n+1); hit.init(height, n+1);
  logArray(ql.left_lower,n+1);
  rep (i,n) sam.insert(s[i] == ')');
  printf("%lld\n", sam.solve());
}