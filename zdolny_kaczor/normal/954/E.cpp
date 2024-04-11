//pi, 23 mar 2018, 11:33:52 CET
//Konrad Paluszek. University of Warsaw
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MP make_pair
#define MT(a, b, c) MP(MP(a, b), c)
#define MQ(a, b, c, d) MP(MP(a, b), MP(c, d))
#define quadr(a, b, c, d) pair <pair <a, b>, pair <c, d> >
#define tri(a, b, c) pair <pair <a, b>, c>
#define st f.f
#define nd f.s
#define rd s.f
#define rth s.s
#define PB push_back
#define EB emplace_back
#define pb pop_back
#define fs(r) r.f, r.s
#define sf(r) r.s, r.f
#define rans return ans
#define retr return true
#define reff return false
#define die(x...) exit((printf(x),puts(""),0))
#define Tt_ template <class T
using PII=pair<int,int>;using VI=vector<int>;using LL=long long;using PLL=pair<LL,LL>;using LD=long double;using VPII=vector<PII>;using
PDD=pair<LD,LD>;using VPLL=vector<PLL>;using VVI=vector<VI>;using VPDD=vector<PDD>;using SI=set<int>;using SPII=set<PII>;using MII=map<int
,int>;using SLL=set<LL>;using MLL=map<LL,LL>;using QII=pair<PII,PII>;using VQII=vector<QII>;using ULL=unsigned long long;using VLL=vector<
LL>;using VULL=vector<ULL>;using PULL=pair<ULL,ULL>;using SULL=set<ULL>;using MULL=map<ULL,ULL>;using UI=unsigned int;using TII=pair<PII,
int>;using VTII=vector<TII>;using STII=set<TII>;using TLL=pair<PLL,LL>; using QLL=pair<PLL,PLL>;using VLD=vector<LD>;using SVI=set<VI>;
ULL randULL(){return((ULL)rand())^((ULL)rand()<<15)^((ULL)rand()<<30)^((ULL)rand()<<45)^((ULL)rand()<<60);}
#define RtKxUA(s, f) int s(int x){return f(x);}int s(UI x){return f(x);}int s(LL x){return f##ll(x);}int s(ULL x){return f##ll(x);}
RtKxUA(popc, __builtin_popcount)RtKxUA(ctz, __builtin_ctz)RtKxUA(clz, __builtin_clz)RtKxUA(bit_parity, __builtin_parity)
#define pmap(F, x) MP(F(x.f), F(x.s))
#define pmap2(F, x, y) MP(F(x.f, y.f), F(x.s, y.s))
#define pmap3(F, x, y, z) MP(F(x.f, y.f, z.f), F(x.s, y.s, z.s))
Tt_,class U>bool one_of(T x, U y){return x==y;}Tt_,class U,class...V>bool one_of(T x,U y,V...z){return x==y||one_of(x,z...);}Tt_>bool
diff(T _){return true;}Tt_,class...U>bool diff(T x,U...y){return!in(x,y...)&&diff(y...);}Tt_,class U>bool equal(T x,U y){return x==y;}
Tt_,class U,class...V>bool equal(T x,U y,V...z){return x==y&&equal(x,z...);}Tt_,class U>bool in_order(T x,U y){return x<=y;}Tt_,class U,
class...V>bool in_order(T x,U y,V...z){return x<=y&&in_order(y,z...);}Tt_,class U> bool in_strorder(T x, U y) {return x < y;}Tt_,class U,
class...V>bool in_strorder(T x,U y,V...z){return x<y&&in_strorder(y,z...);}Tt_>void swap3(T &x, T&y, T&z){swap(x,y);swap(x,z);}Tt_>
pair<T,T>dup(T x){return MP(x,x);}Tt_>tri(T,T,T)thrice(T x){return MT(x,x,x);}Tt_>quadr(T,T,T,T)fourfold(T x){return MQ(x,x,x,x);}
#define ALL(V) V.begin(),V.end()
#define siz(V) ((int)(V).size())
#define FOR(x, b, e)  for(int x=b;x<=(int)(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(int)(e);x--)
#define REP(x, n)     for(int x=0;x<(int)(n);x++)
#define FORBITS(i,m)  for(decltype(m)lP6N4Slr=(m),i=lP6N4Slr?ctz(lP6N4Slr):0;lP6N4Slr;lP6N4Slr&=~((decltype(m))1<<i),i=ctz(lP6N4Slr))
#define FORDBITS(i,m) for(decltype(m)_6Im=(m),i=_6Im?8*sizeof(m)-clz(_6Im)-1:0;_6Im;_6Im&=~((decltype(m))1<<i),i=8*sizeof(m)-clz(_6Im)-1)
#define SUBS(i, mask) for(decltype(mask)i = (mask),NFR9xNQCJZTrYQ=1;NFR9xNQCJZTrYQ;NFR9xNQCJZTrYQ=i,i=(i-1)&(mask))
#define FOR2(i, j, b, e) for (int i = (b); i < (e); ++i) for (int j = i + 1; j <= (e); ++j)
#define FOR3(i, j, k, b, e) for (int i = (b); i < (e); ++i) for (int j = i + 1; j < (e); ++j) for (int k = j + 1; k <= (e); ++k)
#define FORINEX(i, v, j) for (auto i : v) if (i != (j))
#define CYCLE(per, i, s) for (int i = s,jpZl_0i30raaqQ = 1;jpZl_0i30raaqQ || i != s; i = per[i], jpZl_0i30raaqQ = 0)
Tt_,class U,class V> T safvec(const vector<T>&v,int i,U low,V high){if(i<0)return low;if(i>=siz(v))return high;return v[i];}
Tt_,class U> T safar(T *a, int i, U low) {if(i<0)return low;return a[i];}
#define cE7Ux(_,o)Tt_,class U>auto my_##_(const U&x,const T&y)->decltype(1?x:y){return x o y?x:y;}Tt_,class U>bool _##i(U&x,T y){if(y o x)\
{x=y;retr;}reff;}Tt_,class U,class V>auto my_##_(const T&a,const U&b,const V&c)->decltype(1?a:(1?b:c)){return my_##_(a, my_##_(b, c));}Tt_\
,class U,class V,class W>auto my_##_(const T&a,const U&b,const V&c,const W&d)->decltype(1?a:(1?b:(1?c:d))){return my_##_(a,my_##_(b,c,d));}
Tt_,class U,class V>auto med(const T&a,const U&b,const V&c)->decltype(1?a:(1?b:c)){return my_min(my_max(a,b),my_max(my_min(a,b),c));}
namespace std{Tt_,class U>struct hash<pair<T,U>>{size_t operator()(const pair<T,U>&a)const{return(hash<T>()(a.first)*1420343LL^hash<U>()
(a.second)*923275LL)%1463984161;}};}cE7Ux(min,<)cE7Ux(max,>)Tt_>T brange(int l,int r){return~(~((T)0)<<(r-l+1))<<l;}Tt_>T brange(int l,int
r,int s){return (brange<T>(l,l+(r-l)/s*s-1)/brange<T>(0,s-1))|((T)1<<(l+(r-l)/s*s));}Tt_>auto O2kQ(T x, int i, int j)->vector<typename
remove_reference<decltype(*x.end())>::type> {vector<typename remove_reference<decltype(*x.end())>::type>ans;for(auto c:x)if((--i<0)&
(j-->=0))ans.PB(c);rans;}Tt_>vector<T>O2kQ(const T*x,int i,int j){vector<T> ans;FOR(_, i, j) ans.PB(x[_]);rans;}int CON_BOUND=10;
#define next   __next__Yilw3Q
#define left   __left__zLNhrA
#define right __right__BNkEcA
#define prev   __prev__Nfq1Zg
#define pow     __pow__j4xBnT
#define hash   __hash__z3C4HK
#define div     __div__pS5g0g
#define ei else if
string E0ms(){return"";}Tt_>string E0ms(T x){stringstream os;os<<boolalpha<<x;return os.str();}Tt_,class...U>string E0ms(T x,U...y){
return E0ms(x)+", "+E0ms(y...);}string SqC6(bool x){return x?"true":"false";}Tt_>typename enable_if<is_integral<T>::value,string>::type
SqC6(T r){string a;FORD(i,8*sizeof(T)-1,0){if(i%5==4)a+='.';a+='0'+!!(((T)1<<i)&r);}return a;}Tt_,class C>string SqC6(pair<T,C>);Tt_>auto
SqC6(T x)->decltype(x.begin(),string()){string a="";for(auto c:x){if(siz(a))a+=", ";a+=SqC6(c);}return "{"+a+"}_"+to_string(siz(x));}Tt_,
class C>string SqC6(pair<T,C>x){return "<"+SqC6(x.f)+", "+SqC6(x.s)+">";}
#ifdef DEB 
#define debug(x...) lG6xa("\033[1;",30+__LINE__%8,"m[",__FUNCTION__,":",__LINE__,"] \033[",30+(__LINE__/8+__LINE__*3)%8,"m",boolalpha,x)
#define print_stack() kevfqira(__LINE__, __FUNCTION__)
void lG6xa(){cerr<<dec<<"\033[0m"<<endl;}Tt_,class...U>void lG6xa(T x,U...y){cerr<<x;lG6xa(y...);}vector<stringstream>iC39nIWD;struct
hwScnYBN{hwScnYBN(){iC39nIWD.EB();}~hwScnYBN() {iC39nIWD.pop_back();}};const bool deb=true;void kevfqira(int l,string fun){cerr<<
"STACK TRACE from ["<<fun<<":"<<l<<"]"<< endl;for(auto&x:iC39nIWD)cerr<<"  "<<x.str()<<dec<<"\033[0m"<<endl;}void Co8VcQ(){}Tt_,class...C>
void Co8VcQ(T x,C...y){iC39nIWD.back()<<x;Co8VcQ(y...);}
#define local_assert(c, m)(c)?0:(cerr<<"\033[1;41;37m[LINE:"<<__LINE__<<", COND:"<<#c<<"] "<<m<<dec<<"\033[0m\n",print_stack(),exit(-1),0)
#define mark_stack(c...) psrlEPb8ixLKOQ(__LINE__, c)
#define psrlEPb8ixLKOQ(l, c...) aAjr4btK(l, c)
#define aAjr4btK(l,c...) hwScnYBN rQH9guji##l;Co8VcQ("\033[1;",40+l%8,"m[",__FUNCTION__,":",l,"]\033[0m\033[1;",30+(l/8+l*3)%8,"m ",c);
#else
const bool deb = false;
#define debug(...)
#define local_assert(...)
#define mark_stack(...)
#define print_stack()
#endif
Tt_,class C>ostream&operator<<(ostream&os,pair<T,C>x){return os<<"<"<<x.f<<", "<<x.s<<">";}Tt_>auto operator<<(ostream&os,T x)->typename
enable_if<!is_same<T,string>::value,decltype(x.end(),os)>::type{os<<"{";int i=0;for(auto c:x){if(i++==siz(x)-1||siz(x)<CON_BOUND+2||
i<CON_BOUND){if(i-1&&(i!=siz(x)||siz(x)<CON_BOUND+2))os<<", ";os<<c;}if(i==CON_BOUND&&siz(x)>CON_BOUND+1)os<<" ... ";}return os<<"}_"<<
x.size();}string b7Pe(string x){int dep=0;for(char c:x){for(char d:"([{")if(c==d)dep++;for(char d:"}])")if(c==d)dep--;for(char d:
"+-*/%^<>=&|?,")if(c==d&&!dep)return"("+x+")";}return x;}Tt_,class U>pair<U,T>pinv(pair<T,U>x){return MP(sf(x));}
#define cr ,"][",
#define rr ,"] = ",
#define cc ,"[",
#define ao ,"  " 
#define name(a) b7Pe(#a), " = ", (a) ao
#define nmask(a) b7Pe(#a)," = ",SqC6(a) ao
#define arr(a, i) #a cc#i rr#a cc (i) rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc (i) cr (j) rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc (i) cr (j) cr (k) rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc (i) cr (j) cr (k) cr (q) rr a[i][j][k][q] ao
#define arrtom(a, i) #a cc#i rr#a cc (i) rr a[i] ao
#define arr2tom(a, i, j) #a cc #i cr #j rr #a cc (i) cr (j) rr SqC6(a[i][j]) ao
#define arr3tom(a, i, j, k) #a cc #i cr #j cr #k rr #a cc (i) cr (j) cr (k) rr SqC6(a[i][j][k]) ao
#define arr4tom(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc (i) cr (j) cr (k) cr (q) rr SqC6(a[i][j][k][q]) ao
#define _2arr(a, b, i) #a cc #b cc #i, "]" rr #a cc #b cc (i), "]" rr #a cc b[i] rr a[b[i]] ao
#define _3arr(a,b,c,i) #a cc #b cc #c cc #i, "]]" rr #a cc #b cc #c cc (i), "]]" rr #a cc #b cc c[i], "]" rr #a cc b[c[i]] rr a[b[c[i]]] ao
#define range(a, i, j) #a cc(i), "..", (j)rr O2kQ(a,i,j) ao
#define rmask(a, i, j) #a cc(i), "..", (j)rr SqC6(O2kQ(a,i,j)) ao
#define arrm(a, i) #a cc #i rr #a cc SqC6(i) rr a[i] ao
#define arrmtom(a, i) #a cc #i rr #a cc SqC6(i) rr SqC6(a[i]) ao
#define arrmi(a, i, j) #a cc #i cr #j rr #a cc SqC6(i) cr(j)rr a[i][j] ao
#define arrim(a, i, j) #a cc #i cr #j rr #a cc(i)cr SqC6(j) rr a[i][j] ao
#define arrmm(a, i, j) #a cc #i cr #j rr #a cc SqC6(i) cr SqC6(j) rr a[i][j] ao
#define arrm3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc SqC6(i) cr(j)cr(k)rr a[i][j][k] ao
#define arrm4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc SqC6(i) cr(j)cr(k)cr(q)rr a[i][j][k][q] ao
#define oper(a, op, b) b7Pe(#a), " ", #op " ", b7Pe(#b), " = ", (a), " ", #op " ", (b), " = ", ((a) op (b))ao
#define tt ,"(",
#define nn ,") = ",
#define _2fun(f,g,x...)#f tt#g tt#x, ")) = ", #f tt#g tt E0ms(x), ")) = ", #f tt g(x)nn f(g(x))ao
#define _3fun(f,g,h,x...)#f tt#g tt#h tt#x, "))) = ", #f tt#g tt#h tt E0ms(x), "))) = ", #f tt#g tt\
	h(x), ")) = ", #f tt g(h(x))nn f(g(h(x))) ao
