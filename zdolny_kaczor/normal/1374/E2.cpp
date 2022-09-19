//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
//#STAY AT HOME
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#define TIME (chrono::steady_clock::now().time_since_epoch().count())
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define xfm(a,b)a##b
#define xwb(a,b)xfm(a,b)
#define _ xwb(nvj,__LINE__)
#define __ xwb(kjy,__LINE__)
#define ___ xwb(cjm,__LINE__)
#define REP(i,n)for(urs(n)i=0;i<(n);++i)
#define UNTIL(t)while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define ALL(r)(r).begin(),(r).end()
#define RALL(r)(r).rbegin(),(r).rend()
#define FS(r)r.first,r.second
#define SF(r)r.second,r.first
#define M0(r) memset(r, 0, sizeof(r))
#define sim template<class c
#define ros return o
#define rans return ans
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=ctz(i##nvj))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=8*sizeof(m)-clz(i##nxd)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << (k)) - 1); m < ((t)1 << (n)); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
#define pwq(t,i) int clz(t x){return clz<int>(x)-i;}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using vll=vector<ll>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using spii=set<pii>;using mii=map<int,int>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class b,class cmp=less<c> >using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim, class cmp=less<c>>using ordered_set = ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#if defined(LOCAL) // || defined(LOCAL2)
#include </home/kjp/headers/debuglib.hpp>
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#define reg_it(...)
#define def_op(...) struct _{};
#if !defined(LOCAL) && !defined(LOCAL2)
#define exit my_exit
void my_exit(int x) {fflush(stdout);_Exit(x);}
#endif
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
#define pow do not use cmath pow unless you know what you are doing
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;ros;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=(ll)(a*(ld)b/m);ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
#pragma GCC diagnostic pop
#if ((ULONG_MAX) != (UINT_MAX))
namespace std {template <> struct is_signed<__int128> : public true_type {};}
#endif
sim, class d> typename common_type<c,d>::type floor_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using floor_div with different signedness");if (b < 0) b = -b, a = -a;return a / b - (a % b < 0);}
sim, class d> typename common_type<c,d>::type ceil_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using ceil_div with different signedness");if (b < 0) b = -b, a = -a;return a / b + (a % b > 0);}
sim> struct REV {using value_type=typename c::value_type;c &x;using it=typename c::reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> struct CREV {using value_type=typename c::value_type;const c&x;using it=typename c::const_reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> REV<c> reversed(c&x) {return REV<c>{x};}sim> CREV<c> reversed(const c&x) {return CREV<c>{x};}
#define done(r...) exit(0 * printf(r))
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << setprecision(6) << fixed << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
//#STAY AT HOME
#undef tree
#define root this->node_begin()
#define none this->node_end()
#define V get_metadata().in
#define L get_l_child()
#define R get_r_child()
//struct Mal potrzebny tylko jesli Op::T ma nietrywialny konstruktor
	template <class c> struct Mal : allocator<c> {
		template <class U> struct rebind { using other = Mal<U>; };
	};
	template <class...c> struct Mal<detail::rb_tree_node_<c...> > :
	allocator<detail::rb_tree_node_<c...> > {
		using v = typename Mal::value_type;
		v* allocate(int) {
			v* ans = allocator<v>::allocate(1);
			new (&ans->get_metadata()) typename v::metadata_type;
			return ans;
		}
	};
//Jesli nie potrzebujemy find_by_order i order_of_key, to wystarczy:
//	template <class c> struct Baz {mutable c in;};
//i wszedzie dalej pomijamy parametr bool ord, oraz w update wyroznione linie
	template <class c, bool b> struct Baz {
		mutable int size;
		mutable c in;
		operator int() const {return size;}
		void reset() const {size = 1;}
		void inc(int x) const {size += x;}
	};
	template <class c> struct Baz <c, 0> {
		mutable c in;
		void reset() const {}
		void inc(const Baz&) const {}
	};
template <class Op, bool ord> struct Foo {
//W C++11/14 trzeba: template <class A, class B, class C, class D> struct Bar : tree_order_statistics_node_update<A,B,C,D> {
	template <class... X> struct Bar : tree_order_statistics_node_update<X...> {
		using T = typename Op::T;
		using metadata_type = Baz<T, ord>;
		template <class c, class d> void operator()(c n, d end) const {
			n.V = Op::conv(**n);
			n.get_metadata().reset(); //Tylko jak potrzebujemy ordered_seta
			auto l = n.L, r = n.R;
			if (l != end) {
				n.V = Op::mer(l.V, n.V);
				n.get_metadata().inc(l.get_metadata()); //j.w.
			}
			if (r != end) {
				n.V = Op::mer(n.V, r.V);
				n.get_metadata().inc(r.get_metadata()); //j.w.
			}
		}
	};
};
template <class c, class k, class Op, class cmp = less<c>, bool ord = false> 
struct seg_map : tree<c, k, cmp, rb_tree_tag, Foo<Op, ord>::template Bar, Mal<c>> { //Jesli nie uzywamy structa Mal, to po prostu pomijamy ostatni parametr
	using T = typename Op::T;    using C = typename seg_map::const_iterator;
	using N = typename seg_map::node_const_iterator;
	T mer(const T&a, const T&b, bool d) const { return d ? Op::mer(a, b) : Op::mer(b, a); }
	N go(N n, bool d) const {return d ? n.R : n.L;}
	T whole() const { return this->empty() ? Op::neu() : root.V; }
	T read(C it, bool d) const {
		N n = from_it(it);
		T ans = Op::neu();
		if (go(n, d) != none) ans = go(n, d).V;
		while (n != root) {
			N p = P(n);
			if (go(p, !d) == n) {
				ans = mer(ans, Op::conv(**p), d);
				if (go(p, d) != none) ans = mer(ans, go(p, d).V, d);
			}
			n = p;
		}
		return ans;
	}
	T read_pref(C it) const {//[begin, it)
		if (it == this->begin()) return Op::neu();
		if (it == this->end()) return whole();
		return read(it, 0);
	}
	T read_suf(C it) const {//[it, end)
		if (it == this->begin()) return whole();
		if (it == this->end()) return Op::neu();
		return read(--it, 1);
	}
//Dla l > r wynik jest nieokreslony, ale wykona sie w O(log n) i nie bedzie RE
	T read(C l, C r) const { //[l, r)
		if (l == this->begin()) return read_pref(r);
		if (r == this->end()) return read_suf(l);
		N b = from_it(--l), e = from_it(r);
		T B = Op::neu(), E = Op::neu();
		if (!anc(b, e) && e.L != none) E = e.L.V;
		if (!anc(e, b) && b.R != none) B = b.R.V;
		int d = dep(b) - dep(e);
		while (b != e) {
			bool D = d > 0;
			D ? d-- : d++;
			N &m = D ? b : e, &o = D ? e : b;
			T &v = D ? B : E;
			N p = P(m);
			if (p != o && go(p, !D) == m) {
				v = mer(v, Op::conv(**p), D);
				N u = go(p, D);
				if (u != none && u != o) v = mer(v, u.V, D);
			}
			m = p;
		}
		return mer(B, E, 1);
	}
	N P(N x) const {return {x.m_p_nd->m_p_parent};}
	N from_it(C x) const {return {x.m_p_nd};}
	int dep(N x) const {
		int ans = 0;
		while (x != root) {
			ans++;
			x = P(x);
		}
		return ans;
	}
	bool anc(N x, N y) const {
		for (;;) {
			if (x == y) return 1;
			if (x == root) return 0;
			x = P(x);
		}
	}
	template <class Fun> C get_side(C it, Fun pred, bool dir) const {
		T acc = Op::neu();
		N n = from_it(it);
		for (;;) {
			acc = mer(acc, **n, dir);
			if (!pred(acc)) return dir ? *n : ++*n;
			if (go(n, dir) != none) {
				T t1 = mer(acc, go(n, dir).V, dir);
				if (pred(t1)) acc = t1;
				else {
					n = go(n, dir);
					for (;;) {
						if (go(n, !dir) != none) {
							T t2 = mer(acc, go(n, !dir).V, dir);
							if (!pred(t2)) {
								n = go(n, !dir);
								continue;
							}
							acc = t2;
						}
						acc = mer(acc, **n, dir);
						if (!pred(acc)) return dir ? *n : ++*n;
						n = go(n, dir);
					}
				}
			}
			for (;;) {
				if (n == root) return dir ? this->end() : this->begin();
				N p = P(n);
				if (go(p, !dir) == n) {
					n = p;
					break;
				}
				n = p;
			}
		}
	}
//Zwraca najdalszy it taki, ze pred(read(beg, it)), lub it = beg, jesli takiego nie ma. Zaklada, ze jesli jakis przedzial spelnia pred, to jego podprzedzial tez
	template <class Fun> C get_right(C beg, Fun pred) const {
		if (beg == this->end()) return beg;
		return get_side(beg, pred, 1);
	}
	template <class Fun> C get_left(C end, Fun pred) const { //j.w, tylko z read(it, end)
		if (end == this->begin()) return end;
		return get_side(--end, pred, 0);
	}
//Jesli wartosci agregowane zaleza od typu ta ktory jest mapowanie, to po kazdej edycji wartosci (takze wrzuceniu nowej) nalezy wywolac update lub po wszystkich edycjach wywolac update_all
	void update(C pos) { 
		N n = from_it(pos);
		for (;;) {
			seg_map::node_update::operator()(n, none);
			if (n == root) break;
			n = P(n);
		}
	}
	void dfs(N n) {
		if (n == none) return;
		dfs(n.L); dfs(n.R);
		seg_map::node_update::operator()(n, none);
	}
	void update_all() { dfs(root); }
	template <class it> void insert_range(it b, it e) {
		for (it i = b; i != e; ++i) this->insert(*i);
	}
};
template <class c, class Op, class cmp=less<c>, bool ord = false>
using seg_set = seg_map<c, null_type, Op, cmp, ord>;
struct Sum { //Przykladowy typ definiujacy operacje
	using T = ll; //typ wyniku dla przedzialu
	static T neu() {return 0;}; //element neutralny dzialania
//rzutuje typ wartosci na typ wynikowy (w przypadku mapy para: klucz, wartosc)
	static T conv(pii x) { return x.first; }
	static T mer(T a, T b) {return a + b;}
};
//Zeby sie skompilowalo z flaga -D_GLIBCXX_DEBUG, to typ trzymany w kontenerze (tylko typ klucza dla mapy) musi miec zdefiniowany operator<<(ostream &, nasz_typ), przy czym, jesli ten typ jest w namespace std, to operator tez musi byc. 
#undef none
void solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vpii common, alice, bob, none;
	for (int i = 1; i <=n; ++i) {
		int a, b, t;
		scanf("%d%d%d", &t, &a, &b);
		if (a && b) common.emplace_back(t, i);
		else if (a) alice.emplace_back(t, i);
		else if (b) bob.emplace_back(t, i);
		else none.emplace_back(t, i);
	}
	seg_set<pii, Sum, less<pll>, true> candidates;
	auto fix = [&](vpii &a) {
		sort(ALL(a));
		a.resize(m, pii(numeric_limits<int>::max(), -1));
	};
	fix(alice);
	fix(bob);
	fix(none);
	fix(common);
	debug(imie(alice));
	debug(imie(bob));
	debug(imie(none));
	debug(imie(common));
	pair <ll, int> ans = {numeric_limits<ll>::max(), -1};
	candidates.insert_range(alice.begin() + k, alice.end());
	candidates.insert_range(bob.begin() + k, bob.end());
	candidates.insert_range(none.begin(), none.end());
	candidates.insert_range(common.begin() + k, common.end());
	ll sum = 0;
	REP(i, k) sum += alice[i].first;
	REP(i, k) sum += bob[i].first;
	for (int x = 0; x <= k; ++x) {
		if (x != 0) {
			sum += common[x - 1].first;
			sum -= alice[k - x].first;
			sum -= bob[k - x].first;
			candidates.insert(alice[k - x]);
			candidates.insert(bob[k - x]);
		}
		int rest_cou = m - x - 2 * (k - x);
		if (rest_cou >= 0 && rest_cou <= (int) candidates.size()) {
			auto it = candidates.find_by_order(rest_cou);
			ll rest_val = candidates.read(candidates.begin(), it);
			ll total = sum + rest_val;
			debug(range(candidates.begin(), it), imie(rest_val), imie(total), imie(x));
			mini(ans, make_pair(total, x));
		}
	}
	if (ans.second == -1 || ans.first >= 2100000000ll) {
		printf("-1\n");
	}
	else {
		printf("%lld\n", ans.first);
		int x = ans.second;
		REP(i, x) printf("%d ", common[i].second);
		REP(i, k - x) printf("%d ", alice[i].second);
		REP(i, k - x) printf("%d ", bob[i].second);
		int rest_cou = m - x - 2 * (k - x);
		assert(rest_cou >= 0);
		vpii rest_val;
		rest_val.insert(rest_val.end(), common.begin() + k, common.end());
		rest_val.insert(rest_val.end(), ALL(none));
		rest_val.insert(rest_val.end(), alice.begin() + k - x, alice.end());
		rest_val.insert(rest_val.end(), bob.begin() + k - x, bob.end());
		nth_element(rest_val.begin(), rest_val.begin() + rest_cou, rest_val.end());
		REP(i, rest_cou) printf("%d ", rest_val[i].second);
		printf("\n");
	}
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME