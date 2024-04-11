#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
namespace cm{class logger{private:std::ostream*_1c;std::string _1b="\x2c\x20";bool _15=true;int _12=0;std::string _1="\033[0;31m";std::string _2="\033[0;32m";std::string _16="\033[0;33m";std::string _3="\033[0;34m";std::string _4="\033[0;35m";std::string _5="\033[0;36m";std::string _6="\033[1;31m";std::string _7="\033[1;32m";std::string _13="\033[1;33m";std::string _8="\033[1;34m";std::string _9="\033[1;35m";std::string _a="\033[1;36m";std::string _17="\033[0m";std::string _b(std::string _1d){if(_1d=="red")return _1;if(_1d=="green")return _2;if(_1d=="yellow")return _16;if(_1d=="blue")return _3;if(_1d=="magenta")return _4;if(_1d=="cyan")return _5;if(_1d=="red bold")return _6;if(_1d=="green bold")return _7;if(_1d=="yellow bold")return _13;if(_1d=="blue bold")return _8;if(_1d=="magenta bold")return _9;if(_1d=="cyan bold")return _a;if(_1d=="reset")return _17;return "";}public:logger(std::ostream&_1c):_1c(&_1c){}logger&set_ostream(std::ostream&_1c){this->_1c=&_1c;return*this;}logger&set_sep(const std::string&_1b){this->_1b=_1b;return*this;}logger&assert_exit(){_15=true;return*this;}logger&assert_noexit(){_15=false;return*this;}logger&set_exit_code(int _c){_12=_c;return*this;}logger&endl(){*_1c<<std::endl;return*this;}logger&log(){return*this;}template<class Ta,class Tb,class...Tc>logger&log(const Ta&a,const Tb&b,Tc...c){return log(a).log(_1b).log(b,c...);}template<class Ta,typename=decltype(std::cout<<std::declval<Ta>())>logger&log(const Ta&a){*_1c<<a;return*this;}template<class T,typename=decltype(std::declval<T>().begin()),typename=decltype(std::declval<T>().end()),typename=typename std::enable_if<!std::is_base_of<std::string,typename std::decay<T>::type>::value>::type,typename value_type=typename T::value_type>logger&log(const T&_18){log("{");for(auto it=_18.begin();it!=_18.end();++it){if(it!=_18.begin())log(_1b);log(*it);}log("}");return*this;}template<class Ta,class Tb>logger&log(const std::pair<Ta,Tb>&x){return log("(").log(x.first,x.second).log(")");}
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
#include <type_traits>
namespace lambda{template<int k>struct __get_kth{template<class Ta,class...Tb>static auto call(Ta,Tb...b){return __get_kth<k-1>::call(b...);}};template<>struct __get_kth<0>{template<class Ta,class...Tb>static auto call(Ta a,Tb...){return a;}};struct lambda_base{};template<class T>struct lambda_constant:public lambda_base{const T&a;lambda_constant(const T&a):a(a){}template<class...>const T&operator()(...)const{return a;}};template<class T>struct lambda_reference:public lambda_base{T&a;lambda_reference(T&a):a(a){}template<class...>T&operator()(...)const{return a;}};
#define __lambda_define_bop(op, op_name) template <class Ta, class Tb> struct lambda_bop_##op_name : public lambda_base { static_assert(std::is_base_of<lambda_base, Ta>::value, ""); static_assert(std::is_base_of<lambda_base, Tb>::value, ""); const Ta &a; const Tb &b; lambda_bop_##op_name(const Ta &a, const Tb &b) : a(a), b(b) {} template <class... T> auto operator()(T... p) const -> decltype(a(p...) op b(p...)) { return a(p...) op b(p...); } }; template <class Ta, class Tb, typename = typename std::enable_if< std::is_base_of<lambda_base, Ta>::value || std::is_base_of<lambda_base, Tb>::value>::type> auto operator op(const Ta &a, const Tb &b) { if constexpr (!std::is_base_of<lambda_base, Ta>::value) return lambda_bop_##op_name<lambda_constant<Ta>, Tb>( lambda_constant<Ta>(a), b); else if constexpr (!std::is_base_of<lambda_base, Tb>::value) return lambda_bop_##op_name<Ta, lambda_constant<Tb>>( a, lambda_constant<Tb>(b)); else return lambda_bop_##op_name<Ta, Tb>(a, b); } template <class Ta, class Tb, typename = typename std::enable_if< !std::is_base_of<lambda_base, Ta>::value && std::is_base_of<lambda_base, Tb>::value>::type> auto operator op(Ta &a, const Tb &b) { return lambda_bop_##op_name<lambda_reference<Ta>, Tb>( lambda_reference<Ta>(a), b); } template <class Ta, class Tb, typename = typename std::enable_if< std::is_base_of<lambda_base, Ta>::value && !std::is_base_of<lambda_base, Tb>::value>::type> auto operator op(const Ta &a, Tb &b) { return lambda_bop_##op_name<Ta, lambda_reference<Tb>>( a, lambda_reference<Tb>(b)); }
__lambda_define_bop(+,add);__lambda_define_bop(-,sub);__lambda_define_bop(*,mul);__lambda_define_bop(/,div);__lambda_define_bop(<,le);__lambda_define_bop(<=,leq);__lambda_define_bop(>,ge);__lambda_define_bop(>=,geq);__lambda_define_bop(==,eq);__lambda_define_bop(!=,neq);__lambda_define_bop(<<,lsh);__lambda_define_bop(>>,rsh);__lambda_define_bop(&&,and);__lambda_define_bop(||,or);__lambda_define_bop(&,land);__lambda_define_bop(|,lor);__lambda_define_bop(^,lxor);
#define __lambda_define_sop(op, op_name) template <class Ta> struct lambda_sop_##op_name : public lambda_base { static_assert(std::is_base_of<lambda_base, Ta>::value, ""); const Ta &a; lambda_sop_##op_name(const Ta &a) : a(a) {} template <class... T> auto operator()(T... p) const -> decltype(op a(p...)) { return op a(p...); } }; template <class Ta, typename = typename std::enable_if< std::is_base_of<lambda_base, Ta>::value>::type> auto operator op(const Ta &a) { return lambda_sop_##op_name<Ta>(a); }
__lambda_define_sop(!,not);__lambda_define_sop(~,lnot);__lambda_define_sop(+,pos);__lambda_define_sop(-,neg);template<int k>struct lambda_placeholder:public lambda_base{template<class...T>auto operator()(T...p)const{return __get_kth<k>::call(p...);}};namespace placehoders{lambda_placeholder<0>_0;lambda_placeholder<1>_1;lambda_placeholder<2>_2;lambda_placeholder<3>_3;lambda_placeholder<4>_4;lambda_placeholder<5>_5;}}
#include <cctype>
#include <cstdio>
namespace cm{template<class _9,size_t _3>class buffer_reader{protected:FILE*src;_9*const buff;_9*buff_end;_9*buff_pos;void _4(){buff_end=buff+fread(buff,sizeof(_9),_3,src);buff_pos=buff;if(buff_end==buff){*buff_end='\0';}}public:buffer_reader(FILE*_1):src(_1),buff(new _9[_3]){_4();}buffer_reader(const buffer_reader&)=delete;buffer_reader(buffer_reader&&)=delete;buffer_reader&operator=(const buffer_reader&)=delete;buffer_reader&operator=(buffer_reader&&)=delete;_9 get()const{return*buff_pos;}_9 next(){_9 result=get();buff_pos++;if(buff_pos==buff_end)_4();return result;}~buffer_reader(){fclose(src);delete[]buff;}};
using optimal_reader=buffer_reader<char,1<<16>;
template<class _7>class scanner:protected _7{private:using _7::get;using _7::next;inline bool _5(char c){return c<=' ';}inline bool _2(char c){return c=='\n'||c=='\r';}int _6(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using _7::_7;char next_char(){while(_5(get()))next();return next();}char*next_token(char*s){while(_5(get()))next();while(!_5(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(_5(get()))next();while(!_2(get()))*s++=next();*s='\0';return s;}int next_int(){int sign=_6();int result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_long(){int sign=_6();long long result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}template<class _8>_8 next_integer(){_8 sign=_6();_8 result(0);while(isdigit(get()))result=result*_8(10)+_8(next()-'0');return sign*result;}double next_double(){int sign=_6();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
#include <iterator>
#include <utility>
namespace cm{namespace string{template<uint64_t seed>class hash_u64{
#if __cplusplus >= 201103L
static_assert(seed%2==1,"hash_u64 seed show be odd");
#endif
public:const size_t size;protected:uint64_t*const base;uint64_t*const base_inv;uint64_t*const sum;static uint64_t _1(uint64_t a){uint64_t result=1;for(int i=0;i<63;i++){result*=a;a*=a;}return result;}public:template<class InputIterator>hash_u64(InputIterator begin,InputIterator end):size(static_cast<size_t>(std::distance(begin,end))),base(new uint64_t[size+1]),base_inv(new uint64_t[size+1]),sum(new uint64_t[size+1]){base[0]=1;base_inv[0]=1;sum[0]=0;uint64_t seed_inv=_1(seed);for(size_t i=0;i<size;i++){base[i+1]=base[i]*seed;base_inv[i+1]=base_inv[i]*seed_inv;sum[i+1]=sum[i]+base[i]*static_cast<uint64_t>(*begin++);}}uint64_t get_hash(size_t l,size_t r)const{return base_inv[l]*(sum[r]-sum[l]);}std::pair<size_t,uint64_t>get_hash_pair(size_t l,size_t r)const{return std::make_pair(r-l,get_hash(l,r));}std::pair<size_t,uint64_t>cat(const std::pair<size_t,uint64_t>&hpa,const std::pair<size_t,uint64_t>&hpb){return std::make_pair(hpa.first+hpb.first,hpa.second+base[hpa.first]*hpb.second);}~hash_u64(){delete[]base;delete[]base_inv;delete[]sum;}};template<typename IntType>class hash_mod{public:const size_t size;protected:IntType*const base;IntType*const base_inv;IntType*const sum;public:template<class InputIterator>hash_mod(IntType seed,InputIterator begin,InputIterator end):size(static_cast<size_t>(std::distance(begin,end))),base(new IntType[size+1]),base_inv(new IntType[size+1]),sum(new IntType[size+1]){base[0]=1;base_inv[0]=1;sum[0]=0;IntType seed_inv=1/seed;for(size_t i=0;i<size;i++){base[i+1]=base[i]*seed;base_inv[i+1]=base_inv[i]*seed_inv;sum[i+1]=sum[i]+base[i]*static_cast<IntType>(*begin++);}}IntType get_hash(size_t l,size_t r)const{return base_inv[l]*(sum[r]-sum[l]);}std::pair<size_t,IntType>get_hash_pair(size_t l,size_t r)const{return std::make_pair(r-l,get_hash(l,r));}std::pair<size_t,IntType>cat(const std::pair<size_t,IntType>&hpa,const std::pair<size_t,IntType>&hpb){return std::make_pair(hpa.first+hpb.first,hpa.second+base[hpa.first]*hpb.second);}~hash_mod(){delete[]base;delete[]base_inv;delete[]sum;}};template<class Hasher>size_t lcp(const Hasher&a,size_t al,const Hasher&b,size_t bl){size_t l=0;size_t r=std::min(a.size-al,b.size-bl);for(size_t i=1;i<4&&i<=r;i++)if(a.get_hash(al,al+i)!=b.get_hash(bl,bl+i))return i-1;while(l<r){size_t mid=(l+r+1)/2;if(a.get_hash(al,al+mid)==b.get_hash(bl,bl+mid))l=mid;else r=mid-1;}return l;}template<class Hasher>size_t lcs(const Hasher&a,size_t al,const Hasher&b,size_t bl){size_t l=0;size_t r=std::min(al,bl);for(size_t i=1;i<4&&i<=r;i++)if(a.get_hash(al-i,al)!=b.get_hash(bl-i,bl))return i-1;while(l<r){size_t mid=(l+r+1)/2;if(a.get_hash(al-mid,al)==b.get_hash(bl-mid,bl))l=mid;else r=mid-1;}return l;}}}
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
#include <cstring>
#include <string_view>
#include <type_traits>

template <typename BidirectionalIterator, typename Predicate>
bool is_palindrome(BidirectionalIterator begin,
                   BidirectionalIterator end,
                   Predicate             p)
{
  if (begin == end)
  {
    return true;
  }

  --end;
  while (begin != end)
  {
    if (!p(*begin, *end))
    {
      return false;
    }
    ++begin;
    if (begin == end)
    {
      break;
    }
    --end;
  }
  return true;
}
template <typename BidirectionalIterator>
bool is_palindrome(BidirectionalIterator begin, BidirectionalIterator end)
{
  using namespace lambda::placehoders;
  return is_palindrome(begin, end, _0 == _1);
}

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int MOD = 1'000'000'007;
constexpr int N   = 2005;
using int_t       = cm::intm<MOD>;

char s[2][N], t[N];
int  n, k;

int_t cnt[N][2], cur[N][2];

int main()
{
  n = static_cast<int>(sc.next_token(s[0]) - s[0]);
  n = static_cast<int>(sc.next_token(s[1]) - s[1]);
  k = static_cast<int>(sc.next_token(t) - t);
  cm::string::hash_u64<2333333> hs[2]{{s[0], s[0] + n}, {s[1], s[1] + n}};

  if (k == 1)
  {
    int_t ans = 0;
    for (int i = 0; i < n; i++)
      ans += (s[0][i] == t[0]) + (s[1][i] == t[0]);
    std::cout << ans << std::endl;
  }
  else if (k == 2)
  {
    int_t ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[0][i] == t[0] && s[1][i] == t[1])
        ans += 1;
      if (s[1][i] == t[0] && s[0][i] == t[1])
        ans += 1;
    }
    for (int i = 0; i + 1 < n; i++)
    {
      if (s[0][i] == t[0] && s[0][i + 1] == t[1])
        ans += 1;
      if (s[0][i] == t[1] && s[0][i + 1] == t[0])
        ans += 1;
      if (s[1][i] == t[0] && s[1][i + 1] == t[1])
        ans += 1;
      if (s[1][i] == t[1] && s[1][i + 1] == t[0])
        ans += 1;
    }
    std::cout << ans << std::endl;
  }
  else
  {

    auto calc = [&]() -> int_t {
      std::string_view              vt(t, k);
      cm::string::hash_u64<2333333> ht(vt.begin(), vt.end());
      cm::string::hash_u64<2333333> htr(vt.rbegin(), vt.rend());

      int_t ans = 0;
      memset(cnt, 0, sizeof(cnt));

      for (int i = 0; i <= n; i++)
      {
        memset(cur, 0, sizeof(cur));
        cur[0][0] += 1;
        cur[0][1] += 1;
        for (int j = 2; j <= i && j * 2 <= k; j++)
        {
          if (ht.get_hash(j, j + j) == hs[0].get_hash(i - j, i) &&
              htr.get_hash(k - j, k) == hs[1].get_hash(i - j, i))
            cur[j * 2][0] += 1;
          if (ht.get_hash(j, j + j) == hs[1].get_hash(i - j, i) &&
              htr.get_hash(k - j, k) == hs[0].get_hash(i - j, i))
            cur[j * 2][1] += 1;
        }
        for (int j = 0; j + 1 <= k && j <= 2 * (i - 1); j++)
        {
          if (s[0][i - 1] == t[j])
            cur[j + 1][0] += cnt[j][0];
          if (s[1][i - 1] == t[j])
            cur[j + 1][1] += cnt[j][1];
        }
        for (int j = 0; j + 2 <= k && j <= 2 * (i - 1); j++)
        {
          if (s[0][i - 1] == t[j] && s[1][i - 1] == t[j + 1])
            cur[j + 2][1] += cnt[j][0];
          if (s[1][i - 1] == t[j] && s[0][i - 1] == t[j + 1])
            cur[j + 2][0] += cnt[j][1];
        }

        ans += cur[k][0];
        ans += cur[k][1];
        for (int j = 2; i + j <= n && j * 2 <= k; j++)
        {
          if (ht.get_hash(k - j - j, k - j) == hs[0].get_hash(i, i + j) &&
              htr.get_hash(0, j) == hs[1].get_hash(i, i + j))
            ans += cur[k - j * 2][0];
          if (ht.get_hash(k - j - j, k - j) == hs[1].get_hash(i, i + j) &&
              htr.get_hash(0, j) == hs[0].get_hash(i, i + j))
            ans += cur[k - j * 2][1];
        }

        see(i, ans);
        memcpy(cnt, cur, sizeof(cnt));
      }

      return ans;
    };

    auto calc_same = [&]() -> int_t {
      if (k % 2 == 1)
        return 0;

      std::string_view              vt(t, k);
      cm::string::hash_u64<2333333> ht(vt.begin(), vt.end());
      cm::string::hash_u64<2333333> htr(vt.rbegin(), vt.rend());

      int_t ans = 0;
      for (int i = 0; i + k / 2 <= n; i++)
      {
        int j = k / 2;
        if (ht.get_hash(k - j - j, k - j) == hs[0].get_hash(i, i + j) &&
            htr.get_hash(0, j) == hs[1].get_hash(i, i + j))
          ans += 1;
        if (ht.get_hash(k - j - j, k - j) == hs[1].get_hash(i, i + j) &&
            htr.get_hash(0, j) == hs[0].get_hash(i, i + j))
          ans += 1;
      }
      for (int i = k / 2; i <= n; i++)
      {
        int j = k / 2;
        if (ht.get_hash(j, j + j) == hs[0].get_hash(i - j, i) &&
            htr.get_hash(k - j, k) == hs[1].get_hash(i - j, i))
          ans += 1;
        if (ht.get_hash(j, j + j) == hs[1].get_hash(i - j, i) &&
            htr.get_hash(k - j, k) == hs[0].get_hash(i - j, i))
          ans += 1;
      }
      return ans;
    };

    int_t ans = calc();
    std::reverse(t, t + k);
    ans += calc();
    ans -= calc_same();
    std::cout << ans << std::endl;
  }

  return 0;
}