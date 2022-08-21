#ifndef LOCAL
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("-unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//not a multiset
//find_by_order(k) -> itr of k-th(0-based) element
//order_of_key(k) -> index of lower_bound(k)
using ordered_set=tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>;


//https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

//count 
//find 
//move  
//value  null_type  unordered_set 
//insert  ()
//https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures.html (HELP)

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

//find the indices of row maxima
//the smallest index is used in case of tie
//f 
//-inf 
//VERIFY
//Codechef CHEFAOR (needs optimization!)
//Petrozavodsk Camp 2010S Kyiv NU Contest I (D=long double,double )
//GCJ 2020 WF D (D=long double)
//template<class F,class D=typename invoke_result<F,int,int>::type>
template<class F,class D>
vi smawk(F f,int n,int m){
	vi ans(n,-1);
	auto rec=[&](auto self,int*const rs,int x,int*const cs,int y)->void{
		const int t=2;
		if(x<=t||y<=t){
			rep(i,x){
				int r=rs[i];
				D mx;
				rep(j,y){
					int c=cs[j];
					D w=f(r,c);
					if(ans[r]==-1||w>mx){
						ans[r]=c;
						mx=w;
					}
				}
			}
			return;
		}
		if(x<y){
			int s=0;
			rep(i,y){
				int c=cs[i];
				while(s&&f(rs[s-1],cs[s-1])<f(rs[s-1],c))
					s--;
				if(s<x)
					cs[s++]=c;
			}
			y=s;
		}
		auto a=rs+x,b=cs+y;
		int z=0;
		for(int i=1;i<x;i+=2)
			a[z++]=rs[i];
		rep(i,y)
			b[i]=cs[i];
		self(self,a,z,b,y);
		int k=0;
		for(int i=0;i<x;i+=2){
			int to=i+1<x?ans[rs[i+1]]:cs[y-1];
			D mx;
			while(1){
				D w=f(rs[i],cs[k]);
				if(ans[rs[i]]==-1||w>mx){
					ans[rs[i]]=cs[k];
					mx=w;
				}
				if(cs[k]==to)break;
				k++;
			}
		}
	};
	int*rs=new int[n*2];
	rep(i,n)rs[i]=i;
	int*cs=new int[max(m,n*2)];
	rep(i,m)cs[i]=i;
	rec(rec,rs,n,cs,m);
	delete[] rs;
	delete[] cs;
	return ans;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	bool dbg=false;
	#ifdef LOCAL
	dbg=true;
	#endif
	
	vc<hash_table<int,int>> memo(n);
	int cnt=0;
	auto f=[&](int i,int j){
		{
			auto itr=memo[i].find(j);
			if(itr!=memo[i].ed)return itr->b;
		}
		cnt++;
		int res;
		if(!dbg){
			cout<<"? "<<i+1<<" "<<j+1<<endl;
			cin>>res;
		}else{
			res=abs(i-j);
		}
		return memo[i][j]=-res;
	};
	
	vi idx=smawk<decltype(f),int>(f,n,m);
	int ans=-inf;
	rep(i,n)chmax(ans,f(i,idx[i]));
	cout<<"! "<<-ans<<endl;
	dmp(cnt);
}