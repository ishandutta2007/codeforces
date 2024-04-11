//nie, 22 kwi 2018, 23:35:56 CEST
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
#define unq(a) a.resize(unique(ALL(a)) - a.begin())
#define rans return ans
#define retr return true
#define reff return false
#define die(x...) (printf(x),puts(""),bef0re_submIT())
#define Tt_ template <class T
#define Gea0(x) typename remove_reference<typename remove_const<decltype(x)>::type>::type
#define Ymd(t) using S##t=set<t>;using V##t=vector<t>;using M##t=map<t,t>;using MI##t=map<int,t>;using UMI##t=unordered_map<int,t>;
using SI=set<int>;using ULL=unsigned long long;using LL=long long;using VI=vector<int>;using LD=long double;using PULL=pair<ULL,ULL>;
using UI=unsigned int;using PLL=pair<LL,LL>;using PDD=pair<LD,LD>;using MII=map<int,int>;using TDD=pair<PDD,LD>;using TLL=pair<PLL,LL>;
using PII=pair<int,int>;using TII=pair<PII,int>;using QDD=pair<PDD,PDD>;using QII=pair<PII,PII>;using QLL=pair<PLL,PLL>;Ymd(TII)Ymd(QII)
Ymd(LL)Ymd(ULL)Ymd(PULL)Ymd(QLL)Ymd(LD)Ymd(PDD)Ymd(VI)Ymd(TLL)Ymd(UI)Ymd(PII)Ymd(PLL)Ymd(SI)Ymd(VVI)using UMII=unordered_map<int,int>;
ULL randULL(){return((ULL)rand())^((ULL)rand()<<15)^((ULL)rand()<<30)^((ULL)rand()<<45)^((ULL)rand()<<60);}Ymd(TDD)Ymd(QDD)Ymd(VVI)
#define RtKxUA(s, f) int s(int x){return f(x);}int s(UI x){return f(x);}int s(LL x){return f##ll(x);}int s(ULL x){return f##ll(x);}
RtKxUA(popc, __builtin_popcount)RtKxUA(ctz, __builtin_ctz)RtKxUA(clz, __builtin_clz)RtKxUA(bit_parity, __builtin_parity)
Tt_,class U>bool one_of(T x, U y){return x==y;}Tt_,class U,class...V>bool one_of(T x,U y,V...z){return x==y||one_of(x,z...);}Tt_>bool
diff(T _){retr;}Tt_,class...U>bool diff(T x,U...y){return!one_of(x,y...)&&diff(y...);}Tt_,class U>bool equal(T x,U y){return x==y;}
Tt_,class U,class...V>bool equal(T x,U y,V...z){return x==y&&equal(x,z...);}Tt_,class U>bool in_order(T x,U y){return x<=y;}Tt_,class U,
class...V>bool in_order(T x,U y,V...z){return x<=y&&in_order(y,z...);}Tt_,class U> bool in_strorder(T x, U y) {return x < y;}Tt_,class U,
class...V>bool in_strorder(T x,U y,V...z){return x<y&&in_strorder(y,z...);}Tt_>void swap3(T &x, T&y, T&z){swap(x,y);swap(x,z);}Tt_>
pair<T,T>dup(T x){return MP(x,x);}Tt_>tri(T,T,T)thrice(T x){return MT(x,x,x);}Tt_>quadr(T,T,T,T)fourfold(T x){return MQ(x,x,x,x);}
#define ALL(V) V.begin(),V.end()
#define siz(V) ((int)(V).size())
#define FOR(x, b, e)  for(int x=b;x<=(int)(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(int)(e);x--)
#define REP(x, n)     for(int x=0;x<(int)(n);x++)
#define REP1(i, n)    for(int i=1;i<=(int)(n);++i)
#define FORBITS(i,m)  for(decltype(m)lP6N4Slr=(m),i=lP6N4Slr?ctz(lP6N4Slr):0;lP6N4Slr;lP6N4Slr&=~((decltype(m))1<<i),i=ctz(lP6N4Slr))
#define FORDBITS(i,m) for(decltype(m)_6Im=(m),i=_6Im?8*sizeof(m)-clz(_6Im)-1:0;_6Im;_6Im&=~((decltype(m))1<<i),i=8*sizeof(m)-clz(_6Im)-1)
#define SUBS(i, mask) for(decltype(mask)i = (mask),NFR9xNQCJZTrYQ=1;NFR9xNQCJZTrYQ;NFR9xNQCJZTrYQ=i,i=(i-1)&(mask))
#define FOR2(i, b, e) FOR(i##1, b, e) FOR(i##2, i##1 + 1, e)
#define FOR3(i, b, e) FOR2(i, b, e) FOR(i##3, i##2 + 1, e)
#define FOR4(i, b, e) FOR3(i, b, e) FOR(i##4, i##3 + 1, e)
#define FOR5(i, b, e) FOR4(i, b, e) FOR(i##5, i##4 + 1, e)
#define FOR6(i, b, e) FOR5(i, b, e) FOR(i##6, i##5 + 1, e)
#define FOR7(i, b, e) FOR6(i, b, e) FOR(i##7, i##6 + 1, e)
#define FOR8(i, b, e) FOR7(i, b, e) FOR(i##8, i##7 + 1, e)
#define FOR9(i, b, e) FOR8(i, b, e) FOR(i##9, i##8 + 1, e)
#define FOR10(i, b, e) FOR9(i, b, e) FOR(i##10, i##9 + 1, e)
#define FORE2(i, b, e) FOR(i##1, b, e) FOR(i##2, i##1, e)
#define FORE3(i, b, e) FORE2(i, b, e) FOR(i##3, i##2, e)
#define FORE4(i, b, e) FORE3(i, b, e) FOR(i##4, i##3, e)
#define FORE5(i, b, e) FORE4(i, b, e) FOR(i##5, i##4, e)
#define FORE6(i, b, e) FORE5(i, b, e) FOR(i##6, i##5, e)
#define FORE7(i, b, e) FORE6(i, b, e) FOR(i##7, i##6, e)
#define FORE8(i, b, e) FORE7(i, b, e) FOR(i##8, i##7, e)
#define FORE9(i, b, e) FORE8(i, b, e) FOR(i##9, i##8, e)
#define FORE10(i, b, e) FORE9(i, b, e) FOR(i##10, i##9, e)
#define PERM(b, e) for (bool q4J5iR5o0GXmQ = true; q4J5iR5o0GXmQ; q4J5iR5o0GXmQ = next_permutation(b, e))
#define FORINEX(i, v, j) for (auto i : v) if (i != (j))
#define CYCLE(per, i, s) for (int i = s,jpZl_0i30raaqQ = 1;jpZl_0i30raaqQ || i != s; i = per[i], jpZl_0i30raaqQ = 0)
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
Tt_,class U,class V> T safvec(const vector<T>&v,int i,U low,V high){if(i<0)return low;if(i>=siz(v))return high;return v[i];}
Tt_,class U> T safar(T *a, int i, U low) {if(i<0)return low;return a[i];}
#define cE7Ux(_,o)Tt_,class U>auto my_##_(const U&x,const T&y)->decltype(1?x:y){return x o y?x:y;}Tt_,class U>bool _##i(U&x,T y){if(y o x)\
{x=y;retr;}reff;}Tt_,class U,class V>auto my_##_(const T&a,const U&b,const V&c)->decltype(1?a:(1?b:c)){return my_##_(a, my_##_(b, c));}Tt_\
,class U,class V,class W>auto my_##_(const T&a,const U&b,const V&c,const W&d)->decltype(1?a:(1?b:(1?c:d))){return my_##_(a,my_##_(b,c,d));}
Tt_,class U,class V>auto med(const T&a,const U&b,const V&c)->decltype(1?a:(1?b:c)){return my_min(my_max(a,b),my_max(my_min(a,b),c));}
namespace std{Tt_,class U>struct hash<pair<T,U>>{size_t operator()(const pair<T,U>&a)const{return(hash<T>()(a.first)*1420343LL^hash<U>()
(a.second)*923275LL)%1463984161;}};Tt_,class E>using zBZ=T;Tt_>struct hash<zBZ<T,decltype(((T*)0)->end())>>{size_t operator()(const T &x)
const{size_t h=0;for(auto c:x)h=h*1476331^std::hash<decltype(c)>{}(c);return h;}};}cE7Ux(min,<)cE7Ux(max,>)Tt_>T brange(int l,int r)
{return~(~((T)0)<<(r-l+1))<<l;}Tt_>T brange(int l,int r,int s){return (brange<T>(l,l+(r-l)/s*s-1)/brange<T>(0,s-1))|((T)1<<(l+(r-l)/s*s));
}Tt_>auto O2kQ(T x, int i, int j)->vector<typename remove_reference<decltype(*x.end())>::type> {vector<typename remove_reference<decltype
(*x.end())>::type>ans;for(auto c:x)if((--i<0)&(j-->=0))ans.PB(c);rans;}Tt_>vector<T>O2kQ(const T*x,int i,int j){vector<T> ans;FOR(_,i,j)ans
.PB(x[_]);rans;}int CON_BOUND=10;
#define next   __next__Yilw3Q
#define left   __left__zLNhrA
#define right __right__BNkEcA
#define prev   __prev__Nfq1Zg
#define pow     __pow__j4xBnT
#define hash   __hash__z3C4HK
#define div     __div__pS5g0g
#define ei else if
Tt_>auto SqC6(T x)->typename enable_if<!is_same<T,char *>::value&&!is_same<T,const char*>::value,decltype(*x,string())>::type;
string E0ms(){return"";}Tt_>string E0ms(T x){stringstream ans;ans<<boolalpha<<x;rans.str();}Tt_,class...U>string E0ms(T x,U...y){
return E0ms(x)+", "+E0ms(y...);}string SqC6(bool x){return x?"true":"false";}Tt_>typename enable_if<is_integral<T>::value,string>::type
SqC6(T r){string a;FORD(i,8*sizeof(T)-1,0){if(i%5==4)a+='.';a+='0'+!!(((T)1<<i)&r);}return a;}Tt_,class C>string SqC6(pair<T,C>);Tt_>auto
SqC6(T x)->decltype(x.end(),string()){string a="";for(auto c:x){if(siz(a))a+=", ";a+=SqC6(c);}return "{"+a+"}_"+to_string(siz(x));}Tt_,
class C>string SqC6(pair<T,C>x){return "<"+SqC6(x.f)+", "+SqC6(x.s)+">";}Tt_,int N>T&arrp(T a[][N],PII x){return a[x.f][x.s];}
const int mod = 1e9 + 7; LL mpow(LL b, int e){LL ans = 1;while (e){if(e&1)ans=ans*b%mod;b=b*b%mod;e/=2;}rans;}struct zet_p {
#define mYInQ(t,o) Tt_>typename enable_if<is_arithmetic<T>::value,t>::type operator o(t x,T y){return x o t(y);}Tt_>typename enable_if<\
is_arithmetic<T>::value,t>::type operator o(T x,t y){return t(x) o y;} Tt_>t&operator o##=(t&x,T y){return x = x o y;}
#ifdef DEB 
int l;LD d;zet_p(int x,LD y){l=x;d=y;}zet_p(int x=0){d=x;l=x%mod;}int get(){return l >= 0 ? l : l + mod;}zet_p operator-(){return {-l,-d};}
zet_p operator+(zet_p x){return{(x.l+l)%mod,x.d+d};}zet_p operator*(zet_p x){return{(int)((x.l*1ll*l)%mod),x.d*d};}
zet_p operator-(zet_p x){return{(l-x.l)%mod,d-x.d};}zet_p operator/(zet_p x){return{(int)((l*mpow(x.l,mod-2))%mod),d/x.d};}
};using frac_mod=zet_p;ostream&operator<<(ostream&ans,zet_p x){rans<<"["<<x.d<<":=="<<(x.l+mod)%mod<<"]";}
#define debug(x...) cerr<<"\033[1;"<<30+__LINE__%8<<"m["<<__FUNCTION__<<"#"<<__LINE__<<"] \033["<<30+(__LINE__/8+__LINE__*3)%8<<"m"\
	<<boolalpha,::lG6xa(x)
