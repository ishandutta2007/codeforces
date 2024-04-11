#include<bits/stdc++.h>
using namespace std;
int n,m,k,aim,ans,l,r,mid,st[222],f[666][666];

int e[222][666],pre[666],used[666];

int fin(int x){
	for (int i=1;i<=n;i++){
		if (!e[x][i]||used[i]) continue;
		used[i]=1;
		if (!pre[i]||fin(pre[i])){
			pre[i]=x;
			return 1;
		}
	}
	return 0;
}
int doit(){
	memset(pre,0,sizeof pre);
	int t=0;
	for (int i=1;i<=k;i++){
		memset(used,0,sizeof used);
		if (fin(i)) t++;
	}
	return t;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&aim);
	for (int i=1;i<=k;i++){
		scanf("%d",&st[i]);
	}
	int x,y,z;
	memset(f,62,sizeof(f));
	for (int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=f[y][x]=min(f[x][y],z);
	}
	for (int w=1;w<=n;w++){
		for (int u=1;u<=n;u++){
			for (int v=1;v<=n;v++){
				if (w==u||w==v||u==v) continue;
				f[u][v]=min(f[u][v],f[u][w]+f[w][v]);
			}
		}
	}
	
	ans=-1;l=0;r=2222222;
	for (;l<=r;){
		mid=(l+r)>>1;
		memset(e,0,sizeof e);
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++){
				e[i][j]= f[st[i]][j]<=mid?1:0;
			}
		}
		if (doit()>=aim){
			r=(ans=mid)-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
}