#ifndef CM_DEBUG_H
#define CM_DEBUG_H 1
#include <iostream>
#include <utility>
#include <tuple>
#include <iterator>
#include <string>
namespace cm{class logger{private:std::ostream*out;std::string sep="\x2c\x20";bool _assert_exit=true;std::string c_red="\033[0;31m";std::string c_green="\033[0;32m";std::string c_yellow="\033[0;33m";std::string c_blue="\033[0;34m";std::string c_magenta="\033[0;35m";std::string c_cyan="\033[0;36m";std::string c_red_bold="\033[1;31m";std::string c_green_bold="\033[1;32m";std::string c_yellow_bold="\033[1;33m";std::string c_blue_bold="\033[1;34m";std::string c_magenta_bold="\033[1;35m";std::string c_cyan_bold="\033[1;36m";std::string c_reset="\033[0m";std::string get_color(std::string name){if(name=="red")return c_red;if(name=="green")return c_green;if(name=="yellow")return c_yellow;if(name=="blue")return c_blue;if(name=="magenta")return c_magenta;if(name=="cyan")return c_cyan;if(name=="red bold")return c_red_bold;if(name=="green bold")return c_green_bold;if(name=="yellow bold")return c_yellow_bold;if(name=="blue bold")return c_blue_bold;if(name=="magenta bold")return c_magenta_bold;if(name=="cyan bold")return c_cyan_bold;if(name=="reset")return c_reset;return "";}public:logger(std::ostream&out):out(&out){}logger&set_ostream(std::ostream&out){this->out=&out;return*this;}logger&set_sep(const std::string&sep){this->sep=sep;return*this;}logger&assert_exit(){_assert_exit=true;return*this;}logger&assert_noexit(){_assert_exit=false;return*this;}logger&endl(){*out<<std::endl;return*this;}logger&log(){return*this;}template<class Ta,class Tb,class...Tc>logger&log(const Ta&a,const Tb&b,Tc...c){return log(a).log(sep).log(b,c...);}template<class Ta,typename=decltype(std::cout<<std::declval<Ta>())>logger&log(const Ta&a){*out<<a;return*this;}template<class T,typename=decltype(std::declval<T>().begin()),typename=decltype(std::declval<T>().end()),typename=typename std::enable_if<!std::is_base_of<std::string,typename std::decay<T>::type>::value>::type,typename value_type=typename T::value_type>logger&log(const T&container){log("{");for(auto it=container.begin();it!=container.end();++it){if(it!=container.begin())log(sep);log(*it);}log("}");return*this;}template<class Ta,class Tb>logger&log(const std::pair<Ta,Tb>&x){return log("(").log(x.first,x.second).log(")");}
#if __cplusplus >= 201703L
template<class...T>logger&log(const std::tuple<T...>&x){log("(");std::apply([this](auto...x){this->log(x...);},x);return log(")");}
#else
template<class...T>logger&log(const std::tuple<T...>&){return log("<tuple>");}
#endif
template<class T>logger&hint(const T&x,std::string color="cyan"){color=get_color(color);return log(color).log(x).log("\x3a\x20").log(c_reset);}template<class...T>logger&operator()(T...value){return log(value...).endl();}template<class...T>logger&_assert(const std::string&file,int line,const std::string&raw,bool value,const std::string&info_str,T...info){if(!value){endl();hint(file,"magenta").hint(line,"magenta").log(c_yellow).log("Assertion `").log(c_yellow_bold).log(raw).log(c_yellow).log("` failed").log(c_reset).endl();if(info_str!="")hint("detail","magenta").hint(info_str)(info...);if(_assert_exit)exit(0);}return*this;}};namespace impl{logger see_logger(std::cout);}}
#ifdef CM_DEBUG
#define see(arg...) cm::impl::see_logger.hint(#arg)(arg)
#define asee(arg...) cm::impl::see_logger.hint(__FILE__, "magenta").hint(__LINE__, "magenta").hint(#arg)(arg)
#define cm_assert(val, arg...) cm::impl::see_logger._assert(__FILE__, __LINE__, #val, val, #arg, ##arg)
#else
#define see(...)
#define asee(...)
#define cm_assert(...)
#endif
#endif
#ifndef CM_SCANNER_H
#define CM_SCANNER_H
#include <cstdio>
#include <cctype>
namespace cm{template<class Type,size_t buf_size>class buffer_reader{protected:FILE*src;Type*const buff;Type*buff_end;Type*buff_pos;void flush(){buff_end=buff+fread(buff,sizeof(Type),buf_size,src);buff_pos=buff;if(buff_end==buff){*buff_end='\0';}}public:buffer_reader(FILE*src):src(src),buff(new Type[buf_size]){flush();}buffer_reader(const buffer_reader&)=delete;buffer_reader(buffer_reader&&)=delete;buffer_reader&operator=(const buffer_reader&)=delete;buffer_reader&operator=(buffer_reader&&)=delete;Type get()const{return*buff_pos;}Type next(){Type result=get();buff_pos++;if(buff_pos==buff_end)flush();return result;}~buffer_reader(){fclose(src);delete[]buff;}};
#ifdef CM_DEBUG
using optimal_reader=buffer_reader<char,1>;
#else
using optimal_reader=buffer_reader<char,1<<16>;
#endif
template<class BufferReader>class scanner:protected BufferReader{private:using BufferReader::get;using BufferReader::next;inline bool is_ws(char c){return c<=' ';}inline bool is_cr(char c){return c=='\n'||c=='\r';}int get_sign(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using BufferReader::BufferReader;char next_char(){while(is_ws(get()))next();return next();}char*next_token(char*s){while(is_ws(get()))next();while(!is_ws(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(is_ws(get()))next();while(!is_cr(get()))*s++=next();*s='\0';return s;}int next_int(){int sign=get_sign();int result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_long(){int sign=get_sign();long long result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_modint(long long mod){get_sign();long long result=0;while(isdigit(get()))result=(result*10+(next()-'0'))%mod;return result;}double next_double(){int sign=get_sign();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
#endif
#ifndef CM_UTIL_H
#define CM_UTIL_H 1
#include <utility>
namespace cm{template<class T>inline bool check_min(T&a,const T&b){return b<a?a=b,1:0;}template<class T>inline bool check_max(T&a,const T&b){return b>a?a=b,1:0;}struct once_t{bool once=true;bool operator()(){return once?(once=false,true):false;}};}using cm::check_min;using cm::check_max;template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>operator+(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first+rhs.first,lhs.second+rhs.second);}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>operator-(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first-rhs.first,lhs.second-rhs.second);}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>&operator+=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first+=rhs.first;lhs.second+=rhs.second;return lhs;}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>&operator-=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first-=rhs.first;lhs.second-=rhs.second;return lhs;}
#define __AT_INIT(line, Pred) struct CM_INNER_ATINIT##line##_t { \
CM_INNER_ATINIT##line## _t()Pred}CM_INNER_ATINIT##line
#define _AT_INIT(line, Pred) __AT_INIT(line, Pred)
#define AT_INIT(Pred) _AT_INIT(__LINE__, Pred)
#define __AT_EXIT(line, Pred) struct CM_INNER_ATEXIT##line##_t { \
~CM_INNER_ATEXIT##line## _t()Pred}CM_INNER_ATEXIT##line
#define _AT_EXIT(line, Pred) __AT_EXIT(line, Pred)
#define AT_EXIT(Pred) _AT_EXIT(__LINE__, Pred)
#endif
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

cm::scanner<cm::optimal_reader> sc(stdin);

template <class Int>
Int gcd(Int a, Int b)
{ return b == 0 ? a : gcd(b, a % b); }

struct graph_t
{
  std::vector<int> vertices, exclude;
  std::vector<std::vector<std::pair<int,long long>>> edge;
  std::vector<long long> dis;

  void add_vertex(int u) { vertices.push_back(u); }
  int get_vertex(int u) { return static_cast<int>(std::lower_bound(vertices.begin(), vertices.end(), u) - vertices.begin()); }
  void ready() { 
    std::sort(vertices.begin(), vertices.end());
    vertices.erase(std::unique(vertices.begin(), vertices.end()), vertices.end()); 
    edge.resize(vertices.size()); dis = std::vector<long long>(vertices.size(), std::numeric_limits<long long>::max() / 2);
    for (auto& x : exclude) x = get_vertex(x); }
  void add_edge(int u, int v, long long w) { 
    see(u, v, w);
    u = get_vertex(u); v = get_vertex(v);
    edge[u].emplace_back(v, w); }

  long long get_max_mp(int s) { s = get_vertex(s);
    std::priority_queue<std::pair<long long,int>, std::vector<std::pair<long long,int>>, std::greater<std::pair<long long,int>>> que;
    dis[s] = 0; que.emplace(0, s);
    while (!que.empty()) { const auto [d, u] = que.top(); que.pop();
      see(d, u);
      if (d != dis[u]) continue;
      for (const auto& [v,w] : edge[u]) if (check_min(dis[v], d + w)) {
        que.emplace(dis[v], v); see(d, w, d + w); } }
    for (int x : exclude) dis[x] = 0;
    see(dis);
    return *std::max_element(dis.begin(), dis.end()); }
};

int phi(int x) {
  int res = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i; } }
  if (x != 1) res = res / x * (x - 1);
  return res; }
int power(int a, int b, int mod) {
  int r = 1;; 
  for (; b; b >>= 1) {
    if (b & 1) r = 1ll * r * a % mod;
    a = 1ll * a * a % mod; }
  return r; }
int inv(int a, int b) { return power(a, phi(b) - 1, b); }

std::vector<int> join(const std::vector<int> &a, const std::vector<int> &b)
{
  std::vector<int> res(a.size() + b.size());
  std::merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
  res.erase(std::unique(res.begin(), res.end()), res.end());
  return res;
}

long long solve(int n, int m, const std::vector<int> &a, const std::vector<int> &b)
{
  see(n, m);
  see(a);
  see(b);

  {
    int g = gcd(n ,m);
    see(g);
    if (g != 1)
    {
      if ((size_t)g > a.size() + b.size()) { puts("-1"); exit(0); }
      std::vector<std::vector<int>> ga(g), gb(g);
      for (int x : a) ga[x % g].push_back(x / g);
      for (int x : b) gb[x % g].push_back(x / g);
      see(ga, gb);
      long long ans = 0;
      for (int i = 0; i < g; i++)
        check_max(ans, solve(n / g, m / g, ga[i], gb[i]) * g + i);
      return ans;
    }
  }

  if ((int)a.size() == n && (int)b.size() == m) { return -1; }
  if (n < m) return solve(m, n, b, a);
  if (a.empty() && b.empty()) { puts("-1"); exit(0); }

  auto c = join(a, b);
  if ((size_t)n == c.size())
  {
    long long res = 0;
    for (int i = 1; i <= n; i++)
      if ((int)a.size() - i < 0 || a[a.size() - i] != n - i)
      { check_max(res, (long long)n - i); break; }
    for (int i = 1; i <= m; i++)
      if ((int)b.size() - i < 0 || b[b.size() - i] != m - i)
      { check_max(res, (long long)m - i); break; }
    return res;
  }

  graph_t g;
  g.add_vertex(-1);
  for (int x : c) 
  {
    g.add_vertex(x);
    g.add_vertex((x + n - m) % n);
  }
  for (int x : a)
    g.exclude.push_back(x);
  g.ready();

  for (int x : c)
  {
    g.add_edge(-1, x, x);
    g.add_edge((x + n - m) % n, x, m);
  }

  int inv_m = inv(m, n);
  std::vector<std::pair<int,int>> ord;
  for (int x : c)
    ord.emplace_back(1ll * x * inv_m % n, x);
  std::sort(ord.begin(), ord.end());
  ord.push_back(ord.front());
  ord.back().first += n;
  see(ord);

  for (size_t i = 0; i < c.size(); i++)
  {
    long long ew = 1ll * m * (ord[i + 1].first - ord[i].first - 1);
    g.add_edge(ord[i].second, (ord[i].second + ew) % n, ew);
  }

  return g.get_max_mp(-1);
}

int main()
{
  int n = sc.next_int();
  int m = sc.next_int();
  std::vector<int> a(sc.next_int());
  for (auto& x: a) x = sc.next_int();
  std::vector<int> b(sc.next_int());
  for (auto& x: b) x = sc.next_int();
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  std::cout << std::max(0ll, solve(n, m, a, b)) << std::endl;
  return 0;
}