#define debug_imie(x...) cerr<<"\033[1;"<<30+__LINE__%8<<"m["<<__FUNCTION__<<"#"<<__LINE__<<"] \033["<<30+(__LINE__/8+__LINE__*3)%8<<"m"\
	<<boolalpha,::SIc7iN(#x, x)
Tt_>void SIc7iN(const char*s, T x) {cerr<<s<<" = "<<x<<dec<<"\033[0m"<<endl;}Tt_,class...N>void SIc7iN(const char*s,T x,N...y){int d=0;
	while(*s){if(*s=='(')d++;ei(*s==')')d--;if(*s==','&&!d)break;cerr<<*s++;}cerr<<" = "<<x<<"; ";SIc7iN(s+1, y...);}
#define print_stack() keVfQIr7(__LINE__, __FUNCTION__)
void lG6xa(){cerr<<dec<<"\033[0m"<<endl;}Tt_,class...U>void lG6xa(T x,U...y){cerr<<x<<"; ";lG6xa(y...);}vector<stringstream>iC39nIWD;struct
hwScnYBN{hwScnYBN(){iC39nIWD.EB();}~hwScnYBN(){iC39nIWD.pb();}};const bool deb=1;void keVfQIr7(int l,string fun){cerr<<"\033[1mSTACK "
"TRACE from ["<<fun<<"#"<<l<<"]"<< endl;for(auto&x:iC39nIWD)cerr<<"  "<<x.str()<<dec<<"\033[0m"<<endl;}void Co8VcQ(){}Tt_,class...C>
void Co8VcQ(T x,C...y){iC39nIWD.back()<<boolalpha<<x<<' ';Co8VcQ(y...);}
#define local_assert(c, m)(c)?0:(cerr<<"\033[1;41;37m["<<__FUNCTION__<<"#"<<__LINE__<<" "#c"] "<<m<<dec<<"\033[0m\n",print_stack(),\
	exit(-1),0)
