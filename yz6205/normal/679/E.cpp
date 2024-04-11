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
#include <array>
#include <limits>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int64_t inf = std::numeric_limits<int64_t>::max() / 2;

auto pow42 = []() {
  constexpr int LEN = 11;

  std::array<int64_t, LEN> res;
  res[0] = 1;
  for (int i = 0; i + 1 < LEN; i++)
    res[i + 1] = res[i] * 42;
  return res;
}();

auto diff_upgrade(int64_t x)
{
  return x - *std::lower_bound(pow42.begin(), pow42.end(), x);
}

constexpr int N = 100005;

int n, q, a[N];

struct sgt_t
{
  struct node_t
  {
    int64_t val;
    int64_t diff_max;
    int64_t val_add     = 0;
    int64_t val_assign  = -1;
    int64_t diff_assign = -1;

    node_t() = default;
    node_t(int64_t val, int64_t diff) : val(val), diff_max(diff) {}
    node_t(const node_t &lhs, const node_t &rhs) :
        val(lhs.val == rhs.val ? lhs.val : -inf),
        diff_max(std::max(lhs.diff_max, rhs.diff_max))
    {
    }

    void push_assign(int64_t val, int64_t diff)
    {
      this->val         = val;
      this->val_add     = 0;
      this->val_assign  = val;
      this->diff_max    = diff;
      this->diff_assign = diff;
    }
    void push_add(int64_t det)
    {
      this->val      = this->val + det;
      this->val_add  = this->val_add + det;
      this->diff_max = this->diff_max + det;
    }
    void push_down(node_t &lhs, node_t &rhs)
    {
      if (val_assign != -1)
      {
        lhs.push_assign(val_assign, diff_assign);
        rhs.push_assign(val_assign, diff_assign);
        val_assign  = -1;
        diff_assign = -1;
      }
      if (val_add != 0)
      {
        lhs.push_add(val_add);
        rhs.push_add(val_add);
        val_add = 0;
      }
    }
  };

  node_t p[N * 4];

  template <class RandomAccessIterator>
  void init(int u, RandomAccessIterator begin, RandomAccessIterator end)
  {
    if (begin + 1 == end)
    {
      p[u] = node_t(*begin, diff_upgrade(*begin));
    }
    else
    {
      RandomAccessIterator mid = begin + std::distance(begin, end) / 2;
      init(u + u, begin, mid);
      init(u + u + 1, mid, end);
      p[u] = node_t(p[u + u], p[u + u + 1]);
    }
  }

  auto query(int u, int l, int r, int pos)
  {
    if (r - l == 1)
    {
      return p[u];
    }
    else
    {
      p[u].push_down(p[u + u], p[u + u + 1]);
      int mid = l + (r - l) / 2;
      if (pos < mid)
        return query(u + u, l, mid, pos);
      else
        return query(u + u + 1, mid, r, pos);
    }
  }

  void assign(int u, int l, int r, int ml, int mr, int64_t val, int64_t diff)
  {
    if (ml <= l && r <= mr)
    {
      p[u].push_assign(val, diff);
    }
    else
    {
      p[u].push_down(p[u + u], p[u + u + 1]);
      int mid = l + (r - l) / 2;
      if (ml < mid)
        assign(u + u, l, mid, ml, mr, val, diff);
      if (mr > mid)
        assign(u + u + 1, mid, r, ml, mr, val, diff);
      p[u] = node_t(p[u + u], p[u + u + 1]);
    }
  }

  void add(int u, int l, int r, int ml, int mr, int64_t val)
  {
    if (ml <= l && r <= mr)
    {
      p[u].push_add(val);
    }
    else
    {
      p[u].push_down(p[u + u], p[u + u + 1]);
      int mid = l + (r - l) / 2;
      if (ml < mid)
        add(u + u, l, mid, ml, mr, val);
      if (mr > mid)
        add(u + u + 1, mid, r, ml, mr, val);
      p[u] = node_t(p[u + u], p[u + u + 1]);
    }
  }

  void adjust(int u, int l, int r)
  {
    if (p[u].diff_max > 0)
    {
      if (p[u].val >= 0)
        p[u].push_assign(p[u].val, diff_upgrade(p[u].val));
      else
      {
        cm_assert(r - l >= 2);
        p[u].push_down(p[u + u], p[u + u + 1]);
        int mid = l + (r - l) / 2;
        adjust(u + u, l, mid);
        adjust(u + u + 1, mid, r);
        p[u] = node_t(p[u + u], p[u + u + 1]);
      }
    }
  }

} sgt;

int main()
{
  n = sc.next_int();
  q = sc.next_int();
  for (int i = 0; i < n; i++)
    a[i] = sc.next_int();
  sgt.init(1, a, a + n);

  for (int i = 0; i < q; i++)
  {
    int opt = sc.next_int();
    if (opt == 1)
    {
      int p = sc.next_int() - 1;
      std::cout << sgt.query(1, 0, n, p).val << std::endl;
    }
    else if (opt == 2)
    {
      int l   = sc.next_int() - 1;
      int r   = sc.next_int();
      int val = sc.next_int();
      sgt.assign(1, 0, n, l, r, val, diff_upgrade(val));
    }
    else
    {
      int l   = sc.next_int() - 1;
      int r   = sc.next_int();
      int val = sc.next_int();
      do
      {
        sgt.add(1, 0, n, l, r, val);
        sgt.adjust(1, 0, n);
      } while (sgt.p[1].diff_max == 0);
    }
  }

  return 0;
}