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
#ifndef RANGE_H_
#define RANGE_H_

#include <stdexcept>
#include <iterator>
#include <type_traits>

template <typename _IntType>
class range {
  static_assert(std::is_integral<_IntType>::value, "range object must have integral value type");

protected:
  class iterator : public std::iterator<std::input_iterator_tag, _IntType, _IntType, const _IntType*, _IntType> {
    _IntType val, step;

  public:
    using typename std::iterator<std::input_iterator_tag, _IntType, _IntType, const _IntType*, _IntType>::reference;
    explicit constexpr iterator(int val, int step) noexcept : val(val), step(step) {}
    constexpr iterator& operator++() noexcept { val += step; return *this; }
    constexpr iterator& operator++(int) noexcept { iterator ret = *this; val += step; return ret; }
    constexpr bool operator== (const iterator& rhs) const noexcept { return val == rhs.val; }
    constexpr bool operator!= (const iterator& rhs) const noexcept { return val != rhs.val; }
    constexpr reference operator*() const { return val; }
  };

public:
  typedef  _IntType value_type;
  const value_type _begin, _step, _end;

  explicit constexpr range(const value_type end) noexcept : _begin(0), _step(1), _end(end>0 ? end : 0) {}
  explicit constexpr range(const value_type begin, const value_type end) noexcept : 
    _begin(begin), _step(1), _end(end>begin ? end : begin) {}
  explicit constexpr range(const value_type begin, const value_type end, const value_type step) :
    _begin(begin), _step(step), _end((end-begin)/step>0 ? begin+(end-begin)/step*step : begin) {}
  constexpr iterator begin() const noexcept { return iterator(_begin, _step); }
  constexpr iterator end() const noexcept { return iterator(_end, _step); }
};

#endif
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
#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstdlib>
#include <utility>
#include <iterator>
#include <initializer_list>

namespace Temps {

template <class Type>
class Vector {

public:
  typedef Type value_type;
  typedef unsigned int size_type;

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
    bool operator== (const iterator& rhs) const { return ptr == rhs.ptr; }
    bool operator!= (const iterator& rhs) const { return ptr != rhs.ptr; }
    bool operator<  (const iterator& rhs) const { return ptr <  rhs.ptr; }
    bool operator<= (const iterator& rhs) const { return ptr <= rhs.ptr; }
    bool operator>  (const iterator& rhs) const { return ptr >  rhs.ptr; }
    bool operator>= (const iterator& rhs) const { return ptr >= rhs.ptr; }

    iterator operator++ ()    { return iterator(++ptr); }
    iterator operator++ (int) { return iterator(ptr++); }
    iterator operator-- ()    { return iterator(--ptr); }
    iterator operator-- (int) { return iterator(ptr--); }

    iterator operator+ (const difference_type& dif) const { return iterator(ptr + dif); }
    iterator operator- (const difference_type& dif) const { return iterator(ptr - dif); }

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
  Vector(size_type size) : _capacity(size), _size(size) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    for (value_type i=0; i<_size; ++i) { a[i] = value_type(); } }

  Vector(const Vector& rhs) : _capacity(rhs._size), _size(rhs._size) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    for (size_type i=0; i<_size; ++i) { a[i] = rhs.a[i]; } }
  Vector(Vector&& rhs) : _capacity(rhs._capacity), _size(rhs._size) {
    a = rhs.a; rhs.a = nullptr; }
  
  Vector(const std::initializer_list<value_type>& list) : _capacity(list.size()), _size(list.size()) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *p = a;
    for (const auto& i: list) { *p++ = i; } }

  inline size_type size() const { return _size; }
  inline size_type capacity() const { return _capacity; }

  void reserve(size_type __capacity) {
    _capacity = __capacity;
    if (_size > _capacity) { _size = _capacity; }
    a = static_cast<value_type*>(realloc(a, sizeof(value_type) * _capacity)); }
  void resize(size_type  __size) {
    if (_size > __size) { _size = __size; return; }
    __grow_capacity(__size);
    for (size_type i = _size; i < __size; ++i) { a[i] = value_type(); }
    _size = __size; }

  Vector& operator= (const Vector& rhs) {
    __grow_capacity(rhs._size);
    _size = rhs._size;
    for (size_type i=0; i<_size; ++i) {
      a[i] = rhs.a[i]; } 
    return *this; }
  Vector& operator= (Vector&& rhs) {
    _size = rhs._size; _capacity = rhs._capacity;
    a = rhs.a; rhs.a = nullptr; 
    return *this; }

  value_type operator[] (const size_type id) const { return a[id]; }
  value_type& operator[] (const size_type id) { return a[id]; }
  value_type back() const { return a[_size - 1]; }
  value_type& back() { return a[_size - 1]; }
  void pop_back() { _size--; }

  Vector& push_back(const value_type& b) {
    __grow_capacity(_size + 1); a[_size] = b; _size++; return *this; }
  Vector& push_back(value_type&& b) {
    __grow_capacity(_size + 1); a[_size] = std::forward<value_type>(b); _size++; return *this; }
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