#define mark_stack(c...) psrlEPb8ixLKOQ(__LINE__, c)
#define psrlEPb8ixLKOQ(l, c...) aAjr4btK(l, c)
#define aAjr4btK(l,c...) hwScnYBN rQH9guji##l;iC39nIWD.back()<<"\033[1;"<<40+l%8<<"m["<<__FUNCTION__<<"#"<<l<<\
	"]\033[0m\033[1;"<<30+(l/8+l*3)%8<<"m ",::Co8VcQ(c)
#else
int v;int get(){return v>=0?v:v+mod;}zet_p(LL x=0){v=x%mod;}zet_p operator+(zet_p x){return (v+x.v)%mod;}zet_p operator-(zet_p x){return
v-x.v;}zet_p operator*(zet_p x){return v*1ll*x.v;}zet_p operator/(zet_p a){return v*mpow(a.v,mod-2);}zet_p operator-(){return -v;}};struct
frac_mod {int n,d;frac_mod(int x=0){n=x%mod;d=1;}frac_mod(int x,int y){n=x;d=y;}frac_mod operator+(frac_mod x){return {(int)((x.d*1ll*n+d*
1ll*x.n)%mod),x.d*d%mod};}frac_mod operator-(frac_mod x){return {(int)((n*1ll*x.d-x.n*1ll*d)%mod),x.d*d%mod};}frac_mod operator*(frac_mod
x){return{(int)((n*(LL)x.n)%mod),(int)((d*(LL)x.d)%mod)};}frac_mod operator/(frac_mod x){return{(int)(n*(LL)x.d%mod),(int)(d*(LL)x.n%mod)}
;}int get(){int ans=n*mpow(d,mod-2)%mod;if(ans<0)ans+=mod;rans;}frac_mod operator-(){return{n,-d};}};mYInQ(frac_mod,+)mYInQ(frac_mod,-)
mYInQ(frac_mod,*)mYInQ(frac_mod,/)
const bool deb = false;
#define debug(...)
#define debug_imie(...)
#define local_assert(...)
#define mark_stack(...)
#define print_stack(...)
#endif
Tt_,class C>ostream&operator<<(ostream&ans,pair<T,C>x){rans<<"<"<<x.f<<", "<<x.s<<">";}Tt_>auto operator<<(ostream&o,T x)->typename
enable_if<!is_same<T,string>::value,decltype(x.end(),o)>::type{o<<"{";int i=0;for(auto c:x){if(i++==siz(x)-1||siz(x)<CON_BOUND+2||
i<CON_BOUND){if(i-1&&(i!=siz(x)||siz(x)<CON_BOUND+2))o<<", ";o<<c;}if(i==CON_BOUND&&siz(x)>CON_BOUND+1)o<<" ... ";}return o<<"}_"<<
x.size();}string b7Pe(string x){int dep=0;for(char c:x){for(char d:"([{")if(c==d)dep++;for(char d:"}])")if(c==d)dep--;for(char d:
"+-*/%^<>=&|?,")if(c==d&&!dep)return"("+x+")";}return x;}Tt_,class U>pair<U,T>pinv(pair<T,U>x){return MP(sf(x));}Tt_>struct Wt71{T c;int l,
r,L,R;};Tt_>ostream&operator<<(ostream&o,Wt71<T> M){o<<"\n";FOR(i,M.l,M.r){o<<"  "<<i<<": | ";FOR(j,M.L,M.R){o<<M.c[i][j]<<((j-M.L+1)%5?
" ":"; ");}o<<"\n";}return o;}Tt_>Wt71<T>q9cX(T a,int i,int j,int k,int q){return{a,i,j,k,q};}Tt_>string SqC6(Wt71<T> M){stringstream o;
FOR(i,M.l,M.r){o<<"  "<<i<<": | ";FOR(j,M.L,M.R){o<<SqC6(M.c[i][j])<<((j-M.L+1)%5?" ":"; ");}o<<"\n";}return o.str();}
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
=1e9,NONE=-1;const LL INF=3e18;const char*sc2="%d%d",*sc3="%d%d%d",*sc4="%d%d%d%d",*pr2="%d %d\n",*pr3="%d %d %d\n",*pr4="%d %d %d %d\n";
VI factor(int x){VI ans; for(int p=2;p*p<=x;++p)while(x%p==0){ans.PB(p);x/=p;}if(x>1)ans.PB(x);rans;}k66C(+)k66C(-)k66C(/)k66C(*)k66C(%)
k66C(&)k66C(|)k66C(^)k66C(&&)k66C(||)WilQ(++)WilQ(--)yB_A(+=)yB_A(-=)yB_A(*=)yB_A(/=)yB_A(%=)yB_A(^=)yB_A(&=)yB_A(|=)xUk2(*)xUk2(~)xUk2(!)
xUk2(-)mYInQ(zet_p,+)mYInQ(zet_p,-)mYInQ(zet_p,*)mYInQ(zet_p,/) void bef0re_submIT();Tt_>struct v_J;Tt_> v_J<T> nGT4(T w, string n,bool b);
#define FIm(o) Tt_,class N>auto operator o(v_J<T> x,v_J<N> y)->v_J<decltype(RPr(x)o RPr(y))>{return nGT4(RPr(x)o RPr(y),\
	b7Pe(E0ms(x))+" "#o" "+b7Pe(E0ms(y)),x.m||y.m);}Tt_,class N>auto operator o(T x,v_J<N>y)->v_J<decltype(x o RPr(y))>{return\
	nGT4(x)o y;}Tt_, class N> auto operator o(v_J<T> x, N y) -> v_J<decltype(RPr(x) o y)> {return x o nGT4(y);}
