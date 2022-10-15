#include <cstdio>
#include <vector>
#include <algorithm>
const int rt=1,s=100,B=2010,N=2e5+10;
int n,q,cnt,dnt,a[N],b[N],ga[N],gb[N],ta[N],tb[N],sz[N],dfn[N],t[B],pt[B],add[B],head[N],to[N],next[N];
namespace basic{
	int lt,res,dig[50];
	long long nw;
	char cdc;
	bool ngt;
	template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
	inline long long abs(long long x){return x>0?x:(-x);}
	inline long long round(long double x){return x>0?(long long)(x+0.5):(long long)(x-0.5);}
	inline int read(){
		res=0,ngt=false;
		for(;cdc<'0'||cdc>'9';cdc=getchar())ngt|=cdc=='-';
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return ngt?~res+1:res;
	}
	inline void write(long long x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using basic::cmax;using basic::abs;using basic::round;using basic::read;using basic::write;
struct cpx{
	long double x,y;
	cpx(){};
	cpx(long double x,long double y):x(x),y(y){};
	inline bool operator!=(const cpx &nxt)const{return x!=nxt.x||y!=nxt.y;}
	inline bool operator<(const cpx &nxt)const{return x<nxt.x||(x==nxt.x&&y<nxt.y);}
}crr[B<<1];std::vector<cpx> vec[B];
inline int bk(int x){return (x-1)/s+1;}
inline int st(int x){return (x-1)*s+1;}
inline long long f(const cpx &p,long double slp){return round(p.y-slp*p.x);}
inline long double chk(long double x){return x?x:0;}
inline long double slope(const cpx &a,const cpx &b){return (b.y-a.y)/chk(b.x-a.x);}
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void dfs(int u){
	sz[u]=1,dfn[u]=++cnt,ta[u]+=a[u],tb[u]+=b[u];
	for(int i=head[u];i;i=next[i]){
		if(dfn[to[i]])continue;
		ta[to[i]]=ta[u],tb[to[i]]=tb[u],dfs(to[i]),sz[u]+=sz[to[i]];
	}
}
void build(int x){
	int back;
	std::vector<cpx> nw;
	for(int i=st(x);bk(i)==x&&i<=n;++i){
		nw.push_back(cpx(-gb[i],(long long)ga[i]*gb[i]));
		nw.push_back(cpx(gb[i],-(long long)ga[i]*gb[i]));
	}
	vec[x].clear(),std::sort(nw.begin(),nw.end());
	for(cpx pt:nw){
		while((back=vec[x].size()-1)>0&&slope(vec[x][back-1],vec[x][back])<slope(vec[x][back],pt))vec[x].pop_back();
		if(!vec[x].size()||vec[x][back]!=pt)++back,vec[x].push_back(pt);
	}
	pt[x]=back;
}
void modify(int l,int r,int x){
	if(bk(l)==bk(r)){
		int nbk=bk(l);
		for(int i=l;i<=r;++i)ga[i]+=x;
		for(int i=st(nbk);bk(i)==nbk&&i<=n;++i)ga[i]+=add[nbk];
		add[nbk]=0,build(nbk);
	}
	else{
		int bl=bk(l),br=bk(r);
		for(int i=l;bk(i)==bl&&i<=n;++i)ga[i]+=x;
		for(int i=r;bk(i)==br&&i>0;--i)ga[i]+=x;
		for(int i=st(bl);bk(i)==bl&&i<=n;++i)ga[i]+=add[bl];
		for(int i=st(br);bk(i)==br&&i<=n;++i)ga[i]+=add[br];
		add[bl]=add[br]=0,build(bl),build(br);
		for(int i=bl+1;i<br;++i)add[i]+=x;
	}
}
long long query(int l,int r){
	long long res=0;
	if(bk(l)==bk(r)){
		int nbk=bk(l);
		for(int i=l;i<=r;++i)cmax(res,(long long)abs(ga[i]+add[nbk])*gb[i]);
	}
	else{
		int bl=bk(l),br=bk(r);
		for(int i=l;bk(i)==bl&&i<=n;++i)cmax(res,(long long)abs(ga[i]+add[bl])*gb[i]);
		for(int i=r;bk(i)==br&&i>0;--i)cmax(res,(long long)abs(ga[i]+add[br])*gb[i]);
		for(int i=bl+1;i<br;++i){
			while(pt[i]>0&&f(vec[i][pt[i]],add[i])<f(vec[i][pt[i]-1],add[i]))--pt[i];
			cmax(res,f(vec[i][pt[i]],add[i]));
		}
	}
	return res;
}
int main(){
	n=read(),q=read();
	for(int i=2;i<=n;++i)addedge(read(),i);
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	dfs(rt);
	for(int i=1;i<=n;++i)ga[dfn[i]]=ta[i],gb[dfn[i]]=abs(tb[i]);
	for(int i=1;i<=bk(n);++i)build(i);
	for(int v,x,opt,i=1;i<=q;++i){
		opt=read();
		if(opt==1)v=read(),x=read(),modify(dfn[v],dfn[v]+sz[v]-1,x);
		if(opt==2)v=read(),write(query(dfn[v],dfn[v]+sz[v]-1));
	}
	return 0;
}
/*
9 2
1 1 2 2 2 1 6 1 
1 4 -1 -3 -2 -5 -2 2 3 
-4 1 1 4 -4 -2 0 4 1 
1 6 5
2 1
*/