#endif /* VECTOR_H_ */

#ifdef NOT_HEADER

#include <iostream>
#include <algorithm>
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

using namespace Temps;
int main() {
  Vector<int> a{3,2,1};
  Vector<int> b{6,5};
  a.push_back({4}).push_back(b);
  logArray(a.begin(), a.end());
  std::sort(a.begin(), a.end());
  logArray(a.begin(), a.end());
  return 0;
}

#endif /* NOT_HEADER */

// #include "/home/jack/code/creats/STree.h"
// #include "/home/jack/code/creats/Tree.h"
// #include "/home/jack/code/creats/Graph.h"
/** @file creats/Intm.h
 * Integer under mod (with fast mod implement)
 * division only works when %MOD is a prime
 */

#ifndef INTM_H_
#define INTM_H_

#ifndef INTM_FAST_32
#define INTM_FAST_32 int
#endif
#ifndef INTM_FAST_64
#define INTM_FAST_64 long long
#endif

#include <type_traits>
#include <limits>
#include <cmath>
#include <iostream>

namespace Temps {

template <INTM_FAST_32 _MOD>
class ConstModuler {

public:
  typedef INTM_FAST_32 valueType;
  typedef INTM_FAST_64 longType;
  static constexpr valueType MOD = _MOD;
  static inline valueType red(valueType a) { return a >= MOD ? a - MOD : a; }
  static inline void red_set(valueType& a) { a = a >= MOD ? a - MOD : a; }
  static inline valueType mod(longType a) { return a % MOD; }
  static inline void mod_set(longType& a) { a %= MOD; }

private:
  ConstModuler() =delete;

};

/**
 * @brief Integer under mod
 * @tparam Moduler  the module calculater 
 *
 * You may choose moduler from 
 * %ConstModuler(higher performance) whose %MOD should be known at compile time, or
 * %RuntimeModuler whose %MOD can be set at runtime, or
 * customize your moduler
 *
 * requirement:
 *   static valueType MOD;
 *   static valueType red(valueType a);
 *   static void red_set(valueType& a);
 *   static valueType mod(longType a);
 *   static void mod_set(longType& a);
 */

template <class Moduler>
class Intm {

public:
  typedef typename Moduler::valueType valueType;
  typedef typename Moduler::longType longType;

  static_assert(std::numeric_limits<valueType>::is_integer, 
                "valueType should be an integer type");
  static_assert(std::numeric_limits<longType>::is_integer, 
                "longType should be an integer type");
  static_assert(std::is_same<const valueType, const decltype(Moduler::MOD)>::value,
                "type of Moduler::MOD must be Moduler::valueType");
  static_assert(std::is_same<decltype(Moduler::red), valueType(valueType)>::value,
                "Moduler::red should be a function of valueType(valueType)");
  static_assert(std::is_same<decltype(Moduler::red_set), void(valueType&)>::value,
                "Moduler::red_set should be a function of void(valueType&)");
  static_assert(std::is_same<decltype(Moduler::mod), valueType(longType)>::value,
                "Moduler::mod should be a function of valueType(longType)");
  static_assert(std::is_same<decltype(Moduler::mod_set), void(longType&)>::value,
                "Moduler::mod_set should be a function of void(longType&)");

