#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
int f[maxn],n,m,w[maxn],rel[maxn];
vector<int>ve[maxn];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int u,int v){f[find(u)]=find(v);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1;i<=m*2;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int k,u;scanf("%d",&k);
		while(k--)scanf("%d",&u),ve[u].push_back(i);
	}
	for(int i=1;i<=n;++i){
		int x=i,u=ve[i][1],v=ve[i][0],u2,v2;
	//	printf("[%d,%d,%d]\n",x,u,v);
		if(w[i]==1)merge(u,v),merge(u+m,v+m);
		else merge(u+m,v),merge(v+m,u);
	}
	for(int i=1;i<=m;++i)if(find(i)==find(i+m))return printf("NO"),0;
	printf("YES");
}