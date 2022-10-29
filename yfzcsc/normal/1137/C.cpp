#include<bits/stdc++.h>
using namespace std;
const int maxn=101000;
typedef pair<int,int> pii;
vector<int>G[maxn],H[maxn];
int dp[maxn][60],n,m,d;
long long tg[maxn],val[maxn];
int sta[maxn],mx[60],ntp,tp,low[maxn],insta[maxn],dfn[maxn],tim;
int q[maxn],bel[maxn],id,Z[maxn][60];
char S[maxn];
int inline nxt(int x){
	return x==d-1?0:x+1;
}
void sol1(int id){
	static pii Q[maxn*60];
	int l,r;
	l=r=0;
	Q[r++]=pii(H[id][0],0);
	val[H[id][0]]|=1<<0;
//	for(auto a:H[id])printf("[%d]",a);
	while(l<r){
		pii u=Q[l++];
//		printf("{%d,%d}",u.first,u.second);
		for(auto v:G[u.first])if(bel[v]==bel[u.first]&&
			(val[v]>>nxt(u.second)&1)==0){
				Q[r++]=pii(v,nxt(u.second));
				val[v]|=1ll<<nxt(u.second);
			}
	}
	for(auto v:H[id]){
		long long zx=val[v];
//		for(int i=0;i<d;++i)printf("%d",zx>>i&1);printf("[%d]\n",v);
		for(int i=0;i<d;++i){
			Z[id][i]+=(zx&tg[v])!=0;
			zx=(zx<<1)|(zx>>d-1&1);
		}
	}
//	for(int i=0;i<d;++i)printf("[%d]",Z[id][i]);puts("");
}
void tarjan(int u){
	dfn[u]=low[u]=++tim;
	sta[++tp]=u,insta[u]=1;
	for(auto v:G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		} else if(insta[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int v;
		++id;
//		printf("tarjan:<%d>",u);
		do{
			v=sta[tp--];
			bel[v]=id;
			insta[v]=false;
			H[id].push_back(v);
//			printf("[%d->%d]",id,v);
		}while(u!=v);
		sol1(id);
		q[++ntp]=id;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
//		u=i,v=i==n?1:i+1;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;++i){
//		for(int j=0;j<d;++j)S[j]='0';
//		S[i-1]='1';
		scanf("%s",S);
//		for(int j=0;j<d;++j)S[j]='1';
		for(int j=0;j<d;++j)
			tg[i]|=1ll*(S[j]-'0')<<j;
	}
	tarjan(1);
	for(int i=1;i<=ntp;++i){
		int uid=q[i];
//		printf("[%d]",uid);
		memset(mx,0,sizeof(mx));
		for(auto u:H[uid]){
			for(auto v:G[u])if(bel[v]!=bel[u]){
				for(int j=0;j<d;++j)
					dp[u][j]=max(dp[u][j],dp[v][nxt(j)]);
			}
			for(int i=0;i<d;++i)
				for(int j=0;j<d;++j)if(val[u]>>j&1){
					int z=(i+j)%d;
					mx[i]=max(mx[i],dp[u][z]);
				}
		}
		for(auto u:H[uid]){
			for(int i=0;i<d;++i)
				for(int j=0;j<d;++j)if(val[u]>>j&1){
					int A=(i+d-j)%d;		
					dp[u][i]=max(dp[u][i],mx[A]+Z[uid][A]);
				}
		}
		/*
		for(auto u:H[uid]){
			for(int i=0;i<d;++i)printf("[%d]",dp[u][i]);
			printf("<%d>\n",u);
		}
		puts("<<<");*/
	}
	printf("%d",dp[1][0]);
}