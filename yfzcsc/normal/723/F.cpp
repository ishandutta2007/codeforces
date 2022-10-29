#include<bits/stdc++.h>
#define maxm 450000
#define maxn 200100
using namespace std;
struct edge{
	int u,v;
}e[maxm];
int f[maxn],n,m,s,t,ds,dt;
bool use[maxm],a[maxn][2],g;
int find(int  x){return f[x]==x?x:f[x]=find(f[x]);}
void fuck(int p,int& d,int z){
	for(int i=1,x,y;i<=m;++i)if(!use[i]){
		if(e[i].u==s&&e[i].v==t)continue;
		if(e[i].u==t&&e[i].v==s)continue;
		if(e[i].u==p)x=e[i].u,y=e[i].v;
		else if(e[i].v==p)x=e[i].v,y=e[i].u;
		else continue;
		if(a[y][z])continue;
		int fu=find(x),fv=find(y);
		if(fu==fv)continue;
		else if(d==0)break;
		else if(d>0){
			f[fu]=fv;
			use[i]=true;
			d--;
		}
	}
	if(d>0)for(int i=1,x,y;i<=m;++i)if(!use[i]){
		if(e[i].u==s&&e[i].v==t)continue;
		if(e[i].u==t&&e[i].v==s)continue;
		if(e[i].u==p)x=e[i].u,y=e[i].v;
		else if(e[i].v==p)x=e[i].v,y=e[i].u;
		else continue;
		int fu=find(x),fv=find(y);
		if(fu==fv)continue;
		else if(d==0)break;
		else if(d>0){
			f[fu]=fv;
			use[i]=true;
			d--;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&e[i].u,&e[i].v);
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	for(int i=1;i<=m;++i){
		if(e[i].u==s)a[e[i].v][0]=true;
		if(e[i].v==s)a[e[i].u][0]=true;
		if(e[i].u==t)a[e[i].v][1]=true;
		if(e[i].v==t)a[e[i].u][1]=true;
	}
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i)if(e[i].u!=s&&e[i].u!=t&&e[i].v!=s&&e[i].v!=t){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		else f[fu]=fv,use[i]=true;
	}
	if(ds>dt)fuck(s,ds,1),fuck(t,dt,0);
	else fuck(t,dt,0),fuck(s,ds,1);
	if(find(s)!=find(t)&&a[s][1])
		ds--,dt--,g=true,f[find(s)]=find(t);
	if(ds<0||dt<0){
		printf("No\n");
		return 0;
	}
//	for(int i=1;i<=n;++i)printf("[%d-%d]",i,find(i));
	for(int i=1;i<=n;++i)if(find(1)!=find(i)){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if(g)printf("%d %d\n",s,t);
	for(int i=1;i<=m;++i)if(use[i])printf("%d %d\n",e[i].u,e[i].v);
}