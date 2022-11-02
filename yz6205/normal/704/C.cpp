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
#include <cstring>
#include <utility>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int MOD = 1'000'000'007;

int iaddmodl(int x, int y)
{
  return x + y >= MOD ? x + y - MOD : x + y;
}

constexpr int N = 100'005;

struct edge_t
{
  int v;
  int p, q;
  int i;

  edge_t() = default;
  edge_t(int v, int p, int q, int i) : v(v), p(p), q(q), i(i) {}
};

int  n, m, ans[2], deg[N], sgn[N];
int  f[2][2][2], g[2][2][2];
bool vis[N];

std::vector<edge_t> e[N];

void update(int res0, int res1)
{
  int ans0 = ans[0], ans1 = ans[1];
  ans[0] = (1ll * ans0 * res0 + 1ll * ans1 * res1) % MOD;
  ans[1] = (1ll * ans0 * res1 + 1ll * ans1 * res0) % MOD;
}

void solve(int s)
{
  int res[2] = {0, 0};
  memset(f, 0, sizeof(f));
  for (int x = 0; x < 2; x++)
    f[sgn[s] == -1 || deg[s] == 1 ? 0 : sgn[s] ^ x][x][x] = 1;

  for (int u = s, v, w = -1;; u = v)
  {
    memcpy(g, f, sizeof(g));
    memset(f, 0, sizeof(f));
    vis[u]   = true;
    edge_t e = (edge_t){0, 0, 0, -1};
    for (auto i : ::e[u])
    {
      if (i.i != w)
      {
        e = i;
        break;
      }
    }

    v = e.v;
    w = e.i;

    if (w == -1)
    {
      for (int z = 0; z < 2; z++)
        for (int x0 = 0; x0 < 2; x0++)
          for (int y = 0; y < 2; y++)
          {
            int zz  = z ^ (sgn[u] == -1 ? 0 : sgn[u] ^ y);
            res[zz] = iaddmodl(res[zz], g[z][x0][y]);
          }
      break;
    }
    if (v == s)
    {
      for (int z = 0; z < 2; z++)
        for (int x0 = 0; x0 < 2; x0++)
          for (int y = 0; y < 2; y++)
          {
            int zz  = z ^ ((y ^ e.p) | (x0 ^ e.q));
            res[zz] = iaddmodl(res[zz], g[z][x0][y]);
          }
      break;
    }
    for (int z = 0; z < 2; z++)
      for (int x0 = 0; x0 < 2; x0++)
        for (int y = 0; y < 2; y++)
          for (int x = 0; x < 2; x++)
          {
            int zz       = z ^ ((y ^ e.p) | (x ^ e.q));
            f[zz][x0][x] = iaddmodl(f[zz][x0][x], g[z][x0][y]);
          }
  }
  update(res[0], res[1]);
}

std::pair<int, int> parse_var(int x)
{
  return std::make_pair(x < 0, std::abs(x));
}

int main()
{
  m = sc.next_int();
  n = sc.next_int();

  ans[0] = 1;
  for (int u = 1; u <= n; u++)
    sgn[u] = -1;

  for (int i = 0; i < m; i++)
  {
    int k = sc.next_int();
    if (k == 1)
    {
      const auto [p, u] = parse_var(sc.next_int());
      deg[u]++;
      if (sgn[u] == -1)
      {
        sgn[u] = p;
      }
      else
      {
        vis[u] = true;
        if (sgn[u] == p)
          update(2, 0);
        else
          update(0, 2);
      }
    }
    else
    {
      const auto [p, u] = parse_var(sc.next_int());
      const auto [q, v] = parse_var(sc.next_int());
      deg[u]++;
      deg[v]++;
      e[u].emplace_back(v, p, q, i);
      e[v].emplace_back(u, q, p, i);
    }
  }

  for (int u = 1; u <= n; u++)
    if (!vis[u] && (deg[u] == 1 || sgn[u] != -1))
      solve(u);

  for (int u = 1; u <= n; u++)
    if (!vis[u])
      solve(u);

  printf("%d\n", ans[1]);

  return 0;
}