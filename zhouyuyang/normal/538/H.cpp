#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,T,n,m;
int co[N],l[N],r[N];
vector<int> e[N];
void GG(){
	puts("IMPOSSIBLE");
	exit(0);
}
void dfs(int x,int col){
	if (co[x]){
		if (co[x]!=col) GG();
		return;
	}
	co[x]=col;
	for (int i=0;i<e[x].size();i++)
		dfs(e[x][i],3-col);
}
bool chk(int i,int x){
	return l[i]<=x&&x<=r[i];
}
int main(){
	scanf("%d%d",&t,&T);
	scanf("%d%d",&n,&m);
	int mxl=0,mnr=1e9;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		mnr=min(mnr,r[i]);
		mxl=max(mxl,l[i]);
	}
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if (mnr+mxl<t) mxl=t-mnr;
	else if (mnr+mxl>T) mnr=T-mxl;
	if (mxl<0||mnr<0) GG();
	for (int i=1;i<=n;i++)
		if (chk(i,mxl)){
			if (!chk(i,mnr)) dfs(i,1);
		}
		else if (chk(i,mnr)) dfs(i,2);
		else GG();
	for (int i=1;i<=n;i++)
		if (!co[i]) dfs(i,1);
	printf("POSSIBLE\n%d %d\n",mxl,mnr);
	for (int i=1;i<=n;i++) printf("%d",co[i]);
}