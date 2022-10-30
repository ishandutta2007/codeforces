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
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

constexpr int N = 100005;
constexpr int B = 20;
int n, q;

struct edge_t
{
  int v, w;
};

struct tree_t
{
  std::vector<edge_t> e[N];
  void add_edge(int u, int v, int w)
  {
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }

  std::pair<int,int> get_farthest(int u, int f)
  {
    auto res = std::make_pair(0, u);
    for (const auto& [v, w]: e[u]) if (v != f)
    {
      auto v_res = get_farthest(v, u);
      v_res.first += w;
      res = std::max(res, v_res);
    }
    return res;
  }

  int d2root[N], depth[N], p_son[N], fa[N][B];
  void dfs_init_depth(int u, int f)
  {
    fa[u][0] = f;
    for (int i = 0; i + 1 < B; i++)
      fa[u][i + 1] = fa[fa[u][i]][i];
    depth[u] = 0;
    for (const auto& [v, w]: e[u]) if (v != f)
    {
      d2root[v] = d2root[u] + w;
      dfs_init_depth(v, u);
      int v_depth = depth[v] + w;
      if (v_depth > depth[u])
      {
        depth[u] = v_depth;
        p_son[u] = v;
      }
    }
  }

  int len[N];
  void dfs_init_len(int u, int f)
  {
    see(u, p_son[u], len[u]);
    if (p_son[u] != 0)
      len[p_son[u]] = len[u];
    for (const auto& [v, w]: e[u]) if (v != f)
    {
      len[v] += w;
      dfs_init_len(v, u);
    }
  }

  int id[N][B], top[N];
  std::vector<std::pair<int,int>> chains;
  std::vector<int> chains_psum;
  void init_chains()
  {
    for (int u = 1; u <= n; u++)
      if (p_son[u] == 0)
        chains.emplace_back(len[u], u);
    std::sort(chains.begin(), chains.end());
    std::reverse(chains.begin(), chains.end());
    memset(id, 0x3f, sizeof(id));
    int id_top = 1;
    chains_psum.push_back(0);
    for (auto [value, u] : chains)
    {
      chains_psum.push_back(chains_psum.back() + value);
      while (u != 0 && id[u][0] == 0x3f3f3f3f)
      {
        len[u] = value;
        id[u][0] = id_top;
        u = fa[u][0];
      }
      top[id_top] = u;
      id_top++;
    }
    for (int i = 0; i + 1 < B; i++)
      for (int u = 1; u <= n; u++)
        id[u][i + 1] = std::min(id[u][i], id[fa[u][i]][i]);
    for (int u = 1; u <= n; u++)
      see(u, id[u][0]);
    see(chains);
    see(chains_psum);
  }

  int get_intersect(int u, int kth)
  {
    for (int i = B - 1; i >= 0; i--)
      if (id[u][i] > kth)
        u = fa[u][i];
    return u;
  }

  int query(int u, int kth)
  {
    if (kth > (int)(chains.size()))
      kth = (int)(chains.size());
    if (id[u][0] <= kth) 
      return chains_psum[(size_t)kth];
    int ans1;
    {
      const int r = get_intersect(u, kth - 1);
      ans1 = d2root[u] - d2root[r] + depth[u] + chains_psum[(size_t)kth - 1];
    }
    int ans2;
    {
      const int r = get_intersect(u, kth);
      const int rt = top[id[r][0]];
      see(r, rt, id[r][0]);
      ans2 = d2root[u] - d2root[rt] + depth[u] + chains_psum[(size_t)kth] - chains[(size_t)id[r][0] - 1].first;
    }
    return std::max(ans1, ans2);
  }
} t1, t2;

int main()
{
  n = sc.n();
  q = sc.n();
  for (int i = 1; i < n; i++)
  {
    int u = sc.n(), v = sc.n(), w = sc.n();
    t1.add_edge(u, v, w);
    t2.add_edge(u, v, w);
  }

  int r1 = t1.get_farthest(1, 0).second;
  int r2 = t1.get_farthest(r1, 0).second;
  t1.dfs_init_depth(r1, 0);
  t1.dfs_init_len(r1, 0);
  t1.init_chains();
  t2.dfs_init_depth(r2, 0);
  t2.dfs_init_len(r2, 0);
  t2.init_chains();
  see(r1, r2);

  int last_ans = 0;
  while (q --> 0)
  {
    int x = sc.n(), y = sc.n();
    x = (x + last_ans - 1) % n + 1;
    y = (y + last_ans - 1) % n + 1;
    see(x, y);
    last_ans = std::max(t1.query(x, 2 * y - 1), t2.query(x, 2 * y - 1));
    printf("%d\n", last_ans);
  }
  return 0;
}