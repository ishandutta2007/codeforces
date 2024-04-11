//Konrad Paluszek
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define dup(a) MP(a, a)
#define MT(a, b, c) MP(MP(a, b), c)
#define MQ(a, b, c, d) MP(MP(a, b), MP(c, d))
#define QII pair <PII, PII>
#define quadr(a, b, c, d) pair <pair <a, b>, pair <c, d> >
#define tri(a, b, c) pair <pair <a, b>, c>
#define st f.f
#define nd f.s
#define rd s.f
#define rth s.s
#define LD long double
#define PB push_back
#define EB emplace_back
#define PLL pair <LL, LL>
#define VPLL vector <PLL>
#define VVI vector <VI>
#define VPDD vector <PDD>
#define SI set <int>
#define SPII set <PII>
#define MII map <int, int>
#define SLL set<LL>
#define uni(a, b) MP(min(a.f, b.f), max(a.s, b.s))
#define pmap(f, x) MP(f(x.f), f(x.s))
#define pmap2(f, x, y) MP(f(x.f, y.f), f(x.s, y.s))
#define pmap3(f, x, y, z) MP(f(x.f, y.f, z.f), f(x.s, y.s, z.s))
template<typename H,typename T,typename N>bool diff(const H &h,const T& t,const N&n){return h!=t&&h!=n&&t!=n;}
template<typename H,typename T,typename N,typename S>bool diff(const H &h,const T &t,const N &n,const S &s)
	{return h!=t&&h!=n&&h!=s&&t!=n&&t!=s&&n!=s;}
