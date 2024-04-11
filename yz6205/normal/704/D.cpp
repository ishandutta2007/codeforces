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
#include <cstring>
#include <queue>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int inf = 1e9;
constexpr int N   = 100005;
constexpr int V   = N * 2;
constexpr int E   = N * 40;

int  n1, n2, m, q, k1, k2;
int  a1[N], a2[N], tb1[N], tb2[N];
int  cnt1[N], cnt2[N], lim1[N], lim2[N];
int  dis[V], cur[V], deg[V];
int  s, t, ss, tt, ans;
bool flag, vis[V];

struct list_t
{
  int tot, fst[V], nxt[E], to[E], val[E], flw[E];

  list_t()
  {
    memset(fst, -1, sizeof(fst));
  }
  inline void insert(int u, int v, int w)
  {
    nxt[tot] = fst[u];
    to[tot]  = v;
    val[tot] = w;
    fst[u]   = tot++;
  }
  inline void link(int u, int v, int w)
  {
    insert(u, v, w);
    insert(v, u, 0);
  }
} e;

bool bfs()
{
  memset(dis, 60, sizeof(dis));
  memcpy(cur, e.fst, sizeof(cur));
  dis[s] = 0;
  std::queue<int> que;
  for (que.push(s); !que.empty(); que.pop())
  {
    int u = que.front();
    for (int i = e.fst[u]; ~i; i = e.nxt[i])
    {
      int v = e.to[i], w = e.val[i], f = e.flw[i];
      if (dis[v] > dis[u] + 1 && w > f)
      {
        dis[v] = dis[u] + 1;
        if (v == t)
        {
          return true;
        }
        que.push(v);
      }
    }
  }
  return false;
}

int dinic(int u, int _f)
{
  if (u == t)
  {
    return _f;
  }
  int lef = _f;
  vis[u]  = true;
  for (int &i = cur[u]; ~i; i = e.nxt[i])
  {
    int v = e.to[i], w = e.val[i], f = e.flw[i];
    if (dis[v] == dis[u] + 1 && w > f && !vis[v])
    {
      int def = dinic(v, std::min(lef, w - f));
      if (def == 0)
      {
        dis[v] = -1;
        continue;
      }
      lef -= def;
      e.flw[i] += def;
      e.flw[i ^ 1] -= def;
      if (lef == 0)
      {
        break;
      }
    }
  }
  vis[u] = false;
  return _f - lef;
}

int main()
{
  m  = sc.next_int();
  q  = sc.next_int();
  k1 = sc.next_int();
  k2 = sc.next_int();
  if (k1 > k2)
  {
    std::swap(k1, k2);
    flag = true;
  }
  for (int i = 0; i < m; i++)
  {
    a1[i]     = sc.next_int();
    tb1[n1++] = a1[i];
    a2[i]     = sc.next_int();
    tb2[n2++] = a2[i];
  }

  std::sort(tb1, tb1 + n1);
  n1 = std::unique(tb1, tb1 + n1) - tb1;
  std::sort(tb2, tb2 + n2);
  n2 = std::unique(tb2, tb2 + n2) - tb2;
  s  = 0;
  t  = n1 + n2 + 3;
  ss = n1 + n2 + 1;
  tt = n1 + n2 + 2;
  for (int i = 0; i < m; i++)
  {
    a1[i] = std::lower_bound(tb1, tb1 + n1, a1[i]) - tb1;
    a2[i] = std::lower_bound(tb2, tb2 + n2, a2[i]) - tb2;
    cnt1[a1[i]]++;
    cnt2[a2[i]]++;
    int u = a1[i] + 1, v = n1 + a2[i] + 1;
    e.link(u, v, 1);
  }

  memset(lim1, 60, n1 * 4);
  memset(lim2, 60, n2 * 4);
  for (int i = 0; i < q; i++)
  {
    int opt = sc.next_int(), x = sc.next_int(), y = sc.next_int(), u;
    if (opt == 1)
    {
      u = std::lower_bound(tb1, tb1 + n1, x) - tb1;
      if (tb1[u] == x)
        lim1[u] = std::min(lim1[u], y);
    }
    else
    {
      u = std::lower_bound(tb2, tb2 + n2, x) - tb2;
      if (tb2[u] == x)
        lim2[u] = std::min(lim2[u], y);
    }
  }
  for (int i = 0; i < n1; i++)
  {
    int u = i + 1;
    int l = std::max(0, (cnt1[i] - lim1[i] + 1) / 2);
    int r = (cnt1[i] + lim1[i]) / 2;
    if (l > r)
    {
      printf("-1\n");
      return 0;
    }
    e.link(ss, u, r - l);
    deg[ss] -= l;
    deg[u] += l;
  }
  for (int i = 0; i < n2; i++)
  {
    int u = n1 + i + 1;
    int l = std::max(0, (cnt2[i] - lim2[i] + 1) / 2);
    int r = (cnt2[i] + lim2[i]) / 2;
    if (l > r)
    {
      printf("-1\n");
      return 0;
    }
    e.link(u, tt, r - l);
    deg[u] -= l;
    deg[tt] += l;
  }

  for (int u = 1; u <= tt; u++)
  {
    if (deg[u] > 0)
      e.link(s, u, deg[u]);
    if (deg[u] < 0)
      e.link(u, t, -deg[u]);
  }

  e.link(tt, ss, inf);

  while (bfs())
    dinic(s, inf);

  s                = ss;
  t                = tt;
  ans              = e.flw[e.tot - 2];
  e.val[e.tot - 1] = e.flw[e.tot - 1] = 0;
  e.val[e.tot - 2] = e.flw[e.tot - 2] = 0;

  while (bfs())
    ans += dinic(s, inf);

  printf("%lld\n", 1ll * k1 * ans + 1ll * k2 * (m - ans));
  for (int i = 0; i < m; i++)
    putchar(e.flw[i * 2] != flag ? 'r' : 'b');

  return 0;
}