#define arfu(a,f,x...)#a cc#f tt#x, ")] = ", #a cc#f tt E0ms(x), ")] = ", #a cc f(x)rr a[f(x)]ao
#define fuar(f, a, x) #f tt #a cc #x, "]) = ", #f tt #a cc(x), "]) = ", #f tt a[x] nn f(a[x]) ao
#define arrop(a, i, op, j) #a cc b7Pe(#i), #op, b7Pe(#j) rr #a cc (i), #op, (j) rr #a cc((i)op(j))rr a[(i) op (j)] ao
#define funop(f, x, op, y) #f tt b7Pe(#x), #op, b7Pe(#y) nn #f tt x, #op, y nn #f tt(x)op(y)nn f((x) op (y)) ao
#define arropi(a,i,op,j,k) #a cc b7Pe(#i), #op, b7Pe(#j) cr #k rr #a cc (i), #op<r(j) cr k rr	#a cc((i)op(j))cr k rr a[(i)op(j)][k] ao
#define arriop(a,i,j,op,k) #a cc #i cr b7Pe(#j), #op, b7Pe(#k) rr #a cc(i)cr (j), #op, (k) rr	#a cc(i)cr((j)op(k))rr a[i][(j)op(k)] ao
#define arropop(a,i,op,j,k,op2,q)#a cc b7Pe(#i), #op b7Pe(#j)cr b7Pe(#k), #op2 b7Pe(#q)rr#a cc i, #op, j cr\
		k, #op2, q rr#a cc((i)op(j))cr((k)op2(q))nn a[(i)op(j)][(k)op2(q)] ao
