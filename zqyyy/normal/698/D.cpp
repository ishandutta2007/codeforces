#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
struct node{int x,y;}a[9],b[N];
inline bool pd(node x,node y,node z){//y between x and z
	if(!(min(x.x,z.x)<=y.x && y.x<=max(x.x,z.x) && min(x.y,z.y)<=y.y && y.y<=max(x.y,z.y)))return 0;
	return 1ll*(x.y-y.y)*(x.x-z.x)==1ll*(x.y-z.y)*(x.x-y.x);
}
int n,m,t,p[9];
vector<int>vec[9][N],lst;
bool vis[N];
bool dfs(int x){
	if(t>m)return 0;
	for(int y:vec[p[t]][x])
		if(!vis[y]){
			t++;
			if(!dfs(y))return 0;
		}
	return lst.push_back(x),vis[x]=1,1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	m=read(),n=read();
	for(int i=1;i<=m;i++)a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;i++)b[i].x=read(),b[i].y=read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(j!=k && pd(a[i],b[k],b[j])){
					vec[i][j].push_back(k);
					if((int)vec[i][j].size()==m)break;
				}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)p[j]=j;
		do{
			while(!lst.empty())vis[lst.back()]=0,lst.pop_back();
			t=1;if(dfs(i)){ans++;break;}
		}while(next_permutation(p+1,p+m+1));
	}
	printf("%d\n",ans);
	return 0;
}