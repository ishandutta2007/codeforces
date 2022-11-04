#include<bits/stdc++.h>
#define mo 1000000007
#define N 100005
using namespace std;
struct edge{int to,next;}e[N*2];
int f[N][3][11],tmp[3][11];
int head[N],n,m,tot,k,mx,ans;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
void dfs(int x,int fa){
	f[x][0][0]=k-1;
	f[x][1][1]=1;
	f[x][2][0]=m-k;
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to==fa) continue;
		int y=e[i].to; dfs(y,x);
		memset(tmp,0,sizeof(tmp));
		for (int j=0;j<=mx;j++)
			for (int k=0;k+j<=mx;k++)
				for (int jp=0;jp<3;jp++)
					for (int kp=0;kp<3;kp++){
						if (jp==1&&kp) continue;
						if (kp==1&&jp) continue;
						upd(tmp[jp][j+k],1ll*f[x][jp][j]*f[y][kp][k]%mo);
					}
		memcpy(f[x],tmp,sizeof(f[x]));
	}
} 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	scanf("%d%d",&k,&mx);
	dfs(1,0);
	for (int i=0;i<3;i++)
		for (int j=0;j<=mx;j++)
			upd(ans,f[1][i][j]);
	printf("%d",ans); 
}