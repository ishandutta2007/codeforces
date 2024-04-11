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
#include <cctype>
#include <cstdio>
namespace cm{template<class _9,size_t _3>class buffer_reader{protected:FILE*src;_9*const buff;_9*buff_end;_9*buff_pos;void _4(){buff_end=buff+fread(buff,sizeof(_9),_3,src);buff_pos=buff;if(buff_end==buff){*buff_end='\0';}}public:buffer_reader(FILE*_1):src(_1),buff(new _9[_3]){_4();}buffer_reader(const buffer_reader&)=delete;buffer_reader(buffer_reader&&)=delete;buffer_reader&operator=(const buffer_reader&)=delete;buffer_reader&operator=(buffer_reader&&)=delete;_9 get()const{return*buff_pos;}_9 next(){_9 result=get();buff_pos++;if(buff_pos==buff_end)_4();return result;}~buffer_reader(){fclose(src);delete[]buff;}};
using optimal_reader=buffer_reader<char,1<<16>;
template<class _7>class scanner:protected _7{private:using _7::get;using _7::next;inline bool _5(char c){return c<=' ';}inline bool _2(char c){return c=='\n'||c=='\r';}int _6(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using _7::_7;char next_char(){while(_5(get()))next();return next();}char*next_token(char*s){while(_5(get()))next();while(!_5(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(_5(get()))next();while(!_2(get()))*s++=next();*s='\0';return s;}int next_int(){int sign=_6();int result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_long(){int sign=_6();long long result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}template<class _8>_8 next_integer(){_8 sign=_6();_8 result(0);while(isdigit(get()))result=result*_8(10)+_8(next()-'0');return sign*result;}double next_double(){int sign=_6();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
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
#include <bitset>
#include <map>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int N = 1005;

int  m, n, p[N], id[N];
bool ok[N], vis[N];

std::vector<int> e[8][N];

struct point_t
{
  int x, y;
} a[N], b[N];

bool straight(point_t u, point_t v, point_t w)
{
  if (1ll * (v.x - u.x) * (w.y - v.y) != 1ll * (v.y - u.y) * (w.x - v.x))
    return false;
  if (!(std::min(u.x, w.x) <= v.x && v.x <= std::max(u.x, w.x)))
    return false;
  if (!(std::min(u.y, w.y) <= v.y && v.y <= std::max(u.y, w.y)))
    return false;
  return true;
}

void dfs(int &k, int i)
{
  if (k >= m)
    return;
  int _p = p[k];
  for (auto j : e[_p][i])
  {
    if (!vis[j])
    {
      dfs(++k, j);
      if (k >= m)
        return;
    }
  }
  id[_p] = i;
  vis[i] = true;
}

int main()
{
  m = sc.next_int();
  n = sc.next_int();
  for (int i = 0; i < m; i++)
  {
    a[i].x = sc.next_int();
    a[i].y = sc.next_int();
  }
  for (int i = 0; i < n; i++)
  {
    b[i].x = sc.next_int();
    b[i].y = sc.next_int();
  }

  for (int k = 0; k < m; k++)
  {
    p[k] = k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        if (straight(a[k], b[j], b[i]))
        {
          e[k][i].push_back(j);
          if ((int)e[k][i].size() >= m)
            break;
        }
      }
  }

  do
  {
    for (int i = 0; i < n; i++)
    {
      if (ok[i])
        continue;
      int k = 0;
      dfs(k, i);
      ok[i] = k < m;
      for (k = 0; k < m; k++)
        vis[id[k]] = false;
    }
  } while (std::next_permutation(p, p + m));

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += ok[i];
  printf("%d\n", ans);

  return 0;
}