//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
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
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),_=m;_;_^=((urs(m))1<<i),i=ctz(_))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,_=m;_;_^=((urs(m))1<<i),i=8*sizeof(m)-clz(_)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << k) - 1); m < ((t)1 << n); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#ifdef LOCAL
#define loc(r...)r
#define onl(r...)
#define azm(r)sim,class n,class l,class...v>bool emz1(const r<c,n,v...>&o,l b){ros.count(b);}sim,class n,class l,class...v>const n&emz2(const r<c,n,v...>&o,l b){ros.find(b)->second;}
#define oor >ostream&operator<<(ostream&o,
#define debug(c...)::dor(1,vqx(__LINE__,__FUNCTION__),c)
#define rcu m);}g(+)g(-)g(*)g(/)g(%)g(<<)g(>>)g(^)g(|)g(&)g(>=)g(<=)g(>)g(<)g(!=)g(==)
#define zub(h,t,n...)class N>auto operator h(n u)->nep<urs(t)>{return ngy(t,
#define g(o)template<zub(o,v o u,N)tfj(bte(*this))+" " #o " "+tfj(bte(u)),m);}
sim>gyv<int,typename c::value_type>dud(int x);sim>char dud(...);struct kav;sim>struct lfu;sim> struct jat;struct kav{static const int d=0;};sim>struct lfu{static const int d=jat<typename c::value_type>::d + 1;};sim>struct jat{static const int d=conditional<sizeof(dud<c>(0))==1,kav,lfu<c>>::type::d;};sim,class n>struct jat<pair<c,n>>{static const int d=jat<c>::d>jat<n>::d?jat<c>::d:jat<n>::d;};template<>struct jat<string>{static const int d=0;};
sim>c&lum(c&o){ros;}int lum(int8_t o){ros;}unt lum(uint8_t o){ros;}int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>bool emz1(const c&a,ll o){ros>=0&&o<(ll)a.size();}sim>auto emz2(const c&o,ll x)->decltype(o[x]){ros[x];}sim>bool emz1(c*a,ll o){ros>=0;}sim>c&emz2(c*o,ll b){ros[b];}template<size_t n>bool emz1(const bitset<n>&,ll o){ros>=0&&o<(ll)n;}template<size_t n>int emz2(const bitset<n>&o,ll b){ros[b];}string tfj(string o){for(char x:o)if(x=='=')return"("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"#"<<l<<": \033["<<30+l%7+(l%7>=l%8)<<"m";ros.str();}ostream&operator<<(ostream&o,__int128 x){int D[50],c=0;if(x<0)o<<"-",x=-x;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__uint128_t x){int D[50],c=0;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__float128 x){ros<<(ld)x;}sim,class N oor pair<c,N>u){ros<<"<"<<lum(u.first)<<", "<<lum(u.second)<<">";}sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<lum(e);ros<<"}_"<<q;}void dor(bool x){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(int w,c x,N...y){cerr<<setprecision(uuv)<<boolalpha<<x<<"; "+2*w;dor(0,y...);}sim>string bte(c u){stringstream o;o<<setprecision(uuv)<<boolalpha<<lum(u);ros.str();}sim>struct nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);sim>c yyo(c o){ros;}sim>struct nep{c v;string d;int m;nep<c>mask(){return ngy(v,d,1);}template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}sim>c yyo(nep<c>o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
#undef g
#define ckx(o)template<zub(o,o yyo(u),nep<N>)#o+tfj(bte(u)),u.m);}
#define g(o)sim,zub(o,yyo(p)o u.v,c p,nep<N>)tfj(bte(p))+" " #o " "+tfj(bte(u)),uhn(p)+u.m);}
#define ccy(r...)sim>class enable_if<r is_integral<c>::value,string>::type ema(c u){
ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>M.q||M.r>M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r+1,1);FOR(i,M.p,M.q){maxi(l,(int)bte(i).size());X.emplace_back();if(emz1(M.x,i)){auto V=emz2(M.x,i);FOR(j,M.r,M.s){if(emz1(V,j)){auto Q=emz2(V,j);X.back().push_back(bte(Q));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}}FOR(i,M.p,M.q){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}
#undef g
#define imie(a...) ngy(a,#a)
#define imask(a...) ngy(a,#a,1)
#define ra3(u,g,c) ngy(list<urs(u[0])>(begin(u)+yyo(g),begin(u)+yyo(c)+1),#u "["+bte(g)+"..."+bte(c)+"]")
#define ra2(i,j)ngy(list<urs(*i)>(i,j),"[" #i "..." #j ")")
#define zoz(a,b,c,d,e...) d
#define range(r...) zoz(r,ra3,ra2)(r)
#define arr(a,i)ngy(emz1(a,yyo(i))?a[yyo(i)]:urs(a[yyo(i)])(),#a "["+bte(i)+"]")
#define arr2(a,i,j)ngy(emz1(a,yyo(i))&&emz1(a[yyo(i)],yyo(j))?a[yyo(i)][yyo(j)]:urs(a[yyo(i)][yyo(j)])(),#a "["+bte(i)+"]["+bte(j)+"]")
#define print_stack(r...)::imx(vqx(__LINE__,__FUNCTION__))
#define mark_stack(r...)bcx _;::ctm(1,vqx(__LINE__,__FUNCTION__),r)
#define dump(a,i,j,k,q)ngy(nyb(a,yyo(i),yyo(j),yyo(k),yyo(q)),#a "["+bte(imie(i))+".."+bte(imie(j))+"]["+bte(imie(k))+".."+bte(imie(q))+"]")
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#endif
#define next __n3kst
#define prev __prew
#define tree __tRe3
#define left __l3fT
#define right __Ri9ht
#define div __dIv
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1234000000;const ll llinf=1234567890000000000ll;
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int i){return my_rand()%i;})
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
sim,class m>using _un0rDer3d_M4P=loc(unordered_map)onl(cc_hash_table)<c,m,my_hasher<c>>;
#define unordered_map _un0rDer3d_M4P
int n, q;
const int nax = 2e5 + 44;
pii wh[nax];
int a[nax];
int moves(int l, int r) {
	if (l < 0) return 0;
	map <int, int> c;
	FOR(i, l, r) c[a[i]]++;
	int m = 0;
	for (pii x : c) maxi(m, x.second);
	int ans = r - l + 1 - m;
	debug(range(a, l, r), imie(ans));
	rans;
}
void solve() {
	REP(i, nax) wh[i] = {nax, -1};
	REP(i, n) {
		int v = a[i];
		mini(wh[v].first, i);
		maxi(wh[v].second, i);
	}
	vpii all;
	REP(i, n) if (wh[a[i]].first == i)
		all.push_back(wh[a[i]]);
	debug(imie(all));
	sort(ALL(all));
	int beg = -1, end = -1;
	int ans = 0;
	for (pii x : all) {
		if (x.first <= end) maxi(end, x.second);
		else {
			ans += moves(beg, end);
			beg = x.first;
			end = x.second;
		}
	}
	ans += moves(beg, end);
	printf("%d\n", ans);
}
int main() {
	scanf("%d%d", &n, &q);
	REP(i, n) scanf("%d", a + i);
	solve();
	REP(_, q) {
		int i, x;
		scanf("%d%d", &i, &x);
		a[i] = x;
		solve();
	}
}