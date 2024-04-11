#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],m,i,j,x,y,T[N<<2],M,ans[N];
pair<int,int>aa[N];
vector<pair<int,int>>qu[N];
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i),aa[i]={-a[i],i};sort(aa+1,aa+n+1);
	scanf("%d",&m);for(i=1;i<=m;++i)scanf("%d%d",&x,&y),qu[x].push_back({y,i});
	for(M=1;M<n;M<<=1);
	for(i=1;i<=n;++i){
		for(j=aa[i].second+M-1;j;j>>=1)++T[j];
		for(auto u:qu[i]){
			for(j=1,x=u.first;j<M;)if(x<=T[j<<1])j=j<<1;else x-=T[j<<1],j=j<<1|1;
			ans[u.second]=a[j-M+1];
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}