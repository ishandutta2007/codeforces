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

#include <bits/stdc++.h>


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

#include <vector>
#include <type_traits>

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
  std::vector <typename std::iterator_traits<ForwardIterator>::value_type> values(__begin, __end); 
  std::sort(values.begin(), values.end()); std::unique(values.begin(), values.end()); 
  while (__begin != __end) {
    *__dest = static_cast<typename std::iterator_traits<OutputIterator>::value_type>(
              std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), *__begin)));
    __dest++; __begin++; } }

}

using Temps::checkMin;
using Temps::checkMax;

#if __has_include(<utility>)
template <class A, class B> inline __attribute__((always_inline)) 
std::pair<A,B> operator+ (const std::pair<A,B> &lhs, const std::pair<A,B> &rhs) {
  return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second); }
template <class A, class B> inline __attribute__((always_inline)) 
std::pair<A,B> operator- (const std::pair<A,B> &lhs, const std::pair<A,B> &rhs) {
  return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second); }
template <class A, class B> inline __attribute__((always_inline)) 
std::pair<A,B>& operator+= (std::pair<A,B> &lhs, const std::pair<A,B> &rhs) {
  lhs.first += rhs.first; lhs.second += rhs.second; return lhs; }
template <class A, class B> inline __attribute__((always_inline)) 
std::pair<A,B>& operator-= (std::pair<A,B> &lhs, const std::pair<A,B> &rhs) {
  lhs.first -= rhs.first; lhs.second -= rhs.second; return lhs; }
