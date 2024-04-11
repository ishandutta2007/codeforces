// PARSER: begin local header '/home/jack/code/creats/gpl.h'
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
// PARSER: end local header '/home/jack/code/creats/gpl.h'

// PARSER: begin local header '/home/jack/code/creats/Scanner.h'

#ifndef SCANNER_H_
#define SCANNER_H_ 1
#include <stdio.h>
#include <stdlib.h>
class Scanner
{
private:
  static const int BUFFER_SIZE = 10000;
  char buff[BUFFER_SIZE];
  int buffPos, buffLim;

public:
  Scanner()
  {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    buffPos = 0;
  }

private:
  inline void flushBuff()
  {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    if (buffLim == 0) {
      buff[buffLim++] = '\n';
    }
    buffPos = 0;
  }
  inline bool isWS(char t) { return t == ' ' || t == '\n'; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  void nextPos()
  {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }
#define getChar() buff[buffPos]
public:
  inline char getchar()
  {
    char ch = getChar();
    nextPos();
    return ch;
  }
  inline void next(char* s)
  {
    while (isWS(getChar())) {
      nextPos();
    }
    while (!isWS(getChar())) {
      *s = getChar();
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s)
  {
    while (getChar() != '\n') {
      nextPos();
    }
    if (getChar() == '\n') {
      nextPos();
    }
    while (getChar() != '\n') {
      *s = getChar();
      s++;
      buffPos++;
    }
    *s = '\0';
  }
  inline int nextInt()
  {
    while (!isDig(getChar()) && getChar() != '-') {
      nextPos();
    }
    int sign = (getChar() == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    return res * sign;
  }
  inline long long nextLong()
  {
    while (!isDig(getChar()) && getChar() != '-') {
      nextPos();
    }
    long long sign = (getChar() == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    return res * sign;
  }
  inline int n()
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    int res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = res * 10 + (getChar() - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nl()
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = res * 10 + (getChar() - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline double nextDouble()
  {
    while (isWS(getChar())) {
      nextPos();
    }
    int sign = (getChar() == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    if (getChar() == '.') {
      nextPos();
      double ep = 1;
      while (isDig(getChar())) {
        ep *= 0.1;
        res += ep * (getChar() - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar()
  {
    while (isWS(getChar()))
      nextPos();
    char res = getChar();
    nextPos();
    return res;
  }
#undef getChar
};
Scanner sc;
#endif /* SCANNER_H_ */
// PARSER: end local header '/home/jack/code/creats/Scanner.h'
// PARSER: begin local header '/home/jack/code/creats/log.h'
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
// PARSER: end local header '/home/jack/code/creats/log.h'
// PARSER: begin local header '/home/jack/code/creats/loop.h'
#ifndef LOOP_H_
#define LOOP_H_ 1

#define repe(a, b) for (int a = 0; a < (int)b.size(); a++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repa(i, n) for (int i = 1; i <= n; i++)
#define repi(i, a, b) for (int i = a; i <= b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)

#endif /* LOOP_H_ */
// PARSER: end local header '/home/jack/code/creats/loop.h'
// PARSER: begin local header '/home/jack/code/creats/base.h'
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
// PARSER: end local header '/home/jack/code/creats/base.h'
// #include "/home/jack/code/creats/STree.h"
// #include "/home/jack/code/creats/Tree.h"
// #include "/home/jack/code/creats/Graph.h"
// #include "/home/jack/code/creats/Intm.h"
// PARSER: begin local header '/home/jack/code/Math/Poly/main.h'
// PARSER: begin local header '/home/jack/code/creats/gpl.h'
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
// PARSER: end local header '/home/jack/code/creats/gpl.h'
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

// PARSER: begin local header '/home/jack/code/creats/log.h'
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
// PARSER: end local header '/home/jack/code/creats/log.h'

#ifndef POLY_H_MOD
#define POLY_H_MOD 998244353
#define POLY_H_MOD_W 3
#endif

namespace Polys {
typedef int uint32;
typedef unsigned long long uint64;
const double Pi = 3.1415926535897932384626;
const uint32 MAX_B = 21;
const uint32 MOD = POLY_H_MOD;
const uint32 MOD_W = POLY_H_MOD_W;
const uint32 FFT_THR = 6;

namespace Helper {
inline uint32
power(uint32 a, uint32 b, const uint32 _MOD = MOD)
{
  uint32 res = 1;
  while (b) {
    if (b & 1)
      res = 1ull * res * a % _MOD;
    a = 1ull * a * a % _MOD;
    b >>= 1;
  }
  return res;
}

inline uint32
inv(uint32 a, const uint32 _MOD = MOD)
{
  return power(a, _MOD - 2, _MOD);
}

inline uint32
get_2(uint32 _n)
{
  uint32 u2 = 1, res = 0;
  while (u2 < _n) {
    u2 <<= 1;
    ++res;
  }
  return res;
}

// Cipolla help to solve quad residue
namespace Cipolla {
typedef unsigned int uint32;
uint32 w;

struct Num
{
  uint32 x, y;
  Num(int x = 0, int y = 0)
    : x(x)
    , y(y)
  {}
  Num operator*(const Num& B) const
  {
    return Num((1ull * x * B.x + 1ull * y * B.y % MOD * w) % MOD,
               (1ull * x * B.y + 1ull * y * B.x) % MOD);
  }
};

template<class _Num>
inline _Num
power(_Num a, uint32 b)
{
  _Num res(1, 0);
  while (b) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

inline uint32
euler_judge(uint32 x)
{
  return Helper::power(x, (MOD - 1) / 2);
}

struct NoResidueException
{};
uint32
solve(uint32 n)
{
  if (n == 0)
    return 0;
  if (euler_judge(n) != 1)
    return -1u;

  uint32 w_try;
  while (1) {
    w_try = rand() % MOD;
    w = (1ull * w_try * w_try + MOD - n) % MOD;
    if (euler_judge(w) == MOD - 1)
      break;
  }
  Num x(w_try, 1);
  uint32 res = power(x, (MOD + 1) / 2).x;
  if (MOD - res < res)
    res = MOD - res;
  return res;
}
}
}

struct Complex
{
  double r, i;
  Complex(double r = 0, double i = 0)
    : r(r)
    , i(i)
  {}
  Complex operator+(const Complex B) const { return Complex(r + B.r, i + B.i); }
  void operator+=(const Complex B)
  {
    r += B.r;
    i += B.i;
  }
  Complex operator-(const Complex B) const { return Complex(r - B.r, i - B.i); }
  void operator-=(const Complex B)
  {
    r -= B.r;
    i -= B.i;
  }
  Complex operator*(const Complex B) const
  {
    return Complex(r * B.r - i * B.i, r * B.i + i * B.r);
  }
  void operator*=(const Complex B)
  {
    *this = Complex(r * B.r - i * B.i, r * B.i + i * B.r);
  }
  Complex inv() const { return Complex(r, -i); }
  Complex operator/(const Complex B) const
  {
    double _t = B.r * B.r - B.i * B.i;
    Complex R = (*this) * (B.inv());
    return Complex(R.r / _t, R.i / _t);
  }
  void log() { std::cout << "r=" << r << ' ' << "i=" << i << std::endl; }
};

#ifndef INTM_H_
struct Int
{
  typedef int uint32;
  static inline uint32 _mod_red(uint32 a) { return a >= MOD ? a - MOD : a; }
  static inline void _mod_red_set(uint32& a) { a = a >= MOD ? a - MOD : a; }

  uint32 a;
  Int(uint32 a = 0)
    : a(a)
  {}
  inline Int operator+(const Int B) const { return Int(_mod_red(a + B.a)); }
  inline Int& operator+=(const Int B)
  {
    _mod_red_set(a += B.a);
    return *this;
  }
  inline Int operator-(const Int B) const
  {
    return Int(_mod_red(MOD + a - B.a));
  }
  inline Int& operator-=(const Int B)
  {
    _mod_red_set(a += MOD - B.a);
    return *this;
  }
  inline Int operator*(const Int B) const
  {
    return Int(static_cast<uint64>(a) * B.a % MOD);
  }
  inline Int& operator*=(const Int B)
  {
    a = static_cast<uint64>(a) * B.a % MOD;
    return *this;
  }
  inline Int operator/(const Int B) const
  {
    return Int(1ull * a * Helper::inv(B.a) % MOD);
  }
  inline Int& operator/=(const Int B)
  {
    a = 1ull * a * Helper::inv(B.a) % MOD;
    return *this;
  }
  inline Int inv() const { return Int(Helper::inv(a)); }
  inline Int pow(uint32 k) const { return Int(Helper::power(a, k)); }
  inline operator uint32() { return a; }
  inline void log() { std::cout << a << ' '; }
};
#else
typedef Intm::Intm<MOD> Int;
#endif

template<class _Item>
struct _PolyBase
{
  _Item* a;
  uint32 n;

  _PolyBase(uint32 _n = 0)
  {
    // puts("default construct");
    n = Helper::get_2(_n);
    a = new _Item[1 << n];
  }

  _PolyBase(const _PolyBase& B)
  {
    // puts("l-value construct called");
    n = B.n;
    a = new _Item[1 << n];
    memcpy(a, B.a, (1 << n) * sizeof(_Item));
  }

  _PolyBase(_PolyBase&& B)
  {
    // puts("r-value construct called");
    n = B.n;
    a = B.a;
    B.a = nullptr;
  }

  _PolyBase& operator=(const _PolyBase& B)
  {
    // puts("l-value assign called");
    if (this != &B) {
      delete[] a;
      n = B.n;
      a = new _Item[1 << n];
      memcpy(a, B.a, (1 << n) * sizeof(_Item));
    }
    return *this;
  }

  _PolyBase& operator=(_PolyBase&& B)
  {
    // puts("r-value assign called");
    if (this != &B) {
      delete[] a;
      n = B.n;
      a = B.a;
      B.a = nullptr;
    }
    return *this;
  }

  void init(_Item _a[], uint32 len)
  {
    n = Helper::get_2(len);
    delete[] a;
    a = new _Item[1 << n];
    memcpy(a, _a, len * sizeof(_Item));
  }

  _PolyBase resize(uint32 _new_len)
  {
    if (_new_len == (1 << n))
      return *this;
    _Item* origin = a;
    uint32 origin_n = n;
    n = Helper::get_2(_new_len);
    a = new _Item[1 << n];
    if (origin != nullptr) {
      memcpy(a, origin, std::min(1 << n, 1 << origin_n) * sizeof(_Item));
      delete[] origin;
    }
    return *this;
  }

  _PolyBase trim(uint32 _new_len)
  {
    _new_len = (1 << Helper::get_2(_new_len));
    if ((1 << n) > _new_len)
      resize(_new_len);
    return *this;
  }

  _PolyBase sub(uint32 _st, uint32 _l) const
  {
    _PolyBase _Res;
    _Res.init(a + _st, _l);
    return _Res;
  }

  void log()
  {
    uint32 len = 1 << n;
    std::cout << "len=" << len << std::endl;
    if (a != nullptr)
      for (uint32 i = 0; i < len; ++i)
        a[i].log();
    std::cout << std::endl;
  }

  inline _Item& operator[](const uint32 pos) { return a[pos]; }
  inline _Item operator[](const uint32 pos) const { return a[pos]; }

  Int eval(const Int x) const;
  void butterfly();
  void dft();
  void idft();
  _PolyBase deriv() const;
  _PolyBase inter() const;
  _PolyBase operator+(const _PolyBase& _B) const;
  _PolyBase& operator+=(const _PolyBase& _B);
  _PolyBase operator-(const _PolyBase& _B) const;
  _PolyBase& operator-=(const _PolyBase& _B);
  _PolyBase operator*(_Item b) const;
  _PolyBase operator*(const _PolyBase& _B) const;
  _PolyBase& operator*=(_Item b);
  _PolyBase& operator*=(const _PolyBase& _B);
  _PolyBase inv() const;
  _PolyBase sqrt() const;
  _PolyBase ln() const;
  _PolyBase exp() const;
  _PolyBase pow(uint64 k, uint64 k2) const;

  ~_PolyBase() { delete[] a; }
};

typedef _PolyBase<Complex> CPoly;
typedef _PolyBase<Int> Poly;

namespace Pre {
struct Rev_t
{
  struct Rev
  {
    uint32* rev;
    uint32 n2;

    Rev(uint32 n2)
      : n2(n2)
    {
      rev = new uint32[1 << n2];
      rev[0] = 0;
      uint32 len = 1u << n2;
      uint32 h_b = n2 - 1;
      for (uint32 i = 1; i < len; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << h_b);
    }
    ~Rev() { delete[] rev; }
  };

  Rev* rev[MAX_B + 1];
  Rev_t()
  {
    for (uint32 i = 0; i < MAX_B; ++i)
      rev[i] = nullptr;
  }
  void require(int n2)
  {
    if (rev[n2] == nullptr)
      rev[n2] = new Rev(n2);
  }
  ~Rev_t()
  {
    for (uint32 i = 0; i <= MAX_B; ++i)
      delete rev[i];
  }
};
Rev_t Rev;

struct Cw_t
{
  Complex* w;
  uint32 n;

  Cw_t() { w = nullptr; }

  void require(uint32 _new_n)
  {
    if (_new_n <= n)
      return;
    n = _new_n;
    delete[] w;
    w = new Complex[1 << n];
    uint32 _lim = 1 << (n - 1);
    for (uint32 _l = 1; _l <= _lim; _l <<= 1)
      for (uint32 _i = 0; _i < _l; ++_i)
        w[_l + _i] = Complex(std::cos(Pi / _l * _i), std::sin(Pi / _l * _i));
  }

  ~Cw_t() { delete[] w; }
};
Cw_t Cw;

struct Nw_t
{
  Int* w;
  uint32 n;

  Nw_t() { w = nullptr; }

  void require(uint32 _new_n)
  {
    if (_new_n <= n)
      return;
    n = _new_n;
    delete[] w;
    w = new Int[1 << n];
    uint32 _lim = 1 << (n - 1);
    for (uint32 _l = 1; _l <= _lim; _l <<= 1) {
      Int pw = Helper::power(MOD_W, (MOD - 1) / _l / 2);
      Int pos = 1;
      for (uint32 _i = 0; _i < _l; ++_i) {
        w[_l + _i] = pos;
        pos *= pw;
      }
    }
  }

  ~Nw_t() { delete[] w; }
};
Nw_t Nw;

struct Inv_t
{
  Int* inv;
  uint32 n;

  Inv_t() { inv = nullptr; }

  void require(uint32 _new_n)
  {
    if (_new_n <= n)
      return;
    n = _new_n;
    delete[] inv;
    inv = new Int[n];
    inv[1] = 1;
    for (uint32 i = 2; i < n; ++i)
      inv[i] = inv[MOD % i] * Int(MOD - MOD / i);
  }

  ~Inv_t() { delete[] inv; }
};
Inv_t Inv;

}

template<class _Item>
Int
_PolyBase<_Item>::eval(const Int x) const
{
  Int pos = 1;
  Int res = 0;
  uint32 len = 1 << n;
  for (uint32 i = 0; i < len; ++i) {
    res += a[i] * pos;
    pos *= x;
  }
  return res;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::deriv() const
{
  uint32 len = 1 << n;
  _PolyBase<_Item> R(len);
  for (uint32 i = 1; i < len; ++i)
    R[i - 1] = a[i] * _Item(i);
  return R;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::inter() const
{
  uint32 len = 1 << n;
  _PolyBase<_Item> R(len);
  Pre::Inv.require(len);
  for (uint32 i = 1; i < len; ++i)
    R[i] = a[i - 1] * Pre::Inv.inv[i];
  return R;
}

template<class _Item>
void
_PolyBase<_Item>::butterfly()
{
  Pre::Rev.require(n);
  uint32* rev = Pre::Rev.rev[n]->rev;

  uint32 len = 1 << n;
  for (uint32 i = 0; i < len; ++i)
    if (rev[i] < i)
      std::swap(a[rev[i]], a[i]);
}

template<>
void
CPoly::dft()
{
  butterfly();
  Pre::Cw.require(n);
  uint32 len = 1u << n;
  Complex* w = Pre::Cw.w;
  for (uint32 _l = 1; _l < len; _l <<= 1) {
    uint32 _step = _l << 1;
    for (uint32 i = 0; i < len; i += _step)
      for (uint32 j = 0; j < _l; ++j) {
        Complex b = w[_l + j] * a[i + _l + j];
        a[i + _l + j] = a[i + j] - b;
        a[i + j] += b;
      }
  }
}

template<>
void
CPoly::idft()
{
  uint32 len = 1u << n;
  std::reverse(a + 1, a + len);
  dft();
  for (uint32 i = 0; i < len; ++i) {
    a[i].i /= len;
    a[i].r /= len;
  }
}

template<>
void
Poly::dft()
{
  butterfly();
  Pre::Nw.require(n);
  uint32 len = 1u << n;
  Int* w = Pre::Nw.w;
  for (uint32 _l = 1; _l < len; _l <<= 1) {
    uint32 _step = _l << 1;
    for (uint32 i = 0; i < len; i += _step)
      for (uint32 j = 0; j < _l; ++j) {
        Int b = w[_l + j] * a[i + _l + j];
        a[i + _l + j] = a[i + j] - b;
        a[i + j] += b;
      }
  }
}

template<>
void
Poly::idft()
{
  uint32 len = 1u << n;
  std::reverse(a + 1, a + len);
  dft();
  uint32 inv_n = Helper::inv(len);
  for (uint32 i = 0; i < len; ++i)
    a[i] *= inv_n;
}

template<class _Item>
void
mulpn(_PolyBase<_Item>& _A, _PolyBase<_Item>& _B)
{
  uint32 n = std::max(_A.n, _B.n) + 1;
  _A.resize(1 << n);
  _B.resize(1 << n);
  _A.dft();
  _B.dft();
  uint32 len = 1 << n;
  for (uint32 i = 0; i < len; ++i)
    _A[i] *= _B[i];
  _A.idft();
}

template<class _Item>
void
sqrp(_PolyBase<_Item>& _A)
{
  _A.dft();
  uint32 len = 1 << _A.n;
  for (uint32 i = 0; i < len; ++i)
    _A[i] *= _A[i];
  _A.idft();
}

template<class _Item>
void
mulpb(_PolyBase<_Item>& _C,
      const _PolyBase<_Item>& _A,
      const _PolyBase<_Item>& _B)
{
  uint32 n = std::max(_A.n, _B.n) + 1;
  _C.resize(1 << n);
  for (uint32 na = (1 << _A.n), ia = 0; ia < na; ++ia)
    for (uint32 nb = (1 << _B.n), ib = 0; ib < nb; ++ib)
      _C[ia + ib] += _A[ia] * _B[ib];
}

template<class _Item>
void
mulp(_PolyBase<_Item>& _A, const _PolyBase<_Item>& _B)
{
  if (_A.n <= FFT_THR && _B.n <= FFT_THR) {
    _PolyBase<_Item> _R;
    mulpb(_R, _A, _B);
    _A = std::move(_R);
  } else {
    _PolyBase<_Item> b_B = _B;
    mulpn(_A, b_B);
  }
}

template<class _Item>
_PolyBase<_Item>
mulp_r(const _PolyBase<_Item>& _A, const _PolyBase<_Item>& _B)
{
  if (_A.n <= FFT_THR && _B.n <= FFT_THR) {
    Poly _R;
    mulpb(_R, _A, _B);
    return _R;
  } else {
    Poly _R = _A;
    Poly B = _B;
    mulpn(_R, B);
    return _R;
  }
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::operator+(const _PolyBase<_Item>& _B) const
{
  uint32 len_a = 1 << n;
  uint32 len_b = 1 << _B.n;
  Poly _R(std::max(len_a, len_b));
  for (uint32 i = 0; i < len_a; ++i)
    _R[i] += a[i];
  for (uint32 i = 0; i < len_b; ++i)
    _R[i] += _B[i];
  return _R;
}

template<class _Item>
_PolyBase<_Item>&
_PolyBase<_Item>::operator+=(const _PolyBase<_Item>& _B)
{
  uint32 len_a = 1 << n;
  uint32 len_b = 1 << _B.n;
  if (len_b > len_a)
    resize(len_b);
  for (uint32 i = 0; i < len_b; ++i)
    a[i] += _B[i];
  return *this;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::operator-(const _PolyBase<_Item>& _B) const
{
  uint32 len_a = 1 << n;
  uint32 len_b = 1 << _B.n;
  Poly _R(std::max(len_a, len_b));
  for (uint32 i = 0; i < len_a; ++i)
    _R[i] += a[i];
  for (uint32 i = 0; i < len_b; ++i)
    _R[i] -= _B[i];
  return _R;
}

template<class _Item>
_PolyBase<_Item>&
_PolyBase<_Item>::operator-=(const _PolyBase<_Item>& _B)
{
  uint32 len_a = 1 << n;
  uint32 len_b = 1 << _B.n;
  if (len_b > len_a)
    resize(len_b);
  for (uint32 i = 0; i < len_b; ++i)
    a[i] -= _B[i];
  return *this;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::operator*(_Item b) const
{
  uint32 len = 1 << n;
  _PolyBase<_Item> _R(len);
  for (uint32 i = 0; i < len; ++i)
    _R[i] = a[i] * b;
  return _R;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::operator*(const _PolyBase<_Item>& _B) const
{
  return mulp_r(*this, _B);
}

template<class _Item>
_PolyBase<_Item>&
_PolyBase<_Item>::operator*=(_Item b)
{
  uint32 len = 1 << n;
  for (uint32 i = 0; i < len; ++i)
    a[i] *= b;
  return *this;
}

template<class _Item>
_PolyBase<_Item>&
_PolyBase<_Item>::operator*=(const _PolyBase<_Item>& _B)
{
  mulp(*this, _B);
  return *this;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::inv() const
{
  typedef _PolyBase<_Item> Poly;
  Poly R(1);
  R[0] = a[0].inv();
  for (uint32 step = 1; step <= n; ++step) {
    uint32 len = 1 << step;
    uint32 len2 = len << 1;
    uint32 len0 = len >> 1;
    Poly C(len2);
    for (uint32 i = 0; i < len0; ++i)
      C[i] = R[i];
    C.dft();
    Poly D(len2);
    for (uint32 i = 0; i < len; ++i)
      D[i] = a[i];
    D.dft();
    for (uint32 i = 0; i < len2; ++i)
      C[i] *= C[i] * D[i];
    C.idft();
    C.trim(len);
    R.resize(len);
    R *= _Item(2);
    R -= C;
  }
  return R;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::sqrt() const
{
  typedef _PolyBase<_Item> Poly;
  Poly R(2);
  R[0] = Helper::Cipolla::solve(a[0]);
  for (uint32 step = 1; step <= n; ++step) {
    uint32 len = 1 << step;
    uint32 len2 = len << 1;
    Poly C = R.inv();
    sqrp(R);
    R.trim(len);
    for (uint32 i = 0; i < len; ++i)
      R[i] += a[i];
    R *= C;
    R *= (_Item(1) / _Item(2));
    for (uint32 i = len; i < len2; ++i)
      R[i] = 0;
  }
  R.trim(1 << n);
  return R;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::ln() const
{
  typedef _PolyBase<_Item> Poly;
  uint32 len = 1 << n;
  Poly A = deriv();
  Poly B = inv();
  mulp(A, B);
  A.trim(len);
  return A.inter();
}

struct NoExpException
{};
template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::exp() const
{
  typedef _PolyBase<_Item> Poly;
  if (a[0] != 0) {
    throw NoExpException();
  }
  Poly R(2);
  R[0] = 1;
  for (uint32 step = 1; step <= n; ++step) {
    uint32 len = 1u << step;
    Poly C = R.ln();
    for (uint32 i = 0; i < len; ++i)
      C[i] = a[i] - C[i];
    C[0] += 1;
    R *= C;
  }
  R.trim(1 << n);
  return R;
}

template<class _Item>
_PolyBase<_Item>
_PolyBase<_Item>::pow(uint64 k, uint64 k2) const
{
  typedef _PolyBase<_Item> Poly;
  uint32 len = 1 << n;
  uint32 _fir_id = len;
  for (uint32 i = 0; i < len; ++i)
    if (a[i] != 0) {
      _fir_id = i;
      break;
    }
  if (_fir_id == len)
    return Poly(len);
  if (_fir_id != 0 && len / _fir_id < k)
    return Poly(len);
  uint32 _new_len = len - _fir_id;
  Poly A(_new_len);
  _Item _fir = a[_fir_id];
  _Item _inv = _fir.inv();
  for (uint32 i = _fir_id; i < len; ++i)
    A[i - _fir_id] = a[i] * _inv;
  A = A.ln();
  A *= _Item(k);
  A = A.exp();
  _fir = Helper::power(_fir, k2);
  _fir_id *= k;
  Poly R(len);
  for (uint32 i = _fir_id; i < len; ++i)
    R[i] = A[i - _fir_id] * _fir;
  return R;
}

void
muldp(Poly& _A, Poly& _B)
{
  uint32 n = std::max(_A.n, _B.n);
  uint32 len = 1 << n;
  uint32 len2 = len << 1;
  uint32 len4 = len2 << 1;
  Pre::Inv.require(len2);
  Poly _E(len4);
  _E[0] = 1;
  for (uint32 i = 1; i < len2; ++i)
    _E[i] = _E[i - 1] * Pre::Inv.inv[i];
  _A.resize(len4);
  _B.resize(len4);
  _A.dft();
  _B.dft();
  _E.dft();
  for (uint32 i = 0; i < len4; ++i) {
    _A[i] *= _E[i];
    _B[i] *= _E[i];
  }
  _A.idft();
  _B.idft();
  Int fac_pos = 1;
  for (uint32 i = 0; i < len2; ++i) {
    _A[i] *= _B[i] * fac_pos;
    fac_pos *= Int(i + 1);
  }
  for (uint32 i = len2; i < len4; ++i)
    _A[i] = 0;
  _E[0] = 1;
  for (uint32 i = 1; i < len2; ++i)
    _E[i] = _E[i - 1] * Pre::Inv.inv[i];
  for (uint32 i = len2; i < len4; ++i)
    _E[i] = 0;
  for (uint32 i = 1; i < len2; ++i)
    if (i & 1)
      _E[i] = Int(0) - _E[i];
  _A.dft();
  _E.dft();
  for (uint32 i = 0; i < len4; ++i)
    _A[i] *= _E[i];
  _A.idft();
  _A.trim(len2);
}

template<class _Item>
_PolyBase<_Item>
divp(_PolyBase<_Item>& A, uint32 An, _PolyBase<_Item>& B, uint32 Bn)
{
  uint32 Cn = An - Bn + 1;
  std::reverse(A.a, A.a + An);
  std::reverse(B.a, B.a + Bn);
  Poly R = A;
  R *= B.inv();
  R.trim(Cn);
  uint32 Rlen = 1 << R.n;
  for (uint32 i = Cn; i < Rlen; ++i)
    R[i] = _Item();
  std::reverse(R.a, R.a + Cn);
  std::reverse(A.a, A.a + An);
  std::reverse(B.a, B.a + Bn);
  return R;
}

}
// PARSER: end local header '/home/jack/code/Math/Poly/main.h'

#include <bits/stdc++.h>

// #define MULTIPLE_TEST_CASES_WITH_T
// #define MULTIPLE_TEST_CASES_WITHOUT_T
// PARSER: begin local header '/home/jack/code/creats/body.h'
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
// PARSER: end local header '/home/jack/code/creats/body.h'
// #define int long long

/** My code begins here **/


void preInit()
{

}

void init()
{

}

void solve()
{
  using namespace Polys;
  int n = sc.n(), m = sc.n();
  Poly A(m+1);
  rep (i,n) { 
    int u = sc.n();
    if (u <= m) A[u] -= 4; }
  A[0] = 1;
  A = A.sqrt();
  A[0] = 2;
  A = A.inv();
  A *= Int(2);
  repa (i,m) printf("%u\n", static_cast<unsigned>(A[i]));
}