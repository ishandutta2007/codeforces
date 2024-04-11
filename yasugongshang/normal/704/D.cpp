#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
void GG(int x){
	if(!x){puts("-1"); exit(0);}
}
const int N=100002,NN=N*3,MM=N*8,inf=1e9;
int ne=1,x[N],y[N],sumx[N],sumy[N],mx[N],my[N],d[NN],qx[N],qy[N],cur[NN],dep[NN],son[NN],nxt[MM],ed[MM],di[MM];
char ans[N];
void ae(int a,int b,int c){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b; di[ne]=c;
}
void ins(int a,int b,int c){
	ae(a,b,c); ae(b,a,0);
	//cout<<a<<" "<<b<<" "<<c<<endl;
}
bool bfs(int s,int t){
	For(i,0,NN-1){dep[i]=inf; cur[i]=son[i];}
	dep[s]=0; queue<int> q; q.push(s);
	while(q.size()){
		int zs=q.front(); q.pop();
		for(int i=son[zs];i;i=nxt[i])if(dep[ed[i]]==inf&&di[i]){
			dep[ed[i]]=dep[zs]+1; q.push(ed[i]);
		}
	}
	return dep[t]<inf;
}
int dfs(int p,int t,int lim){
	if(!lim||p==t)return lim;
	int flow=0,f;
	for(int &i=cur[p];i;i=nxt[i]){
		if(dep[ed[i]]==dep[p]+1&&(f=dfs(ed[i],t,min(lim,di[i])))){
			flow+=f; lim-=f; di[i]-=f; di[i^1]+=f; if(!lim)return flow;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int ans=0;
	while(bfs(s,t))ans+=dfs(s,t,inf);
	return ans;
}
int main(){
	int n=read(),m=read();
	int r=read(),b=read(),f=0;
	if(r>b){
		f=1; swap(r,b);
	}
	For(i,1,n){qx[i-1]=x[i]=read(); qy[i-1]=y[i]=read();}
	sort(qx,qx+n); sort(qy,qy+n);
	int X=unique(qx,qx+n)-qx,Y=unique(qy,qy+n)-qy,s=n+X+Y+1,t=s+1,S=t+1,T=S+1;
	For(i,1,n){
		x[i]=lower_bound(qx,qx+X,x[i])-qx;
		y[i]=lower_bound(qy,qy+Y,y[i])-qy;
		sumx[x[i]]++; sumy[y[i]]++;
		ins(n+x[i]+1,i,1); ins(i,n+X+y[i]+1,1);
	}
	For(i,0,X-1)mx[i]=sumx[i];
	For(i,0,Y-1)my[i]=sumy[i];
	For(i,1,m){
		int t=read(),l=read(),d=read();
		if(t==1){
			int p=lower_bound(qx,qx+X,l)-qx;
			if(p<X&&qx[p]==l)mx[p]=min(mx[p],d);
		}else{
			int p=lower_bound(qy,qy+Y,l)-qy;
			if(p<Y&&qy[p]==l)my[p]=min(my[p],d);
		}
	}
	For(i,0,X-1){
		int R=(sumx[i]+mx[i])/2,L=sumx[i]-R; GG(R>=L);
		d[s]+=L; d[n+i+1]-=L;
		ins(s,n+i+1,R-L);
	}
	For(i,0,Y-1){
		int R=(sumy[i]+my[i])/2,L=sumy[i]-R; GG(R>=L);
		d[n+i+X+1]+=L; d[t]-=L;
		ins(n+i+X+1,t,R-L);
	}
	int zs=ne,sss=0;
	ins(t,s,inf);
	For(i,1,t)if(d[i]>0){ins(i,T,d[i]); sss+=d[i];} else if(d[i]<0)ins(S,i,-d[i]);
	//cout<<sss<<endl;
	GG(sss==dinic(S,T));
	For(i,1,t)for(int j=son[i];j;j=nxt[j])if(j>zs)di[j]=0;
	dinic(s,t);
	ll myh=0;
	For(i,1,n)for(int j=son[i];j;j=nxt[j])if(ed[j]>n+X){
		if(di[j]){ans[i]='b'; myh+=b;}else {ans[i]='r'; myh+=r;}
	}
	cout<<myh<<endl;
	For(i,1,n)if(f)ans[i]='r'+'b'-ans[i];
	cout<<(ans+1)<<endl;
}