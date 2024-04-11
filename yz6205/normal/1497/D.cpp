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

std::string cout_list_sep = " ";
template<class IterateType, typename = decltype(std::declval<IterateType>().begin()),
                            typename = decltype(std::declval<IterateType>().end()),
                            typename = typename std::enable_if<std::is_convertible<
                                typename std::iterator_traits< typename IterateType::iterator> ::iterator_category,
                                std::input_iterator_tag> ::value> ::type,
                            typename = typename std::enable_if<!std::is_same<std::string, typename std::decay<IterateType>::type>::value>::type,
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
#ifndef RANGE_H_
#define RANGE_H_

#include <stdexcept>
#include <iterator>
#include <type_traits>

namespace Temps {

template <typename _IntType>
class RangeInt {
  static_assert(std::is_integral<_IntType>::value, "RangeInt object must have integral value type");

public:
  class iterator : public std::iterator<std::input_iterator_tag, _IntType, _IntType, const _IntType*, _IntType> {
    _IntType val, step;

  public:
    using typename std::iterator<std::input_iterator_tag, _IntType, _IntType, const _IntType*, _IntType>::reference;
    explicit constexpr iterator(int val, int step) noexcept : val(val), step(step) {}
    constexpr iterator& operator++() noexcept { val += step; return *this; }
    constexpr iterator operator++(int) noexcept { iterator ret = *this; val += step; return ret; }
    constexpr bool operator== (const iterator& rhs) const noexcept { return val == rhs.val; }
    constexpr bool operator!= (const iterator& rhs) const noexcept { return val != rhs.val; }
    constexpr reference operator*() const { return val; }
  };

  typedef  _IntType    value_type;
  typedef  _IntType    size_type;
  const value_type _begin, _step, _end;

  explicit constexpr RangeInt(const value_type end) noexcept : _begin(0), _step(1), _end(end>0 ? end : 0) {}
  explicit constexpr RangeInt(const value_type begin, const value_type end) noexcept : 
    _begin(begin), _step(1), _end(end>begin ? end : begin) {}
  explicit constexpr RangeInt(const value_type begin, const value_type end, const value_type step) :
    _begin(begin), _step(step), _end(
      ((step>0&&end<=begin) || (step<0&&end>=begin)) ? begin :
      (step>0 ? begin+(end-begin+step-1)/step*step : begin+(begin-end-step-1)/(-step)*step)) {}

  constexpr iterator begin() const noexcept { return iterator(_begin, _step); }
  constexpr iterator end() const noexcept { return iterator(_end, _step); }
  constexpr size_type size() const noexcept { return (_end - _begin) / _step; }
};

template <class IntType,
          typename = typename std::enable_if<
            std::is_integral<IntType>::value>::type>
inline constexpr 
RangeInt<IntType> range(IntType arg1) {
  return RangeInt<IntType>(arg1);
}

template <class IntType,
          typename = typename std::enable_if<
            std::is_integral<IntType>::value>::type>
inline constexpr 
RangeInt<IntType> range(IntType arg1, IntType arg2) {
  return RangeInt<IntType>(arg1, arg2);
}

template <class IntType,
          typename = typename std::enable_if<
            std::is_integral<IntType>::value>::type>
inline constexpr 
RangeInt<IntType> range(IntType arg1, IntType arg2, IntType arg3) {
  return RangeInt<IntType>(arg1, arg2, arg3);
}

} /* namespace Temps */

using Temps::range;

#endif

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

// #include "/home/jack/code/creats/STree.h"
// #include "/home/jack/code/creats/Tree.h"
// #include "/home/jack/code/creats/Graph.h"
// #include "/home/jack/code/creats/Intm.h"
// #include "/home/jack/code/Math/Poly/main.h"

#include <bits/stdc++.h>

#define MULTIPLE_TEST_CASES_WITH_T
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

constexpr int N = 5005;
int tag[N], s[N], n;
long long dp[N];

void preInit() { } void init() {
  n = sc.n();
  for (int i: range(n)) { tag[i] = sc.n(); }
  for (int i: range(n)) { s[i] = sc.n(); }
  std::fill(dp, dp+n, 0);
} void solve() {
  for (int u=1;u<n;++u) for (int v=u-1;v>=0;v--) if (tag[u] != tag[v]) {
    int ds = std::abs(s[u] - s[v]);
    long long du = dp[v] + ds, dv = dp[u] + ds;
    checkMax(dp[u], du); checkMax(dp[v], dv); }
  std::cout << *std::max_element(dp, dp+n) << std::endl;
}