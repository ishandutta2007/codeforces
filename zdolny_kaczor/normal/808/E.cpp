#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
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
template<typename H,typename T,typename N>bool diff(const H &h,const T& t,const N&n){return h!=t&&h!=n&&t!= n;}
template<typename H,typename T,typename N,typename S>bool diff(const H &h,const T &t,const N &n,const S &s)
	{return h!=t&&h!=n&&h!=s&&t!=n&&t!=s&&n!=s;}
template<typename H,typename T,typename N>bool in(const H &h,const T& t,const N& n) {return h==t||h==n;}
template<typename H,typename T,typename N,typename S> bool in(const H &h,const T &t,const N &n,const S &s) {return h==t||h==n||h==s;}
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
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
const bool deb = 
#ifdef DEB
true;
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
false;
#define debug if(0) cout
#endif
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
#define name(a) #a << " = " << (a) ao
#define arr(a, i) #a cc #i rr #a cc i rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q] ao
#define _2arr(a, b, i) #a cc #b cc #i << "]" rr #a cc #b cc i << "]" rr #a cc b[i] rr a[b[i]] ao
#define _3arr(a,b,c,i) #a cc #b cc #c cc #i<<"]]" rr #a cc #b cc #c cc i<<"]]" rr #a cc #b cc c[i]<<"]" rr #a cc b[c[i]] rr a[b[c[i]]] ao
#define range(a, i, j) #a cc i << ".." << j rr vector <remove_reference<decltype(a[0])>::type>(&a[i], &a[j + 1]) ao
#define arrm(a, i) #a cc #i rr #a cc strmask(i) rr a[i] ao
#define arrmi(a, i, j) #a cc #i cr #j rr #a cc strmask(i) cr j rr a[i][j] ao
#define arrim(a, i, j) #a cc #i cr #j rr #a cc i cr strmask(j) rr a[i][j] ao
#define arrmm(a, i, j) #a cc #i cr #j rr #a cc strmask(i) cr strmask(j) rr a[i][j] ao
#define arrm3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc strmask(i) cr j cr k rr a[i][j][k] ao
#define arrm4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc strmask(i) cr j cr k cr q rr a[i][j][k][q] ao
#define oper(a, op, b) '(' << #a<<')' ao << #op ao <<'('<< #b << ") = (" << a << ')' ao << #op ao << '(' << b << ") = " << ((a) op (b))ao
#define tt << "(" <<
#define tn << ", " <<
#define nn << ") = " << 
#define _2fun(f, g, x) #f tt #g tt #x << ")) = " << #f tt #g tt x << ")) = " << #f tt g(x) nn f(g(x)) ao
#define _3fun(f, g, h, x) #f tt #g tt #h tt #x << "))) = " << #f tt #g tt #h tt x << "))) = " \
	<< #f tt #g tt h(x) << ")) =i " << #f tt g(h(x)) nn f(g(h(x))) ao
#define arfu(a, f, x) #a cc #f tt #x << ")] = " << #a cc #f tt x << ")] = " << #a cc f(x) rr a[f(x)] ao
#define fuar(f, a, x) #f tt #a cc #x << "]) = " << #f tt #a cc x << "]) = " << #f tt a[x] nn f(a[x]) ao
#define arrop(a, i, op, j) #a cc #i #op #j rr #a cc i #op j rr #a cc i op j rr a[(i) op (j)] ao
#define funop(f, x, op, y) #f tt #x #op #y nn #f tt x #op y nn #f tt x op y nn f((x) op (y)) ao
#define arropi(a,i,op,j,k) #a cc "("<<#i<<")"<<#op<<"("<<#j<<")" cr #k rr #a cc "("<<i<<")"<<#op<<"("<<j<<")" cr k rr\
	#a cc(i)op(j)cr k rr a[(i)op(j)][k] ao
#define arriop(a,i,j,op,k) #a cc #i cr "("<<#j<<")"<<#op<<"("<<#k<<")" rr #a cc i cr "("<<j<<")"<<#op<<"("<<k<<")" rr\
	#a cc i cr(j)op(k)rr a[i][(j)op(k)] ao
#define arropop(a, i, op, j, k, op2, q) #a cc "("<<#i<<")" #op "("<<#j<<")" cr "("<<#k<<")" #op2 "("<<#q<<")" rr\
	#a cc "("<<i<<")" #op "("<<j<<")" cr "("<<k<<")" #op2 "("<<q<<")" nn #a cc((i)op(j))cr((k)op2(q))nn a[(i)op(j)][(k)op2(q)]
