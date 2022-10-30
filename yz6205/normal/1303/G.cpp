// Copyright (C) 2021 JacderZhang
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


#ifndef SCANNER_H_
#define SCANNER_H_ 1
#include <stdio.h>
#include <stdlib.h>
class Scanner {
private:
  static const int BUFFER_SIZE = 1 << 18;
  char buff[BUFFER_SIZE];
  char *buffPos, *buffLim;
  FILE *file;

public:
  Scanner(FILE *file) {
    this->file = file;
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    buffPos = buff; }

private:
  inline void flushBuff() {
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    if (buffLim == buff) {
      *buffLim++ = '\n'; }
    buffPos = buff; }
  inline bool isWS(char t) {
    return t <= ' '; }
  inline bool isDig(char t) {
    return t >= '0' && t <= '9'; }
  inline void nextPos() {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff(); } }
public:
  inline char getchar() {
    char ch = *buffPos;
    nextPos();
    return ch; }
  inline void next(char* s) {
    while (isWS(*buffPos)) {
      nextPos(); }
    while (!isWS(*buffPos)) {
      *s = *buffPos;
      s++;
      nextPos(); }
    *s = '\0'; }
  inline void nextLine(char* s) {
    while (*buffPos != '\n') {
      nextPos(); }
    if (*buffPos == '\n') {
      nextPos(); }
    while (*buffPos != '\n') {
      *s++ = *buffPos;
      nextPos(); }
    *s = '\0'; }
  inline int nextInt() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos(); }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos(); }
    return res * sign; }
  inline long long nextLong() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos(); }
    long long sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos(); }
    return res * sign; }
  inline int n() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    int res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    return res; }
  inline long long nl() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    return res; }
  inline long long nlm(const int MOD) {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = (res * 10 + (*buffPos - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    return res; }
  inline double nextDouble() {
    while (isWS(*buffPos)) {
      nextPos(); }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos(); }
    if (*buffPos == '.') {
      nextPos();
      double ep = 1;
      while (isDig(*buffPos)) {
        ep *= 0.1;
        res += ep * (*buffPos - '0');
        nextPos(); } }
    return sign * res; }
  inline char nextChar() {
    while (isWS(*buffPos))
      nextPos();
    char res = *buffPos;
    nextPos();
    return res; }
  ~Scanner() {
    fclose(file); } };
#ifndef SCANNER_H_CUSTOM
Scanner sc(stdin);
#endif
#endif /* SCANNER_H_ */
#ifndef LOG_H_
#define LOG_H_ 1

#include <iostream>
#include <utility>
#include <iterator>
#include <string>

template<class __TyFirst, class __TySecond>
std::ostream&
operator<<(std::ostream& out, const std::pair<__TyFirst, __TySecond>& o);

static std::string cout_list_sep = " ";
template<class IterateType, typename = decltype(std::declval<IterateType>().begin()),
                            typename = decltype(std::declval<IterateType>().end()),
                            typename = typename std::enable_if<std::is_convertible<
                                typename std::iterator_traits< typename IterateType::iterator> ::iterator_category,
                                std::input_iterator_tag> ::value> ::type,
                            typename = typename std::enable_if<!std::is_base_of<std::string, typename std::decay<IterateType>::type>::value>::type,
                            typename value_type = typename IterateType::value_type>
std::ostream& operator<< (std::ostream& out, const IterateType& a)
{
  for (const auto& i: a) 
    out << i << cout_list_sep;
  return out; 
}

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
__ses(const T& a)
{
  std::cout << a << " ";
}
template<typename T, typename... Args>
void
__ses(const T& a, Args... b)
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
logArray(_ForwardIterator,
         _ForwardIterator,
         const char* = 0)
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
#ifndef UTIL_H_
#define UTIL_H_ 1

#include <algorithm>

#ifndef VECTOR_H_
#include <vector>
#endif

