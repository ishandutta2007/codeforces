#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define pb push_back
#define fi first
#define se second
#define PI pair<int,int>
#define matrix vector<PI > 
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=10005,mod=1000000007;
const ll mod2=(ll)mod*mod*7;
inline ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod; a=a*a%mod;
	}
	return ans;
}
int rnd(int mod){
	unsigned long long ans=0;
	for(int i=0;i<5;i++)ans=ans<<15^rand();
	return ans%(mod-1)+1;
}
vector<ll> BM(vector<ll> x){
	vector<ll> ls,cur;// lscur 
	int lf,lt,len=x.size(); //lflt
	for(int i=0;i<len;i++){
		ll t=-x[i]%mod;
		for(unsigned j=0;j<cur.size();j++){
			t=(t+(ll)x[i-j-1]*cur[j])%mod;
		}
		if(!t)continue;
		if(!cur.size()){
			cur.resize(i+1); lf=i; lt=t; continue;
		}
		ll zs=-t*ksm(lt,mod-2)%mod;
		vector<ll> c(i-lf-1); c.pb(-zs); //0
		for(auto j:ls)c.pb(j*zs%mod);
		if(c.size()<cur.size())c.resize(cur.size());
		for(unsigned j=0;j<cur.size();j++)c[j]=(c[j]+cur[j])%mod; 
		if(i-lf+ls.size()>=cur.size()){
			ls=cur; lf=i; lt=t; //0 
		}
		cur=c;
	}
	for(auto &i:cur)i=(i%mod+mod)%mod;
	return cur;
}
ll f[2][N];
int d[N];
ll solve(int n,matrix &v){
	ll sum=1;
	vector<ll> h(n),hh(n);
	for(int i=0;i<n;i++)sum=sum*(hh[i]=rnd(mod))%mod;
	for(int i=0;i<n;i++)f[0][i]=rnd(mod);
	for(int i=0;i<n;i++)h[i]=rnd(mod);
	vector<ll> g(2*n);
	for(int i=0;i<2*n;i++){
		int t=i&1;
		if(i){
			memset(f[t],0,sizeof(f[t]));
			for(auto j:v)f[t][j.fi]-=f[t^1][j.se];
			for(int j=0;j<n;j++)f[t][j]=(f[t][j]+f[t^1][j]*d[j])%mod*hh[j]%mod+mod;
		//for(auto j:v)cout<<f[t^1][j.fi.se]<<" "<<j.se<<' '<<f[t^1][j.fi.se]*j.se<<endl;
		}
		for(int j=0;j<n;j++){g[i]+=h[j]*f[t][j]; if(g[i]>=mod2)g[i]-=mod2;}
		g[i]%=mod;
	}
	//for(auto i:g)wri(i); puts("");
	g=BM(g); //cout<<g.size()<< " "<<mod-g[0]<<" "<<g[1]<<" "<<sum<<endl;
	if(g.size()==n)return g[n-1]*ksm(sum,mod-2)%mod;
	else exit(0);
}
ll getdet(int n,matrix &v){
	if(!n)return 1;
	return (solve(n,v)*((n&1)?1:-1)+mod)%mod;
}
int main(){
	int n=read(),k=read();
	matrix v;
	for(int i=1;i<k;i++){
		for(int j=0;j<i;j++){
			if(i+1<n){v.push_back(mp(i,j)); v.push_back(mp(j,i));}
			d[i]++; d[j]++;
		}
	}
	for(int i=k;i<n;i++){
		for(int j=0;j<k;j++){
			int t=read()-1;
			if(i+1<n){v.push_back(mp(i,t)); v.push_back(mp(t,i));}
			d[i]++; d[t]++;
		}
	}
	//for(auto i:v)cout<<i.fi.fi<<' '<<i.fi.se<<" "<<i.se<<endl;
	cout<<getdet(n-1,v)<<endl;
}
/*
2
5 6
7 8

*/