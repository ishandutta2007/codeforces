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
/** @file creats/Intdm.h
 * Integer under mod
 * division only works when %MOD is a prime
 */

#ifndef INTDM_H_
#define INTDM_H_

#if __cplusplus >= 201103L
#include <type_traits>
#endif

#include <limits>
#include <iostream>

#ifndef INTDM_FAST_32
#define INTDM_FAST_32 int
#endif
#ifndef INTDM_FAST_64
#define INTDM_FAST_64 unsigned long long
#endif

#define ATTR_INLINE __attribute__ ((always_inline)) inline

#if __cplusplus >= 201103L
#define CXX11_EXPLICIT  explicit
#else
#define CXX11_EXPLICIT
#endif

namespace Temps {

template <int _id>
class Intdm {

protected:
  static INTDM_FAST_32 MOD;
  INTDM_FAST_32 a = 0;

  static ATTR_INLINE Intdm 
  __make_Intdm(INTDM_FAST_32 _a) { return Intdm(_a, 0); }

  static ATTR_INLINE INTDM_FAST_32 
  __impl_inc(INTDM_FAST_32 a) { return a < 0 ? a+MOD : a; }

  static ATTR_INLINE INTDM_FAST_32
  __impl_dec(INTDM_FAST_32 a) { return a >= MOD ? a-MOD : a; }

  static ATTR_INLINE INTDM_FAST_32
  __impl_pow(INTDM_FAST_32 a, INTDM_FAST_32 b) {
    INTDM_FAST_32 res = 1; 
    for (; b; b >>= 1) {
      if (b & 1) { res = static_cast<INTDM_FAST_32>((INTDM_FAST_64)(res) * (INTDM_FAST_64)(a) % MOD); }
      a = static_cast<INTDM_FAST_32>((INTDM_FAST_64)(a) * (INTDM_FAST_64)(a) % MOD); }
    return res; }

public:

  static void set_mod(INTDM_FAST_32 _MOD)
  {
    MOD = _MOD; 
  }

#if __cplusplus >= 201103L
  Intdm() =default;
#else
  Intdm() {}
#endif

  ATTR_INLINE Intdm(int a)                : a(__impl_inc(a % MOD)) {}
  ATTR_INLINE Intdm(long a)               : a(__impl_inc(a % MOD)) {}
  ATTR_INLINE Intdm(long long a)          : a(__impl_inc(a % MOD)) {}
  ATTR_INLINE Intdm(unsigned int a)       : a(static_cast<INTDM_FAST_32>(a % MOD)) {}
  ATTR_INLINE Intdm(unsigned long a)      : a(static_cast<INTDM_FAST_32>(a % MOD)) {}
  ATTR_INLINE Intdm(unsigned long long a) : a(static_cast<INTDM_FAST_32>(a % MOD)) {}
  ATTR_INLINE CXX11_EXPLICIT Intdm(INTDM_FAST_32 a, int) : a(a)          {}
  template <class _IntType> ATTR_INLINE CXX11_EXPLICIT operator _IntType() const { return a; }
  ATTR_INLINE friend std::ostream& operator<< (std::ostream& out, const Intdm  rhs) { out << rhs.a; return out; }
  ATTR_INLINE friend std::istream& operator>> (std::istream& in,        Intdm &rhs) { long long a; in >> a; rhs = Intdm(a); return in; }

  template <class _IntType> ATTR_INLINE Intdm pow(_IntType k) const { return __make_Intdm(__impl_pow(a, k % (MOD-1))); }
  ATTR_INLINE Intdm inv() const 
  { 
#ifdef __LOCALE__
    if (a == 0)
      std::cerr << "warning: 0 do not have inv" << std::endl;
#endif
    return __make_Intdm(__impl_pow(a, MOD-2)); 
  }

  ATTR_INLINE friend bool operator<  (const Intdm a, const Intdm b) { return a.a <  b.a; }
  ATTR_INLINE friend bool operator<= (const Intdm a, const Intdm b) { return a.a <= b.a; }
  ATTR_INLINE friend bool operator>  (const Intdm a, const Intdm b) { return a.a >  b.a; }
  ATTR_INLINE friend bool operator>= (const Intdm a, const Intdm b) { return a.a >= b.a; }
  ATTR_INLINE friend bool operator== (const Intdm a, const Intdm b) { return a.a == b.a; }
  ATTR_INLINE friend bool operator!= (const Intdm a, const Intdm b) { return a.a != b.a; }

  template <class _IntType> ATTR_INLINE friend bool operator<  (const _IntType a, const Intdm b) { return a   <  b.a; }
  template <class _IntType> ATTR_INLINE friend bool operator<  (const Intdm a, const _IntType b) { return a.a <  b;   }
  template <class _IntType> ATTR_INLINE friend bool operator<= (const _IntType a, const Intdm b) { return a   <= b.a; }
  template <class _IntType> ATTR_INLINE friend bool operator<= (const Intdm a, const _IntType b) { return a.a <= b;   }
  template <class _IntType> ATTR_INLINE friend bool operator>  (const _IntType a, const Intdm b) { return a   >  b.a; }
  template <class _IntType> ATTR_INLINE friend bool operator>  (const Intdm a, const _IntType b) { return a.a >  b;   }
  template <class _IntType> ATTR_INLINE friend bool operator>= (const _IntType a, const Intdm b) { return a   >= b.a; }
  template <class _IntType> ATTR_INLINE friend bool operator>= (const Intdm a, const _IntType b) { return a.a >= b;   }
  template <class _IntType> ATTR_INLINE friend bool operator== (const _IntType a, const Intdm b) { return a   == b.a; }
  template <class _IntType> ATTR_INLINE friend bool operator== (const Intdm a, const _IntType b) { return a.a == b;   }
  template <class _IntType> ATTR_INLINE friend bool operator!= (const _IntType a, const Intdm b) { return a   != b.a; }
  template <class _IntType> ATTR_INLINE friend bool operator!= (const Intdm a, const _IntType b) { return a.a != b;   }

