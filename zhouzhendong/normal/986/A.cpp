#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct Gragh{
	static const int M=100005*2;
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,m,s,k;
vector <int> t[N];
int dis[N][105];
int q[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for (int i=1;i<=k;i++)
		t[i].clear();
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		t[x].push_back(i);
	}
	g.clear();
	for (int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		g.add(a,b),g.add(b,a);
	}
	memset(dis,-1,sizeof dis);
	for (int l=1;l<=k;l++){
		int head=0,tail=0;
		for (int j=0;j<t[l].size();j++)
			dis[q[++tail]=t[l][j]][l]=0;
		while (head<tail){
			int x=q[++head];
			for (int i=g.fst[x];i;i=g.nxt[i]){
				int y=g.y[i];
				if (dis[y][l]==-1){
					dis[y][l]=dis[x][l]+1;
					q[++tail]=y;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		sort(dis[i]+1,dis[i]+k+1);
		int ans=0;
		for (int j=1;j<=s;j++)
			ans+=dis[i][j];
		printf("%d ",ans);
	}
	return 0;
}