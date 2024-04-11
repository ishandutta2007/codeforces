#include<bits/stdc++.h>
#define maxn 10001000
#define lim 10000000
#define maxm 1001000
using namespace std;
typedef long long ll;
struct edge{
	int r,nxt;
}d[maxm];
int f[maxn],g[maxn];
ll s[maxn];
int n,m,k,buy,anses[maxm],head[maxn],esz;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,a;i<=n;++i)scanf("%d",&a),f[a]++;
	for(int i=1,a;i<=m;++i)scanf("%d",&a),g[a]++,d[++esz].r=i,d[esz].nxt=head[a],head[a]=esz;
	s[0]=f[0];
	for(int i=1;i<=lim;++i)s[i]=f[i]+s[i-1];
	for(int i=0;i<=lim;++i)s[i]=1ll*(i+1)*k-s[i];//printf("[%d]",s[i]);
	for(int i=lim-1;i>=0;--i)s[i]=min(s[i],s[i+1]);
//	printf("[%d]",s[0]);
	if(s[0]<0){
//		printf("[%d]",s[0]);
		printf("-1");
		return 0;
	}
	for(int i=0;i<=lim;++i){
		int t=head[i];
		while(g[i]>0&&s[i]-buy-1>=0)buy++,g[i]--,anses[buy]=d[t].r,t=d[t].nxt;
	}
	printf("%d\n",buy);
	for(int i=1;i<=buy;++i)printf("%d ",anses[i]);
}