Tt_>T RPr(v_J<T> x);Tt_>T RPr(T x);Tt_>struct v_J{T v;string t;bool m;v_J<T>mask(){return v_J<T>{v,t,true};}template<class N>auto operator
[](N x)->v_J<Gea0(v[RPr(x)])>{return nGT4<Gea0(v[RPr(x)])>(v[RPr(x)],t+"["+E0ms(x)+"]", 0);}};Tt_>v_J<T>nGT4(T w,string n,bool b){return
v_J<T>{w,n,b};}Tt_>v_J<T>nGT4(T w,string n){return nGT4(w,n,false);}Tt_>v_J<T>nGT4(T w){return v_J<T>{w};}Tt_>ostream&operator<<(ostream&
ans,v_J<T>x){rans<<x.t<<(siz(x.t)?" = ":"")<<(x.m?SqC6(x.v):E0ms(x.v));}Tt_> T RPr(v_J<T> x){return x.v;}Tt_> T RPr(T x){return x;}FIm(+)
FIm(-)FIm(/)FIm(*)FIm(%)FIm(>>)FIm(<<)FIm(&)FIm(|)FIm(^)FIm(&&)FIm(||)FIm(==)FIm(!=)FIm(>)FIm(<)FIm(<=)FIm(>=) 
void freo(string name){if(!deb){freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}}
#define imie(a) nGT4(a, b7Pe(#a))
#define imask(a) nGT4(a, b7Pe(#a),true)
#define fun0(F)nGT4(F(),#F"()")
#define fun1(F,a)nGT4(F(RPr(a)),#F"("+E0ms(a)+")")
#define fun2(F,a,b)nGT4(F(RPr(a),RPr(b)),#F"("+E0ms(a,b)+")")
#define fun3(F,a,b,c)nGT4(F(RPr(a),RPr(b),RPr(c)),#F"("+E0ms(a,b,c)+")")
#define fun4(F,a,b,c,d)nGT4(F(RPr(a),RPr(b),RPr(c),RPr(d)),#F"("+E0ms(a,b,c,d)+")")
#define fun5(F,a,b,c,d,e)nGT4(F(RPr(a),RPr(b),RPr(c),RPr(d),RPr(e)),#F"("+E0ms(a,b,c,d,e)+")")
#define fun6(F,a,b,c,d,e,f)nGT4(F(RPr(a),RPr(b),RPr(c),RPr(d),RPr(e),RPr(f)),#F"("+E0ms(a,b,c,d,e,f)+")")
#define fun7(F,a,b,c,d,e,f,g)nGT4(F(RPr(a),RPr(b),RPr(c),RPr(d),RPr(e),RPr(f),RPr(g)),#F"("+E0ms(a,b,c,d,e,f,g)+")")
#define fun8(F,a,b,c,d,e,f,g,h)nGT4(F(RPr(a),RPr(b),RPr(c),RPr(d),RPr(e),RPr(f),RPr(g),RPr(g)),#F"("+E0ms(a,b,c,d,e,f,g,h)+")")
#define fun9(F,a,b,c,d,e,f,g,h,i)nGT4(F(RPr(a),RPr(b),RPr(c),RPr(d),RPr(e),RPr(f),RPr(g),RPr(g),RPr(i)),#F"("+E0ms(a,b,c,d,e,f,g,h,i)+")")
#define range(a, i, j)nGT4(O2kQ(a,RPr(i),RPr(j)), #a"["+E0ms(i)+"..."+E0ms(j)+"]")
#define matr(a,l1,r1,l2,r2) nGT4(q9cX(a,RPr(l1),RPr(r1),RPr(l2),RPr(r2)),#a"["+E0ms(l1)+"..."+E0ms(r1)+"]["+E0ms(l2)+"..."+E0ms(r2)+"]")
#define field(e, x) nGT4(e.v.x,e.t+"."+#x) 
#define wfield(e, x) nGT4(RPr(e).x, b7Pe(E0ms(e))+"."+#x)
#define pfield(e, x) nGT4(RPr(e)->x, b7Pe(E0ms(e))+"->"+#x)
#define wpfield(e, x) nGT4(RPr(e)->x, b7Pe(E0ms(e))+"->"+#x)
#define method1(e, f, x) nGT4(RPr(e).f(RPr(x)), b7Pe(E0ms(e))+"."#f"("+E0ms(x)+")")
#define method2(e, f, x, y) nGT4(RPr(e).f(RPr(x), RPr(y)), b7Pe(E0ms(e))+"."#f"("+E0ms(x, y)+")")
#define adde(G, a, b) G[a].PB(b), G[b].PB(a)
#define addew(G, a, b, c...) G[a].EB(b, c), G[b].EB(a, c)
Tt_>auto operator<<(ostream &ans,T x)->typename enable_if<!is_same<T,char *>::value&&!is_same<T,const char*>::value,
	decltype(*x,ans)>::type {rans << "[" << *x << "]";}