namespace Temps {

template<class T>
inline bool
checkMin(T& a, T b)
{ return (b < a ? a = b, 1 : 0); }

template<class T>
inline bool
checkMax(T& a, T b)
{ return (a < b ? a = b, 1 : 0); }

template <class IntType, typename = typename
          std::enable_if<std::is_integral<IntType>::value>::type>
IntType
gcd(const IntType a, const IntType b) {
  return b == 0 ? a : gcd(b, a % b); }

template <class ForwardIterator, class OutputIterator>
void dissociate(ForwardIterator __begin, ForwardIterator __end, OutputIterator __dest) {

#ifdef VECTOR_H_
  Temps::Vector
#else
  std::vector
#endif
    <typename std::iterator_traits<ForwardIterator>::value_type> values(__begin, __end); 
  std::sort(values.begin(), values.end()); std::unique(values.begin(), values.end()); 
  while (__begin != __end) {
    *__dest = std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), *__begin));
    __dest++; __begin++; } }

}

using Temps::checkMin;
using Temps::checkMax;

#endif /* UTIL_H_ */
#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstdlib>
#include <utility>
#include <iterator>
#include <initializer_list>
#include <type_traits>

namespace Temps {

template <class Type>
class Vector {
  static_assert(std::is_trivial<Type>::value, 
                "Temps::Vector can only be used for trival types");

public:
  typedef Type         value_type;
  typedef unsigned int size_type;
  typedef Type&        reference;
  typedef const Type&  const_reference;

  class iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
  public:
    friend class Vector;
    using typename std::iterator<std::random_access_iterator_tag, value_type>::difference_type;
    using typename std::iterator<std::random_access_iterator_tag, value_type>::pointer;
    using typename std::iterator<std::random_access_iterator_tag, value_type>::reference;
  
  private:
    pointer ptr;
    iterator(pointer ptr) : ptr(ptr) {}

  public:
    bool operator== (const iterator rhs) const { return ptr == rhs.ptr; }
    bool operator!= (const iterator rhs) const { return ptr != rhs.ptr; }
    bool operator<  (const iterator rhs) const { return ptr <  rhs.ptr; }
    bool operator<= (const iterator rhs) const { return ptr <= rhs.ptr; }
    bool operator>  (const iterator rhs) const { return ptr >  rhs.ptr; }
    bool operator>= (const iterator rhs) const { return ptr >= rhs.ptr; }

    iterator operator++ ()    { return iterator(++ptr); }
    iterator operator++ (int) { return iterator(ptr++); }
    iterator operator-- ()    { return iterator(--ptr); }
    iterator operator-- (int) { return iterator(ptr--); }

    iterator operator+ (const difference_type dif) const { return iterator(ptr + dif); }
    iterator operator- (const difference_type dif) const { return iterator(ptr - dif); }
    iterator operator+= (const difference_type dif) { ptr += dif; return *this; }
    iterator operator-= (const difference_type dif) { ptr -= dif; return *this; }

    difference_type operator- (const iterator& rhs) const { return ptr - rhs.ptr; }

    operator pointer() { return ptr; }
  };


protected:
  value_type *a = nullptr;
  size_type _capacity=0, _size=0;