template<typename H,typename T,typename N>bool in(const H &h,const T& t,const N& n) {return h==t||h==n;}
template<typename H,typename T,typename N,typename S> bool in(const H &h,const T &t,const N &n,const S &s) {return h==t||h==n||h==s;}
template<typename H,typename T,typename N> bool equal(const H &h,const T&t,const N&n) {return h==t && t==n;}
template<typename H,typename T,typename N,typename S> bool equal(const H &h,const T&t,const N&n,const S&s) {return h==t&&t==n&&n==s;}
template<typename H,typename T,typename N> bool in_order(const H&h,const T&t, const N&n) {return h <= t && t <= n;}
template<typename H,typename T,typename N> bool in_strorder(const H&h,const T&t, const N&n) {return h < t && t < n;}
template<typename H,typename T,typename N,typename S> bool in_order(const H&h,const T&t,const N&n,const S&s){return h<=t&&t<=n&&n<=s;}
template<typename H,typename T,typename N,typename S> bool in_strorder(const H&h,const T&t, const N&n,const S&s){return h<t&&t<n&&n<s;}
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define safar(a, i, o) ((i) >= 0 ? a[i] : (o))
#define safvec(v, i, l, h) ((i) >= 0 ? ((i) < siz(v)?v[i]:h) : l)
template <typename T, typename U> auto my_min(const T & x, const U & y) -> decltype(true?x:y) {if (x < y) return x; return y;}
template <typename T, typename U> auto my_max(const T & x, const U & y) -> decltype(true?x:y) {if (x > y) return x; return y;}
#define make_mins(_) template <typename T, typename U, typename V> auto my_##_(const T& a, const U& b, const V& c) ->\
	decltype(true?a:(true?b:c)) {return my_##_(a, my_##_(b, c));}\
	template <typename T, typename U> U & _##i(U& x, T y) {return x = my_##_(x, y);}\
	template <typename T, typename U, typename V, typename W> auto my_##_(const T& a, const U& b, const V& c, const W&d)\
	->decltype(true?a:(true?b:(true?c:d))){return my_##_(my_##_(a, d), my_##_(b, c));}
make_mins(min) make_mins(max)
template <typename T, typename U, typename V> auto med(const T& a, const U& b, const V& c) -> decltype(true?a:(true?b:c))
	{return my_min(my_max(a, b), my_max(my_min(a, b), c));}
#define pinv(a) MP(a.s, a.f)
#define next __next__Yilw3Q
#define left __left__zLNhrA
#define right __right__BNkEcA
#define prev __prev__Nfq1Zg
#define pow __pow__j4xBnT
#ifdef DEB
const bool deb = true;
#define debug cerr<<"\033[1;"<<30+__LINE__%8<<"m"<<"[LINE:"<<__LINE__<<"] \033[" << 30+(__LINE__/8+__LINE__*3)%8<<"m"<<boolalpha
#else
const bool deb = false;
#define debug if(0) cout
#endif
#define eoln endl << "\033[0m"
#define fs(r) r.f, r.s
#define sf(r) r.s, r.f
#define ei else if
int CON_BOUND = 10;
template <typename T, typename C>ostream & operator<<(ostream &os, pair<T, C> x) {return os << "<" << x.f << ", " << x.s << ">";}
template <typename T> auto operator<<(ostream&os,T x)->typename enable_if<is_same<decltype(x.begin()),decltype(x.end())>::value&&
	!is_same<T, string>::value, ostream &>::type{os << "{";int cou=0;for(auto c:x){if(cou++)os<<", ";os<<c;
	if(cou==CON_BOUND&&siz(x)>CON_BOUND+2){os<<" ... "<<*--x.end();break;}}return os << "}_" << x.size();}
#define cr << "][" << 
#define rr << "] = " << 
#define cc << "[" <<
#define ao << ' ' 
#define br(x) "("<<(x)<<")"
#define name(a) #a << " = " << (a) ao
#define arr(a, i) #a cc #i rr #a cc (i) rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc (i) cr (j) rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc (i) cr (j) cr (k) rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc (i) cr (j) cr (k) cr (q) rr a[i][j][k][q] ao
#define _2arr(a, b, i) #a cc #b cc #i << "]" rr #a cc #b cc (i) << "]" rr #a cc b[i] rr a[b[i]] ao
#define _3arr(a,b,c,i) #a cc #b cc #c cc #i<<"]]" rr #a cc #b cc #c cc (i)<<"]]" rr #a cc #b cc c[i]<<"]" rr #a cc b[c[i]] rr a[b[c[i]]] ao
#define range(a, i, j) #a cc i << ".." << j rr vector <remove_reference<decltype(a[0])>::type>(&a[i], &a[j + 1]) ao
#define arrm(a, i) #a cc #i rr #a cc strmask(i) rr a[i] ao
#define arrmi(a, i, j) #a cc #i cr #j rr #a cc strmask(i) cr(j)rr a[i][j] ao
#define arrim(a, i, j) #a cc #i cr #j rr #a cc(i)cr strmask(j) rr a[i][j] ao
#define arrmm(a, i, j) #a cc #i cr #j rr #a cc strmask(i) cr strmask(j) rr a[i][j] ao
#define arrm3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc strmask(i) cr(j)cr(k)rr a[i][j][k] ao
#define arrm4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc strmask(i) cr(j)cr(k)cr(q)rr a[i][j][k][q] ao
#define oper(a, op, b) br(#a) ao << #op ao <<'('<< #b << ") = (" <<(a)<< ')' ao << #op ao << '(' <<(b)<< ") = " << ((a) op (b))ao
#define tt << "(" <<
#define tn << ", " <<
#define nn << ") = " <<
#define _2fun(f, g, x) #f tt #g tt(#x)<< ")) = " << #f tt #g tt(x)<< ")) = " << #f tt g(x) nn f(g(x)) ao
#define _3fun(f, g, h, x) #f tt #g tt #h tt #x << "))) = " << #f tt #g tt #h tt(x)<< "))) = " \
	<< #f tt #g tt h(x) << ")) = " << #f tt g(h(x)) nn f(g(h(x))) ao
#define arfu(a, f, x) #a cc #f tt #x << ")] = " << #a cc #f tt(x)<< ")] = " << #a cc f(x) rr a[f(x)] ao
#define fuar(f, a, x) #f tt #a cc #x << "]) = " << #f tt #a cc(x)<< "]) = " << #f tt a[x] nn f(a[x]) ao
#define arrop(a, i, op, j) #a cc br(#i)<<#op<<br(#j) rr #a cc br(i) << #op << br(j) rr #a cc i op j rr a[(i) op (j)] ao
#define funop(f, x, op, y) #f tt #x #op #y nn #f tt x << #op << y nn #f tt x op y nn f((x) op (y)) ao
#define arropi(a,i,op,j,k) #a cc br(#i)<<#op<<br(#j) cr #k rr #a cc br(i)<<#op<<br(j) cr k rr	#a cc(i)op(j)cr k rr a[(i)op(j)][k] ao
#define arriop(a,i,j,op,k) #a cc #i cr br(#j)<<#op<<br(#k) rr #a cc(i)cr br(j)<<#op<<br(k) rr	#a cc(i)cr(j)op(k)rr a[i][(j)op(k)] ao
#define arropop(a, i, op, j, k, op2, q) #a cc "("<<#i<<")" #op "("<<#j<<")" cr "("<<#k<<")" #op2 "("<<#q<<")" rr\
	#a cc "("<<i<<")" #op "("<<j<<")" cr "("<<k<<")" #op2 "("<<q<<")" nn #a cc((i)op(j))cr((k)op2(q))nn a[(i)op(j)][(k)op2(q)] ao
#define arroparr(a, i, op, b, j) #a cc #i<<"]"<<#op<<#b cc #j rr #a cc (i)<<"]"<<#op<<#b cc(j)rr a[i] <<#op<< b[j]<<" = "<<(a[i] op b[j])ao
#define funopfun(f, x, op, g, y) #f tt #x<<")"<<#op<<#g tt #y nn #f tt (x)<<")"<<#op<<#g tt(y)nn f(x) <<#op<< g(y)<<" = "<<(f(x) op g(y))ao
#define funoparr(f, x, op, b, j) #f tt #x<<")"<<#op<<#b cc #j rr #f tt (x)<<")"<<#op<<#b cc(j)rr f(x) <<#op<< b[j]<<" = "<<(f(x) op b[j])ao
#define arropfun(a, i, op, g, y) #a cc #i<<"]"<<#op<<#g tt #y nn #a cc (i)<<"]"<<#op<<#g tt(y)nn a[i] <<#op<< g(y)<<" = "<<(a[i] op g(y))ao
#define make_op(op) template <typename A, typename B, typename C, typename D> auto operator op (pair <A, B> x, pair <C, D> y) \
	-> pair <decltype(x.f op y.f), decltype(x.s op y.s)> {return MP(x.f op y.f, x.s op y.s);} \
template <typename A, typename B, typename C> auto operator op (pair <A, B> x, C y) \
	-> pair <decltype(x.f op y), decltype(x.s op y)> {return MP(x.f op y, x.s op y);} \
template <typename A, typename C, typename D> auto operator op (A x, pair <C, D> y) \
	-> pair <decltype(x op y.f), decltype(x op y.s)> {return MP(x op y.f, x op y.s);}
#define make_op2(op) template <typename A, typename B, typename C, typename D> pair <A, B> & operator op(pair<A, B> &x, pair<C, D>y){\
	x.f op y.f; x.s op y.s; return x;} \
template <typename A, typename B, typename C> pair <A, B> & operator op(pair <A, B> &x, C y) {x.f op y; x.s op y; return x;}
#define make_op3(op) template <typename A, typename B> pair <A, B> & operator op(pair <A, B> & x){fs(op x);return x;}\
	template <typename A, typename B> pair <A, B> operator op(pair <A, B> &x, int _){return MP(x.f op, x.s op);}
#define make_op4(op) template <typename A, typename B> auto operator op(pair <A, B> x) -> pair <decltype (op x.f), decltype (op x.s)> \
	{return MP(fs(op x));}
make_op(+) make_op(-) make_op(/) make_op(*) make_op(%) make_op(&) make_op(|) make_op(^) make_op(&&) make_op(||)
make_op2(+=) make_op2(-=) make_op2(*=) make_op2(/=) make_op2(%=) make_op2(^=) make_op2(&=) make_op2(|=)
make_op3(++) make_op3(--)                       make_op4(*) make_op4(~) make_op4(!) make_op4(-) make_op4(&)
template <typename T>string concat(T x) {stringstream os;os << x;return os.str();}
template <typename T, typename ...U>string concat(T x, U... y) {stringstream os;os << x << ", ";return os.str() + concat(y...);}
#define fun(f, ...) #f tt #__VA_ARGS__ nn #f tt concat(__VA_ARGS__) nn f(__VA_ARGS__) ao
template<typename T>string strmask(T r) {string ans;FORD(i,8*sizeof(T)-1,0){if(i%5==4)ans+='.';ans+='0'+!!(((T)1<<i)&r);}return ans;}
#if 0 
ostream&operator<<(ostream&os, __int128_t x){if (x<0){os<<'-';x=-x;}if(x>=10)os<<x/10;return os<<(int)(x%10);}
ostream&operator<<(ostream & os, __uint128_t x){if(x>=10)os<<x/10;return os<<(int)(x%10);}
#endif
#define nmask(a) #a << " = " << strmask(a) ao
const int inf = 1e9;
const LL llinf = 3e18;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,
167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,
587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,
811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int big_primes[] = {1307533217, 1336158883, 1339172111, 1367797777, 1376837461, 1399436671, 1426555723, 1440115249, 1444635091,
	1489833511, 1553111299, 1562150983, 1587763421, 1610362631, 1652547823, 1666107349, 1700759471, 1782116627, 1797182767, 1810742293,
	1818275363, 1892099449, 1904152361, 1919218501, 1940311097, 1944830939, 1968936763, 1977976447, 1985509517, 1990029359};
int gens[]={1,2,3,5,2,11,3,14,19,11,17,32,30,34,29,19,34,31,63,33,5,63,53,58,40,83,21,18,99,33,106,40,85,109,40,77,91,120,105,91,79,53,
182,10,184,48,48,150,168,72,65,46,31,216,101,134,163,147,93,42,69,7,151,308,112,12,227,185,214,305,163,234,154,316,3,11,233,390,271,173,
82,407,13,135,414,391,177,293,426,432,337,281,385,103,95,152,12,371,390,77,532,34,287,73,308,493,258,549,528,411,12,283,614,596,622,309,
91,511,287,433,585,123,2,170,183,341,459,322,333,337,507,718,82,517,396,315,565,48,362,617,776,425,584,231,578,395,127,27,506,435,727,659,
697,385,290,109,430,422,344,849,513,453,852,920,152,482,653,271};
int big_gens[]={661761153,1315209189,235649158,80905954,861543922,677870461,332266749,1192707557,820697698,93737534,1395132003,176849700,
1113502216,860516128,1543755630,328298286,1219407972,1407392293,733053145,400000570,1081174233,847228024,1516266762,83276926,500618997,
44975430,47827763,1411328206,151880843,19696955};
const int MN = 2e5 + 44;
int u[MN];
bool sat[MN];
int find(int x) {
	if (u[x] == x) return x;
	else return u[x] = find(u[x]);
}
bool onion(int a, int b) {
	debug << "onion " << name(a) << name(b) << eoln;
	a = find(a);
	b = find(b);
	debug << "onion " << name(a) << name(b) << eoln;
	if (a == b) {
		debug << "same" << arr(sat, a) << eoln;
		if (sat[a])
			return false;
		else
			return sat[a] = true;
	}
	else {
		if (sat[a] && sat[b]) {
			debug << "both sat" << eoln;
			return false;
		}
		else {
			debug << arr(sat, a) << eoln;
			sat[a] = sat[a] || sat[b];
			u[b] = a;
			return true;	
		}
	}
}
tri(int, int, int) edges[MN];
int main() {
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!  " << range(primes, 6, 9) << fun(med, 66, ~66, 0xd) << eoln;
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) u[i] = i;
	REP(i, m)
		scanf("%d%d%d", &edges[i].s, &edges[i].nd, &edges[i].st);
	sort(edges, edges + m);
	reverse(edges, edges + m);
	LL ans = 0;
	REP(i, m)
		if (onion(edges[i].nd, edges[i].s)) {
			debug << "ans += " << arr(edges, i) << name(edges[i].st) << eoln;
			ans += edges[i].st;
		}
	printf("%lld\n", ans);
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!  " << arropfun(primes, MN % 7, +, log10, MN) << eoln;
}