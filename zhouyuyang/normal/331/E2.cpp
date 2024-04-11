#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define For2(i,j) for (int i=1;i<=j;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233);
#define pii pair<int,int>
using namespace std;
const int mo=1000000007;
const int N=52;
int g[2][2][N][N][N*2];
int f[N*2][N][2];
int n,m,st[N*N],ed[N*N];
vector<int> seq[N*N];
int e[N][N];
pii walk(vector<int> &tp,int x,bool fl){
	int now=0;
	for (;now+1<=tp.size();){
		int y=tp[now],ed=e[x][y];
		if (!ed||tp.size()>2*n||(ed>m)!=fl)
			return pii(23333,-1);
		for (int j=0;j<seq[ed].size();j++)
			tp.push_back(seq[ed][j]);
		x=y; now++;
	}
	return pii(tp.size(),x);
}
int man[N][N][N*2];
int wei[N][N][N*2];
void work(bool fl){
	memset(man,0,sizeof(man));
	memset(wei,0,sizeof(wei));
	For2(i,2*m) if ((i<=m)^fl)
		for (int j=0;j<seq[i].size();j++) if (seq[i][j]==st[i]){
			vector<int> t1,t2;
			for (int k=j-1;k>=0;k--) t1.push_back(seq[i][k]);
			pii res=walk(t1,st[i],fl^1);
			if (res.first>2*n) continue;
			if (j+1==seq[i].size())
				wei[res.second][ed[i]][res.first+1]++;
			else if (seq[i][j+1]==ed[i]){
				for (int k=j+2;k<seq[i].size();k++)
					t2.push_back(seq[i][k]);
				pii res2=walk(t2,ed[i],fl);
				if (res2.first+1+res.first<=2*n)
					man[res.second][res2.second][res2.first+1+res.first]++;
			}
		}
}
int main(){
	scanf("%d%d",&n,&m);
	For2(i,m){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		e[x][y]=i; e[y][x]=i+m;
		st[i]=ed[i+m]=x; st[i+m]=ed[i]=y;
		For2(j,k){
			int v;
			scanf("%d",&v);
			seq[i].push_back(v);
		}
		seq[i+m]=seq[i];
		reverse(seq[i+m].begin(),seq[i+m].end());
		if (!k) g[0][0][x][y][1]++;
	}
	work(0);
	For2(i,n) For2(j,n) For2(k,n*2)
		g[1][1][i][j][k]=man[i][j][k],
		g[1][0][i][j][k]=wei[i][j][k];
	work(1);
	For2(i,n) For2(j,n) For2(k,n*2)
		g[0][1][j][i][k]=wei[i][j][k];
	For2(i,n) For2(j,n) For2(k,n*2) For(v,0,1)
		UPD(f[k][j][v],g[1][v][i][j][k]);
	For2(k,n*2){
		int ans=0;
		For2(i,n){
			UPD(ans,f[k][i][1]);
			For(mid,0,1) if (f[k][i][mid])
				For(ed,0,1) For2(zd,n) For2(l,2*n-k)
					UPD(f[k+l][zd][ed],1ll*f[k][i][mid]*g[mid^1][ed][i][zd][l]%mo);
		}
		printf("%d\n",ans);
	}
}