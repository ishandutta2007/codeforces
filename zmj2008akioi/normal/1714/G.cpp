#include <cstdio>
const int N=2e5+10;
int T,n,dnt,top,a[N],b[N],head[N],to[N],next[N],ans[N];
long long sa[N],sb[N];
int md(int l,int r){return (l+r)>>1;}
void ad(int u,int v,int p,int q){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v,a[dnt]=p,b[dnt]=q;}
int bsc(){
	int mid,l=0,r=top;
	while(l!=r){
		mid=md(l,r+1);
		if(sb[mid]<=sa[top])l=mid;
		else r=mid-1;
	}
	return l;
}
void dfs(int u){
	ans[u]=bsc(),++top;
	for(int i=head[u];i;i=next[i]){
		sa[top]=sa[top-1]+a[i],sb[top]=sb[top-1]+b[i],dfs(to[i]);
	}
	--top;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),dnt=0;
		for(int i=1;i<=n;++i)head[i]=0;
		for(int p,a,b,i=2;i<=n;++i)scanf("%d %d %d",&p,&a,&b),ad(p,i,a,b);
		dfs(1);
		for(int i=2;i<=n;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}