#define arroparr(a,i,o,b,j) #a cc #i, "]", #o, #b cc #j rr #a cc (i), "]", #o, #b cc(j)rr a[i], #o, b[j], " = ", (a[i] o b[j])ao
#define funopfun(f,x,o,g,y...)#f tt#x ")" #o, #g tt#y nn#f tt E0ms(x), ")" #o, #g tt E0ms(y)nn f(x), #o, g(y), " = ", (f(x)o g(y))ao
#define funoparr(f,x,o,b,j) #f tt #x, ")", #o, #b cc #j rr #f tt (x), ")", #o, #b cc(j)rr f(x), #o, b[j], " = ", (f(x) o b[j])ao
#define arropfun(a,i,o,g,x...)#a cc#i, "]", #o, #g tt#x nn#a cc(i), "]", #o, #g tt E0ms(x)nn a[i], #o, g(x), " = ", (a[i] o g(x))ao
#define fun(f,x...) #f tt #x nn #f tt E0ms(x) nn f(x) ao
#define funm(f, x) #f tt #x nn #f tt SqC6(x) nn f(x) ao
#define funmm(f, x, y) #f tt #x nn #f tt SqC6(x), ", ", SqC6(y) nn f(x, y) ao
#define funmmtom(f, x, y) #f tt #x, ", ", #y nn #f tt SqC6(x), ", ", SqC6(y) nn SqC6(f(x, y)) ao
#define funmi(f, x,y...) #f tt #x, ", ", #y nn #f tt SqC6(x), ", ", E0ms(y) nn f(x, y) ao
#define funmim(f, x,y...) #f tt #x, ", ", #y nn#f tt SqC6(x), ", ", E0ms(y)nn SqC6(f(x, y))ao
#define funtom(f,x...) #f tt #x nn #f tt E0ms(x) nn SqC6(f(x)) ao
#define funmtom(f, x) #f tt #x nn #f tt SqC6(x) nn SqC6(f(x)) ao
#define k66C(o)Tt_,class B,class C,class D>auto operator o(pair<T,B>x,pair<C,D>y)->pair<decltype(x.f o y.f),decltype(x.s o y.s)>{return \
MP(x.f o y.f,x.s o y.s);}Tt_,class B,class C>auto operator o(pair<T,B>x,C y)->pair<decltype(x.f o y),decltype(x.s o y)>{return MP(x.f o \
y,x.s o y);}Tt_,class C,class D>auto operator o(T x,pair<C, D>y)->pair<decltype(x o y.f),decltype(x o y.s)>{return MP(x o y.f,x o y.s);}
#define yB_A(o)Tt_,class B,class C,class D>pair<T,B>&operator o(pair<T,B>&x,pair<C,D>y){x.f o y.f;\
	x.s o y.s;return x;}Tt_,class B,class C>pair<T,B>&operator o(pair<T,B>&x,C y){x.f o y;x.s o y;return x;}
