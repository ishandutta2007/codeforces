#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,i,j,a,b,t[N],v[N],w[N],xb;
vector<int>e[N];
bool bb[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
	for(i=1;i<=n;++i)scanf("%d",t+i),v[i]=i;
	sort(v+1,v+n+1,[&](int x,int y){return t[x]<t[y];});
	for(i=1;i<=n;++i){
		bb[v[i]]=1;
		xb=0;for(int x:e[v[i]])if(bb[x])w[++xb]=t[x];
		sort(w+1,w+xb+1);
		for(j=1;j<=xb && w[j]<=w[j-1]+1;++j);
		if(t[v[i]]!=w[j-1]+1){puts("-1");return 0;}
	}
	for(i=1;i<=n;++i)printf("%d%c",v[i],i==n?'\n':' ');
}