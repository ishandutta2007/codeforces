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
#include <set>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

const long double eps  = 1e-12L;
const long double eeps = 1e-7L;
const long double inf  = 1e18;

constexpr int N = 200005;
constexpr int V = 10'000'005;

long double _;

struct segment_t
{
  long double s, t, l, c;
  int         i;

  segment_t() = default;
  segment_t(long double s, long double t, long double l, long double c, int i) :
      s(s), t(t), l(l), c(c), i(i)
  {
  }
  segment_t(
      long double s, long double t, long double l, long double c, size_t i) :
      s(s), t(t), l(l), c(c), i(static_cast<int>(i))
  {
  }

  [[nodiscard]] long double r() const
  {
    return l + (_ - s) * c;
  }
};

bool operator<(const segment_t &i, const segment_t &j)
{
  return std::abs(i.r() - j.r()) < eps ? i.i < j.i : i.r() < j.r();
}

long double ans;

int n, m;
int ft[N], dep[N], size[N];
int hs[N], top[N], tms, dfn[N], opt[V];

std::vector<std::pair<long double, int>> b;

std::vector<int>       e[N];
std::vector<segment_t> a;
std::set<segment_t>    f;

void dfs1(int u, int fa)
{
  ft[u]   = fa;
  dep[u]  = dep[fa] + 1;
  size[u] = 1;
  for (auto v : e[u])
  {
    if (v == fa)
      continue;
    dfs1(v, u);
    size[u] += size[v];
    if (size[hs[u]] < size[v])
      hs[u] = v;
  }
}
void dfs2(int u, int tp)
{
  top[u] = tp;
  dfn[u] = ++tms;
  if (hs[u] > 0)
    dfs2(hs[u], tp);
  for (auto v : e[u])
  {
    if (v == ft[u] || v == hs[u])
      continue;
    tms++;
    dfs2(v, v);
  }
}

int find_lca(int u, int v)
{
  while (top[u] != top[v])
  {
    if (dep[top[u]] > dep[top[v]])
      u = ft[top[u]];
    else
      v = ft[top[v]];
  }
  return dep[u] < dep[v] ? u : v;
}

int distance(int u, int v)
{
  return dep[u] + dep[v] - dep[find_lca(u, v)] * 2;
}

void update(segment_t i, segment_t j)
{
  if (i.i == -1 || j.i == -1)
  {
    return;
  }
  long double d = j.r() - i.r();
  long double c = i.c - j.c;
  if (std::abs(c) < eps)
  {
    if (std::abs(d) < eps)
    {
      ans = std::min(ans, _);
    }
    return;
  }
  long double t = _ + d / c;
  if (t < i.s - eps || t < j.s - eps)
  {
    return;
  }
  if (t > i.t + eps || t > j.t + eps)
  {
    return;
  }
  ans = std::min(ans, t);
}

int main()
{
  n = sc.next_int();
  m = sc.next_int();
  for (int i = 1; i < n; i++)
  {
    int u = sc.next_int();
    int v = sc.next_int();
    e[u].push_back(v);
    e[v].push_back(u);
  }

  dfs1(1, 0);
  dfs2(1, 1);

  for (int i = 0; i < m; i++)
  {
    long double s = sc.next_int(), c = sc.next_int(), t, _s, _t;
    int         u = sc.next_int(), v = sc.next_int(), _u, _v;

    t = s + distance(u, v) / c;
    while (top[u] != top[v])
    {
      _u = ft[top[u]];
      _v = ft[top[v]];
      if (dep[_u] > dep[_v])
      {
        _s = s + (dep[u] - dep[_u]) / c;
        a.push_back((segment_t){s, _s, dfn[u] + 0.0L, -c, a.size()});
        u = _u;
        s = _s;
      }
      else
      {
        _t = t - (dep[v] - dep[_v]) / c;
        a.push_back((segment_t){_t, t, dfn[top[v]] - 1.0L, c, a.size()});
        v = _v;
        t = _t;
      }
    }
    if (dep[u] > dep[v])
      a.push_back((segment_t){s, t, dfn[u] + 0.0L, -c, a.size()});
    else
      a.push_back((segment_t){s, t, dfn[u] + 0.0L, c, a.size()});
  }

  ans = inf;
  f.insert((segment_t){0.0L, 0.0L, -inf, 0.0L, -1});
  f.insert((segment_t){0.0L, 0.0L, +inf, 0.0L, -1});
  for (int i = 0; i < (int)a.size(); i++)
  {
    a[i].t += eps * 9;
    b.emplace_back(a[i].s, i);
    b.emplace_back(a[i].t, i);
  }

  std::sort(b.begin(), b.end());
  for (auto p : b)
  {
    int i = p.second;
    _     = p.first;
    opt[i]++;
    if (_ > ans - eeps)
    {
      printf("%.6f\n", (double)ans);
      return 0;
    }
    if (opt[i] == 1)
    {
      auto it = f.insert(a[i]).first;
      auto l  = it;
      update(a[i], *(--l));
      auto r = it;
      update(a[i], *(++r));
    }
    else
    {
      auto r = f.erase(f.lower_bound(a[i]));
      auto l = r;
      update(*(--l), *r);
    }
  }

  if (ans > inf / 2)
  {
    puts("-1");
    return 0;
  }

  printf("%.6f\n", static_cast<double>(ans));

  return 0;
}