#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
struct pv{
	LL x,y;
	pv (LL _=0,LL __=0){
		x=_; y=__; 
	}
};
pv operator +(pv A,pv B){
	return pv(A.x+B.x,A.y+B.y);
}
pv operator -(pv A,pv B){
	return pv(A.x-B.x,A.y-B.y);
}
struct edge{
	int y; pv t;
};
vector<edge> v[M];
int cnt,to[M<<1],nxt[M<<1],head[M];
pv w[M<<1];
bool vis[M<<1];
int tt;
void add(int x,int y,pv z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
void jb(int x,int y,pv z){
//	cout<<x<<" "<<y<<"    edge  ? \n"; 
	add(x,y,z); add(y,x,z);
}
void rebuild(int x,int fa){
	int np=0;
	F(i,0,SZ(v[x])){
		int y=v[x][i].y;
		if (y==fa) continue;
		int nw=++tt;
		if (np) jb(np,nw,pv(0,0));
		else jb(x,nw,pv(0,0));
		jb(nw,y,v[x][i].t);
		np=nw;
		rebuild(y,x);
	}
}
int mu,mv,mid,mi,S,sz[M]; 
void ge(int x,int fa,int id){
	sz[x]=1;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa || vis[i]) continue;
		ge(y,x,i);
		sz[x]+=sz[y]; 
	}
	if (id && max(sz[x],S-sz[x])<mi) mi=max(sz[x],S-sz[x]),mu=x,mv=fa,mid=id;
}
bool cmp(pv A,pv B){
	return A.x==B.x ? A.y<B.y : A.x<B.x;
}
#define all(x) x.begin(),x.end()
int s[M];
#define DX(a,A,B) (a[A].x-a[B].x)
#define DY(a,A,B) (a[A].y-a[B].y)
#define slope(a,A,B) DY(a,A,B)/(1.0*DX(a,A,B))
void convex(vector<pv> &a){
	sort(all(a),cmp);
	int tp=0;
	F(i,0,SZ(a)){
		if (i<SZ(a) && a[i].x==a[i+1].x) continue; 
		while (tp>1 && slope(a,i,s[tp])>=slope(a,s[tp],s[tp-1])) tp--;
		s[++tp]=i;
	}
//	cout<<tp<<"   convex hull \n";
	vector<pv> b;
	F(i,1,tp) b.pb(a[s[i]]);
	a.resize(b.size());
	a=b; 
}
vector<pv> tmpa,tmpb,ans;
void dfs(int x,int fa,pv tmp,vector<pv> &a){
	a.pb(tmp);
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa || vis[i]) continue;
		dfs(y,x,tmp+w[i],a);
	}
}
bool cp(pv A,pv B){
	return atan2(A.y,A.x)>atan2(B.y,B.x); 
}
void convexsum(vector<pv> &a,vector<pv> &b){
	ans.pb(a[0]+b[0]);
	int poa=1,pob=1;
	while (poa<=SZ(a) || pob<=SZ(b)){
		if (poa>SZ(a)) ans.pb(ans.back()+b[pob]-b[pob-1]),pob++; 
		else if (pob>SZ(b)) ans.pb(ans.back()+a[poa]-a[poa-1]),poa++; 
		else if (slope(a,poa,poa-1)>slope(b,pob,pob-1)) ans.pb(ans.back()+a[poa]-a[poa-1]),poa++;
		else ans.pb(ans.back()+b[pob]-b[pob-1]),pob++; 
	}
}
void divide(int x,int os){
	if (os==1) return ; 
//	cout<<x<<" "<<os<<"  div\n"; 
	S=os; mi=1e9; ge(x,0,0);
	vis[mid]=vis[mid^1]=1; 
	tmpa.clear(); tmpb.clear(); 
	dfs(mu,0,pv(0,0),tmpa);
	dfs(mv,0,w[mid],tmpb);
//	cout<<mu<<" "<<mv<<"\n"; 
	convex(tmpa); convex(tmpb);
	convexsum(tmpa,tmpb);
	int tmu=mu,tmv=mv,szf=sz[mu];
	divide(tmu,szf);
	divide(tmv,os-szf);
}
int n,m; 
int stk[50],len;
void out(LL x){
	if (x==0) putchar('0');
	len=0; while (x) stk[++len]=x%10,x/=10;
	while (len) putchar('0'+stk[len]),len--;
}
int main(){
	n=read(); m=read(); 
	F(i,1,n-1){
		int x=read(),y=read(),xx=read(),yy=read();
		v[x].pb(edge{y,pv(xx,yy)});
		v[y].pb(edge{x,pv(xx,yy)});
	}
	ans.pb(pv(0,0)); 
	tt=n; cnt=1; rebuild(1,0);
	divide(1,tt);	
//	cout<<"fuck\n";
	convex(ans);
	int l=0,r=SZ(ans);
//	F(i,l,r) cout<<ans[i].x<<" "<<ans[i].y<<" points \n";
//	cout<<DY(ans,1,0)<<" "<<DX(ans,1,0)<<" ?  >?\n"; 
	F(i,0,m-1){
		while (l<r && slope(ans,l+1,l)>=-i) l++;
//		cout<<l<<" "<<ans[l].x<<" "<<ans[l].y<<"   ??? \n";
		out(ans[l].x*i+ans[l].y); putchar(' ');
//		cout<<ans[l].x*i+ans[l].y<<" "; 
	}
	cout<<"\n";
	return 0;
}