  ATTR_INLINE friend Intdm  operator+  (const Intdm  a, const Intdm b) { return __make_Intdm(__impl_dec(a.a + b.a)); }
  ATTR_INLINE friend Intdm  operator-  (const Intdm  a, const Intdm b) { return __make_Intdm(__impl_inc(a.a - b.a)); }
  ATTR_INLINE friend Intdm  operator*  (const Intdm  a, const Intdm b) { return __make_Intdm(static_cast<INTDM_FAST_32>((INTDM_FAST_64)(a.a) * (INTDM_FAST_64)(b.a) % MOD)); }
  ATTR_INLINE friend Intdm  operator/  (const Intdm  a, const Intdm b) { return a * b.inv(); }
  ATTR_INLINE friend Intdm& operator+= (      Intdm &a, const Intdm b) { return a = a + b;  }
  ATTR_INLINE friend Intdm& operator-= (      Intdm &a, const Intdm b) { return a = a - b;  }
  ATTR_INLINE friend Intdm& operator*= (      Intdm &a, const Intdm b) { return a = a * b;  }
  ATTR_INLINE friend Intdm& operator/= (      Intdm &a, const Intdm b) { return a = a / b;  }

  template <class _IntType> ATTR_INLINE friend Intdm  operator+  (const Intdm  a, const _IntType b) { return a +  Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm  operator-  (const Intdm  a, const _IntType b) { return a -  Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm  operator*  (const Intdm  a, const _IntType b) { return a *  Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm  operator/  (const Intdm  a, const _IntType b) { return a /  Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm& operator+= (      Intdm &a, const _IntType b) { return a += Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm& operator-= (      Intdm &a, const _IntType b) { return a -= Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm& operator*= (      Intdm &a, const _IntType b) { return a *= Intdm(b); }
  template <class _IntType> ATTR_INLINE friend Intdm& operator/= (      Intdm &a, const _IntType b) { return a /= Intdm(b); }

  template <class _IntType> ATTR_INLINE friend Intdm     operator+  (const _IntType  a, const Intdm b) { return Intdm(a) +  b; }
  template <class _IntType> ATTR_INLINE friend Intdm     operator-  (const _IntType  a, const Intdm b) { return Intdm(a) -  b; }
  template <class _IntType> ATTR_INLINE friend Intdm     operator*  (const _IntType  a, const Intdm b) { return Intdm(a) *  b; }
  template <class _IntType> ATTR_INLINE friend Intdm     operator/  (const _IntType  a, const Intdm b) { return Intdm(a) /  b; }
  template <class _IntType> ATTR_INLINE friend _IntType& operator+= (      _IntType &a, const Intdm b) { return a += _IntType(b); }
  template <class _IntType> ATTR_INLINE friend _IntType& operator-= (      _IntType &a, const Intdm b) { return a -= _IntType(b); }
  template <class _IntType> ATTR_INLINE friend _IntType& operator*= (      _IntType &a, const Intdm b) { return a *= _IntType(b); }
  template <class _IntType> ATTR_INLINE friend _IntType& operator/= (      _IntType &a, const Intdm b) { return a /= _IntType(b); }
};

template <int _id>
INTDM_FAST_32 Intdm<_id>::MOD;

}

#undef ATTR_INLINE
#undef CXX11_CONSTEXPR
#undef CXX14_CONSTEXPR
#undef INTDM_FAST_32
#undef INTDM_FAST_64

#endif /* INTDM_H_ */
// #include "/home/jack/cm/string"

#include <cstring>

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int N = 105;
using int_t = Temps::Intdm<0>;
int_t fac[N], c[N][N], f[N][N][N];
int n, m, k;

int_t dp(int size, int cnt, int dep)
{
  int_t &ans = f[dep][size][cnt];
  if (ans != -1) return ans;
  ans = 0;

  if (size == 0) return ans = 1;
  if ((m - dep < 7 && 
      (1 << (m - dep)) < cnt) || (cnt && size < m - dep))
    return ans;
  if (dep == m)
    return ans = (cnt == 1 ? fac[size] : 0);

  for (int i = 0; i < size; i++)
  {
    int_t fi = 0;
    for (int j = std::max(0, cnt + i + 1 - size); j <= std::min(cnt, i); j++)
      fi += dp(i, j, dep + 1) * dp(size - i - 1, cnt - j,  dep + 1);
    ans += fi * c[size - 1][i];
  }

  return ans;
}

int main()
{
  n = sc.next_int();
  m = sc.next_int() - 1;
  k = sc.next_int();
  int_t::set_mod(sc.next_int());

  c[0][0] = fac[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    c[i][0] = 1;
    fac[i] = fac[i - 1] * i;
    for (int j = 1; j <= i; j++)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }

  memset(f, -1, sizeof(f));
  dp(n, k, 0);
  std::cout << f[0][n][k] << std::endl;

  return 0;
}