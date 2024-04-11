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
#ifndef UTIL_H_
#define UTIL_H_ 1

#include <vector>
#include <type_traits>
#include <algorithm>

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
IntType gcd(const IntType a, const IntType b) {
  return b == 0 ? a : gcd(b, a % b); }

template <class IntType, typename = typename
          std::enable_if<std::is_integral<IntType>::value>::type>
IntType lcm(const IntType a, const IntType b) {
  return a / gcd(a, b) * b; }

template <class ForwardIterator, class OutputIterator>
void dissociate(ForwardIterator __begin, ForwardIterator __end, OutputIterator __dest) {
  std::vector <typename std::iterator_traits<ForwardIterator>::value_type> values(__begin, __end); 
  std::sort(values.begin(), values.end()); values.erase(std::unique(values.begin(), values.end()), values.end());
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

constexpr int N = 405;
int MOD;

int power(int a, int b)
{
  int r = 1;
  for (; b; b >>= 1)
  {
    if (b & 1) 
      r = 1ll * r * a % MOD;
    a = 1ll * a * a % MOD;
  }
  return r;
}

int inv(int a)
{
  return power(a, MOD - 2);
}

struct matrix_t
{
  int a[N][N];
  matrix_t() { memset(a, 0, sizeof(a)); }
  int det(int n)
  {
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      int non_zero_id = -1;
      for (int j = i; j < n; j++)
        if (a[j][i] != 0)
        {
          non_zero_id = j;
          break;
        }
      if (non_zero_id == -1) 
        return 0;
      if (non_zero_id != i)
      {
        ans = -ans;
        for (int j = i; j < n; j++)
          std::swap(a[i][j], a[non_zero_id][j]);
      }
      for (int j = i + 1; j < n; j++)
      {
        int factor = 1ll * inv(a[i][i]) * a[j][i] % MOD;
        for (int k = i; k < n; k++)
          a[j][k] = (a[j][k] - 1ll * a[i][k] * factor) % MOD;
      }
      ans = 1ll * ans * a[i][i] % MOD;
    }
    return (ans + MOD) % MOD;
  }
};

constexpr int M = 105 * 105;

struct dsu_t
{
  int p[M];
  int id[M];

  dsu_t()
  {
    for (int i = 0; i < M; i++)
      p[i] = i;
  }
  int get(int u)
  {
    return u == p[u] ? u : p[u] = get(p[u]);
  }
};

using edge_t = std::pair<int,int>;

int calc(const std::vector<edge_t> &must, const std::vector<edge_t> alter, int n)
{
  dsu_t st;
  for (const auto& [u,v] : must)
  {
    int pu = st.get(u);
    int pv = st.get(v);
    if (pu == pv) return 0;
    st.p[pu] = pv;
  }
  int id_cnt = 0;
  for (int i = 0; i < n; i++) 
    if (st.p[i] == i)
      st.id[i] = id_cnt++;
  if (id_cnt - 1> (int)alter.size())
    return 0;
  matrix_t mt;
  for (const auto& [u,v] : alter)
  {
    int pu = st.id[st.get(u)], pv = st.id[st.get(v)];
    see(pu, pv);
    mt.a[pu][pu]++;
    mt.a[pv][pv]++;
    mt.a[pu][pv]--;
    mt.a[pv][pu]--;
  }
  see(id_cnt - 1);
  return mt.det(id_cnt - 1);
}

char a[105][105];
int id[105][105];
int n, m;

int main()
{
  n = sc.n(); m = sc.n(); MOD = sc.n();
  for (int i = 0; i < n; i++)
    sc.next(a[i]);

  int cnt[2] = {0, 0};
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      id[i][j] = cnt[(i + j) % 2]++;
  int ans = 0;
  {
    std::vector<edge_t> must, alter;
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++)
      {
        int u = (i + j) % 2 == 0 ? id[i][j] : id[i][j + 1];
        int v = (i + j) % 2 == 0 ? id[i + 1][j + 1] : id[i + 1][j];
        if (a[i][j] == '*') alter.push_back({u, v});
        else if (a[i][j] == ((i + j) % 2 == 0 ? '\\' : '/')) must.push_back({u, v});
      }
    see(must);
    see(alter);
    ans += calc(must, alter, cnt[0]);
    see(ans);
  }
  {
    std::vector<edge_t> must, alter;
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++)
      {
        int u = (i + j) % 2 == 0 ? id[i][j + 1] : id[i][j];
        int v = (i + j) % 2 == 0 ? id[i + 1][j] : id[i + 1][j + 1];
        if (a[i][j] == '*') alter.push_back({u, v});
        else if (a[i][j] == ((i + j) % 2 == 0 ? '/' : '\\')) must.push_back({u, v});
      }
    see(must);
    see(alter);
    ans += calc(must, alter, cnt[1]);
    see(ans);
  }
  printf("%d\n", ans % MOD);
  return 0;
}