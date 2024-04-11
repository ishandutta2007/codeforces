#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
struct node{int l,r,s;}t[N*35];int tcnt;
void ins(int&x,int l,int r,int k){
	if(!x)x=++tcnt;++t[x].s;if(l==r)return;
	int m=l+r>>1;if(k<=m)ins(t[x].l,l,m,k);else ins(t[x].r,m+1,r,k);
}
ll S;
int merge(int x,int y){
	if(!x || !y)return x|y;
	t[x].s+=t[y].s;S+=1ll*t[t[x].l].s*t[t[y].r].s;
	t[x].l=merge(t[x].l,t[y].l);t[x].r=merge(t[x].r,t[y].r);
	return x;
}
int n,i,j,a[N],sz[N*35],ch[N*35][2],rt[N*35],xb,ans2;
ll s0[35],s1[35],ans1;
void dfs(int x,int d){
	if(d==-1)return;
	for(int y:ch[x])if(y)dfs(y,d-1);
	s0[d]+=1ll*sz[ch[x][0]]*sz[ch[x][1]];
	S=0;rt[x]=merge(rt[ch[x][0]],rt[ch[x][1]]);s1[d]+=S;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		int u=0,x;
		for(j=29;j>=0;--j){
			x=a[i]>>j&1;
			if(!ch[u][x])ch[u][x]=++xb;
			u=ch[u][x];++sz[u];
		}
		ins(rt[u],1,n,i);
	}
	dfs(0,29);
	for(i=0;i<30;++i)if(s0[i]-s1[i]>s1[i])ans2|=1<<i,ans1+=s1[i];else ans1+=s0[i]-s1[i];
	printf("%lld %d\n",ans1,ans2);
}