#include<bits/stdc++.h>
#define N 101000
using namespace std;
int n,m,k,T,sz[N],t1[N],t2[N],tim,w[N],nrt[N];
vector<int>r[N];

inline dfs(int x){
	if (t1[x]) assert(0);
	t1[x]=++tim;
	sz[x]=1;
	for (int y:r[x]){
		dfs(y);
		sz[x]+=sz[y];
	}
	t2[x]=++tim;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&T);
	int x,y;
	for (;k--;w[y]=x){
		scanf("%d%d",&x,&y);
		if (w[y]) r[w[y]].push_back(x),nrt[x]=1;
	}
	for (int i=1;i<=n;i++) if (!nrt[i]) dfs(i);
	for (;T--;){
		scanf("%d%d",&x,&y);
		printf("%d\n",(w[y]&&t1[x]<t1[w[y]]&&t2[x]>t2[w[y]])?sz[x]:0);
	}
}