  void __grow_capacity(size_type least_size) {
    if (_capacity >= least_size) { return; }
    if (_capacity == 0) { _capacity = 1; }
    while (_capacity < least_size) { _capacity = _capacity * 2; }
    a = static_cast<value_type*>(realloc(a, sizeof(value_type) * _capacity)); }

public:
  Vector() =default;
  explicit Vector(size_type size, const value_type& initial_value = value_type()) : _capacity(size), _size(size) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *__first = a, *const __last = a + _size;
    while (__first != __last) { *__first++ = initial_value; } }

  Vector(const Vector& rhs) : _capacity(rhs._size), _size(rhs._size) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *__first = a, *__r_p = rhs.a, *const __last = a + _size;
    while (__first != __last) { *__first++ = *__r_p++; } }
  Vector(Vector&& rhs) : _capacity(rhs._capacity), _size(rhs._size) {
    a = rhs.a; rhs.a = nullptr; }
  
  template <typename Container, typename =
            decltype(std::declval<Container>().begin(),
                     std::declval<Container>().end())>
  Vector(const Container& list) : _capacity(std::distance(list.begin(), list.end())), _size(_capacity) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *p = a; for (const auto& i: list) { *p++ = i; } }

  template <typename _InputIterator, typename = typename 
            std::enable_if<std::is_convertible<typename std::iterator_traits<_InputIterator>::iterator_category,
                                               std::input_iterator_tag>::value>::type>
  explicit Vector(_InputIterator __first, _InputIterator __last) {
    _size = _capacity = std::distance(__first, __last);
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *p = a; while (__first != __last) { *p++ = *__first++; } }

  inline bool empty() const { return _size == 0; }
  inline size_type size() const { return _size; }
  inline size_type capacity() const { return _capacity; }

  void reserve(size_type __capacity) {
    _capacity = __capacity;
    if (_size > _capacity) { _size = _capacity; }
    a = static_cast<value_type*>(realloc(a, sizeof(value_type) * _capacity)); }
  void resize(size_type  __size) {
    if (_size > __size) { _size = __size; return; }
    __grow_capacity(__size);
    value_type *__un = a + _size, *const __ed = a + __size;
    while (__un != __ed) { *__un++ = value_type(); }
    _size = __size; }
  inline void clear() { resize(0); }

  Vector& operator= (const Vector& rhs) {
    __grow_capacity(rhs._size);
    _size = rhs._size;
    value_type *__first = a;
    const value_type *const __last = a+_size, *__r_p = rhs.a;
    while (__first != __last) { *__first++ = *__r_p++; }
    return *this; }
  Vector& operator= (Vector&& rhs) {
    _size = rhs._size; _capacity = rhs._capacity;
    free(a); a = rhs.a; rhs.a = nullptr; 
    return *this; }

  value_type operator[] (const size_type id) const { return a[id]; }
  value_type& operator[] (const size_type id) { return a[id]; }
  value_type front() const { return a[0]; }
  value_type& front() { return a[0]; }
  value_type back() const { return a[_size - 1]; }
  value_type& back() { return a[_size - 1]; }
  void pop_back() { _size--; }

  Vector& push_back(const value_type& b) {
    __grow_capacity(_size + 1); a[_size] = b; _size++; return *this; }
  Vector& push_back(const Vector& rhs) {
    __grow_capacity(_size + rhs._size);
    for (const auto& i: rhs) { a[_size++] = i; } 
    return *this; }
  Vector& push_back(const std::initializer_list<value_type>& rhs) {
    __grow_capacity(_size + rhs.size());
    for (const auto& i: rhs) { a[_size++] = i; } 
    return *this; }

  inline iterator begin() const { return iterator(a); }
  inline iterator end() const { return iterator(a + _size); }

  ~Vector() { free(a); }

};

} /* namespace Temps */

using Temps::Vector;

#endif /* VECTOR_H_ */

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

#define long long long
constexpr int N = 300005;
int w[N], n;

struct Tree {
  std::vector<int> e[N];
  void addEdge(int u, int v) {
    e[u].push_back(v); e[v].push_back(u); }
};

inline bool checkSlope(const std::pair<long,long>& a, decltype(a) b, decltype(a) c) {
  long dax = b.first - a.first, day = b.second - a.second;
  long dbx = c.first - b.first, dby = c.second - b.second;
  return static_cast<__int128_t>(dax) * dby < static_cast<__int128_t>(day) * dbx; }
inline long max_calc(const std::pair<long,long>& a, decltype(a) b) {
  return a.second + a.first * b.first + b.second; }
