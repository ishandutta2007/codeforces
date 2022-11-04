#include<bits/stdc++.h>
#define mo 1000000007
#define N 255
using namespace std;
map<int,int> mp;
int u[10],v[10],tot;
int head[N],num[N],vis[N];
struct edge{int to,next;}e[N*10];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:23333;
}
int getid(int x){
	if (!mp[x]) mp[x]=(int)mp.size();
	return mp[x];
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
	e[++tot]=(edge){x,head[y]};
	head[y]=tot;
}
int calsz(int u,int n,int d){
	int t=u,c=0,res;
	for (;t;c++,t/=2);
	res=(1<<(d-c+1))-1,t=c;
	for (;t<d;t++,u=u<<1|1);
	return res-max(min(u-n,1<<(d-c)),0);
}
void predp(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			num[x]-=num[e[i].to];
			predp(e[i].to,x);
		}
}
void dfs(int x,int &tot){
	upd(tot,num[x]);
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]) dfs(e[i].to,tot);
	vis[x]=0;
}
int main(){
	int n,m,d=0;
	scanf("%d%d",&n,&m);
	for (;(1<<d)<=n;d++);
	getid(1);
	for (int i=0;i<m;i++){
		scanf("%d%d",&u[i],&v[i]);
		for (int t=u[i];t;getid(t),t/=2);
		for (int t=v[i];t;getid(t),t/=2);
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		int u=it->first,id=it->second;
		if (u>1) add(getid(u),getid(u/2));
		num[id]=calsz(u,n,d);
	}
	predp(1,0);
	for (int i=0;i<m;i++)
		add(getid(u[i]),getid(v[i]));
	int ans=0;
	for (int i=1;i<=mp.size();i++){
		int tot=0; dfs(i,tot);
		upd(ans,1ll*tot*num[i]%mo);
	}
	printf("%d",ans);
}