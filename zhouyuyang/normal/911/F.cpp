#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int d[N],dl[N],dr[N],dd[N];
int head[N],q[N],id[N],a[N];
long long ans;
int n,tot;
bool cmp(int x,int y){
	if (dd[x]!=dd[y]) return dd[x]>dd[y];
	return dl[x]>dl[y]; 
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void bfs(int S,int *d){
	for (int i=1;i<=n;i++) d[i]=-1;
	d[S]=0; q[1]=S;
	for (int h=0,t=1;h!=t;)
		for (int x=q[++h],i=head[x];i;i=e[i].next)
			if (d[e[i].to]==-1)
				d[e[i].to]=d[x]+a[e[i].to],q[++t]=e[i].to;
}
int findmax(int *d){
	int mx=1;
	for (int i=2;i<=n;i++)
		if (d[mx]<d[i]) mx=i;
	return mx;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		a[i]=1;
	bfs(1,d);
	int l=findmax(d);
	bfs(l,dl);
	int r=findmax(dl);
	bfs(r,dr);
	for (int i=1;i<=n;i++)
		if (dl[i]+dr[i]==dl[r]) a[i]=0;
		else ans+=max(dl[i],dr[i]);
	ans+=1ll*dl[r]*(dl[r]+1)/2;
	printf("%I64d\n",ans);
	bfs(l,dd);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<n;i++)
		if (dd[id[i]]){
			int tmp=dl[id[i]]>dr[id[i]]?l:r;
			printf("%d %d %d\n",tmp,id[i],id[i]);
		}
		else printf("%d %d %d\n",l,id[i],id[i]);
}