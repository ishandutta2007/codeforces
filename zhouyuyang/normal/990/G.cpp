#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int> vec[N],e[N];
int fa[N],q[N],vis[N];
long long ans[N];
int n,T,sz[N];
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		vec[x].push_back(i);
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i=N;i>=1;i--){
		int tot=0; ++T;
		for (int j=i;j<N;j+=i)
			for (int k=0;k<vec[j].size();k++)
				q[++tot]=vec[j][k];
		for (int j=1;j<=tot;j++)
			vis[q[j]]=T,fa[q[j]]=q[j],sz[q[j]]=1;
		for (int j=1;j<=tot;j++){
			int x=q[j];
			for (int k=0;k<e[x].size();k++)
				if (vis[e[x][k]]==T){
					int X=get(x),Y=get(e[x][k]);
					if (X!=Y) fa[Y]=X,sz[X]+=sz[Y];
				}
		}
		T++;
		for (int j=1;j<=tot;j++){
			int x=get(q[j]);
			if (vis[x]!=T){
				ans[i]+=1ll*sz[x]*(sz[x]+1)/2;
				vis[x]=T;
			}
		}
		for (int j=i+i;j<N;j+=i)
			ans[i]-=ans[j];
	}	
	for (int j=1;j<N;j++)
		if (ans[j]) printf("%d %lld\n",j,ans[j]);
}