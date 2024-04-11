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


#ifndef SCANNER_H_
#define SCANNER_H_ 1
#include <stdio.h>
#include <stdlib.h>
class Scanner
{
private:
  static const int BUFFER_SIZE = 1 << 18;
  char buff[BUFFER_SIZE];
  char *buffPos, *buffLim;

public:
  Scanner()
  {
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, stdin);
    buffPos = buff;
  }

private:
  inline void flushBuff()
  {
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, stdin);
    if (buffLim == buff) {
      *buffLim++ = '\n';
    }
    buffPos = buff;
  }
  inline bool isWS(char t) { return t <= ' '; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  inline void nextPos()
  {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }
public:
  inline char getchar()
  {
    char ch = *buffPos;
    nextPos();
    return ch;
  }
  inline void next(char* s)
  {
    while (isWS(*buffPos)) {
      nextPos();
    }
    while (!isWS(*buffPos)) {
      *s = *buffPos;
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s)
  {
    while (*buffPos != '\n') {
      nextPos();
    }
    if (*buffPos == '\n') {
      nextPos();
    }
    while (*buffPos != '\n') {
      *s++ = *buffPos;
      nextPos();
    }
    *s = '\0';
  }
  inline int nextInt()
  {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos();
    }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    return res * sign;
  }
  inline long long nextLong()
  {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos();
    }
    long long sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    return res * sign;
  }
  inline int n()
  {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    int res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nl()
  {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nlm(const int MOD)
  {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = (res * 10 + (*buffPos - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline double nextDouble()
  {
    while (isWS(*buffPos)) {
      nextPos();
    }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    if (*buffPos == '.') {
      nextPos();
      double ep = 1;
      while (isDig(*buffPos)) {
        ep *= 0.1;
        res += ep * (*buffPos - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar()
  {
    while (isWS(*buffPos))
      nextPos();
    char res = *buffPos;
    nextPos();
    return res;
  }
};
Scanner sc;
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

  inline Intm() { a = 0; } 
  inline Intm(valueType a) : a(a) {}
  inline Intm(long long a) : a(Moduler::red(Moduler::mod(a) + Moduler::MOD)) {}
  inline explicit operator valueType() { return a; }
  inline void log() const { 
#ifdef LOG_H_
    std::cout << a << " "; 
#endif
  }
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
constexpr int N = 5005;
typedef Temps::Intm<Temps::ConstModuler<MOD>> Int;

struct Poly : public std::vector<Int> {
  using std::vector<Int>::vector;
  Poly operator* (const Poly& B) const {
    Poly C(size() + B.size() - 1);
    for (std::size_t i=0; i<size(); ++i) {
      for (std::size_t j=0;j<B.size(); ++j) {
        C[i+j] += operator[](i) * B[j]; } } 
    return C; } 
  void log() {
    see(size());
    for (const auto& i: *this) {
      i.log(); }
    see("");
  }
};

int a[N], n, m;

void preInit() { } void init() {
  n = sc.n(); m = sc.n();
  rep (i,n) a[i] = sc.n();
} void solve() {
  Int ans = 1;
  rep (i,n) ans *= a[i];
  Poly B{1};
  rep (i,n) B = B * Poly({static_cast<long long>(a[i]), -1ll});
  {
    Int c = 1;
    rep (i,n+1) {
      if (m-i < 0) { break; }
      ans -= c * B[i];
      c /= n; c *= (m-i); }
  }
  printf("%d\n", static_cast<int>(ans));
}