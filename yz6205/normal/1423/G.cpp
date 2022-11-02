#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
namespace cm{
class logger{public:logger(std::ostream&){}logger&set_ostream(std::ostream&){return*this;}logger&set_sep(const std::string&){return*this;}logger&assert_push_enable(){return*this;}logger&assert_push_disable(){return*this;}logger&assert_exit(){return*this;}logger&assert_noexit(){return*this;}logger&set_exit_code(int){return*this;}logger&endl(){return*this;}template<class...T>logger&log(T...){return*this;}template<class T>logger&hint(T...){return*this;}template<class...T>logger&operator()(T...){return*this;}template<class...T>logger&assert_(T...){return*this;}};
namespace impl{logger cm_logger(std::cout);}}
#define see(...)
#define asee(...)
#define cm_assert(...)
#include <cctype>
#include <cstdio>
namespace cm{template<class _9,size_t _3>class buffer_reader{protected:FILE*src;_9*const buff;_9*buff_end;_9*buff_pos;void _4(){buff_end=buff+fread(buff,sizeof(_9),_3,src);buff_pos=buff;if(buff_end==buff){*buff_end='\n';buff_end++;}}public:explicit buffer_reader(FILE*_1):src(_1),buff(new _9[_3]){_4();}buffer_reader(const buffer_reader&)=delete;buffer_reader(buffer_reader&&)=delete;buffer_reader&operator=(const buffer_reader&)=delete;buffer_reader&operator=(buffer_reader&&)=delete;_9 get()const{return*buff_pos;}_9 next(){_9 result=get();buff_pos++;if(buff_pos==buff_end)_4();return result;}~buffer_reader(){if(src!=stdin)fclose(src);delete[]buff;}};
using optimal_reader=buffer_reader<char,1<<16>;
template<class _7>class scanner:protected _7{private:using _7::get;using _7::next;inline bool _6(char c){return c<=' ';}inline bool _2(char c){return c=='\n'||c=='\r';}int _5(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using _7::_7;char next_char(){while(_6(get()))next();return next();}char*next_token(char*s){while(_6(get()))next();while(!_6(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(_6(get()))next();while(!_2(get()))*s++=next();*s='\0';return s;}template<class _8>_8 next_integer(){_8 sign=_5();_8 result(0);while(isdigit(get()))result=result*_8(10)+_8(next()-'0');return sign*result;}int next_int(){return next_integer<int>();}long long next_long(){return next_integer<long long>();}double next_double(){int sign=_5();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
#include <utility>
#include <vector>
#define _3 inline __attribute__((always_inline))
namespace cm{template<class T>inline bool check_min(T&a,const T&b){return b<a?a=b,1:0;}template<class T>inline bool check_max(T&a,const T&b){return a<b?a=b,1:0;}struct once_t{bool _1=true;bool operator()(){return _1?(_1=false,true):false;}};}using cm::check_max;using cm::check_min;template<class A,class B>_3 std::pair<A,B>operator+(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first+rhs.first,lhs.second+rhs.second);}template<class A,class B>_3 std::pair<A,B>operator-(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first-rhs.first,lhs.second-rhs.second);}template<class A,class B>_3 std::pair<A,B>&operator+=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first+=rhs.first;lhs.second+=rhs.second;return lhs;}template<class A,class B>_3 std::pair<A,B>&operator-=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first-=rhs.first;lhs.second-=rhs.second;return lhs;}template<class A,class B>_3 std::pair<A,B>operator*(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first*rhs.first,lhs.second*rhs.second);}template<class A,class B>_3 std::pair<A,B>operator/(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first/rhs.first,lhs.second/rhs.second);}template<class A,class B>_3 std::pair<A,B>&operator*=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first*=rhs.first;lhs.second*=rhs.second;return lhs;}template<class A,class B>_3 std::pair<A,B>&operator/=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first/=rhs.first;lhs.second/=rhs.second;return lhs;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const std::vector<T>&b){a.insert(a.end(),b.begin(),b.end());return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const T&b){a.insert(a.end(),b);return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,T&&b){a.insert(a.end(),std::forward<T>(b));return a;}template<class T>std::vector<T>operator+(std::vector<T>a,const std::vector<T>&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&&b){a+=std::forward<T>(b);return a;}
#define M__AT_INIT(line, Pred) struct CM_INNER_ATINIT##line##_2 { CM_INNER_ATINIT##line## _2 () Pred } CM_INNER_ATINIT##line
#define M_AT_INIT(line, Pred) M__AT_INIT(line, Pred)
#define AT_INIT(Pred) M_AT_INIT(__LINE__, Pred)
#define M__AT_EXIT(line, Pred) struct CM_INNER_ATEXIT##line##_2 { ~CM_INNER_ATEXIT##line## _2 () Pred } CM_INNER_ATEXIT##line
#define M_AT_EXIT(line, Pred) M__AT_EXIT(line, Pred)
#define AT_EXIT(Pred) M_AT_EXIT(__LINE__, Pred)
#define CONSTRAINT(n, a, b) constexpr auto n = a;
#undef _3
#include <set>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);
FILE                           *output = stdout;

CONSTRAINT(N, 100005, 10)