Tt_>auto SqC6(T x)->typename enable_if<!is_same<T,char *>::value&&!is_same<T,const char*>::value,decltype(*x,string())>::type {
	return "["+SqC6(*x)+"]";}
//start here
#define lose die("Marsel")
#define win die("Timur")
const int MN = 1344;
bool winning[MN];
int main() {
	debug("Read all complier warnings!!!!!  ");
	debug("Complied on: " __DATE__ " " __TIME__);
	debug("LONG LONGS!!!!!  ", fun1((int), imie(0xd1617all * 0x200f1LL)));	
	debug(imie(MN), "to small MN => Runtime Error on test", MN % 181); 
	cerr << setprecision(10); 
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (n % 2 == 0) lose;
	VI divs;
	for (int i = 1; i * i <= m; ++i) {
		if (m % i == 0) {
			divs.PB(i);
			if (i != m / i)
				divs.PB(m / i);
		}
	}
	sort(ALL(divs));
	REP(i, siz(divs)) {
		REP(j, i) {
			debug(imie(divs)[imie(i)], imie(divs)[imie(j)], imie(winning)[imie(i)], imie(winning)[imie(j)]);
			if (divs[i] % divs[j] == 0 && divs[j] >= k && (!winning[j] || divs[i] / divs[j] % 2 == 0)) {
				debug("match");
				winning[i] = true;
			}
		}
	}
	if (winning[siz(divs) - 1])
		win;
	else
		lose;
	bef0re_submIT();
}
void bef0re_submIT() {
	#pragma GCC diagnostic ignored "-Woverflow" 
	print_stack();
	debug("Before submit:!!!!!!!!!!!!!!!!"); 
	debug(imie(MN), "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!  ");
	debug("LONG LONGS!!!!! ");
	debug("Check if m, n aren't misused  ");
	debug("Make sure output format is right (including YES/NO vs Yes/No vs Tak/Nie, newlines vs spaces)");
	debug("Run with n = 1");
	debug("Make sure two ints aren't multiplied to get a long long");
	debug("Read all compiler warnings");
	debug("Output enough digits after decimal point (%.20Lf)");
	debug("Hereby I confirm that I have done all above (Ctrl + D)");
	while (deb && getchar() != EOF);
	exit(0);
}