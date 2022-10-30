#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
namespace cm{class logger{private:std::ostream*_1c;std::string _1b="\x2c\x20";bool _15=true;int _12=0;std::string _1="\033[0;31m";std::string _2="\033[0;32m";std::string _16="\033[0;33m";std::string _3="\033[0;34m";std::string _4="\033[0;35m";std::string _5="\033[0;36m";std::string _6="\033[1;31m";std::string _7="\033[1;32m";std::string _13="\033[1;33m";std::string _8="\033[1;34m";std::string _9="\033[1;35m";std::string _a="\033[1;36m";std::string _17="\033[0m";std::string _b(const std::string&_1d){if(_1d=="red")return _1;if(_1d=="green")return _2;if(_1d=="yellow")return _16;if(_1d=="blue")return _3;if(_1d=="magenta")return _4;if(_1d=="cyan")return _5;if(_1d=="red bold")return _6;if(_1d=="green bold")return _7;if(_1d=="yellow bold")return _13;if(_1d=="blue bold")return _8;if(_1d=="magenta bold")return _9;if(_1d=="cyan bold")return _a;if(_1d=="reset")return _17;return "";}public:explicit logger(std::ostream&_1c):_1c(&_1c){}logger&set_ostream(std::ostream&_1c){this->_1c=&_1c;return*this;}logger&set_sep(const std::string&_1b){this->_1b=_1b;return*this;}logger&assert_exit(){_15=true;return*this;}logger&assert_noexit(){_15=false;return*this;}logger&set_exit_code(int _c){_12=_c;return*this;}logger&endl(){*_1c<<std::endl;return*this;}logger&log(){return*this;}template<class Ta,class Tb,class...Tc>logger&log(const Ta&a,const Tb&b,Tc...c){return log(a).log(_1b).log(b,c...);}template<class Ta,typename=decltype(std::cout<<std::declval<Ta>())>logger&log(const Ta&a){*_1c<<a;return*this;}template<class T,typename=decltype(std::declval<T>().begin()),typename=decltype(std::declval<T>().end()),typename=typename std::enable_if<!std::is_base_of<std::string,typename std::decay<T>::type>::value>::type,typename value_type=typename T::value_type>logger&log(const T&_18){log("{");for(auto it=_18.begin();it!=_18.end();++it){if(it!=_18.begin())log(_1b);log(*it);}log("}");return*this;}template<class Ta,class Tb>logger&log(const std::pair<Ta,Tb>&x){return log("(").log(x.first,x.second).log(")");}
#if __cplusplus >= 201703L
template<class...T>logger&log(const std::tuple<T...>&x){log("(");std::apply([this](auto...x){this->log(x...);},x);return log(")");}
#else
template<class...T>logger&log(const std::tuple<T...>&){return log("<tuple>");}
#endif
template<class T>logger&hint(const T&x,std::string _19="cyan"){_19=_b(_19);return log(_19).log(x).log("\x3a\x20").log(_17);}template<class...T>logger&operator()(T..._1a){return log(_1a...).endl();}template<class...T>logger&_d(const std::string&_e,int _f,const std::string&_10,bool _1a,const std::string&_14,T..._11){if(!_1a){endl();hint(_e,"magenta").hint(_f,"magenta").log(_16).log("Assertion `").log(_13).log(_10).log(_16).log("` failed").log(_17).endl();if(_14!="")hint("detail","magenta").hint(_14)(_11...);if(_15)exit(_12);}return*this;}};namespace impl{logger see_logger(std::cout);}}
#define see(...)
#define asee(...)
#define cm_assert(...)
#if __cplusplus >= 201103L
#include <type_traits>
#endif
#include <iostream>
#include <limits>
#define INTM_FAST_32 int
#define INTM_FAST_64 unsigned long long
#define _7 __attribute__((always_inline)) inline
#if __cplusplus >= 201103L
#define _6 constexpr
#define CXX11_EXPLICIT explicit
#else
#define _6
#define CXX11_EXPLICIT
#endif
#if __cplusplus >= 201402L
#define _5 constexpr
#else
#define _5
#endif
namespace cm{template<INTM_FAST_32 _2=998244353>class intm{
#if __cplusplus >= 201103L
static_assert(_2*2<std::numeric_limits<INTM_FAST_32>::max(),"");
#endif
public:static constexpr int MOD=_2;protected:INTM_FAST_32 a=0;_7 _6 explicit intm(INTM_FAST_32 a,int):a(a){}static _7 _6 INTM_FAST_32 _4(INTM_FAST_32 a){return a<0?a+MOD:a;}static _7 _6 INTM_FAST_32 _1(INTM_FAST_32 a){return a>=MOD?a-MOD:a;}template<class IntType>static _7 _5 INTM_FAST_32 _3(INTM_FAST_32 a,IntType b){INTM_FAST_32 res=1;for(;b;b>>=1){if(b&1){res=(INTM_FAST_32)((INTM_FAST_64)(res)*(INTM_FAST_64)(a)%MOD);}a=(INTM_FAST_32)((INTM_FAST_64)(a)*(INTM_FAST_64)(a)%MOD);}return res;}static int pretty(int x){if(x>=MOD-1000)return x-MOD;return x;}public:
#if __cplusplus >= 201103L
intm()=default;
#else
intm(){}
#endif
static _6 intm raw(INTM_FAST_32 x){return intm(x,0);}_7 _6 intm(int a):a(static_cast<INTM_FAST_32>(_4(a%MOD))){}_7 _6 intm(long a):a(static_cast<INTM_FAST_32>(_4(a%MOD))){}_7 _6 intm(long long a):a(static_cast<INTM_FAST_32>(_4(a%MOD))){}_7 _6 intm(unsigned int a):a(static_cast<INTM_FAST_32>(a%MOD)){}_7 _6 intm(unsigned long a):a(static_cast<INTM_FAST_32>(a%MOD)){}_7 _6 intm(unsigned long long a):a(static_cast<INTM_FAST_32>(a%MOD)){}template<class _8>_7 _6 CXX11_EXPLICIT operator _8()const{return a;}_7 friend std::ostream&operator<<(std::ostream&out,const intm rhs){
out<<rhs.a;return out;
}_7 friend std::istream&operator>>(std::istream&in,intm&rhs){long long a;in>>a;rhs=intm(a);return in;}template<class _8>_7 _5 intm pow(_8 k)const{return raw(_3(a,k));}_7 _5 intm inv()const{
cm_assert(a!=0,"warning:0 do not have inv");
return raw(_3(a,MOD-2));}_7 _6 friend bool operator<(const intm a,const intm b){return a.a<b.a;}_7 _6 friend bool operator<=(const intm a,const intm b){return a.a<=b.a;}_7 _6 friend bool operator>(const intm a,const intm b){return a.a>b.a;}_7 _6 friend bool operator>=(const intm a,const intm b){return a.a>=b.a;}_7 _6 friend bool operator==(const intm a,const intm b){return a.a==b.a;}_7 _6 friend bool operator!=(const intm a,const intm b){return a.a!=b.a;}template<class _8>_7 _6 friend bool operator<(const _8 a,const intm b){return a<b.a;}template<class _8>_7 _6 friend bool operator<(const intm a,const _8 b){return a.a<b;}template<class _8>_7 _6 friend bool operator<=(const _8 a,const intm b){return a<=b.a;}template<class _8>_7 _6 friend bool operator<=(const intm a,const _8 b){return a.a<=b;}template<class _8>_7 _6 friend bool operator>(const _8 a,const intm b){return a>b.a;}template<class _8>_7 _6 friend bool operator>(const intm a,const _8 b){return a.a>b;}template<class _8>_7 _6 friend bool operator>=(const _8 a,const intm b){return a>=b.a;}template<class _8>_7 _6 friend bool operator>=(const intm a,const _8 b){return a.a>=b;}template<class _8>_7 _6 friend bool operator==(const _8 a,const intm b){return a==b.a;}template<class _8>_7 _6 friend bool operator==(const intm a,const _8 b){return a.a==b;}template<class _8>_7 _6 friend bool operator!=(const _8 a,const intm b){return a!=b.a;}template<class _8>_7 _6 friend bool operator!=(const intm a,const _8 b){return a.a!=b;}_7 _6 friend intm operator+(const intm a,const intm b){return raw(_1(a.a+b.a));}_7 _6 friend intm operator-(const intm a,const intm b){return raw(_4(a.a-b.a));}_7 _6 friend intm operator*(const intm a,const intm b){return raw(static_cast<INTM_FAST_32>((INTM_FAST_64)(a.a)*(INTM_FAST_64)(b.a)%MOD));}_7 _5 friend intm operator/(const intm a,const intm b){return a*b.inv();}_7 _6 friend intm&operator+=(intm&a,const intm b){return a=a+b;}_7 _6 friend intm&operator-=(intm&a,const intm b){return a=a-b;}_7 _6 friend intm&operator*=(intm&a,const intm b){return a=a*b;}_7 _5 friend intm&operator/=(intm&a,const intm b){return a=a/b;}template<class _8>_7 _6 friend intm operator+(const intm a,const _8 b){return a+intm(b);}template<class _8>_7 _6 friend intm operator-(const intm a,const _8 b){return a-intm(b);}template<class _8>_7 _6 friend intm operator*(const intm a,const _8 b){return a*intm(b);}template<class _8>_7 _5 friend intm operator/(const intm a,const _8 b){return a/intm(b);}template<class _8>_7 _6 friend intm&operator+=(intm&a,const _8 b){return a+=intm(b);}template<class _8>_7 _6 friend intm&operator-=(intm&a,const _8 b){return a-=intm(b);}template<class _8>_7 _6 friend intm&operator*=(intm&a,const _8 b){return a*=intm(b);}template<class _8>_7 _5 friend intm&operator/=(intm&a,const _8 b){return a/=intm(b);}template<class _8>_7 _6 friend intm operator+(const _8 a,const intm b){return intm(a)+b;}template<class _8>_7 _6 friend intm operator-(const _8 a,const intm b){return intm(a)-b;}template<class _8>_7 _6 friend intm operator*(const _8 a,const intm b){return intm(a)*b;}template<class _8>_7 _5 friend intm operator/(const _8 a,const intm b){return intm(a)/b;}template<class _8>_7 _6 friend _8&operator+=(_8&a,const intm b){return a+=_8(b);}template<class _8>_7 _6 friend _8&operator-=(_8&a,const intm b){return a-=_8(b);}template<class _8>_7 _6 friend _8&operator*=(_8&a,const intm b){return a*=_8(b);}template<class _8>_7 _5 friend _8&operator/=(_8&a,const intm b){return a/=_8(b);}};}
#undef _7
#undef _6
#undef _5
#undef INTM_FAST_32
#undef INTM_FAST_64
#include <vector>
namespace cm{template<class _8>struct math_util{static class _1{private:std::vector<_8>_5;public:void require(int n){n++;int c=static_cast<int>(_5.size());if(c<n){_5.resize(n);if(c==0){_5[0]=1;c=1;}for(int i=c;i<n;i++){_5[i]=_5[i-1]*_8(i);}}}_8 operator()(int i)const{return _5[i];}_8 get(int i){require(i);return _5[i];}}fac;static class _2{private:std::vector<_8>_7;static constexpr int MOD=_8::MOD;public:void require(int n){n++;int c=static_cast<int>(_7.size());if(c<n){_7.resize(n);if(c==0){_7[0]=1;c=1;}if(c==1&&n>1){_7[1]=1;c=2;}for(int i=c;i<n;i++){_7[i]=_7[MOD%i]*(MOD-MOD/i);}}}_8 operator()(int i)const{return _7[i];}_8 get(int i){require(i);return _7[i];}}inv;static class _3{private:std::vector<_8>_6;public:void require(int n){inv.require(n);n++;int c=static_cast<int>(_6.size());if(c<n){_6.resize(n);if(c==0){_6[0]=1;c=1;}for(int i=c;i<n;i++){_6[i]=_6[i-1]*inv(i);}}}_8 operator()(int i)const{return _6[i];}_8 get(int i){require(i);return _6[i];}}ifac;static class _4{public:void require(int n){fac.require(n);ifac.require(n);}_8 operator()(int n,int m){if(m<0||m>n)return _8(0);return fac(n)*ifac(m)*ifac(n-m);}_8 get(int n,int m){if(m<0||m>n)return _8(0);return fac.get(n)*ifac.get(m)*ifac.get(n-m);}}binom;};template<class _8>typename math_util<_8>::_1 math_util<_8>::fac;template<class _8>typename math_util<_8>::_2 math_util<_8>::inv;template<class _8>typename math_util<_8>::_3 math_util<_8>::ifac;template<class _8>typename math_util<_8>::_4 math_util<_8>::binom;}
#include <cctype>
#include <cstdio>
namespace cm{template<class _9,size_t _3>class buffer_reader{protected:FILE*src;_9*const buff;_9*buff_end;_9*buff_pos;void _4(){buff_end=buff+fread(buff,sizeof(_9),_3,src);buff_pos=buff;if(buff_end==buff){*buff_end='\0';}}public:explicit buffer_reader(FILE*_1):src(_1),buff(new _9[_3]){_4();}buffer_reader(const buffer_reader&)=delete;buffer_reader(buffer_reader&&)=delete;buffer_reader&operator=(const buffer_reader&)=delete;buffer_reader&operator=(buffer_reader&&)=delete;_9 get()const{return*buff_pos;}_9 next(){_9 result=get();buff_pos++;if(buff_pos==buff_end)_4();return result;}~buffer_reader(){fclose(src);delete[]buff;}};
using optimal_reader=buffer_reader<char,1<<16>;
template<class _7>class scanner:protected _7{private:using _7::get;using _7::next;inline bool _6(char c){return c<=' ';}inline bool _2(char c){return c=='\n'||c=='\r';}int _5(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using _7::_7;char next_char(){while(_6(get()))next();return next();}char*next_token(char*s){while(_6(get()))next();while(!_6(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(_6(get()))next();while(!_2(get()))*s++=next();*s='\0';return s;}template<class _8>_8 next_integer(){_8 sign=_5();_8 result(0);while(isdigit(get()))result=result*_8(10)+_8(next()-'0');return sign*result;}int next_int(){return next_integer<int>();}long long next_long(){return next_integer<long long>();}double next_double(){int sign=_5();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
#include <utility>
#include <vector>
#define _3 inline __attribute__((always_inline))
namespace cm{template<class T>inline bool check_min(T&a,const T&b){return b<a?a=b,1:0;}template<class T>inline bool check_max(T&a,const T&b){return a<b?a=b,1:0;}struct once_t{bool _1=true;bool operator()(){return _1?(_1=false,true):false;}};}using cm::check_max;using cm::check_min;template<class A,class B>_3 std::pair<A,B>operator+(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first+rhs.first,lhs.second+rhs.second);}template<class A,class B>_3 std::pair<A,B>operator-(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first-rhs.first,lhs.second-rhs.second);}template<class A,class B>_3 std::pair<A,B>&operator+=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first+=rhs.first;lhs.second+=rhs.second;return lhs;}template<class A,class B>_3 std::pair<A,B>&operator-=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first-=rhs.first;lhs.second-=rhs.second;return lhs;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const std::vector<T>&b){a.insert(a.end(),b.begin(),b.end());return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const T&b){a.insert(a.end(),b);return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,T&&b){a.insert(a.end(),std::forward<T>(b));return a;}template<class T>std::vector<T>operator+(std::vector<T>a,const std::vector<T>&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&&b){a+=std::forward<T>(b);return a;}
#define M__AT_INIT(line, Pred) struct CM_INNER_ATINIT##line##_2 { CM_INNER_ATINIT##line## _2 () Pred } CM_INNER_ATINIT##line
#define M_AT_INIT(line, Pred) M__AT_INIT(line, Pred)
#define AT_INIT(Pred) M_AT_INIT(__LINE__, Pred)
#define M__AT_EXIT(line, Pred) struct CM_INNER_ATEXIT##line##_2 { ~CM_INNER_ATEXIT##line## _2 () Pred } CM_INNER_ATEXIT##line
#define M_AT_EXIT(line, Pred) M__AT_EXIT(line, Pred)
#define AT_EXIT(Pred) M_AT_EXIT(__LINE__, Pred)
#define CONSTRAINT(n, a, b) constexpr auto n = a;
#undef _3
#include <algorithm>
#include <numeric>
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int MOD = 1'000'000'007;
constexpr int N   = 1505;

using int_t = cm::intm<MOD>;
using mu    = cm::math_util<int_t>;

int n, m, k;

int_t  pa, pb, p;
int_t  p0[N], p1[N];
int_t  p_pr0[2][N], p_pr1[2][N], p_pr2[2][N];
int_t *pr0[N], *pr1[N], *pr2[N];

int main()
{
  n  = sc.next_int();
  m  = sc.next_int();
  pa = sc.next_int();
  pb = sc.next_int();
  k  = sc.next_int();
  p  = pa / pb;

  for (int i = 0; i <= std::min(m, k); i++)
    p0[i] = p.pow(i) * (1 - p).pow(k - i) * mu::binom.get(k, i);
  std::partial_sum(p0, p0 + m + 1, p1);

  for (int i = 0; i <= n; i++)
  {
    pr0[i] = p_pr0[i % 2];
    pr1[i] = p_pr1[i % 2];
    pr2[i] = p_pr2[i % 2];
  }

  auto make_pr = [](int i) {
    std::partial_sum(pr0[i], pr0[i] + m + 1, pr1[i]);
    for (int j = 0; j <= m; j++)
      pr2[i][j] = pr1[i][j] * p0[j];
    std::partial_sum(pr2[i], pr2[i] + m + 1, pr2[i]);
  };

  int_t psum = 1;
  pr0[0][m]  = 1;
  make_pr(0);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      int_t s_prob = p0[m - j] * p1[j - 1];
      // clang-format off
      pr0[i][j] = psum * s_prob
                - pr1[i - 1][m - j] * s_prob
                - pr2[i - 1][j - 1] * p0[m - j];
      // clan-format on
    }
    make_pr(i);
    psum = pr1[i][m];
  }

  std::cout << pr1[n][m] << std::endl;

  return 0;
}