#include<bits/stdc++.h>
using namespace std;
int n,m,k,aim,st[205],f[605][605];
int e[205][605],pre[605];
bool use[605];
int dfs(int x){
	for (int i=1;i<=n;i++){
		if (!e[x][i]||use[i]) continue;
		use[i]=1;
		if (!pre[i]||dfs(pre[i])){
			pre[i]=x; return 1;
		}
	}
	return 0;
}
int doit(){
	memset(pre,0,sizeof(pre));
	int ans=0;
	for (int i=1;i<=k;i++){
		memset(use,0,sizeof(use));
		if (dfs(i)) ans++;
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&aim);
	for (int i=1;i<=k;i++) scanf("%d",&st[i]);
	memset(f,60,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		f[x][y]=f[y][x]=min(f[x][y],z);
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)	
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int l=0,r=1800000,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		memset(e,0,sizeof(e));
		for (int i=1;i<=k;i++)
			for (int j=1;j<=n;j++)
				e[i][j]=(f[st[i]][j]<=mid?1:0);
		if (doit()>=aim) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}