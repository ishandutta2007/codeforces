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
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#ifdef LOCAL
#include </home/kjp/headers/debuglib.hpp>
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
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}sim>c gcd(c o,c b){while(o&&b){int x=ctz(o),y=ctz(b);if(x>y)o>>=x-y;else b>>=y-x;if(o>b)o-=b;else b-=o;}ros?o:b;}sim>c lcm(c o,c b){ros/gcd(o,b)*b;}
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
#else
struct _un0rDer3d_M4P : public cc_hash_table<c,m,my_hasher<c>>{bool count(const c&x)const{return this->find(x) != this->end();}};
#endif
#define unordered_map _un0rDer3d_M4P
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
const int nax = 101;
namespace interactor {
	int n;
	loc(char str[nax];)
	vector <string> query(int l, int r) {
		assert(1 <= l && l <= r && r <= n);
		int len = r - l + 1;
		static int q_cou = 0, a_cou = 0;
		int curr = len * (len + 1) / 2;
		a_cou += curr;
		q_cou++;
		assert(a_cou <= ((n + 1) * (n + 1) * 777 + 999) / 1000);
		assert(q_cou <= 3);
		vector <string> ans;
		#ifdef LOCAL
			debug(string(str + l - 1, str + r));
			for (int i = l; i <= r; ++i)
				for (int j = i; j <= r; ++j)
					ans.emplace_back(str + i - 1, str + j);
			random_shuffle(ALL(ans));
			for (auto &x : ans) random_shuffle(ALL(x));
		#else
			printf("\? %d %d\n", l, r);
			fflush(stdout);
			REP(_, curr) {
				static char sub[nax];
				scanf("%s", sub);
				ans.emplace_back(sub);
			}
		#endif
		rans;
	}
	void answer(const char *ans) {
		loc(assert(strcmp(ans, str) == 0));
		assert((int)strlen(ans) == n);
		printf("! %s\n", ans);
		exit(0);
	}
};
const int A = 26;
ull charhash[A];
struct BT {
	BT(int _len, vector <string> whole) : len(_len) {
		for (string &s : whole) {
			ull v = 0;
			for (char c : s) v += charhash[c - 'a'];
			sums[s.size()][v]++;
		}
		psum[len] = sums[len].begin()->first;
	}
	int len;
	vector <string> poss;
	char gen[nax];
	ull psum[nax];
	map <ull, int> sums[nax];
	bool rem(int i, int j) {
		if (i > j) swap(i, j);
		assert(i != j);
		// debug("try", range(gen, 0, i), range(gen, i, j), range(gen, j, len));
		auto it = sums[j - i].find(psum[j] - psum[i]);
		if (it == sums[j - i].end() || it->second == 0) {
			// debug("fail");
			return false;
		}
		// debug("succeed");
		it->second--;
		return true;
	}
	void undo(int i, int j) {
		if (i > j) swap(i, j);
		assert(i != j);
		// debug("undo", range(gen, 0, i), range(gen, i, j), range(gen, j, len));
		sums[j - i][psum[j] - psum[i]]++;
	}
	int get_p(int x) {
		return x & 1 ? len - (x >> 1) - 1 : (x >> 1);
	}
	int get_pref(int x) {
		return x & 1 ? len - (x >> 1) : (x >> 1);
	}
	void bt(int x) {
		int p = get_p(x);
		if (x == len - 1) {
			ull diff = psum[p + 1] - psum[p];
			int a = -1;
			REP(i, A) if (charhash[i] == diff) a = i;
			assert(a != -1);
			gen[p] = a + 'a';
			debug(gen);
			poss.emplace_back(gen);
		}
		else {
			REP(c, A) {
				gen[p] = c + 'a';
				int did = -1;
				if (x & 1) {
					psum[p] = psum[p + 1] - charhash[c];
					did = p;
				}
				else {
					psum[p + 1] = psum[p] + charhash[c];
					did = p + 1;
				}
				int rev = -1;
				REP(i, x + 2) {
					int v = get_pref(i);
					if (!rem(did, v)) {
						rev = i;
						break;
					}
				}
				if (rev == -1) bt(x + 1);
				REP(i, x + 2) {
					if (i == rev) break;
					int v = get_pref(i);
					undo(did, v);
				}
			}
		}
	}
	const vector <string> &get() {
		bt(0);
		assert(poss.size() <= 2u);
		return poss;
	}
};
vector <pii> ranges;
vector <ull> hashes(string x) {
	static ull prefs[nax];
	static ull rsum[nax][nax];
	int n = x.size();
	prefs[0] = 0;
	REP(i, n) prefs[i + 1] = prefs[i] + charhash[x[i] - 'a'];
	memset(rsum, 0, sizeof(rsum));
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			rsum[i][j] = mix(prefs[j + 1] - prefs[i]);
	auto get = [&](int i, int j) -> ull {
		if (i == 0 || j == 0) return 0;
		return rsum[i - 1][j - 1];
	};
	REP(i, nax) REP(j, nax - 1) rsum[i][j + 1] += rsum[i][j];
	REP(j, nax) REP(i, nax - 1) rsum[i + 1][j] += rsum[i][j];
	vector <ull> ans;
	for (auto [l, r] : ranges) {
		ull a = get(r + 1, r + 1) - get(r + 1, l) - get(l, r + 1) + get(l, l);
		#ifdef LOCAL
			// ull bru = 0;
			// for (int i = l; i <= r; ++i) for (int j = i; j <= r; ++j) {
				// ull s = 0;
				// for (int p = i; p <= j; ++p)
					// s += charhash[x[p] - 'a'];
				// bru += mix(s);
			// }
			// assert(a == bru);
			// debug(imie(a), imie(bru));
		#endif
		ans.push_back(a);
	}
	rans;
}
int main() {
	//init
	REP(i, A)
		charhash[i] = mix(i);
	int n;
	scanf("%d", &n);
	interactor::n = n;
	loc(scanf("%s", interactor::str));
	//solve
	if (n == 1) {
		interactor::answer(interactor::query(1, 1)[0].c_str());
	}
	// debug(BT(n, query(1, n)).get());
	int h = n / 2;
	vector <string> left = BT(h, interactor::query(1, h)).get(), right = BT(n - h, interactor::query(h + 1, n)).get();
	debug(imie(left), imie(right));
	vector <string> cans;
	for (const string &a : left)
		for (const string &b : right)
			cans.push_back(a + b);
	debug(imie(cans));
	FOR(i, 0, n - 2) FOR(j, i, n - 2) ranges.emplace_back(i, j);
	debug(ranges);
	vector <vector <ull> > H;
	REP(i, cans.size())
		H.push_back(hashes(cans[i]));
	int r = ranges.size();
	REP(i, r) {
		set <ull> s;
		REP(j, cans.size())
			s.insert(H[j][i]);
		if (s.size() == cans.size()) {
			auto a = interactor::query(ranges[i].first + 1, ranges[i].second + 1);
			ull got = 0;
			for (const string &s : a) {
				ull curr = 0;
				for (char c : s)
					curr += charhash[c - 'a'];
				got += mix(curr);
			}
			REP(j, cans.size())
				if (H[j][i] == got)
					interactor::answer(cans[j].c_str());
			assert(false);
		}
	}
	assert(false);
}