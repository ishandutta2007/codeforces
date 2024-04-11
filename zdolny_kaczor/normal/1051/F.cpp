//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#define TIME (chrono::steady_clock::now().time_since_epoch().count())
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define xfm(a, b) a##b
#define xwb(a,b) xfm(a,b)
#define _ xwb(nvj, __LINE__)
#define FOR(i,b,e) for(urs((b)+(e)) i=(b);i<=(e);++i)
#define REP(i,n) for(urs(n)i=0; i<(n);++i)
#define FORD(i,b,e) for(urs((b)+(e))i=(b);i>=(int)(e);--i)
#define UNTIL(t) while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...) for(bool _=1;_||next_permutation(r);_=false)
#define ALL(r) (r).begin(),(r).end()
#define FS(r) r.first,r.second
#define sim template <class c
#define ros return o
#define rans return ans
#define forbits(i, m) if(m)for(urs(m)i=ctz(m), _ = m;_;_^=((urs(m))1<<i),i=ctz(_)) 
#define fordbits(i, m) if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,_=m;_;_^=((urs(m))1<<i),i=8*sizeof(m)-clz(_)-1)
#define urs(r...) typename decay<decltype(r)>::type
#define hur(f,g) sim>int f(c a){if(sizeof(c)==8)return g##ll(a);return g(a);}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount)hur(ctz,__builtin_ctz)hur(clz,__builtin_clz)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}
#ifdef LOCAL
#define loc(r...) r
#define onl(r...)
#define azm(r) sim,class n>pair<bool,n>emz(r<c,n>a,ll b){if(a.count(b))return{1,a[b]};return{0,n()};}
#define yvd(r...) pair<bool,urs(r()[0])>emz(const r&a,ll b){if(b>=0&&b<(ll)a.size())return{1,a[b]};return{0,typename r::value_type()};}
#define oor >ostream &operator<<(ostream &o,
#define bnt ;}sim> struct
#define debug(c...)::dor(1,vqx(__LINE__,__FUNCTION__),c)
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
#define g(o) template<zub(o, v o u, N) tfj(bte(*this)) + " " #o " " + tfj(bte(u)), m);}
sim>c&lum(c&o){ros;}int lum(int8_t o){ros;}unt lum(uint8_t o){ros;}int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>yvd(vector<c>)sim>yvd(deque<c>)sim,size_t N>yvd(array<c,N>)yvd(string)sim>pair<bool,typename std::decay<c>::type>emz(c*a,ll b){return {1,a[b]};}template<size_t n>pair<bool,bool>emz(bitset<n>a,ll b){if(b>=0&&b<(ll)n)return{1,a[b]};return{0,0};}string tfj(string o){for(char x:o)if(x=='=')return "("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"#"<<l<<": \033["<<30+l%7+(l%7>=l%8)<<"m";ros.str();}ostream&operator<<(ostream&o,__int128 x){int D[50],c=0;if(x<0)o<<"-",x=-x;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__uint128_t x){int D[50],c=0;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__float128 x){ros<<(ld)x;}sim,class N oor pair<c,N>u){ros<<"<"<<lum(u.first)<<", "<<lum(u.second)<<">";}sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<lum(e);ros<<"}_"<<q;}void dor(bool x){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(int w,c x,N...y){cerr<<setprecision(uuv)<<boolalpha<<x<<"; "+2*w;dor(0,y...);}sim>string bte(c u){stringstream o;o<<setprecision(uuv)<<boolalpha<<lum(u);ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}sim>c yyo(nep<c>o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
#undef g
#define ckx(o) template<zub(o, o yyo(u), nep<N>) #o+tfj(bte(u)), u.m);}
#define g(o) sim,zub(o,yyo(p) o u.v,c p,nep<N>) tfj(bte(p))+" " #o " "+tfj(bte(u)),uhn(p)+u.m);}
#define ccy(r...) sim> class enable_if<r is_integral<c>::value,string>::type ema(c u){
ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>M.q||M.r>M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r+1,1);FOR(i,M.p,M.q){maxi(l,(int)bte(i).size());auto V=emz(M.x,i);X.emplace_back();if(V.first)FOR(j,M.r,M.s){auto Q=emz(V.second,j);if(Q.first){X.back().push_back(bte(Q.second));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}FOR(i,M.p,M.q){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}
#undef g
#define imie(a...) ngy(a, #a)
#define imask(a...) ngy(a, #a, 1)
#define range_v(u,g,c) ngy(list<urs(u[0])>(&u[yyo(g)],&u[yyo(c)] + 1), #u "[" + bte(g) + "..." + bte(c) + "]")
#define range(i,j) ngy(list<urs(*i)>(i,j), "[" #i "..." #j ")")
#define arr(a,i) imie(a)[imie(i)]
#define arr2(a, i, j) imie(a)[imie(i)][imie(j)]
#define print_stack(r...) ::imx(vqx(__LINE__,__FUNCTION__))
#define mark_stack(r...) bcx _;::ctm(1,vqx(__LINE__,__FUNCTION__),r)
#define dump(a,i,j,k,q) ngy(nyb(a,yyo(i),yyo(j),yyo(k),yyo(q)),#a "["+bte(imie(i))+".."+bte(imie(j))+"]["+bte(imie(k))+".."+bte(imie(q))+"]")
#else
#define loc(...)
#define onl(r...) r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#endif
#define muu(v...) struct hash<v>{size_t operator()(const v&x)const{size_t ans=x.size();for(auto&e:x)ans=mix(ans^hash<typename v::value_type>()(e));rans;}};
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&o)const{return mix(hash<typename decay<c>::type>()(o.first))^hash<typename decay<n>::type>()(o.second);}};sim>muu(vector<c>)sim>muu(list<c>)sim>muu(set<c>)sim,class n>muu(map<c,n>)sim,size_t N>muu(array<c,N>)sim>muu(deque<c>)}
#define next __n3kst
#define prev __prew
#define tree __tRe3
#define left __l3fT
#define right __Ri9ht
#ifndef LOCAL
sim,class m>using _un0rDer3d_M4P=cc_hash_table<c,m,hash<c>>;
#define unordered_map _un0rDer3d_M4P
#endif
ull tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){tqu=x;}sim>c gcd(c o,c b){while(o&&b){int x=ctz(o),y=ctz(b);if(x>y)o>>=x-y;else b>>=y-x;if(o>b)o-=b;else b-=o;}ros?o:b;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...) random_shuffle(r,[](int i){return my_rand()%i;})
ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
#define log __l0g
const int nax = 1e5 + 44, log = 17, cax = 50;
vpii graf[nax];
int jump[log][nax];
int wei_up[nax];
int deg[nax];
vector <int> down[nax];
bool done[nax];
int dep[nax];
int top[nax];
ll dist[nax];
pair <int, ll> on[nax];
const ll llinf = (ll)1e18 + 123456789;
const int inf = (int)1e9 + 1234567;
void cut(int x) {
	debug(arr(deg, x));
	if (deg[x] == 1 && !done[x]) {
		debug("remove ", imie(x));
		done[x] = 1;
		for (pii e : graf[x]) {
			if (!done[e.first]) {
				deg[e.first]--;
				cut(e.first);
				jump[0][x] = e.first;
				down[e.first].push_back(x);
				wei_up[x] = e.second;
				debug(arr2(jump, 0, x), arr(wei_up, x));
			}
		}
	}
}
void dfs(int x, int t, int d = 0, ll di = 0) {
	dep[x] = d;
	dist[x] = di;
	top[x] = t;
	for (int v : down[x]) {
		dfs(v, t, d + 1, di + wei_up[v]);
	}
}
void simple_dfs(int x, int y = -1, int d = 0, ll di = 0) {
	jump[0][x] = y == -1 ? x : y;
	dep[x] = d;
	dist[x] = di;
	for (pii e : graf[x])
		if (e.first != y)
			simple_dfs(e.first, x, d + 1, di + e.second);
}
int lca(int a, int b) {
	debug(imie(a), imie(b));
	assert(top[a] == top[b]);
	debug(arr(dep, a), arr(dep, b));
	REP(_, 2) {
		if (dep[a] > dep[b]) {
			int diff = dep[a] - dep[b];
			forbits(i, diff)
				a = jump[i][a];
		}
		swap(a, b);
	}
	debug(imie(a), imie(b));
	if (a == b) return a;
	FORD(l, log - 1, 0) {
		int aa = jump[l][a];
		int bb = jump[l][b];
		if (aa != bb) {
			a = aa;
			b = bb;
		}
	}
	return jump[0][a];
}
vector <pair <ll, int> > to[nax];
int c_num[nax];
ll on_cycle[nax];
ll fw[cax][cax];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].emplace_back(b, c);
		graf[b].emplace_back(a, c);
		deg[a]++;
		deg[b]++;
	}
	if (m == n - 1) {
		simple_dfs(1);
		FOR(l, 1, log - 1)
			FOR(v, 1, n) jump[l][v] = jump[l - 1][jump[l - 1][v]];
		int q;
		scanf("%d", &q);
		REP(_, q) {
			int a, b;
			scanf("%d%d", &a, &b);
			int l = lca(a, b);
			printf("%lld\n", dist[a] + dist[b] - 2 * dist[l]);
		}
		return 0;
	}
	FOR(i, 1, n)
		cut(i);
	FOR(i, 1, n) if (!done[i]) {
		dfs(i, i);
		jump[0][i] = i;
	}
	FOR(l, 1, log - 1)
		FOR(v, 1, n) jump[l][v] = jump[l - 1][jump[l - 1][v]];
	int cou = 0;
	memset(c_num, -1, sizeof(c_num));
	FOR(i, 1, n) if (!done[i] && deg[i] >= 3) {
		c_num[i] = cou++;
		debug(arr(c_num, i));
	}
	if (cou == 0) {
		int x = -1;
		FOR(i, 1, n) if (!done[i]) x = i;
		assert(x != -1);
		ll cycle_len = 0;
		int wh = x;
		int prev = -1;
		loc(int turns = 0;)
		do {
			loc(turns++;assert(turns <= n);)
			on_cycle[wh] = cycle_len;
			debug(arr(on_cycle, wh));
			for (pii e : graf[wh]) {
				if (e.first != prev && !done[e.first]) {
					cycle_len += e.second;
					prev = wh;
					wh = e.first;
					break;
				}
			}
		}
		while (wh != x);
		debug(imie(cycle_len));
		int q;
		scanf("%d", &q);
		REP(_, q) {
			int a, b;
			scanf("%d%d", &a, &b);
			debug(arr(top, a), arr(top, b));
			if (top[a] == top[b])
				printf("%lld\n", dist[a] + dist[b] - 2 * dist[lca(a, b)]);
			else {
				ll c = abs(on_cycle[top[a]] - on_cycle[top[b]]);
				printf("%lld\n", dist[a] + dist[b] + min(c, cycle_len - c));
			}
		}
	}
	else {
		debug(imie(cou));
		REP(i, cou) REP(j, cou) fw[i][j] = llinf;
		REP(i, cou) fw[i][i] = 0;
		int pnum = 0;
		FOR(i, 1, n) if (c_num[i] != -1) {
			to[i].emplace_back(0, i);
			for (pii e : graf[i]) if (!done[e.first]) {
				pnum++;
				ll plen = e.second;
				int wh = e.first, prev = i;
				while (deg[wh] == 2) {
					on[wh] = {pnum, plen};
					to[wh].emplace_back(plen, i);
					debug(arr(on, wh));
					for (pii e2 : graf[wh]) if (!done[e2.first] && e2.first != prev) {
						plen += e2.second;
						prev = wh;
						wh = e2.first;
						break;
					}
				}
				debug(imie(wh), imie(i), imie(plen));
				mini(fw[c_num[wh]][c_num[i]], plen);
				mini(fw[c_num[i]][c_num[wh]], plen);
			}
		}
		REP(i, cou) REP(j, cou) debug(arr2(fw, i, j));
		REP(i, cou) REP(j, cou) REP(k, cou) mini(fw[j][k], fw[j][i] + fw[i][k]);
		REP(i, cou) REP(j, cou) debug(arr2(fw, i, j));
		int q;
		scanf("%d", &q);
		REP(_, q) {
			int a, b;
			scanf("%d%d", &a, &b);
			debug(arr(top, a), arr(top, b));
			if (top[a] == top[b])
				printf("%lld\n", dist[a] + dist[b] - 2 * dist[lca(a, b)]);
			else {
				ll ans = llinf;
				int aa = top[a], bb = top[b];
				if (on[aa].first == on[bb].first && on[aa].first != 0)
					mini(ans, abs(on[aa].second - on[bb].second));
				for (auto x : to[aa]) for (auto y : to[bb]) {
					debug(imie(x.first) + imie(y.first) + arr2(fw, arr(c_num, x.second), arr(c_num, y.second)));
					mini(ans, x.first + y.first + fw[c_num[x.second]][c_num[y.second]]);
				}
				ans += dist[a] + dist[b];
				printf("%lld\n", ans);
			}
		}
	}
}