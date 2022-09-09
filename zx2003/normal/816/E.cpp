#include<bits/stdc++.h>
using namespace std;
const int N=5010;
typedef long long ll;
int n,i,xb;
vector<int> e[N];
ll f[N][N],a[N],b[N],m,x,dfn[N],sz[N];
void dfs(int x,int fa){
	sz[x]=1;
	int j,k,y,z;
	ll s=0;
	dfn[z=++xb]=a[x];
	unsigned int i;
	f[x][1]=b[x];
	for(i=0;i<e[x].size();++i){
		y=e[x][i];
		if(y!=fa){
			dfs(y,x);
			for(j=sz[x];j>=1;--j)
				for(k=1;k<=sz[y];++k)
					if(!f[x][j+k] || f[x][j]+f[y][k]<f[x][j+k])f[x][j+k]=f[x][j]+f[y][k];
			sz[x]+=sz[y];
		}
	}
	sort(dfn+z,dfn+xb+1);
	for(j=z;j<=xb;++j){
		s+=dfn[j];
		if(!f[x][j-z+1] || s<f[x][j-z+1])f[x][j-z+1]=s;
	}
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		b[i]=a[i]-b[i];
		if(i>1)cin>>x,e[x].push_back(i);
	}
	dfs(1,0);
	for(i=1;i<=n;++i)if(f[1][i]>m)break;
	cout<<i-1<<endl;
	return 0;
}