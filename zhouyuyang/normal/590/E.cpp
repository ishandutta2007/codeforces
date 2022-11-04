#include<bits/stdc++.h>
using namespace std;
const int N=10000005,M=755;
int ch[N][2],q[N];
int fail[N],pre[N];
int n,m,tot,cnt,ans;
char s[N];
int lp[M],rp[M],ul[M],ur[M];
int to[M][M],vis[M],from[N];
int id[M];
void build(){
	int h=0,t=1; q[1]=1;
	while (h!=t){
		int x=q[++h];
		for (int i=0;i<2;i++)
			if (ch[x][i]){
				q[++t]=ch[x][i];
				if (x==1) fail[ch[x][i]]=1;
				else fail[ch[x][i]]=ch[fail[x]][i];
				if (!pre[ch[x][i]])
					pre[ch[x][i]]=pre[fail[ch[x][i]]];
			}
			else{
				if (x==1) ch[x][i]=1;
				else ch[x][i]=ch[fail[x]][i];
			}
	}
}

int dfs(int x){
	for (int i=1;i<=m;i++)
		if (i!=x&&to[x][i]&&!vis[i]){
			vis[i]=1;
			if (!from[i]||dfs(from[i])){
				from[i]=x;
				return 1;
			}
		}
	return 0;
}

void dfs2(int x){
	for (int i=1;i<=m;i++)
		if (i!=x&&to[x][i]&&!ur[i]){
			ur[i]=1; ul[from[i]]=0;
			dfs2(from[i]);
		}
}

int main(){
	scanf("%d",&n);
	tot=1;
	for (int i=1;i<=n;i++){
		lp[i]=rp[i-1];
		scanf("%s",s+lp[i]);
		rp[i]=strlen(s+lp[i])+lp[i];
		int x=1;
		for (int j=lp[i];j<rp[i];j++){
			int tmp=s[j]-'a';
			if (!ch[x][tmp])
				ch[x][tmp]=++tot;
			x=ch[x][tmp];
		}
		if (!pre[x])
			pre[x]=++m,id[m]=i;
	}
	build();
	for (int i=1;i<=m;i++){
		int x=1;
		for (int j=lp[id[i]];j<rp[id[i]];j++){
			x=ch[x][s[j]-'a'];
			if (j!=rp[id[i]]-1)
				to[pre[x]][i]=1;
			else to[pre[fail[x]]][i]=1;
		}
		to[i][i]=1;
	}
	for (int k=1;k<=m;k++)
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++)
				to[i][j]|=to[i][k]&to[k][j];
	for (int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis));
		ans+=dfs(i);
	}
	printf("%d\n",m-ans);
	for (int i=1;i<=m;i++)
		ul[from[i]]=1;
	for (int i=1;i<=m;i++)
		if (!ul[i]) dfs2(i);
	for (int i=1;i<=m;i++)
		if (!ul[i]&&!ur[i])
			printf("%d ",id[i]);
}