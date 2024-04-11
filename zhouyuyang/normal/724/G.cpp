#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
#define N 100005
using namespace std;

struct edge{
	int to,next;
	ll v;
}e[N*4];
int head[N],tot;
int q[N],vis[N];
ll dis[N],a[N],b[N*3];
ll ans;
int n,m;
void add(int x,int y,ll v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void work(int S){
	int h=0,t=1,sum=0,P=1; a[1]=0;
	dis[S]=0; q[1]=S; vis[S]=1;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (vis[e[i].to]){
				if (dis[x]^dis[e[i].to]^e[i].v)
					b[++sum]=dis[x]^dis[e[i].to]^e[i].v;
			}
			else{
				vis[e[i].to]=1;
				dis[e[i].to]=dis[x]^e[i].v;
				a[++P]=dis[e[i].to];
				q[++t]=e[i].to;
			}
	}
	ll all=0; int cnt=0;
	for (int i=1;i<=sum;i++)
		if (b[i]){
			cnt++; all|=b[i];
			ll bit=b[i]&(-b[i]);
			for (int j=i+1;j<=sum;j++)
				if (b[j]&bit) b[j]^=b[i];
		}
	if (cnt)
		ans=(ans+1ll*P*(P-1)/2%mo*((1ll<<(cnt-1))%mo)%mo*(all%mo))%mo;
	for (int B=0;B<=62;B++)
		if (!((all>>B)&1)){
			int count=0;
			for (int i=1;i<=P;i++)
				if ((a[i]>>B)&1) count++;
			ans=(ans+(1ll<<B)%mo*count%mo*(P-count)%mo*((1ll<<cnt)%mo))%mo; 
		} 
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y; ll v;
		scanf("%d%d%lld",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) work(i);
	printf("%lld\n",ans);
}