  inline constexpr Intm() : a(0) {}
  inline constexpr Intm(valueType a) : a(a) {}
  inline constexpr Intm(long long a) : a(Moduler::red(Moduler::mod(a) + Moduler::MOD)) {}
  inline explicit operator valueType() { return a; }
  inline void log() const { 
#ifdef LOG_H_
    std::cout << a << " "; 
#endif
  }
  friend std::ostream& operator<< (std::ostream& out, const Intm& a) {
    out << a.a; return out; }
  inline bool operator< (const Intm& B) const { return a < B.a; }
  inline bool operator== (const Intm& B) const { return a == B.a; }
  inline bool operator!= (const Intm& B) const { return a != B.a; }

  inline Intm operator+ (const Intm& B) const {
    return Intm(Moduler::red(a + B.a)); }
  inline Intm& operator+= (const Intm& B) {
    Moduler::red_set(a += B.a);
    return *this; }
  inline Intm operator- (const Intm& B) const {
    return Intm(Moduler::red(a + Moduler::MOD - B.a)); }
  inline Intm& operator-= (const Intm& B) {
    Moduler::red_set(a += Moduler::MOD - B.a);
    return *this; }
  inline Intm operator* (const Intm& B) const {
    return Intm(Moduler::mod(static_cast<longType>(a) * B.a)); }
  inline Intm& operator*= (const Intm& B) {
    a = Moduler::mod(static_cast<longType>(a) * B.a); 
    return *this; }
  inline Intm operator/ (const Intm& B) const {
    return Intm(Moduler::mod(static_cast<longType>(a) * __inv_impl(B.a))); }
  inline Intm operator/= (const Intm& B) {
    a = Moduler::mod(static_cast<longType>(a) * __inv_impl(B.a));
    return *this; }
  inline Intm pow(valueType k) const {
    return Intm(__pow_impl(a, k)); }
  inline Intm inv() const {
    return Intm(__inv_impl(a)); }

protected:
  static inline valueType __pow_impl(valueType _a, valueType b) {
    longType res = 1, a = _a;
    while (b) {
      if (b & 1) Moduler::mod_set(res *= a);
      Moduler::mod_set(a *= a);
      b >>= 1; }
    return static_cast<valueType>(res); }
  static inline valueType __inv_impl(valueType _a) {
    return __pow_impl(_a, Moduler::MOD - 2); }

  valueType a;

};

}

#endif /* INTM_H_ */
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

constexpr int MOD = 1000000007;
typedef Temps::Intm<Temps::ConstModuler<MOD>> Int;
constexpr int N = 100005;

struct Dsu {
  int p[N];
  Dsu() { for (int i: range(N)) p[i]=i; }
  int get(int u) { return u==p[u] ? u : p[u] = get(p[u]); }
  void merge(int u, int v) { p[get(u)] = get(v); }
} loves;

Temps::Vector<std::pair<int,int>> elove, ehate;
Temps::Vector<int> e[N];
int n, m, col[N];

void preInit() { } void init() {
  n = sc.n(); m = sc.n();

  for ([[maybe_unused]] int _: range(m)) {
    int u=sc.n(), v=sc.n(), c=sc.n();
    (c ? elove : ehate).push_back({u,v}); }
} void solve() {
  auto add_edge = [](const int u, const int v) {
    e[u].push_back(v); e[v].push_back(u); };
  for (const auto& [u,v]: elove) { loves.merge(u,v); }    
  for (const auto& [u,v]: ehate) { add_edge(loves.get(u), loves.get(v)); }

  std::function<bool(int)> valid_graph = [&](int u) -> bool {
    for (const int v: e[u]) {
      if (col[v] != -1) {
        if (col[v] == col[u]) { return false; } }
      else { col[v] = !col[u]; if (!valid_graph(v)) { return false; } } }
    return true; };

  std::fill(col+1, col+n+1, -1);
  Int ans = 1;
  for (const int _u: range(1,n+1)) {
    const int u = loves.get(_u);
    if (col[u] == -1) { col[u] = 0;
      if (!valid_graph(u)) { ans = 0; break; }
      else { ans *= 2; } } }

  printf("%d\n", static_cast<int>(ans / 2));
}