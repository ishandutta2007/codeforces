#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
vector<int>G[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int rt=0;
	for(int i=1;i<=n;++i)
		if(G[i].size()>2&&!rt)rt=i;
		else if(G[i].size()>2)rt=-1;
	if(rt==0){
		printf("Yes\n1\n");
		for(int i=1;i<=n;++i)if(G[i].size()==1)
			printf("%d ",i);
	} else if(rt>0){
		int cnt=0;
		for(int i=1;i<=n;++i)if(G[i].size()==1)cnt++;
		printf("Yes\n%d\n",cnt);
		for(int i=1;i<=n;++i)if(G[i].size()==1)printf("%d %d\n",rt,i);
	} else puts("No");
}