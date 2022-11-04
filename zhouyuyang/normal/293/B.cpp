#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[15][15],vis[15][15],vis1[15][15],cnt[15];
int dfs(int x,int y){
	if (y>m) y=1,x++;
	if (x>n){return 1;}
	int tmp=(vis[x][y-1]|vis[x-1][y]),s=-1,ans=0;
	if (a[x][y]){
		if ((tmp&(1<<a[x][y]))||(vis1[x][y]&(1<<a[x][y]))) return 0;
		vis[x][y]=tmp|(1<<a[x][y]);
		return dfs(x,y+1);
	}
	for (int i=1;i<=k;i++){
		if ((tmp&(1<<i))||(vis1[x][y]&(1<<i))) continue;
		vis[x][y]=tmp|(1<<i);
		cnt[i]++;
		if (cnt[i]==1){
			if (s==-1) s=dfs(x,y+1);
			ans=(ans+s)%1000000007;
		}
		else ans=(ans+dfs(x,y+1))%1000000007;
		cnt[i]--;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if (n+m-1>k){
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			cnt[a[i][j]]++;
			for (int k=1;k<=i;k++)
				for (int l=1;l<=j;l++)
					if (k!=i||l!=j)
						vis1[k][l]|=1<<a[i][j];
		}
	printf("%d\n",dfs(1,1));
}