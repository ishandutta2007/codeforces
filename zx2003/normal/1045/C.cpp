#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<24],*ih=ibuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
const int N=100005;
int f[22][N],dep[N],n,m,qq,x,y,i,j;
vector<int>e[N];
pair<int,int>a[N*5];
inline bool aske(int x,int y){
	if(x>y)swap(x,y);
	pair<int,int>z=make_pair(x,y);
	return *lower_bound(a+1,a+m+1,z)==z;
}
int q[N],t,w;
inline int lca(int x,int y){
	int i,d;
	if(dep[x]>dep[y])swap(x,y);d=dep[y]-dep[x];
	for(i=19;i>=0;--i)if(d>>i&1)y=f[i][y];
	if(x==y)return x;
	for(i=19;i>=0;--i)if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return f[0][x];
}
inline int ka(int x,int k){
	for(int i=19;i>=0;--i)if(k>>i&1)x=f[i][x];
	return x;
}
int main(){
	fread(ibuf,1,1<<24,stdin);
	read(n);read(m);read(qq);
	for(i=1;i<=m;++i){
		read(x);read(y);a[i]=make_pair(x,y);
		e[x].push_back(y);e[y].push_back(x);
	}
	sort(a+1,a+m+1);dep[1]=1;q[w=1]=1;
	for(;t<w;){
		x=q[++t];
		for(i=0;i<e[x].size();++i){
			y=e[x][i];
			if(!dep[y])q[++w]=y,dep[y]=dep[x]+1,f[0][y]=x;
		}
	}
	for(i=1;i<20;++i)for(j=1;j<=n;++j)f[i][j]=f[i-1][f[i-1][j]];
	while(qq--){
		read(x);read(y);
		int z=lca(x,y),ans;
		if(x==z){
			ans=dep[y]-dep[z];
		}else if(y==z){
			ans=dep[x]-dep[z];
		}else{
			ans=dep[x]+dep[y]-dep[z]*2;
			int u=ka(x,dep[x]-dep[z]-1),v=ka(y,dep[y]-dep[z]-1);
			ans-=aske(u,v);
		}
		printf("%d\n",ans);
	}
	return 0;
}