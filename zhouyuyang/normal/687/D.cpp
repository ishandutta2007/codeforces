#include<bits/stdc++.h>
#define maxn 1010
using namespace std;
int n,m,Q;
struct Node{
	int x,y,V,id;
	bool operator<(const Node &t)const{return V<t.V;}
}A[maxn*maxn];
int fa[maxn],f[maxn];
int find(int u){
	if(fa[u]==u)return u;
	int t=find(fa[u]);
	f[u]^=f[fa[u]];
	return fa[u]=t;
}
bool Union(int u,int v){
	int uf=find(u),vf=find(v);
	if(uf!=vf){
		fa[uf]=vf;f[uf]=f[u]^f[v]^1;
		find(u);
	}
	return f[u]!=f[v];
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].V),A[i].id=i;
	sort(A+1,A+m+1);
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int i=1;i<=n;i++)fa[i]=i,f[i]=0;
		int ans=-1;
		for(int i=m;i;i--)if(A[i].id>=l&&A[i].id<=r)
			if(!Union(A[i].x,A[i].y)){
				ans=A[i].V;break;
			}
		printf("%d\n",ans);
	}
}