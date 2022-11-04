#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
struct LBCTaiQiangLe{
	int fa[N],v[N],id[N],n;
	void init(int x){
		n=x;
		for (int i=1;i<=n;i++)
			fa[i]=id[i]=i;
	}
	int get(int x){
		if (fa[x]==x) return x;
		int t=get(fa[x]);
		v[x]=max(v[x],v[fa[x]]);
		return fa[x]=t;
	}
	void merge(int x,int y){
		int X=x;
		x=id[x]; y=id[y];
		fa[x]=fa[y]=++n;
		fa[n]=id[X]=n;
	}
	void set(int x,int y){
		v[id[x]]=y;
	}
	int ask(int x){
		get(x);
		return v[x];
	}
}f1;
struct LBCAKNOIp2017{
	int fa[N],sz[N],id[N],n;
	ll v[N];
	void init(int x){
		n=x;
		for (int i=1;i<=n;i++)
			fa[i]=id[i]=i,sz[i]=1;
	}
	int get(int x){
		if (fa[x]==x) return x;
		int t=get(fa[x]);
		if (t!=fa[x]) v[x]+=v[fa[x]];
		return fa[x]=t;
	}
	void merge(int x,int y){
		int X=x;
		x=id[x],y=id[y];
		fa[x]=fa[y]=++n;
		sz[n]=sz[x]+sz[y];
		fa[n]=id[X]=n;
	}
	void add(int x,int y){
		v[id[x]]+=y;
	}
	int size(int x){
		return sz[id[x]];
	} 
	ll ask(int x){
		int t=get(x);
		return v[x]+(x==t?0:v[t]);
	}
}f2;
struct que{
	int op,v,id,t,x,y;
	bool operator <(const que& AKLBC)const{
		return t<AKLBC.t;
	}
}q[N];
ll ans[N];
int n,m,x,y,tot;
char ch[10];
int main(){
	scanf("%d%d",&n,&m);
	f1.init(n); f2.init(n);
	memset(ans,-1,sizeof(ans));
	for (int i=1;i<=m;i++){
		scanf("%s%d",ch,&x);
		if (ch[0]=='M'){
			scanf("%d",&y);
			f1.merge(x,y);
		}
		if (ch[0]=='Z')
			f1.set(x,i);
		if (ch[0]=='A')
			q[++tot]=(que){2,0,0,i,x};
		if (ch[0]=='U'){
			scanf("%d",&y);
			q[++tot]=(que){1,0,0,i,x,y};
		}
		if (ch[0]=='Q'){
			int o=f1.ask(x);
			ans[i]=0;
			q[++tot]=(que){3,1,i,i,x};
			if (o) q[++tot]=(que){3,-1,i,o,x};
		}
	}
	sort(q+1,q+tot+1);
	for (int i=1;i<=tot;i++)
		if (q[i].op==1)
			f2.merge(q[i].x,q[i].y);
		else if (q[i].op==2)
			f2.add(q[i].x,f2.size(q[i].x));
		else ans[q[i].id]+=q[i].v*f2.ask(q[i].x);
	for (int i=1;i<=m;i++)
		if (ans[i]!=-1) printf("%I64d\n",ans[i]);
}