struct sgt_t
{
  struct node_t
  {
    uint64_t wei_add = 0;
    uint64_t cnt_add = 0;

    node_t() = default;

    void push_wei_add(uint64_t det)
    {
      wei_add += det;
    }

    void push_cnt_add(uint64_t det)
    {
      cnt_add += det;
    }

    void push_down(node_t &lhs, node_t &rhs)
    {
      if (wei_add != 0)
      {
        lhs.push_wei_add(wei_add);
        rhs.push_wei_add(wei_add);
        wei_add = 0;
      }
      if (cnt_add != 0)
      {
        lhs.push_cnt_add(cnt_add);
        rhs.push_cnt_add(cnt_add);
        cnt_add = 0;
      }
    }
  };

  node_t p[N * 4];

  void modify_wei_add(int u, int l, int r, int ml, int mr, uint64_t det)
  {
    if (ml <= l && r <= mr)
    {
      p[u].push_wei_add(det);
    }
    else
    {
      p[u].push_down(p[u + u], p[u + u + 1]);
      int m = l + (r - l) / 2;
      if (ml < m)
        modify_wei_add(u + u, l, m, ml, mr, det);
      if (mr > m)
        modify_wei_add(u + u + 1, m, r, ml, mr, det);
    }
  }

  void modify_cnt_add(int u, int l, int r, int ml, int mr, uint64_t det)
  {
    if (ml <= l && r <= mr)
    {
      p[u].push_cnt_add(det);
    }
    else
    {
      p[u].push_down(p[u + u], p[u + u + 1]);
      int m = l + (r - l) / 2;
      if (ml < m)
        modify_cnt_add(u + u, l, m, ml, mr, det);
      if (mr > m)
        modify_cnt_add(u + u + 1, m, r, ml, mr, det);
    }
  }

  node_t query(int u, int l, int r, int pos)
  {
    if (r - l == 1)
    {
      return p[u];
    }
    else
    {
      p[u].push_down(p[u + u], p[u + u + 1]);
      int m = l + (r - l) / 2;
      if (pos < m)
        return query(u + u, l, m, pos);
      else
        return query(u + u + 1, m, r, pos);
    }
  }
};

sgt_t sgt;

void update_lens(int len, uint64_t det)
{
  if (len > 0)
  {
    sgt.modify_wei_add(1, 1, N, 1, len + 1, det);
    sgt.modify_cnt_add(1, 1, N, 1, len + 1, -det * (N - len - 1));
  }
}

int n, m;

struct occur_t
{
  using inter_t = std::pair<int, int>;
  std::set<inter_t> inters;

  void init()
  {
    inters.emplace(-1, 0);
    inters.emplace(n, n + 1);
  }

  void erase_inter(int l, int r)
  {
    auto it = inters.find({l, r});
    cm_assert(it != inters.end());
    int prev_r = std::prev(it)->second;
    int next_l = std::next(it)->first;
    update_lens(l - prev_r, 1);
    update_lens(next_l - r, 1);
    update_lens(next_l - prev_r, -1);
    inters.erase(it);
  }

  void insert_inter(int l, int r)
  {
    auto it     = inters.lower_bound({l, r});
    int  prev_r = std::prev(it)->second;
    int  next_l = it->first;
    update_lens(next_l - prev_r, 1);
    update_lens(l - prev_r, -1);
    update_lens(next_l - r, -1);
    inters.emplace_hint(it, l, r);
  }
};

occur_t occur[N];

struct inter_t
{
  int l, r;
  int w;

  bool operator<(const inter_t &rhs) const
  {
    return l < rhs.l;
  }
};

std::set<inter_t> inters;

void cover_inter(int l, int r, int w)
{
  std::vector<inter_t> add_list{{l, r, w}};

  auto it = inters.lower_bound({l, r, w});
  if (it != inters.begin() && std::prev(it)->r > l)
    it--;
  while (it != inters.end() && it->l < r)
  {
    int il = it->l, ir = it->r, iw = it->w;
    // see("erase", iw, il, ir);
    occur[iw].erase_inter(il, ir);
    if (il < l)
      add_list.push_back({il, l, iw});
    if (ir > r)
      add_list.push_back({r, ir, iw});
    it = inters.erase(it);
  }
  for (const auto i : add_list)
  {
    // see("insert", w, l, r);
    int l = i.l, r = i.r, w = i.w;
    occur[w].insert_inter(l, r);
    inters.insert({l, r, w});
  }
}

int main()
{
  n = sc.next_int();
  m = sc.next_int();

  for (int i = 0; i < N; i++)
    occur[i].init();

  for (int i = 0; i < n; i++)
  {
    int x = sc.next_int();
    cover_inter(i, i + 1, x);
  }
  for (int i = 0; i < m; i++)
  {
    int opt = sc.next_int();
    if (opt == 1)
    {
      int l = sc.next_int() - 1;
      int r = sc.next_int();
      int x = sc.next_int();
      cover_inter(l, r, x);
    }
    else
    {
      int      k        = sc.next_int();
      auto     ans_node = sgt.query(1, 1, N, k);
      uint64_t ans      = ans_node.wei_add * (N - k) + ans_node.cnt_add;
      fprintf(output, "%llu\n", (unsigned long long)(ans));
    }
  }
  return 0;
}