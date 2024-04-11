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
#define quq xwb(nvj, __LINE__)
#define FOR(i, b, e) for(auto i=(b);i<=(e);++i)
#define REP(i, n) for(urs(n)i=0; i<(n);++i)
#define FORD(i, b, e) for(auto i=(b);i>=(int)(e);--i)
#define UNTIL(t) while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...) for (bool quq=1;quq||next_permutation(r);quq=false)
#define ALL(r) (r).begin(),(r).end()
#define FS(r) r.first,r.second
#define sim template <class c
#define ros return o
#define rans return ans
#define forbits(i, m) if(m)for(urs(m)i=ctz(m), quq = m;quq;quq^=((urs(m))1<<i),i=ctz(quq)) 
#define fordbits(i, m) if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,quq=m;quq;quq^=((urs(m))1<<i),i=8*sizeof(m)-clz(quq)-1)
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
#define debug(c...)::dor(1,vqx(__LINE__,__FUNCTION__),c);
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
#define g(o) template<zub(o, v o u, N) tfj(bte(*this)) + " " #o " " + tfj(bte(u)), m);}
int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>yvd(vector<c>)sim>yvd(deque<c>)sim,size_t N>yvd(array<c,N>)yvd(string)sim>pair<bool,typename std::decay<c>::type>emz(c*a,ll b){return {1,a[b]};}template<size_t n>pair<bool,bool>emz(bitset<n>a,ll b){if(b>=0&&b<(ll)n)return{1,a[b]};return{0,0};}string tfj(string o){for(char x:o)if(x=='=')return "("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"#"<<l<<": \033["<<30+l%7+(l%7>=l%8)<<"m";ros.str();}ostream&operator<<(ostream&o,__int128 x){int D[50],c=0;if(x<0)o<<"-",x=-x;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__uint128_t x){int D[50],c=0;do{D[c++]=x%10;x/=10;}while(x);while(c)o<<D[--c];ros;}ostream&operator<<(ostream&o,__float128 x){ros<<(ld)x;}sim,class N oor pair<c,N>u){ros<<"<"<<u.first<<", "<<u.second<<">";}sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<e;ros<<"}";}void dor(bool x){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(int w,c x,N...y){cerr<<setprecision(uuv)<<boolalpha<<x<<"; "+2*w;dor(0,y...);}sim>string bte(c u){stringstream o;o<<setprecision(uuv)<<boolalpha<<u;ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}sim>c yyo(nep<c>o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
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
#define mark_stack(r...) bcx quq;::ctm(1,vqx(__LINE__,__FUNCTION__),r)
#define dump(a,i,j,k,q) ngy(nyb(a,yyo(i),yyo(j),yyo(k),yyo(q)),#a "["+bte(imie(i))+".."+bte(imie(j))+"]["+bte(imie(k))+".."+bte(imie(q))+"]")
#else
#define loc(...)
#define onl(r...) r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#endif
#define vsv sim,class d,class e
#define nop(o,c,r,l...)>auto operator o(const c&a,const r&b)->decltype(make_pair(l)){return{l};}
#define pcg(o) vsv,class f nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second)vsv,class=typename enable_if<!is_base_of<ios_base,c>::value>::type nop(o,c,pair<d u e>,a o b.first,a o b.second)vsv nop(o,pair<c u d>,e,a.first o b,a.second o b)
#define clp(o) pcg(o)vsv>void operator o##=(pair<c,d>&a,const e&b){a.first o##=b;a.second o##=b;}vsv,class f>void operator o##=(pair<c,d>&a,const pair<e,f>&b){a.first o##=b.first;a.second o##=b.second;}
#define syd(o) sim,class d>auto operator o(pair<c, d> e)->decltype(make_pair(o e.first,o e.second)){return{o e.first,o e.second};}
#define u ,
#define muu(v...) struct hash<v>{size_t operator()(const v&x)const{size_t ans=x.size();for(auto&e:x)ans=mix(ans^hash<typename v::value_type>()(e));rans;}};
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&o)const{return mix(hash<typename decay<c>::type>()(o.first))^hash<typename decay<n>::type>()(o.second);}};sim>muu(vector<c>)sim>muu(list<c>)sim>muu(set<c>)sim,class n>muu(map<c,n>)sim,size_t N>muu(array<c,N>)sim>muu(deque<c>)}
#undef u
#define next __n3kst
#define prev __prew
#define tree __tRe3
#define left __l3fT
#define right __Ri9ht
#ifndef LOCAL
sim,class m>using _un0rDer3d_M4P=cc_hash_table<c,m,hash<c>>;
#define unordered_map _un0rDer3d_M4P
#endif
#define rer(o,f)zet_p operator o(zet_p y)const{return zet_p(v f loc(,w o y.w));}zet_p&operator o##=(zet_p y){return*this=*this o y;}
#define ycc(o)sim>typename enable_if<is_integral<c>::value,zet_p>::type operator o(c a, zet_p b){return zet_p(a)o b;}
void fre(string c) {
#if !defined(LOCAL) && !defined(LOCAL2)
freopen((c+".in").c_str(),"r",stdin);freopen((c+".out").c_str(),"w",stdout);
#endif
} const int mod = 1e9 + 7;
ll inv(ll b){assert(b);int e=mod-2;ll o=1;while(e){if(e&1)o=o*b%mod;b=b*b%mod;e>>=1;}ros;}struct zet_p{int v;loc(ld w;)sim=int,typename=typename enable_if<is_integral<c>::value>::type>zet_p(c r=0):v(r%mod)loc(,w(r)){}loc(sim>zet_p(c a,ld b):v(a%mod),w(b){})rer(+,+y.v)rer(-,-y.v)rer(*,*1ll*y.v)rer(/,*inv(y.v))int get()const{return((unt)v+mod)%mod;}zet_p operator-()const{return zet_p(-v loc(,-w));}bool operator==(zet_p y)const{return(v-y.v)%mod==0;}};ycc(+)ycc(-)ycc(*)ycc(/)sim>bool operator==(c a,zet_p b){return zet_p(a)==b;}loc(ostream&operator<<(ostream&o,zet_p y){ros<<"["<<y.get()<<"~"<<y.w<<"]";})ull tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){tqu=x;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...) random_shuffle(r,[](int i){return my_rand()%i;})
int a[101];
int main() {
	int n;
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", a + i);
	int s = 0;
	FOR(i, 1, n) s += a[i];
	int c = a[1];
	int ii = 1;
	FOR(i, 2, n) if (a[i] * 2 <= a[1]) {
		c += a[i];
		ii++;
	}
	debug(imie(c), imie(s));
	if (c * 2 > s) {
		printf("%d\n1", ii);
		FOR(i, 2, n) if (a[i] * 2 <= a[1]) printf(" %d", i);
		printf("\n");
	}
	else printf("0\n");
	return 0;
}