#define arroparr(a, i, op, b, j) #a cc #i<<"]"<<#op<<#b cc #j rr #a cc i <<"]"<<#op<<#b cc j rr a[i] <<#op<< b[j]<<" = "<<(a[i] op b[j])ao
#define funopfun(f, x, op, g, y) #f tt #x<<")"<<#op<<#g tt #y nn #f tt x <<")"<<#op<<#g tt y nn f(x) <<#op<< g(y)<<" = "<<(f(x) op g(y))ao
#define funoparr(f, x, op, b, j) #f tt #x<<")"<<#op<<#b cc #j rr #f tt x <<")"<<#op<<#b cc j rr f(x) <<#op<< b[j]<<" = "<<(f(x) op b[j])ao
#define arropfun(a, i, op, g, y) #a cc #i<<"]"<<#op<<#g tt #y nn #a cc i <<"]"<<#op<<#g tt y nn a[i] <<#op<< g(y)<<" = "<<(a[i] op g(y))ao
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
make_op3(++) make_op3(--)
make_op4(*) make_op4(~) make_op4(!) make_op4(-) make_op4(&)
template <typename T>string concat(T x) {stringstream os;os << x;return os.str();}
template <typename T, typename ...U>string concat(T x, U... y) {stringstream os;os << x << ", ";return os.str() + concat(y...);}
#define fun(f, ...) #f tt #__VA_ARGS__ nn #f tt concat(__VA_ARGS__) nn f(__VA_ARGS__) ao
template<typename T>string strmask(T r) {string ans;REP(i,8*(int)sizeof(T)){ans+='0'+!!(((T)1<<i)&r);if(i%5==4)ans+='.';}return ans;}
#if 0 
ostream&operator<<(ostream&os, __int128_t x){if (x<0){os<<'-';x=-x;}if(x>=10)os<<x/10;return os<<(int)(x%10);}
ostream&operator<< (ostream & os, __uint128_t x){if(x>=10)os<<x/10;return os<<(int)(x%10);}
#endif
#define nmask(a) #a << " = " << strmask(a) ao
const int MN = 1e5 + 44;
VI obj[4];
LL best[MN * 3];
LL inf = 1e18;
int main() {
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n) {
		int w, c;
		scanf("%d%d", &w, &c);
		obj[w].PB(c);
	}
	FOR(i, 1, 3) {
		sort(ALL(obj[i]));
		reverse(ALL(obj[i]));
	}
	int s1 = siz(obj[1]), s2 = siz(obj[2]), i = 0, j = 0;
	REP(_, 5)
		FOR(i, 1, 2)
			obj[i].PB(0);
	debug << name(obj[1]) << name(obj[2]) << endl;
	int total = 0;
	LL sum = 0;
	while (i < s1 || j < s2) {
		LL sum1[4], sum2[4];
		LL sub1[4], sub2[4];//ile dodaj jak zabieram 1, 2, 3 (czyli -warto)
		sum1[0] = sum2[0] = sub1[0] = sub2[0] = 0;
		REP(x, 3) {
			sum1[x + 1] = sum1[x] + obj[1][i + x];
			sum2[x + 1] = sum2[x] + obj[2][j + x];
		}
		FOR(x, 1, 3) {
			sub1[x] = sub1[x - 1] - (i - x >= 0 ? obj[1][i - x] : inf);
			sub2[x] = sub2[x - 1] - (j - x >= 0 ? obj[2][j - x] : inf);
		}
		debug << name(i) << name(j) << name(total) << name(sum) << endl;
		debug << range(sum1, 0, 3) << range(sub1, 0, 3) << range(sum2, 0, 3) << range(sub2, 0, 3) << endl;
		FOR(x, -3, 3)
			FOR(y, -3, 3) {
				if (total + x + 2 * y >= 0) {
					maxi(best[total + x + 2 * y], sum + (x > 0 ? sum1[x] : sub1[-x]) + (y > 0 ? sum2[y] : sub2[-y]));
				}
			}
		if (obj[1][i] * 2 > obj[2][j]) {
			sum += obj[1][i];
			i++;
			total++;
		}
		else {
			sum += obj[2][j];
			j++;
			total += 2;
		}
		debug << range(best, 0, m) << endl;
	}
	REP(i, m)
		maxi(best[i + 1], best[i]);
	CON_BOUND = 30;
	debug << name(obj[1]) << name(obj[2]) << endl;
	debug << range(best, 0, m) << endl;
	sum = 0;
	total = 0;
	LL ans = best[m];
	for (int x : obj[3]) {
		total += 3;
		sum += x;
		if (total > m)
			break;
		maxi(ans, best[m - total] + sum);
	}
	printf("%lld\n", ans);
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}