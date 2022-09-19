//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
//it's nice to stick a fork into an open socket
//clock says it's time to sleep
//our getppid() in heaven, hallowed by ttyname
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
#define FOR(i,b,e)for(urs((b)+(e))i=(b);i<=(e);++i)
#define REP(i,n)for(urs(n)i=0;i<(n);++i)
#define FORD(i,b,e)for(urs((b)+(e))i=(b);i>=(int)(e);--i)
#define UNTIL(t)while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define ALL(r)(r).begin(),(r).end()
#define FS(r)r.first,r.second
#define sim template<class c
#define ros return o
#define rans return ans
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=ctz(i##nvj))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=8*sizeof(m)-clz(i##nxd)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << (k)) - 1); m < ((t)1 << (n)); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
#define pwq(t,i) int clz(t x){return clz<int>(x)-i;}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class cmp=less<c> >using ordered_set=tree<c,null_type,cmp,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#ifdef LOCAL
namespace std {
#include </home/kjp/headers/debuglib.hpp>
};
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#define reg_it(...)
#endif
#define next nexT
#define prev preV
#define left lefT
#define right righT
#define div diV
#define y1 y_1
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
#if ((ULONG_MAX) != (UINT_MAX))
namespace std {template <> struct is_signed<__int128> : public true_type {};}
#endif
#define q31 (8 * sizeof(c) - 1)
sim> typename enable_if<is_signed<c>::value, c>::type FastMax(c x, c y) { return ((x - y) >> q31 & (x ^ y)) ^ x; }
sim> typename enable_if<is_signed<c>::value, c>::type FastMin(c x, c y) { return ((x - y) >> q31 & (x ^ y)) ^ y; }
sim> typename enable_if<is_signed<c>::value, c>::type FastAbs(c x)        { return (x ^ x >> q31) - (x >> q31); }
sim> typename enable_if<is_signed<c>::value, c>::type gcd(c a, c b) {
	loc(assert(a > 0 && b > 0));
	int aa = ctz(a), bb = ctz(b);
	int r = FastMin(aa, bb);
	a >>= aa;
	while (a && b) {
		b >>= ctz(b);
		c x = FastAbs(a - b);
		a = FastMin(a, b);
		b = x;
	}
	return (a + b) << r;
}
sim> c lcm(c a, c b) {return a / gcd(a, b) * b;}
sim>typename enable_if<is_integral<c>::value,ull>::type my_hash(c x){
	if(sizeof(c)>8) return mix((ull)x^SALT)^mix((ull)(x>>64)^SALT);
	return mix(x^SALT);
}
template<size_t N>ull my_hash(const bitset<N>&x){
	return mix(hash<bitset<N>>()(x)^SALT);
}
sim,class n>ull my_hash(const pair<c,n>&);
sim>gyv<ull,typename c::value_type>my_hash(const c&x){
	ull o=SALT;
	for(auto&d:x)o=mix(o^my_hash(d));
	ros;
}
sim,class n>ull my_hash(const pair<c,n>&x){return mix(my_hash(x.first))^my_hash(x.second);}
sim>struct my_hasher{size_t operator()(const c&o)const{return my_hash(o);}};
sim, class m>
#ifdef LOCAL
using _un0rDer3d_M4P=unordered_map<c,m,my_hasher<c>>;
sim> using _un0rDer3d_5et = unordered_set<c, my_hasher<c>>;
#else
struct _un0rDer3d_M4P : public cc_hash_table<c,m,my_hasher<c>>{bool count(const c&x)const{return this->find(x) != this->end();}};
sim> using _un0rDer3d_5et = _un0rDer3d_M4P<c, null_type>;
#endif
#define unordered_map _un0rDer3d_M4P
#define unordered_set _un0rDer3d_5et
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
template <class c> struct Mal : allocator<c> {
	template <class U> struct rebind {
		using other = Mal<U>;
	};
};
template <class...c>
struct Mal<detail::rb_tree_node_<c...> > : allocator<detail::rb_tree_node_<c...> > {
	using pointer = typename Mal::pointer;
	using value_type = typename Mal::value_type;
	pointer allocate(int) {
		pointer ans = (pointer)malloc(sizeof(value_type));
		new (&(*ans).get_metadata()) typename value_type::metadata_type;
		return ans;
	}
	void deallocate(pointer p, int) {
		free(p);
	}
};
struct Sum {
	using value = ll; //typ wyniku dla przedziau
	static value neu() {return 0;}; //element neutralny dziaania
	static value convert(pii x) { //rzutuje typ trzymany w secie/mapie na typ wynikowy (w przypadku mapy para: klucz, warto)
		return x.second;
	}
	static value convert(ll x) { //rzutuje typ trzymany w secie/mapie na typ wynikowy (w przypadku mapy para: klucz, warto)
		return x;
	}
	static value merge(value a, value b) {
		return a + b;
	}
};
template <class c, bool b> struct Baz {
	mutable size_t size;
	mutable c in;
	operator size_t() const {return size;}
	void reset() const {
		size = 1;
	}
	void inc(size_t x) const {
		size += x;
	}
};
template <class c> struct Baz <c, false> {
	mutable c in;
	operator size_t() const {return 0;}
	void reset() const {}
	void inc(size_t) const {}
};
template <class Op, bool ordered> struct Foo {
	template <class... X> struct Bar : tree_order_statistics_node_update<X...> {
		using value = typename Op::value;
		using metadata_type = Baz<value, ordered>;
		void operator()(typename Bar::node_const_iterator node, typename Bar::node_const_iterator end) const {
			node.get_metadata().in = Op::convert(**node);
			node.get_metadata().reset();
			// debug(imie(**node));
			auto l = node.get_l_child();
			if (l != end) {
				node.get_metadata().in = Op::merge(l.get_metadata().in, node.get_metadata().in);
				node.get_metadata().inc(l.get_metadata());
			}
			auto r = node.get_r_child();
			if (r != end) {
				node.get_metadata().in = Op::merge(node.get_metadata().in, r.get_metadata().in);
				node.get_metadata().inc(r.get_metadata());
			}
		}
	};
};
template <class c, class d, class cmp, class Op, bool ordered = false> 
struct seg_map : tree<c, d, cmp, rb_tree_tag, Foo<Op, ordered>::template Bar, Mal<char>> {
	using value = typename Op::value;
	using const_iterator = typename seg_map::const_iterator;
	using node = typename seg_map::node_const_iterator;
	value whole() const {
		return this->empty() ? Op::neu() : this->node_begin().get_metadata().in;
	}
	value read_pref(const_iterator it) const {
		if (it == this->begin()) return Op::neu();
		if (it == this->end()) return whole();
		node n = from_it(it);
		value ans = Op::neu();
		if (n.get_l_child() != this->node_end()) ans = n.get_l_child().get_metadata().in;
		while (n != this->node_begin()) {
			node p = parent(n);
			if (p.get_r_child() == n) {
				ans = Op::merge(Op::convert(**p), ans);
				if (p.get_l_child() != this->node_end())
					ans = Op::merge(p.get_l_child().get_metadata().in, ans);
			}
			n = p;
		}
		return ans;
	}
	value read_suf(const_iterator it) const {
		if (it == this->begin()) return whole();
		if (it == this->end()) return Op::neu();
		it--;
		node n = from_it(it);
		value ans = Op::neu();
		if (n.get_r_child() != this->node_end()) ans = n.get_r_child().get_metadata().in;
		while (n != this->node_begin()) {
			node p = parent(n);
			if (p.get_l_child() == n) {
				ans = Op::merge(ans, Op::convert(**p));
				if (p.get_r_child() != this->node_end())
					ans = Op::merge(ans, p.get_r_child().get_metadata().in);
			}
			n = p;
		}
		return ans;
	}
	//Jeli b > e, to dziaanie jest niezdefiniowane
	value read(const_iterator l, const_iterator r) const {
		if (l == this->begin()) return read_pref(r);
		if (r == this->end()) return read_suf(l);
		l--;
		node b = from_it(l), e = from_it(r);
		value B = Op::neu(), E = Op::neu();
		if (!anc(b, e) && e.get_l_child() != this->node_end()) E = e.get_l_child().get_metadata().in;
		if (!anc(e, b) && b.get_r_child() != this->node_end()) B = b.get_r_child().get_metadata().in;
		int db = dep(b), de = dep(e);
		auto fun_b = [&]() {
			auto bp = parent(b);
			if (bp != e && bp.get_l_child() == b) {
				B = Op::merge(B, Op::convert(**bp));
				if (bp.get_r_child() != this->node_end() && bp.get_r_child() != e)
					B = Op::merge(B, bp.get_r_child().get_metadata().in);
			}
			b = bp;
		};
		auto fun_e = [&]() {
			auto ep = parent(e);
			if (ep != b && ep.get_r_child() == e) {
				E = Op::merge(Op::convert(**ep), E);
				if (ep.get_l_child() != this->node_end() && ep.get_l_child() != b) {
					E = Op::merge(ep.get_l_child().get_metadata().in, E);
				}
			}
			e = ep;
		};
		if (db > de) for (int i = 0; i < db - de; ++i) fun_b();
		if (db < de) for (int i = 0; i < de - db; ++i) fun_e();
		while (b != e) {
			fun_b();
			fun_e();
		}
		return Op::merge(B, E);
	}
	node parent(node x) const {
		return {x.m_p_nd->m_p_parent};
	}
	node from_it(const_iterator x) const {
		return {x.m_p_nd};
	}
	int dep(node x) const {
		int ans = 0;
		while (x != this->node_begin()) {
			ans++;
			x = parent(x);
		}
		return ans;
	}
	bool anc(node x, node y) const {
		while (true) {
			if (x == y) return true;
			if (x == this->node_begin()) return false;
			x = parent(x);
		}
	}
	template <class Fun> const_iterator get_right(const_iterator beg, Fun pred) const {
		
	}
	template <class Fun> const_iterator get_left(const_iterator end, Fun pred) const {
		
	}
	//jeli wartoci agregowane zale od typu ta ktry jest mapowanie, to po kadej edycji wartoci, ktra ju jest w mapie naley wywoa
	void update(const_iterator pos) { 
		node n = from_it(pos);
		// debug(imie(**n));
		while (true) {
			seg_map::node_update::operator()(n, this->node_end());
			if (n == this->node_begin()) break;
			n = parent(n);
		}
	}
	void dfs(ostream &o, node n, int dep) {
		if (n == this->node_end()) return;
		dfs(o, n.get_l_child(), dep + 1);
		REP(_, dep) o << "   ";
		o << **n << "\t" << n.get_metadata().in << "\n";
		dfs(o, n.get_r_child(), dep + 1);
	}
	string get_shape() {
		stringstream o;
		o << "\n";
		dfs(o, this->node_begin(), 0);
		ros.str();
	}
};
template <class c, class cmp, class Op, bool ordered = false> using seg_set = seg_map<c, null_type, cmp, Op, ordered>;
int main() {
	seg_set<int, less <int>, Sum, true> seg;
	int n;
	scanf("%d", &n);
	vpii vec(n);
	REP(i, n) scanf("%d", &vec[i].second);
	REP(i, n) scanf("%d", &vec[i].first);
	sort(ALL(vec));
	debug(imie(vec));
	ll ans = 0;
	for (auto [_, x] : vec) {
		auto it = seg.lower_bound(x);
		int less = seg.order_of_key(x);
		ans += x * 1ll * less - seg.read(seg.begin(), it);
		debug(range(seg.begin(), it));
		seg.insert(x);
	}
	printf("%lld\n", ans);
}