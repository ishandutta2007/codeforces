#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,x,y,i,j,dfn[N],dcnt,aa[N],dad[N],t1[N],t2[N],p[N];
bool ins[N],fl,bb[N];
vector<int>e[N],ans;
void dfs(int x){
	dfn[x]=++dcnt;ins[x]=1;
	for(int y:e[x])if(!dfn[y])dfs(y);else fl|=!ins[y];ins[x]=0;
}
void dfs2(int x){
	dfn[x]=++dcnt;aa[dcnt]=x;
	for(int y:e[x]){
		if(!dfn[y])dad[y]=x,dfs2(y),t1[x]+=t1[y],t2[x]^=t2[y];
			else ++t1[x],--t1[y],t2[x]^=y,t2[y]^=y;
	}
}
int main(){
//	freopen("1","r",stdin);
	mt19937 R(time(0));
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)e[i].clear();
		for(i=1;i<=m;++i)scanf("%d%d",&x,&y),e[x].push_back(y);
		for(i=1;i<=n;++i)p[i]=i,swap(p[R()%i+1],p[i]);
		int lim=min(200,n);
		for(i=1;i<=lim;++i){
			dcnt=fl=0;memset(dfn+1,0,n<<2);
			dfs(p[i]);if(dcnt==n && !fl)break;
		}
		if(i>lim){puts("-1");continue;}
		dcnt=0;memset(dfn+1,0,n<<2);memset(t1+1,0,n<<2);memset(t2+1,0,n<<2);
		dfs2(p[i]);
		bb[p[i]]=1;
		for(j=2;j<=n;++j)x=aa[j],bb[x]=t1[x]==1 && bb[t2[x]];
		ans.clear();for(i=1;i<=n;++i)if(bb[i])ans.push_back(i);
		if(ans.size()*5<n)puts("-1");else{
			for(int x:ans)printf("%d ",x);puts("");
		}
	}
}