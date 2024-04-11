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
int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>yvd(vector<c>)sim>yvd(deque<c>)sim,size_t N>yvd(array<c,N>)yvd(string)sim>pair<bool,typename std::decay<c>::type>emz(c*a,ll b){return {1,a[b]};}template<size_t n>pair<bool,bool>emz(bitset<n>a,ll b){if(b>=0&&b<(ll)n)return{1,a[b]};return{0,0};}string tfj(string o){for(char x:o)if(x=='=')return "("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"#"<<l<<": \033["<<30+l%7+(l%7>=l%8)<<"m";ros.str();}ostream&operator<<(ostream&o,__int128 x){int D[50],c=0;if(x<0)o<<"-",x=-x;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__uint128_t x){int D[50],c=0;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__float128 x){ros<<(ld)x;}sim,class N oor pair<c,N>u){ros<<"<"<<u.first<<", "<<u.second<<">";}sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<e;ros<<"}_"<<q;}void dor(bool x){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(int w,c x,N...y){cerr<<setprecision(uuv)<<boolalpha<<x<<"; "+2*w;dor(0,y...);}sim>string bte(c u){stringstream o;o<<setprecision(uuv)<<boolalpha<<u;ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}sim>c yyo(nep<c>o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
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
#define right __Ri9ht
#define left __l3ft
#ifndef LOCAL
sim,class m>using _un0rDer3d_M4P=cc_hash_table<c,m,hash<c>>;
#define unordered_map _un0rDer3d_M4P
#endif
ull tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){tqu=x;}sim>c gcd(c o,c b){while(o&&b){int x=ctz(o),y=ctz(b);if(x>y)o>>=x-y;else b>>=y-x;if(o>b)o-=b;else b-=o;}ros?o:b;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...) random_shuffle(r,[](int i){return my_rand()%i;})
ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
const int nax = 1 << 17;
int num[nax], p[nax], top[nax], right[nax], siz[nax], left[nax], bot[nax];
ll up_wei[nax], dep[nax];
pii edge[nax];
vector <pair <int, ll> > graf[nax];
void dfs1(int x, int y = -1, ll d = 0) {
	dep[x] = d;
	siz[x] = 1;
	for (auto e : graf[x]) if (e.first != y) {
		p[e.first] = x;
		up_wei[e.first] = e.second;
		dfs1(e.first, x, d + e.second);
		siz[x] += siz[e.first];
	}
}
void dfs2(int x, int y = -1) {
	static int timer = 0;
	debug(arr(graf, x));
	REP(i, (int)graf[x].size()) {
		if (graf[x][i].first == y) {
			swap(graf[x][i], graf[x].back());
			graf[x].pop_back();
			i--;
		}
	}
	REP(i, (int) graf[x].size())
		if (siz[graf[x][i].first] > siz[graf[x][0].first])
			swap(graf[x][i], graf[x][0]);
	left[x] = num[x] = timer++;
	for (auto e : graf[x])
		dfs2(e.first, x);
	right[x] = timer - 1;
}
pair <ll, int> tree1[nax * 2];
ll push[nax * 2];
void push_down(int x) {
	if (x < nax) {
		push[x * 2] += push[x];
		push[x * 2 + 1] += push[x];
		tree1[x * 2].first += push[x];
		tree1[x * 2 + 1].first += push[x];
	}
	push[x] = 0;
}
int wh_gl_max() {
	return tree1[1].second;
}
void add(int l, int r, ll val, int wh = 1, int lb = 0, int rb = nax - 1) {
	// loc(
		// debug(imie(l), imie(r), imie(val));
		// FOR(i, l, r) tree1[i + nax].first += val;
		// return;
	// )
	if (l > rb || r < lb) return;
	if (l <= lb && r >= rb) {
		tree1[wh].first += val;
		push[wh] += val;
		return;
	}
	push_down(wh);
	int sb = (lb + rb) / 2;
	add(l, r, val, wh * 2, lb, sb);
	add(l, r, val, wh * 2 + 1, sb + 1, rb);
	tree1[wh] = max(tree1[wh * 2], tree1[wh * 2 + 1]);
}
const int inf = (int)1e9 + 123456;
const ll llinf = (ll)1e18 + 12345678910ll;
pair <ll, int> read_max(int l, int r, int wh = 1, int lb = 0, int rb = nax - 1) {
	// loc (
		// pair <ll, int> ans = {-llinf, -inf};
		// FOR(i, l, r) maxi(ans, tree1[i + nax]);
		// debug(imie(l), imie(r), imie(ans));
		// rans;
	// )
	if (l > rb || r < lb) return {-llinf, -inf};
	if (l <= lb && r >= rb) return tree1[wh];
	push_down(wh);
	int sb = (lb + rb) / 2;
	return max(read_max(l, r, wh * 2, lb, sb), read_max(l, r, wh * 2 + 1, sb + 1, rb));
}
void dfs3(int x, int y = -1) {
	if (y == -1 || num[y] != num[x] - 1)
		top[x] = x;
	else
		top[x] = top[y];
	for (auto e : graf[x])
		dfs3(e.first, x);
}
ll tree2[nax * 2];
ll push2[nax * 2];
void push_down2(int x) {
	if (x < nax) {
		tree2[x * 2] += push2[x];
		tree2[x * 2 + 1] += push2[x];
		push2[x * 2] += push2[x];
		push2[x * 2 + 1] += push2[x];
	}
	push2[x] = 0;
}
ll read2(int l, int r, int wh = 1, int lb = 0, int rb = nax - 1) {
	// loc(
		// ll ans = -llinf;
		// FOR(i, l, r) {
			// debug(arr(tree2, imie(i) + nax));
			// maxi(ans, tree2[i + nax]);
		// }
		// debug(imie(l), imie(r), imie(ans));
		// rans;
	// )
	if (l > rb || r < lb) return -llinf;
	if (l <= lb && r >= rb) return tree2[wh];
	push_down2(wh);
	int sb = (lb + rb) / 2;
	return max(read2(l, r, wh * 2, lb, sb), read2(l, r, wh * 2 + 1, sb + 1, rb));
}
void add2(int l, int r, ll val, int wh = 1, int lb = 0, int rb = nax - 1) {
	// loc(
		// debug(imie(l), imie(r), imie(val));
		// FOR(i, l, r) tree2[i + nax] += val;
		// return;
	// )
	if (l > rb || r < lb) return;
	if (l <= lb && r >= rb) {
		push2[wh] += val;
		tree2[wh] += val;
		return;
	}
	push_down2(wh);
	int sb = (lb + rb) / 2;
	add2(l, r, val, wh * 2, lb, sb);
	add2(l, r, val, wh * 2 + 1, sb + 1, rb);
	tree2[wh] = max(tree2[wh * 2], tree2[wh * 2 + 1]);
}
ll read_point2(int x) {
	return read2(x, x);
}
void put_point2(int x, ll val) {
	debug(arr(tree2, imie(x) + nax), "change to ", imie(val));
	add2(x, x, val - read_point2(x));
}
int main() {
	int n, q;
	ll w;
	scanf("%d%d%lld", &n, &q, &w);
	REP(i, n - 1) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		graf[a].emplace_back(b, c);
		graf[b].emplace_back(a, c);
		edge[i] = {a, b};
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	FOR(i, 1, n) if (num[bot[top[i]]] <= num[i])
		bot[top[i]] = i;
	FOR(i, 1, n)
		bot[i] = bot[top[i]];
	FOR(i, 1, n)
		debug(arr(num, i), arr(p, i), arr(top, i), arr(left, i), arr(right, i), arr(siz, i), arr(up_wei, i), arr(dep, i), arr(bot, i));
	FOR(i, 1, n) tree1[num[i] + nax] = {dep[i], i};
	FORD(i, nax - 1, 1) tree1[i] = max(tree1[i * 2], tree1[i * 2 + 1]);
	FOR(i, 1, n) {
		ll val = dep[i];
		if (!graf[i].empty()) {
			maxi(val, read_max(right[graf[i][0].first] + 1, right[i]).first);
		}
		tree2[num[i] + nax] = val + dep[top[i]] - 2 * dep[i];
	}
	FORD(i, nax - 1, 1) tree2[i] = max(tree2[i * 2], tree2[i * 2 + 1]);
	ll last = 0;
	REP(i, n - 1)
		if (num[edge[i].first] > num[edge[i].second])
			swap(FS(edge[i]));
	REP(_, q) {
		int d;
		ll v;
		scanf("%d%lld", &d, &v);
		d = (d + last) % (n - 1);
		v = (v + last) % w;
		int down = edge[d].second;
		debug("NEXT QUERY!!!!!!!!!!!!!!!!!!", arr(edge, d), arr(up_wei, down), imie(v));
		ll cha = v - up_wei[down];
		up_wei[down] = v;
		if (top[down] != down)
			add2(num[down], num[bot[down]], -cha);
		add(left[down], right[down], cha);
		int x = p[top[down]];
		while (x) {
			debug("touch", imie(x));
			ll val = read_max(num[x], num[x]).first;
			ll my_dep = val;
			ll top_dep = read_max(num[top[x]], num[top[x]]).first;
			if (!graf[x].empty()) {
				debug("include range", arr(right, graf[x][0].first) + 1, arr(right, x));
				maxi(val, read_max(right[graf[x][0].first] + 1, right[x]).first);
			}
			debug(imie(x), imie(val), imie(my_dep), imie(top_dep));
			put_point2(num[x], val + top_dep - 2 * my_dep);
			x = p[top[x]];
		}
		debug("update done");
		auto deepest = read_max(0, n - 1);
		ll maxdep = deepest.first;
		int u = deepest.second;
		debug(imie(deepest));
		ll ans = 0;
		while (u) {
			int v = top[u];
			ll rvu = read2(num[v], num[u] - 1);
			ll dep_v = read_max(num[v], num[v]).first;
			debug(imie(maxdep) + imie(rvu) - imie(dep_v));
			maxi(ans, maxdep + rvu - dep_v);
			int l = p[v];
			debug(imie(l), imie(v), imie(u), "rvu from ", arr(num, v), arr(num, u) - 1);
			if (l) {
				ll ldep = read_max(num[l], num[l]).first;
				ll sub = max(read_max(left[l], left[v] - 1).first, read_max(right[v] + 1, right[l]).first);
				maxi(ans, sub + maxdep - 2 * ldep);
			}
			u = l;
		}
		debug("query done");
		printf("%lld\n", ans);
		last = ans;
	}
}