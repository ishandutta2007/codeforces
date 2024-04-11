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
#ifndef CM_INTM_H_
#define CM_INTM_H_ 1
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
namespace cm{template<INTM_FAST_32 MOD=998244353>class intm{
#if __cplusplus >= 201103L
static_assert(MOD*2<std::numeric_limits<INTM_FAST_32>::max(),"");
#endif
protected:INTM_FAST_32 a=0;ATTR_INLINE CXX11_CONSTEXPR explicit intm(INTM_FAST_32 a,int):a(a){}static ATTR_INLINE CXX11_CONSTEXPR INTM_FAST_32 __impl_inc(INTM_FAST_32 a){return a<0?a+MOD:a;}static ATTR_INLINE CXX11_CONSTEXPR INTM_FAST_32 __impl_dec(INTM_FAST_32 a){return a>=MOD?a-MOD:a;}static ATTR_INLINE CXX14_CONSTEXPR INTM_FAST_32 __impl_pow(INTM_FAST_32 a,INTM_FAST_32 b){INTM_FAST_32 res=1;for(;b;b>>=1){if(b&1){res=static_cast<INTM_FAST_32>((INTM_FAST_64)(res)*(INTM_FAST_64)(a)%MOD);}a=static_cast<INTM_FAST_32>((INTM_FAST_64)(a)*(INTM_FAST_64)(a)%MOD);}return res;}public:
#if __cplusplus >= 201103L
intm()=default;
#else
intm(){}
#endif
static intm raw(INTM_FAST_32 x){return intm(x,0);}ATTR_INLINE CXX11_CONSTEXPR intm(int a):a(static_cast<INTM_FAST_32>(__impl_inc(a%MOD))){}ATTR_INLINE CXX11_CONSTEXPR intm(long a):a(static_cast<INTM_FAST_32>(__impl_inc(a%MOD))){}ATTR_INLINE CXX11_CONSTEXPR intm(long long a):a(static_cast<INTM_FAST_32>(__impl_inc(a%MOD))){}ATTR_INLINE CXX11_CONSTEXPR intm(unsigned int a):a(static_cast<INTM_FAST_32>(a%MOD)){}ATTR_INLINE CXX11_CONSTEXPR intm(unsigned long a):a(static_cast<INTM_FAST_32>(a%MOD)){}ATTR_INLINE CXX11_CONSTEXPR intm(unsigned long long a):a(static_cast<INTM_FAST_32>(a%MOD)){}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR CXX11_EXPLICIT operator _IntType()const{return a;}ATTR_INLINE friend std::ostream&operator<<(std::ostream&out,const intm rhs){out<<rhs.a;return out;}ATTR_INLINE friend std::istream&operator>>(std::istream&in,intm&rhs){long long a;in>>a;rhs=intm(a);return in;}template<class _IntType>ATTR_INLINE CXX14_CONSTEXPR intm pow(_IntType k)const{return raw(__impl_pow(a,k%(MOD-1)));}ATTR_INLINE CXX14_CONSTEXPR intm inv()const{
#ifdef CM_DEBUG_H
cm_assert(a!=0,"warning:0 do not have inv");
#endif
return raw(__impl_pow(a,MOD-2));}ATTR_INLINE CXX11_CONSTEXPR friend bool operator<(const intm a,const intm b){return a.a<b.a;}ATTR_INLINE CXX11_CONSTEXPR friend bool operator<=(const intm a,const intm b){return a.a<=b.a;}ATTR_INLINE CXX11_CONSTEXPR friend bool operator>(const intm a,const intm b){return a.a>b.a;}ATTR_INLINE CXX11_CONSTEXPR friend bool operator>=(const intm a,const intm b){return a.a>=b.a;}ATTR_INLINE CXX11_CONSTEXPR friend bool operator==(const intm a,const intm b){return a.a==b.a;}ATTR_INLINE CXX11_CONSTEXPR friend bool operator!=(const intm a,const intm b){return a.a!=b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator<(const _IntType a,const intm b){return a<b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator<(const intm a,const _IntType b){return a.a<b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator<=(const _IntType a,const intm b){return a<=b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator<=(const intm a,const _IntType b){return a.a<=b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator>(const _IntType a,const intm b){return a>b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator>(const intm a,const _IntType b){return a.a>b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator>=(const _IntType a,const intm b){return a>=b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator>=(const intm a,const _IntType b){return a.a>=b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator==(const _IntType a,const intm b){return a==b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator==(const intm a,const _IntType b){return a.a==b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator!=(const _IntType a,const intm b){return a!=b.a;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend bool operator!=(const intm a,const _IntType b){return a.a!=b;}ATTR_INLINE CXX11_CONSTEXPR friend intm operator+(const intm a,const intm b){return raw(__impl_dec(a.a+b.a));}ATTR_INLINE CXX11_CONSTEXPR friend intm operator-(const intm a,const intm b){return raw(__impl_inc(a.a-b.a));}ATTR_INLINE CXX11_CONSTEXPR friend intm operator*(const intm a,const intm b){return raw(static_cast<INTM_FAST_32>((INTM_FAST_64)(a.a)*(INTM_FAST_64)(b.a)%MOD));}ATTR_INLINE CXX14_CONSTEXPR friend intm operator/(const intm a,const intm b){return a*b.inv();}ATTR_INLINE CXX11_CONSTEXPR friend intm&operator+=(intm&a,const intm b){return a=a+b;}ATTR_INLINE CXX11_CONSTEXPR friend intm&operator-=(intm&a,const intm b){return a=a-b;}ATTR_INLINE CXX11_CONSTEXPR friend intm&operator*=(intm&a,const intm b){return a=a*b;}ATTR_INLINE CXX14_CONSTEXPR friend intm&operator/=(intm&a,const intm b){return a=a/b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm operator+(const intm a,const _IntType b){return a+intm(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm operator-(const intm a,const _IntType b){return a-intm(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm operator*(const intm a,const _IntType b){return a*intm(b);}template<class _IntType>ATTR_INLINE CXX14_CONSTEXPR friend intm operator/(const intm a,const _IntType b){return a/intm(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm&operator+=(intm&a,const _IntType b){return a+=intm(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm&operator-=(intm&a,const _IntType b){return a-=intm(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm&operator*=(intm&a,const _IntType b){return a*=intm(b);}template<class _IntType>ATTR_INLINE CXX14_CONSTEXPR friend intm&operator/=(intm&a,const _IntType b){return a/=intm(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm operator+(const _IntType a,const intm b){return intm(a)+b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm operator-(const _IntType a,const intm b){return intm(a)-b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend intm operator*(const _IntType a,const intm b){return intm(a)*b;}template<class _IntType>ATTR_INLINE CXX14_CONSTEXPR friend intm operator/(const _IntType a,const intm b){return intm(a)/b;}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend _IntType&operator+=(_IntType&a,const intm b){return a+=_IntType(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend _IntType&operator-=(_IntType&a,const intm b){return a-=_IntType(b);}template<class _IntType>ATTR_INLINE CXX11_CONSTEXPR friend _IntType&operator*=(_IntType&a,const intm b){return a*=_IntType(b);}template<class _IntType>ATTR_INLINE CXX14_CONSTEXPR friend _IntType&operator/=(_IntType&a,const intm b){return a/=_IntType(b);}};}
#undef ATTR_INLINE
#undef CXX11_CONSTEXPR
#undef CXX14_CONSTEXPR
#undef INTM_FAST_32
#undef INTM_FAST_64
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
#include <algorithm>
#include <cstring>
#include <vector>
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int W = 10'000'005;
bool is_prime[W];
std::vector<int> primes;
int mu[W], fac[W];

void sieve()
{
  memset(is_prime, 1, sizeof(is_prime));
  mu[1] = 1;
  is_prime[1] = false;
  for (int i = 2; i < W; i++)
  {
    if (is_prime[i])
    {
      primes.push_back(i);
      mu[i] = -1;
      fac[i] = i;
    }
    for (int j : primes)
    {
      int k = i * j;
      if (k >= W)
        break;
      is_prime[k] = false;
      fac[k] = j;
      if (i % j == 0)
      {
        mu[k] = 0;
        break;
      }
      mu[k] = mu[i] * mu[j];
    }
  }
}

std::vector<int> factors(int n)
{
  std::vector<int> res{1};
  while (n > 1)
  {
    std::vector<int> cur;
    int p = fac[n], pi = 0;
    while (n % p == 0)
      n /= p, pi++;
    for (int x : res)
      for (int i = 0, pc = 1; i <= pi; i++, pc *= p)
        cur.push_back(x * pc);
    res = std::move(cur);
  }
  return res;
}

constexpr int MOD = 1'000'000'007;
constexpr int N = 500005;
using int_t = cm::intm<MOD>;

int_t g_cnt[W];
int a[N];
int n;

int main()
{
  sieve();

  n = sc.next_int();
  for (int i = 0; i < n; i++)
    a[i] = sc.next_int();

  for (int i = 0; i < W; i++)
    g_cnt[i] = 1;
  for (int i = 0; i < n; i++)
    for (int p : factors(a[i]))
      g_cnt[p] *= 2;
  for (int i = 0; i < W; i++)
    g_cnt[i] -= 1;
  for (int p = 2; p < W; p++)
    if (is_prime[p])
      for (int j = 1; j * p < W; j++)
        g_cnt[j] -= g_cnt[j * p];
  g_cnt[1] = 0;

  // see(std::vector<int_t>(g_cnt, g_cnt + 10));

  for (int p = 2; p < W; p++)
    if (is_prime[p])
      for (int j = (W - 1) / p; j >= 1; j--)
        g_cnt[j] += g_cnt[j * p];

  // see(std::vector<int_t>(g_cnt, g_cnt + 10));

  int_t ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int p : factors(a[i]))
      ans += mu[p] * g_cnt[p];
  }

  std::cout << ans << std::endl;

  return 0;
}