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
#include <vector>
namespace cm{template<class T>inline bool check_min(T&a,const T&b){return b<a?a=b,1:0;}template<class T>inline bool check_max(T&a,const T&b){return a<b?a=b,1:0;}struct once_t{bool once=true;bool operator()(){return once?(once=false,true):false;}};}using cm::check_min;using cm::check_max;template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>operator+(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first+rhs.first,lhs.second+rhs.second);}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>operator-(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first-rhs.first,lhs.second-rhs.second);}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>&operator+=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first+=rhs.first;lhs.second+=rhs.second;return lhs;}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>&operator-=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first-=rhs.first;lhs.second-=rhs.second;return lhs;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const std::vector<T>&b){a.insert(a.end(),b.begin(),b.end());return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const T&b){a.insert(a.end(),b);return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,T&&b){a.insert(a.end(),std::forward<T>(b));return a;}template<class T>std::vector<T>operator+(std::vector<T>a,const std::vector<T>&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&&b){a+=std::forward<T>(b);return a;}
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

cm::scanner<cm::optimal_reader> sc(stdin);

#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 50000, M = 50000;
int k, mod, n, s[N], m;
std::pair<int, int> v[M + 1];
std::vector<std::pair<int, std::pair<bool, int>>> v0;

struct matrix_t
{
  int a[2][2];
  const int *operator[](int x) const
  {
    return a[x];
  }
  int *operator[](int x)
  {
    return a[x];
  }
  matrix_t(int x = 0, int y = 0, int z = 0, int xx = 0)
  {
    a[0][0] = x, a[0][1] = y, a[1][0] = z, a[1][1] = xx;
  }
  friend matrix_t operator*(const matrix_t &lhs, const matrix_t &rhs)
  {
    return matrix_t{(lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0]) % mod,
                    (lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]) % mod,
                    (lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0]) % mod,
                    (lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]) % mod};
  }
};

matrix_t pow(matrix_t x, int y)
{
  matrix_t res(1, 0, 0, 1);
  while (y)
  {
    if (y & 1)
      res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}

struct sgt_t
{
  struct node_t
  {
    signed l, r;
    matrix_t v;
  };

  node_t p[N * 4];

  void push_up(int pos)
  {
    p[pos].v = p[pos * 2].v * p[pos * 2 + 1].v;
  }

  void build(signed l = 0, signed r = (signed)(n - 1), int pos = 1)
  {
    p[pos].l = l;
    p[pos].r = r;
    if (l == r)
    {
      p[pos].v = matrix_t(0, s[l], 1, s[(l + 1) % n]);
      return;
    }
    signed mid = (l + r) / 2;
    build(l, mid, pos * 2);
    build(mid + 1, r, pos * 2 + 1);
    push_up(pos);
  }

  void modify(int x, bool y, int v, int pos = 1)
  {
    if (p[pos].l == p[pos].r)
    {
      p[pos].v[y][1] = v;
      return;
    }
    signed mid = (p[pos].l + p[pos].r) / 2;
    modify(x, y, v, pos * 2 + (x > mid));
    push_up(pos);
  }
  matrix_t prod(int l = 0, int r = n - 1, int pos = 1)
  {
    if (l > r)
      return matrix_t(1, 0, 0, 1);
    if (l <= p[pos].l && r >= p[pos].r)
      return p[pos].v;
    signed mid = (p[pos].l + p[pos].r) / 2;
    matrix_t res(1, 0, 0, 1);
    if (l <= mid)
      res = prod(l, r, pos * 2);
    if (r > mid)
      res = res * prod(l, r, pos * 2 + 1);
    return res;
  }
} sgt;

signed main()
{
  k = sc.next_long();
  mod = sc.next_long();
  n = sc.next_long();
  for (int i = 0; i < n; i++)
    s[i] = sc.next_long();
  m = sc.next_long();
  for (int i = 1; i <= m; i++)
  {
    v[i].first = sc.next_long();
    v[i].second = sc.next_long();
  }

  v0.push_back(std::make_pair(-n, std::make_pair(0, 0)));
  v0.push_back(std::make_pair(inf, std::make_pair(0, 0)));
  for (int i = 1; i <= m; i++)
  {
    v0.push_back(std::make_pair(v[i].first, std::make_pair(0, v[i].second)));
    if (v[i].first)
      v0.push_back(
          std::make_pair(v[i].first - 1, std::make_pair(1, v[i].second)));
  }

  std::sort(v0.begin(), v0.end());
  sgt.build();
  matrix_t res(1, 0, 0, 1);
  int las = 0;
  for (size_t i = 1, ie; i < v0.size(); i = ie)
  {
    ie = i;
    while (ie < v0.size() && v0[ie].first / n == v0[i].first / n)
      ie++;
    if (v0[i].first / n >= k / n)
    {
      las = v0[i - 1].first / n;
      break;
    }
    res = res * pow(sgt.prod(), v0[i].first / n - 1 - v0[i - 1].first / n);
    for (size_t j = i; j < ie; j++)
      sgt.modify(v0[j].first % n, v0[j].second.first, v0[j].second.second);
    res = res * sgt.prod();
    for (size_t j = i; j < ie; j++)
      sgt.modify(v0[j].first % n, v0[j].second.first,
                 v0[j].second.first ? s[(v0[j].first + 1) % n]
                                    : s[v0[j].first % n]);
  }

  res = res * pow(sgt.prod(), k / n - 1 - las);
  for (size_t i = 0; i < v0.size(); i++)
    if (v0[i].first / n == k / n)
      sgt.modify(v0[i].first % n, v0[i].second.first, v0[i].second.second);
  res = res * sgt.prod(0, k % n - 1);
  std::cout << res[1][0] << std::endl;

  return 0;
}