#define WilQ(o) Tt_, class B> pair <T, B> & operator o(pair<T,B> & x){fs(o x);return x;}\
	Tt_,class B> pair <T,B> operator o(pair<T,B>&x,int _){return MP(x.f o,x.s o);}
#define xUk2(o)Tt_,class B>auto operator o(pair<T,B>x)->pair<typename remove_reference<decltype(o x.f)>::type,\
	typename remove_reference<decltype(o x.s)>::type>{return MP(fs(o x));}
//ostream&operator<<(ostream&os, __int128_t x){if (x<0){os<<'-';x=-x;}if(x>=10)os<<x/10;return os<<(int)(x%10);}
//ostream&operator<<(ostream & os, __uint128_t x){if(x>=10)os<<x/10;return os<<(int)(x%10);}
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,
167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,
587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,
811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997},big_primes[]={1307533217,
1336158883,1339172111,1367797777,1376837461,1399436671,1426555723,1440115249,1444635091,1489833511,1553111299,1562150983,1587763421,16103\
62631,1652547823,1666107349,1700759471,1782116627,1797182767,1810742293,1818275363,1892099449,1904152361,1919218501,1940311097,1944830939,
1968936763,1977976447,1985509517,1990029359},gens[]={1,2,3,5,2,11,3,14,19,11,17,32,30,34,29,19,34,31,63,33,5,63,53,58,40,83,21,18,99,33,
106,40,85,109,40,77,91,120,105,91,79,53,182,10,184,48,48,150,168,72,65,46,31,216,101,134,163,147,93,42,69,7,151,308,112,12,227,185,214,305
,163,234,154,316,3,11,233,390,271,173,82,407,13,135,414,391,177,293,426,432,337,281,385,103,95,152,12,371,390,77,532,34,287,73,308,493,258
,549,528,411,12,283,614,596,622,309,91,511,287,433,585,123,2,170,183,341,459,322,333,337,507,718,82,517,396,315,565,48,362,617,776,425,584
,231,578,395,127,27,506,435,727,659,697,385,290,109,430,422,344,849,513,453,852,920,152,482,653,271},big_gens[]={661761153,1315209189,2356\
49158,80905954,861543922,677870461,332266749,1192707557,820697698,93737534,1395132003,176849700,1113502216,860516128,1543755630,328298286,
1219407972,1407392293,733053145,400000570,1081174233,847228024,1516266762,83276926,500618997,44975430,47827763,1411328206,151880843,19696\
955};LL vbig_primes[]={1223771071LL,2557943639LL,4625922079LL,8465729693LL,16196062793LL,32628322457LL,64355194333LL,128143942897LL,25672\
8067087LL,512368953949LL,1024440714547LL,2048302681847LL,4096121499499LL,8192933500519LL,16384652744209LL,32768255472209LL,6553600783264\
9LL,131072225217863LL,262144391360893LL,524288060819213LL,1048576249040491LL,2097152266756471LL,4194304028438527LL,8388608209001387LL,
16777216572671047LL,33554432072300339LL,67108864903274897LL,134217728402776373LL,268435456069367221LL,536870912016065747LL};const int inf
=1e9,NONE=-1;const LL llinf=3e18;const char*sc2="%d%d",*sc3="%d%d%d",*sc4="%d%d%d%d",*pr2="%d %d\n",*pr3="%d %d %d\n",*pr4="%d %d %d %d\n";
VI factor(int x){VI ans; for(int p=2;p*p<=x;++p)while(x%p==0){ans.PB(p);x/=p;}if(x>1)ans.PB(x);return ans;}void fixmod(LL&a,LL m){a%=m;
if(a<0)a+=m;}VI get_vi(int l=-1){l+1||scanf("%d",&l);VI a(l);REP(i,l)scanf("%d",&a[i]);return a;}VPII get_vpi(int l=-1){l+1||scanf("%d",&l
);VPII a(l);REP(i,l)scanf(sc2,fs(&a[i]));return a;}k66C(+)k66C(-)k66C(/)k66C(*)k66C(%)k66C(&)k66C(|)k66C(^)k66C(&&)k66C(||)WilQ(++)WilQ(--)
yB_A(+=)yB_A(-=)yB_A(*=)yB_A(/=)yB_A(%=)yB_A(^=)yB_A(&=)yB_A(|=)xUk2(*)xUk2(~)xUk2(!)xUk2(-)

