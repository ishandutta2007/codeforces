#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],dl[N],dr[N],d[N],q[N];
int n,x,y,tot,l,r,ans,md;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void spfa(int S,int *d){
	for (int i=1;i<=n;i++) d[i]=-1;
	q[1]=S; d[S]=0;
	for (int h=0,t=1;h!=t;)
		for (int x=q[++h],i=head[x];i;i=e[i].next)
			if (d[e[i].to]==-1)
				d[e[i].to]=d[x]+1,q[++t]=e[i].to;
}
int dfs(int x,int fa){
	vector<int> vec;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) vec.push_back(dfs(e[i].to,x));
	sort(vec.begin(),vec.end());
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	if (x!=fa){
		if (vec.size()>1){
			puts("-1");
			exit(0);
		}
		return vec.empty()?1:vec[0]+1;
	}
	if (vec.size()>2) return -1;
	return vec[0]+vec[vec.size()-1];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	spfa(1,d); l=1;
	for (int i=2;i<=n;i++)
		if (d[i]>d[l]) l=i;
	spfa(l,dl); r=1;
	for (int i=2;i<=n;i++)
		if (dl[i]>dl[r]) r=i;
	spfa(r,dr); md=1;
	for (int i=2;i<=n;i++)
		if (dl[r]==dl[i]+dr[i]&&max(dl[i],dr[i])<max(dl[md],dr[md]))
			md=i;
	ans=dfs(md,md);
	for (;ans%2==0;ans/=2);
	printf("%d",ans);
}