#endif

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
  
  Vector(const std::initializer_list<value_type>& list) : 
      _capacity(static_cast<unsigned int>(std::distance(list.begin(), list.end()))), _size(_capacity) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *p = a; for (const auto& i: list) { *p++ = i; } }

  template <typename Container, typename =
            decltype(std::declval<Container>().begin(),
                     std::declval<Container>().end())>
  Vector(const Container& list) : _capacity(
      static_cast<unsigned int>(std::distance(list.begin(), list.end()))), _size(_capacity) {
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
// #include "/home/jack/code/creats/STree.hpp"
// #include "/home/jack/code/creats/Tree.hpp"
// #include "/home/jack/code/creats/Graph.hpp"
#define INTM_FAST_64 long long
/** @file creats/Intm.h
 * Integer under mod
 * division only works when %MOD is a prime
 */

#ifndef INTM_H_
#define INTM_H_

#if __cplusplus >= 201103L
#include <type_traits>
#endif

#include <limits>
#include <iostream>

#ifndef INTM_FAST_32
#define INTM_FAST_32 int
#endif
#ifndef INTM_FAST_64
#define INTM_FAST_64 unsigned long long
#endif

#define ATTR_INLINE __attribute__ ((always_inline)) inline

#if __cplusplus >= 201103L
#define CXX11_CONSTEXPR constexpr
#define CXX11_EXPLICIT  explicit
#else
#define CXX11_CONSTEXPR
#define CXX11_EXPLICIT
#endif

#if __cplusplus >= 201402L
#define CXX14_CONSTEXPR constexpr
#else
#define CXX14_CONSTEXPR
#endif

namespace Temps {

template <INTM_FAST_32 MOD = 998244353>
class Intm {

#if __cplusplus >= 201103L
  static_assert(MOD * 2 < std::numeric_limits<INTM_FAST_32>::max(), "");
#endif

protected:
  INTM_FAST_32 a;

  static ATTR_INLINE CXX11_CONSTEXPR Intm 
  __make_Intm(INTM_FAST_32 _a) { return Intm(_a, 0); }

  static ATTR_INLINE CXX11_CONSTEXPR INTM_FAST_32 
  __impl_inc(INTM_FAST_32 a) { return a < 0 ? a+MOD : a; }

  static ATTR_INLINE CXX11_CONSTEXPR INTM_FAST_32
  __impl_dec(INTM_FAST_32 a) { return a >= MOD ? a-MOD : a; }

  static ATTR_INLINE CXX14_CONSTEXPR INTM_FAST_32
  __impl_pow(INTM_FAST_32 a, INTM_FAST_32 b) {
    INTM_FAST_32 res = 1; 
    for (; b; b >>= 1) {
      if (b & 1) { res = static_cast<INTM_FAST_32>((INTM_FAST_64)(res) * a % MOD); }
      a = static_cast<INTM_FAST_32>((INTM_FAST_64)(a) * a % MOD); }
    return res; }

public:

#if __cplusplus >= 201103L
  Intm() =default;
#else
  Intm() {}
#endif

  ATTR_INLINE CXX11_CONSTEXPR Intm(int a)                : a(__impl_inc(a % MOD)) {}
  ATTR_INLINE CXX11_CONSTEXPR Intm(long a)               : a(__impl_inc(a % MOD)) {}
  ATTR_INLINE CXX11_CONSTEXPR Intm(long long a)          : a(__impl_inc(a % MOD)) {}
  ATTR_INLINE CXX11_CONSTEXPR Intm(unsigned int a)       : a(static_cast<INTM_FAST_32>(a % MOD))             {}
  ATTR_INLINE CXX11_CONSTEXPR Intm(unsigned long a)      : a(static_cast<INTM_FAST_32>(a % MOD))             {}
  ATTR_INLINE CXX11_CONSTEXPR Intm(unsigned long long a) : a(static_cast<INTM_FAST_32>(a % MOD))             {}
  ATTR_INLINE CXX11_CONSTEXPR explicit Intm(INTM_FAST_32 a, int) : a(a)           {}
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR CXX11_EXPLICIT operator _IntType() const { return a; }
  ATTR_INLINE friend std::ostream& operator<< (std::ostream& out, const Intm  rhs) { out << rhs.a; return out; }
  ATTR_INLINE friend std::istream& operator>> (std::istream& in,        Intm &rhs) { long long a; in >> a; rhs = Intm(a); return in; }

  template <class _IntType> ATTR_INLINE CXX14_CONSTEXPR Intm pow(_IntType k) const { return __make_Intm(__impl_pow(a, k % (MOD-1))); }
  ATTR_INLINE CXX14_CONSTEXPR Intm inv() const { return __make_Intm(__impl_pow(a, MOD-2)); }

  ATTR_INLINE CXX11_CONSTEXPR friend bool operator<  (const Intm a, const Intm b) { return a.a <  b.a; }
  ATTR_INLINE CXX11_CONSTEXPR friend bool operator<= (const Intm a, const Intm b) { return a.a <= b.a; }
  ATTR_INLINE CXX11_CONSTEXPR friend bool operator>  (const Intm a, const Intm b) { return a.a >  b.a; }
  ATTR_INLINE CXX11_CONSTEXPR friend bool operator>= (const Intm a, const Intm b) { return a.a >= b.a; }
  ATTR_INLINE CXX11_CONSTEXPR friend bool operator== (const Intm a, const Intm b) { return a.a == b.a; }
  ATTR_INLINE CXX11_CONSTEXPR friend bool operator!= (const Intm a, const Intm b) { return a.a != b.a; }

  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator<  (const _IntType a, const Intm b) { return a   <  b.a; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator<  (const Intm a, const _IntType b) { return a.a <  b;   }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator<= (const _IntType a, const Intm b) { return a   <= b.a; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator<= (const Intm a, const _IntType b) { return a.a <= b;   }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator>  (const _IntType a, const Intm b) { return a   >  b.a; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator>  (const Intm a, const _IntType b) { return a.a >  b;   }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator>= (const _IntType a, const Intm b) { return a   >= b.a; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator>= (const Intm a, const _IntType b) { return a.a >= b;   }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator== (const _IntType a, const Intm b) { return a   == b.a; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator== (const Intm a, const _IntType b) { return a.a == b;   }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator!= (const _IntType a, const Intm b) { return a   != b.a; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend bool operator!= (const Intm a, const _IntType b) { return a.a != b;   }

  ATTR_INLINE CXX11_CONSTEXPR friend Intm  operator+  (const Intm  a, const Intm b) { return __make_Intm(__impl_dec(a.a + b.a)); }
  ATTR_INLINE CXX11_CONSTEXPR friend Intm  operator-  (const Intm  a, const Intm b) { return __make_Intm(__impl_inc(a.a - b.a)); }
  ATTR_INLINE CXX11_CONSTEXPR friend Intm  operator*  (const Intm  a, const Intm b) { return __make_Intm(static_cast<INTM_FAST_32>((INTM_FAST_64)(a.a) * b.a % MOD)); }
  ATTR_INLINE CXX14_CONSTEXPR friend Intm  operator/  (const Intm  a, const Intm b) { return a * b.inv(); }
  ATTR_INLINE CXX11_CONSTEXPR friend Intm& operator+= (      Intm &a, const Intm b) { return a = a + b;  }
  ATTR_INLINE CXX11_CONSTEXPR friend Intm& operator-= (      Intm &a, const Intm b) { return a = a - b;  }
  ATTR_INLINE CXX11_CONSTEXPR friend Intm& operator*= (      Intm &a, const Intm b) { return a = a * b;  }
  ATTR_INLINE CXX14_CONSTEXPR friend Intm& operator/= (      Intm &a, const Intm b) { return a = a / b;  }

  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm  operator+  (const Intm  a, const _IntType b) { return a +  Intm(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm  operator-  (const Intm  a, const _IntType b) { return a -  Intm(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm  operator*  (const Intm  a, const _IntType b) { return a *  Intm(b); }
  template <class _IntType> ATTR_INLINE CXX14_CONSTEXPR friend Intm  operator/  (const Intm  a, const _IntType b) { return a /  Intm(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm& operator+= (      Intm &a, const _IntType b) { return a += Intm(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm& operator-= (      Intm &a, const _IntType b) { return a -= Intm(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm& operator*= (      Intm &a, const _IntType b) { return a *= Intm(b); }
  template <class _IntType> ATTR_INLINE CXX14_CONSTEXPR friend Intm& operator/= (      Intm &a, const _IntType b) { return a /= Intm(b); }

  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm      operator+  (const _IntType  a, const Intm b) { return Intm(a) +  b; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm      operator-  (const _IntType  a, const Intm b) { return Intm(a) -  b; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend Intm      operator*  (const _IntType  a, const Intm b) { return Intm(a) *  b; }
  template <class _IntType> ATTR_INLINE CXX14_CONSTEXPR friend Intm      operator/  (const _IntType  a, const Intm b) { return Intm(a) /  b; }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend _IntType& operator+= (      _IntType &a, const Intm b) { return a += _IntType(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend _IntType& operator-= (      _IntType &a, const Intm b) { return a -= _IntType(b); }
  template <class _IntType> ATTR_INLINE CXX11_CONSTEXPR friend _IntType& operator*= (      _IntType &a, const Intm b) { return a *= _IntType(b); }
  template <class _IntType> ATTR_INLINE CXX14_CONSTEXPR friend _IntType& operator/= (      _IntType &a, const Intm b) { return a /= _IntType(b); }
};

}

#undef ATTR_INLINE
#undef CXX11_CONSTEXPR
#undef CXX14_CONSTEXPR
#undef INTM_FAST_32
#undef INTM_FAST_64

#endif /* INTM_H_ */
// #include "/home/jack/code/Math/Poly/main.h"


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

constexpr int MOD = 1000000007;
constexpr int N = 100005;
using Int = Temps::Intm<MOD>;
char s[N];
size_t slen;
int T;

Int fac[N], ifac[N];

Int binomial(int n, int r) {
  return fac[n] * ifac[r] * ifac[n - r]; }

std::vector<Int> get(size_t n) {
  std::vector<Int> res(N);
  for (size_t i=0; i<n; ++i) res[i] = 0;
  res[n] = 1;
  for (size_t i=n+1; i<N; i++)  {
    res[i] = binomial((int)i-1, (int)n-1) * Int(25).pow(i - n) + res[i-1] * 26; }
  return res; }

std::vector<Int> mem[N];

void preInit()
{
  fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
  for (int i=2; i<N; ++i) {
    fac[i] = fac[i-1] * i;
    ifac[i] = fac[i].inv(); }
}

void init() 
{
  T = sc.n();
  sc.next(s);
  slen = std::strlen(s);
  mem[slen] = get(slen);
} 

void solve() 
{
  while (T--) {
    int opt = sc.n();
    if (opt == 1) {
      sc.next(s); slen = std::strlen(s);
      if (mem[slen].empty()) mem[slen] = get(slen); }
    else { printf("%d\n", static_cast<int>(mem[slen][(size_t)sc.n()])); } }
}