long get_max(std::vector<std::pair<long,long>> points, std::vector<std::pair<long,long>> querys) {
  if (points.size() == 0 || querys.size() == 0) { return 0; }
  std::sort(points.begin(), points.end(), [](const std::pair<long,long>& a, decltype(a) b) {
    return a.first < b.first; });
  std::sort(querys.begin(), querys.end(), [](const std::pair<long,long>& a, decltype(a) b) {
    return a.first < b.first; });
  logArray(points.begin(), points.end());
  logArray(querys.begin(), querys.end());
  std::vector<std::pair<long,long>> st;
  for (const auto& p: points) {
    while (st.size() >= 2) {
      const auto& p0 = st[st.size()-2], p1=st[st.size()-1];
      if (!checkSlope(p0, p1, p)) { st.pop_back(); }
      else { break; } }
    st.push_back(p); }
  long res = 0; std::size_t best_id = 0;
  for (const auto& p: querys) {
    while (best_id+1 < st.size() && max_calc(st[best_id], p) <= max_calc(st[best_id+1], p)) { best_id++; }
    checkMax(res, max_calc(st[best_id], p)); }
  return res; }

struct TreePD : public Tree {
  bool vis[N];
  TreePD() { memset(vis,true,sizeof(vis)); }
  int size[N], totSize, rootC, root;
  void getSize(int u, int f) {
    size[u] = 1;
    for (int v: e[u]) if (vis[v] && v != f) {
      getSize(v,u); size[u] += size[v]; } }
  void getRoot(int u, int f) {
    int cost = totSize - size[u];
    for (int v: e[u]) if (vis[v] && v != f) {
      getRoot(v,u); checkMax(cost, size[v]); }
    if (checkMin(rootC, cost)) { root = u; } }
  void get(int u) {
    getSize(u,u); totSize = size[u];
    rootC = std::numeric_limits<int>::max(); getRoot(u,u); }

  void dfsDown(int u, int f, std::vector<std::pair<long,long>>& g, long pre_cnt=0, long pre_sum=0, long pre_tot=0) {
    if (u <= n) { pre_cnt++; pre_sum += w[u]; pre_tot += pre_cnt * w[u]; g.push_back(std::make_pair(pre_sum, pre_tot)); }
    for (int v: e[u]) if (vis[v] && v != f) {
      dfsDown(v, u, g, pre_cnt, pre_sum,  pre_tot); } }
  void dfsUp(int u, int f, std::vector<std::pair<long,long>>& g, long pre_cnt=0, long pre_sum=0, long pre_tot=0) {
    if (u <= n) { pre_cnt++; pre_sum += w[u]; pre_tot += pre_sum; g.push_back(std::make_pair(pre_cnt, pre_tot)); }
    for (int v: e[u]) if (vis[v] && v != f) { 
      dfsUp(v, u, g, pre_cnt, pre_sum , pre_tot); } }
  long dfs(int u) {
    get(u); u = root; vis[root] = false;
    see(u);
    std::vector< std::vector<std::pair<long,long>> > up, down;
    for (int v: e[u]) if (vis[v]) {
      std::vector<std::pair<long,long>> a, b;
      dfsDown(v,u,a, 1,w[u],w[u]); dfsUp(v,u,b); 
      down.emplace_back(std::move(a)); up.emplace_back(std::move(b)); }
    int top = up.size();
    long ans = 0;
    for (int B=1;B<top;B<<=1) {
      std::vector<std::pair<long,long>> a,b;
      for (int i=0;i<top;++i) {
        if (i & B) { for (const auto& p: down[i]) { a.push_back(p); } }
        else { for (const auto& p: up[i]) { b.push_back(p); } } }
      checkMax(ans, get_max(a,b));
      a.clear(); b.clear();
      for (int i=0;i<top;++i) {
        if (!(i & B)) { for (const auto& p: down[i]) { a.push_back(p); } }
        else { for (const auto& p: up[i]) { b.push_back(p); } } }
      checkMax(ans, get_max(a,b)); }
    for (int v: e[u]) if (vis[v]) { checkMax(ans, dfs(v)); }
    return ans; }
} Tsolve;

void preInit() { } void init() {
  n = sc.n();
  rep (i,n-1) { int u=sc.n(), v=sc.n(); Tsolve.addEdge(u,v); }
  repa (i,n) w[i] = sc.n();
} void solve() {
  if (n == 2) { printf("%d\n", std::max(w[1]+w[2]*2, w[2]+w[1]*2)); return; }
  printf("%lld\n", Tsolve.dfs(1));
}