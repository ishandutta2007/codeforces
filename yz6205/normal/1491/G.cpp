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
#ifndef PIPE_H_
#define PIPE_H_

#include <stdexcept>
#include <iterator>
#include <type_traits>
#include <functional>
#include <algorithm>

namespace Temps {

template <class...> using valid_to_void = void;

template <typename _Ty, typename = void>
struct is_input_iterator : public std::false_type {};
template <typename _Ty>
struct is_input_iterator<_Ty, typename std::enable_if<std::is_convertible<
                              typename std::iterator_traits<_Ty>::iterator_category,std::input_iterator_tag>
                          ::value>::type> : public std::true_type {};

template <typename _Ty, typename = void>
struct is_ranges : public std::false_type {};
template <typename _Ty>
struct is_ranges<_Ty, valid_to_void<typename _Ty::iterator>> : public 
  std::conditional<
    is_input_iterator<typename _Ty::iterator>::value,
  std::true_type, std::false_type>::type {};


namespace ranges {

struct rangesMethod {};

// reverse
struct reverse_t : public rangesMethod {
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  Range&& operator() (Range&& obj) const {
    std::reverse(obj.begin(), obj.end()); 
    return std::forward<Range>(obj); }
} reverse;

// sort
struct sort_t : public rangesMethod {
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  Range&& operator() (Range&& obj) const {
    std::sort(obj.begin(), obj.end()); 
    return std::forward<Range>(obj); }
} sort;

// unique
struct unique_t : public rangesMethod {
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  Range operator() (Range&& obj) const {
    return Range(obj.begin(), std::unique(obj.begin(), obj.end())); }
} unique;

// transform
template <class FuncType>
struct transform_t : public rangesMethod {
  const FuncType func;
  transform_t() =delete;
  explicit transform_t(FuncType func) : func(func) {}
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  Range&& operator() (Range&& obj) const {
    for (auto& x: obj) { x = func(x); }
    return std::forward<Range>(obj); } };
template <class FuncType>
transform_t<FuncType> transform(FuncType func) {
  return transform_t<FuncType>(func); }

// foreach
template <class FuncType>
struct foreach_t : public rangesMethod {
  const FuncType func;
  foreach_t() =delete;
  explicit foreach_t(FuncType func) : func(func) {}
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  int operator() (const Range& obj) const {
    for (const auto& x: obj) { func(x); }
    return 0; } };
template <class FuncType>
foreach_t<FuncType> foreach(FuncType func) {
  return foreach_t<FuncType>(func); }

// filter
template <class FuncType>
struct filter_t : public rangesMethod {
  const FuncType func;
  filter_t() =delete;
  explicit filter_t(FuncType func) : func(func) {}
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  Range operator() (const Range& obj) const {
    Range res;
    for (const auto& x: obj) if (func(x)) { res.push_back(x); }
    return res; } };
template <class FuncType>
filter_t<FuncType> filter(FuncType func) {
  return filter_t<FuncType>(func); }

// sortby
template <class FuncType>
struct sortby_t : public rangesMethod {
  const FuncType func;
  sortby_t() =delete;
  explicit sortby_t(FuncType func) : func(func) {}
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  Range&& operator() (Range&& obj) const {
    std::sort(obj.begin(), obj.end(), func);
    return std::forward<Range>(obj); } };
template <class FuncType>
sortby_t<FuncType> sortby(FuncType func) {
  return sortby_t<FuncType>(func); }

// count
template <class FuncType>
struct count_t : public rangesMethod {
  const FuncType func;
  count_t() =delete;
  explicit count_t(FuncType func) : func(func) {}
  template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type>
  int operator() (const Range& obj) const {
    int res = 0;
    for (const auto& x: obj) {
      if (func(x)) { res ++; } }
    return res; } };
template <class FuncType>
count_t<FuncType> count(FuncType func) {
  return count_t<FuncType>(func); }

} /* namespace ranges */



template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type,
          class Method, typename = typename std::enable_if<std::is_base_of<ranges::rangesMethod, Method>::value>::type>
auto operator| (Range&& obj, const Method& method) -> decltype(method(std::forward<Range>(obj))) {
  return method(std::forward<Range>(obj)); }

template <class Range, typename = typename std::enable_if<is_ranges<Range>::value>::type,
          class Method, typename = typename std::enable_if<std::is_base_of<ranges::rangesMethod, Method>::value>::type>
auto operator| (const Range& obj, const Method& method) -> decltype(method(obj)) {
  return method(obj); }

} /* namespace Temps */

using Temps::operator|;

#endif /* PIPE_H_ */


#ifdef NOT_HEADER

#include  "/home/jack/code/creats/Vector.h"
#include  "/home/jack/code/creats/log.h"
#include <algorithm>
#include <vector>

int main() {
  using namespace Temps;
  auto r = std::vector<int>{1,5,3,4,5,3,4,8,9}
            | ranges::sort 
            | ranges::unique 
            | ranges::transform([](int a){ return a * 2; })
            | ranges::filter([](int a) { return a % 3 == 1; })
            | ranges::sortby([](int a, int b) { return a > b; });
  std::cout << r << std::endl;
  return 0;
}

#endif 


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

constexpr int N = 200005;
int to[N], n, pos[N];
bool vis[N];
std::vector<Vector<int>> circs;

std::vector<std::pair<int,int>> opts;
auto swap = [](int& a, int& b) {
  opts.push_back({pos[a], pos[b]}); 
  std::swap(pos[a], pos[b]); std::swap(a,b); };

void dfs(Vector<int> &output, int u) {
  vis[u] = true; output.push_back(to[u]);
  if (!vis[to[u]]) { dfs(output, to[u]); } }

void handle_two(Vector<int> &&a, Vector<int> &&b) {
  swap(a[0], b[0]);    
  for (std::size_t i=1; i<a.size(); ++i) swap(a[i], b[0]);
  for (std::size_t i=1; i<b.size(); ++i) swap(b[i], a[0]);
  swap(a[0], b[0]); }

void handle_one(Vector<int> &a) {
  assert(a.size() >= 3);
  see(a);
  swap(a.back(), a[0]);
  swap(a[0], a[1]); 
  swap(a.back(), a[1]);
  for (std::size_t i=2; i<a.size()-1; ++i) swap(a[0], a[i]);
  swap(a.back(), a[0]);
}

Vector<int> find_spare(const Vector<int>& a) {
  assert(a.size() < (unsigned)n);
  Vector<bool> vis(n, false);
  for (int i: a) vis[i] = true;
  for (int i=0;;++i) if (!vis[i])
    return Vector<int>(1,i);
}

void preInit() { } void init() {
  n = sc.n();
  for (int i: range(n)) { to[i] = sc.n() - 1; pos[to[i]] = i; }
} void solve() {
  for (int i: range(n)) if (!vis[i]) { 
    circs.push_back({}); dfs(circs.back(), i); 
    if (circs.back().size() <= 1ul) { circs.pop_back(); } }

  for (std::size_t i=0; i+1<circs.size(); i+=2) 
    handle_two(std::move(circs[i]), std::move(circs[i + 1]));

  if (circs.size() % 2 == 1) {
    if (circs.back().size() > 2) handle_one(circs.back());
    else handle_two(std::move(circs.back()), find_spare(circs.back())); }

  std::cout << opts.size() << std::endl;
  for (const auto& [u,v]: opts) std::cout << u+1 << " " << v+1 << std::endl;
}