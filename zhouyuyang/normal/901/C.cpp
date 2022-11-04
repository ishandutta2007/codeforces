#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
int n,m,Q,x,y,X,tot;
struct edge{int to,next;}e[N*2];
int fa[N],mark[N],head[N],hh[N];
ll can[N],sum[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	mark[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			if (mark[e[i].to]&&hh[x]) continue;
			if (mark[e[i].to]){
				int mn=x,mx=x;
				for (int t=x;;t=fa[t]){
					mn=min(mn,t);
					mx=max(mx,t);
					hh[t]=1;
					if (t==e[i].to) break;
				}
				can[mx]=max(can[mx],(ll)mn+1);
			}
			else{
				fa[e[i].to]=x;
				dfs(e[i].to);
			}
		}
}
ll he(ll x,ll y){
	return (x+y)*(y-x+1)/2;
}
ll can_he(ll x,ll y){
	return sum[y]-sum[x-1];
}
ll calc(ll x,ll y){
	if (x>y) return 0;
	if (x==y) return x-max(can[x],(ll)X);
	int mid=(x+y)/2;
	if (can[mid]>X)
		return he(mid,y)-can_he(mid,y)+calc(x,mid-1);
	return he(x,mid)-X*(mid-x+1)+calc(mid+1,y);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		can[i]=1;
	for (int i=1;i<=n;i++)
		if (!mark[i]) dfs(i);
	for (int i=1;i<=n;i++)
		can[i]=max(can[i],can[i-1]);
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+can[i];
	scanf("%d",&Q);
	while (Q--){
		scanf("%d%d",&x,&y); X=x;
		printf("%I64d\n",calc(x,y)+(y-x+1));
	}
}