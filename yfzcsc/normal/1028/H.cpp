#include<bits/stdc++.h>
#define maxn 210100
#define maxm 1101000
#define maxk 5101000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=1e9+7;
int pri[maxk/10],psz,n,q,nxt[maxk];
bool vis[maxk];
int mn[maxn<<2],zkwm=1;
int anses[maxm],wxh,a[maxn],f[200],g[200],dp[200];
vector<pii>Q[maxn];
int sta[maxk][8],sz[maxk];
void mdy(int l,int r,int a){
	if(l>r)return ;
	l+=zkwm-1-1,r+=zkwm+1-1;
	for(;l^r^1;l>>=1,r>>=1){
		if(~l&1)mn[l^1]=min(mn[l^1],a);
		if(r&1)mn[r^1]=min(mn[r^1],a);
	}
}
int qry(int x){
	x+=zkwm-1;
	int ret=inf;
	for(;x;x>>=1)ret=min(ret,mn[x]);
	return ret;
}
int main(){
	int M=5100000;
	for(int i=2;i<=M;++i){
		if(!vis[i])pri[++psz]=i,nxt[i]=i;
		for(int j=1;j<=psz&&i*pri[j]<=M;++j){
			vis[i*pri[j]]=1,nxt[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	scanf("%d%d",&n,&q);
	for(zkwm=1;zkwm-2<=n;zkwm<<=1);
	for(int i=1;i<=zkwm*2;++i)mn[i]=inf;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1,l,r;i<=q;++i){
		scanf("%d%d",&l,&r);
		Q[r].push_back(pii(l,i));
	}
	for(int i=0;i<128;++i)dp[i]=__builtin_popcount(i);
	for(int i=1;i<=n;++i){
		int lst=-1,c=0,d=0;
		for(int j=a[i];j!=1;j/=nxt[j]){
			if(lst!=nxt[j])f[++c]=nxt[j],g[c]=1;
			else g[c]^=1;
			lst=nxt[j];
		}
		for(int j=1;j<=c;++j)if(g[j])
			f[++d]=f[j];
		a[i]=c=d; 
		for(int j=0;j<(1<<c);++j){
			int bt=c-dp[j],x=1;
			for(int k=1;k<=c;++k)if(j>>k-1&1)x*=f[k];
			for(int k=0;k<sz[x];++k)
				mdy(k==0?1:sta[x][k-1]+1,sta[x][k],a[sta[x][k]]+a[i]-2*dp[j]);
			while(sz[x]&&a[sta[x][sz[x]-1]]>=a[i])sz[x]--;
			sta[x][sz[x]++]=i;
		}
		for(auto c:Q[i])
			anses[c.second]=qry(c.first);
	}
	for(int i=1;i<=q;++i)printf("%d\n",anses[i]);
}