const int MN = 2e5 + 44;
//start here
int a[MN];
int tem[MN];
int main() {
	debug("Read all complier warnings!!!!!  ", fun(factor, __LINE__));
	debug("Complied on: " __DATE__ " " __TIME__);
	debug("LONG LONGS!!!!!  ", funop((int), 0xd1617all, *, 0x200f1LL));
	debug(fun(factor, MN), range(primes, 6, 9), "to small MN => Runtime Error on test ", MN % 181);
	[](){}();
	//start here
	int n, t;
	scanf("%d%d", &n, &t);
	VPII pos, neg;
	REP(i, n)
		scanf("%d", a + i);
	REP(i, n)
		scanf("%d", tem + i);
	LL possum = 0, negsum = 0;
	LD ans = 0;
	REP(i, n) {
		if (tem[i] > t) {
			pos.EB(tem[i] - t, a[i]);
			possum += (tem[i] - t) * 1ll * a[i];
		}
		ei (tem[i] < t) {
			neg.EB(t - tem[i], a[i]);
			negsum += (t - tem[i]) * 1ll * a[i];
		}
		else
			ans += a[i];
	}
	debug(name(possum), name(negsum));
	if (possum > negsum) {
		debug("swap");
		swap(pos, neg);
		swap(possum, negsum);
	}
	for (auto c : pos)
		ans += c.s;
	sort(ALL(neg));
	debug(name(pos), name(neg), name(ans));
	for (auto c : neg) {
		debug(name(c));
		if (c.f * 1ll * c.s <= possum) {
			debug("to small");
			possum -= c.f * 1ll * c.s;
			ans += c.s;
		}
		else {
			debug("final ", name(possum), name(c));
			ans += possum / (LD) c.f;
			break;
		}
	}
	printf("%.10Lf\n", ans);
	#pragma GCC diagnostic ignored "-Woverflow"
	debug("Before submit:!!!!!!!!!!!!!!!!");
	debug(name(MN), "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!  ", nmask(MN));
	debug("LONG LONGS!!!!!  ", oper(111111 * 111111, ==, 111111LL * 111111LL), name((int)0xB060051A));
	debug("Check if m, n aren't misused  ", arr(4, __FILE__));
	debug("Make sure output format is right (including YES/NO vs Yes/No vs Tak/Nie, newlines vs spaces)");
	debug("Run with n = 1  ", range(__DATE__, 1, 8));
	debug("Make sure two ints aren't multiplied to get a long long  ", oper(__LINE__, %, 7));
	debug("Read all compiler warnings");
	debug("Hereby I confirm that I have done all above (Ctrl + D)");
	while (deb && getchar() != EOF);
}