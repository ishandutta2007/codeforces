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
template<class BufferReader>class scanner:protected BufferReader{private:using BufferReader::get;using BufferReader::next;inline bool is_ws(char c){return c<=' ';}inline bool is_cr(char c){return c=='\n'||c=='\r';}int get_sign(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using BufferReader::BufferReader;char next_char(){while(is_ws(get()))next();return next();}char*next_token(char*s){while(is_ws(get()))next();while(!is_ws(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(is_ws(get()))next();while(!is_cr(get()))*s++=next();*s='\0';return s;}int next_int(){int sign=get_sign();int result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_long(){int sign=get_sign();long long result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}template<class Integer>Integer next_integer(){Integer sign=get_sign();Integer result(0);while(isdigit(get()))result=result*Integer(10)+Integer(next()-'0');return sign*result;}double next_double(){int sign=get_sign();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
#endif
#ifndef CM_UTIL_H
#define CM_UTIL_H 1
#include <utility>
#include <vector>
#ifdef CM_DEBUG
#define CONSTRAINT(n, a, b) constexpr auto n = b;
#else
#define CONSTRAINT(n, a, b) constexpr auto n = a;
#endif
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
#include <functional>
#include <stack>
#include <vector>
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

int main()
{
  struct edge_t
  {
    int u, v, c, t;
  };

  int n = sc.next_int();
  int m = sc.next_int();
  std::vector<edge_t> es;
  for (int i = 0; i < m; i++)
  {
    int u = sc.next_int() - 1;
    int v = sc.next_int() - 1;
    int c = sc.next_int() - 1;
    int t = sc.next_int();
    es.push_back({u, v, c, t});
  }

  auto check = [&](int thr, bool print_ans = false) -> bool {
    // TODO
    std::vector<std::vector<int>> e(m * 10);

    for (int i = 0; i < m; i++)
      if (es[i].t > thr)
        e[i * 2 + 1].push_back(i * 2);

    std::vector<std::vector<int>> eu(n);
    for (int i = 0; i < m; i++)
    {
      eu[es[i].u].push_back(i);
      eu[es[i].v].push_back(i);
    }

    int cur_uid = m * 2;
    for (int i = 0; i < n; i++)
    {
      int k = static_cast<int>(eu[i].size());
      int pre_offset = cur_uid;
      int suf_offset = cur_uid + k;
      cur_uid += 2 * k;
      for (int j = 0; j < k; j++)
      {
        e[pre_offset + j].push_back(eu[i][j] * 2);
        e[suf_offset + j].push_back(eu[i][j] * 2);
        if (j > 0)
        {
          e[pre_offset + j].push_back(pre_offset + j - 1);
          e[eu[i][j] * 2 + 1].push_back(pre_offset + j - 1);
        }
        if (j + 1 < k)
        {
          e[suf_offset + j].push_back(suf_offset + j + 1);
          e[eu[i][j] * 2 + 1].push_back(suf_offset + j + 1);
        }
      }

      std::sort(eu[i].begin(), eu[i].end(),
                [&](int x, int y) { return es[x].c < es[y].c; });
      pre_offset = cur_uid;
      suf_offset = cur_uid + k;
      cur_uid += 2 * k;
      for (int jl = 0, jr = 0; jl < k; jl = jr)
      {
        while (jr < k && es[eu[i][jl]].c == es[eu[i][jr]].c)
          jr++;
        for (int j = jl; j < jr; j++)
        {
          e[pre_offset + j].push_back(eu[i][j] * 2 + 1);
          e[suf_offset + j].push_back(eu[i][j] * 2 + 1);
          if (j > jl)
          {
            e[pre_offset + j].push_back(pre_offset + j - 1);
            e[eu[i][j] * 2].push_back(pre_offset + j - 1);
          }
          if (j + 1 < jr)
          {
            e[suf_offset + j].push_back(suf_offset + j + 1);
            e[eu[i][j] * 2].push_back(suf_offset + j + 1);
          }
        }
      }
    }

    cm_assert(m * 10 == cur_uid, m, cur_uid);

    std::vector<int> dfn(cur_uid, -1), low(cur_uid), col(cur_uid);
    int cur_dfn = 0, cur_col = 0;
    std::vector<bool> in_stack(cur_uid);
    std::stack<int> st;

    std::function<void(int)> dfs = [&](int u) {
      low[u] = dfn[u] = cur_dfn++;
      in_stack[u] = true;
      st.push(u);
      for (int v : e[u])
      {
        if (dfn[v] == -1)
          dfs(v);
        if (in_stack[v])
          check_min(low[u], low[v]);
      }
      if (low[u] == dfn[u])
      {
        col[u] = cur_col++;
        while (st.top() != u)
        {
          col[st.top()] = col[u];
          in_stack[st.top()] = false;
          st.pop();
        }
        in_stack[u] = false;
        st.pop();
      }
    };

    for (int i = 0; i < cur_uid; i++)
      if (dfn[i] == -1)
        dfs(i);

    for (int i = 0; i < m; i++)
      if (col[i * 2] == col[i * 2 + 1])
      {
        if (print_ans)
          puts("No");
        return false;
      }

    if (print_ans)
    {
      puts("Yes");
      std::vector<int> ans;
      for (int i = 0; i < m; i++)
        if (col[i * 2 + 1] < col[i * 2])
          ans.push_back(i);
      std::cout << thr << " " << ans.size() << std::endl;
      for (int x : ans)
        std::cout << x + 1 << " ";
      std::cout << std::endl;
    }

    return true;
  };

  int l = 0, r = 1e9;
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  check(l, true);

  return 0;
}