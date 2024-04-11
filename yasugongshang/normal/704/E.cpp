#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
const ll inf=2e5;
int sz[N],wson[N],top[N],fa[N],dep[N];
vector<int> v[N];
struct num{
	ll a,b;
	void operator =(const ll c){
		a=c; b=1;
	}
	void xiao(){
		if(b<0){b=-b; a=-a;}
	}
}ans,qj;
num qz(ll a){return (num){a,1};}
num operator +(num a,num b){return (num){a.a*b.b+b.a*a.b,a.b*b.b};}
num operator -(num a,num b){b.a=-b.a; return a+b;}
num operator *(num a,num b){return (num){a.a*b.a,a.b*b.b};}
num operator /(num a,num b){swap(b.a,b.b); b.xiao(); return a*b;}
bool chu(ll a){return a>0;}
bool operator <(num a,num b){ll A=a.a*b.b,B=b.a*a.b;  return (A<B)^chu(a.b)^chu(b.b);}
bool operator <=(num a,num b){return !(b<a);}
bool operator ==(num a,num b){return !(a<b)&&!(b<a);}
struct data{
	num k,b,l,r;
	void print(){
		cout<<(ld)k.a/k.b<<" "<<(ld)b.a/b.b<<" "<<(ld)l.a/l.b<<" "<<(ld)r.a/r.b<<endl;
	}
	void xiao(){
		k.xiao(); b.xiao(); l.xiao(); r.xiao();
	}
};
bool operator <(data a,data b){
	num A=a.k*qj+a.b,B=b.k*qj+b.b;
	return A==B?(a.l==b.l?(a.r==b.r?(a.k==b.k?a.b<b.b:a.k<b.k):a.r<b.r):a.l<b.l):A<B;
}
vector<data> zhong[N],qing[N];
void dfs1(int p){
	sz[p]=1;
	for(auto it=v[p].begin();it!=v[p].end();it++)if(*it==fa[p]){v[p].erase(it); break;}
	for(auto i:v[p]){
		fa[i]=p; dfs1(i); sz[p]+=sz[i]; if(sz[i]>sz[wson[p]])wson[p]=i;
	}
}
void dfs2(int p){
	dep[p]=dep[fa[p]]+1;
	top[p]=wson[fa[p]]==p?top[fa[p]]:p;
	if(wson[p])dfs2(wson[p]);
	for(auto i:v[p])if(i!=wson[p])dfs2(i);
}
int lca(int s,int t){
	while(top[s]!=top[t]){
		if(dep[top[s]]>dep[top[t]])s=fa[top[s]];
		else t=fa[top[t]];
	}
	return dep[s]>dep[t]?t:s;
}
void solve(int ti,int sp,int S,int T){
	int s=S,t=T,lc=lca(s,t),x=2*dep[lc]-dep[S];num ks,SP; ks=ti,SP=sp; 
	while(top[s]!=top[t]){
		if(dep[top[s]]>dep[top[t]]){
			zhong[top[s]].pb((data){qz(-sp),qz(dep[S]+ti*sp),ks+qz(dep[S]-dep[s])/SP,ks+qz(dep[S]-dep[top[s]])/SP});
			s=top[s]; 
			qing[s].pb((data){qz(-sp),qz(dep[S]+ti*sp),ks+qz(dep[S]-dep[s])/SP,ks+qz(dep[S]-dep[fa[s]])/SP}); 
			s=fa[s];
		}else{
			zhong[top[t]].pb((data){qz(sp),qz(x-ti*sp),ks+qz(dep[top[t]]-x)/SP,ks+qz(dep[t]-x)/SP});
			t=top[t];
			qing[t].pb((data){qz(sp),qz(x-ti*sp),ks+qz(dep[fa[t]]-x)/SP,ks+qz(dep[t]-x)/SP});
			t=fa[t];
		}
	}
	if(dep[s]>dep[t])zhong[top[s]].pb((data){qz(-sp),qz(dep[S]+ti*sp),ks+qz(dep[S]-dep[s])/SP,ks+qz(dep[S]-dep[t])/SP});
	else zhong[top[s]].pb((data){qz(sp),qz(x-ti*sp),ks+qz(dep[s]-x)/SP,ks+qz(dep[t]-x)/SP});
}
bool cmp(pair<data,bool> a,pair<data,bool> b){
	num A=a.se?a.fi.r:a.fi.l,B=b.se?b.fi.r:b.fi.l;
	return A==B?a.se<b.se:A<B;
}
void chk(data a,data b){
	if(a.k==b.k){
		if(!(a.b==b.b))return;
		if(b.l<=a.l&&a.l<=b.r&&a.l<ans)ans=a.l;
		if(a.l<=b.l&&b.l<=a.r&&b.l<ans)ans=b.l;
	}else{
		num x=(a.b-b.b)/(b.k-a.k);
		if(a.l<=x&&x<=a.r&&b.l<=x&&x<=b.r&&(x<ans))ans=x;
	}
}
void Solve(vector<data> &v){
	vector<pair<data,bool> > V;
	for(auto &i:v){
		V.pb(mp(i,1));
		V.pb(mp(i,0));
	}
	sort(V.begin(),V.end(),cmp);
	multiset<data> s;
	for(auto i:V){
		if(i.se){
			data o=i.fi; 
			if(ans<=o.r)return; qj=o.r;
			auto R=s.find(o); 
			s.erase(R++);
			auto L=R;
			if(R!=s.end()&&R!=s.begin())chk(*R,*(--L));
		}else{
			data o=i.fi;
			if(ans<=o.l)return; qj=o.l;
			auto tmp=s.insert(o),L=tmp,R=tmp;
			if(L!=s.begin())chk(*(--L),*tmp);
			R++; if(R!=s.end())chk(*R,*tmp);
		}
	}
}
ld QZ(num a){
	return (ld)a.a/a.b;
}
int main(){
	int n=read(),m=read();
	For(i,1,n-1){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	dfs1(1);
	dfs2(1);
	For(i,1,m){
		int t=read(),c=read(),v=read(),u=read();
		solve(t,c,v,u); 
	}
	ans=inf;
	For(i,1,n)if(top[i]==i){
		Solve(zhong[i]);
		if(i>1)Solve(qing[i]);
	}
	if(ans.a==inf)puts("-1"); else printf("%.10lf\n",QZ(ans));
}
/*


*/