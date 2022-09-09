#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,I=1<<25;
int T,n,a[N],x,y,i,j,f[N][2],ans;
vector<int>e[N];
void dfs(int x,int fa){
	f[x][0]=a[x]!=1?-I:0;f[x][1]=a[x]!=2?-I:0;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		for(i=0;i<2;++i)for(j=0;j<2;++j)ans=max(ans,f[x][i]+f[y][j]+(i!=j));
		if(a[x])for(i=0;i<2;++i)for(j=0;j<2;++j)f[x][i]=max(f[x][i],f[y][j]+(i!=j));
			else for(i=0;i<2;++i)f[x][i]=max(f[x][i],f[y][i]);
		if(a[x])f[x][(a[x]-1)^1]=-I;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n;for(i=1;i<=n;++i)cin>>a[i],e[i].clear();
		for(i=1;i<n;++i)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
		if(n==2){
			sort(a+1,a+3);
			cout<<(a[1]==1 && a[2]==2?2:1)<<'\n';continue;
		}
		ans=0;for(i=1;e[i].size()==1;++i);dfs(i,0);cout<<(ans+1)/2+1<<'\n';
	}
}