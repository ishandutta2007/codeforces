#include<bits/stdc++.h>
const int N=500005;
using namespace std;
int n,m,nn,fa[N];
int vis[N],be[N];
vector<int> e[N];
vector<int> vec[N];
bool ok[N];
int findring(int x){
	vis[x]=1;
	for (int i=0;i<e[x].size();i++){
		int to=e[x][i];
		if (to==fa[x]) continue;
		if (!vis[to]){
			fa[to]=x;
			findring(to);
		}
		else if (!be[x]){
			++nn; ok[to]=1;
			for (int y=x;;y=fa[y]){
				be[y]=nn;
				vec[nn].push_back(y);
				if (y==to) break;
			}
		}
	}
	if (!be[x]){
		be[x]=++nn; ok[x]=1;
		vec[nn].push_back(x); 
	}
}
int worked[N],SUB[N];
int sub[N],vfa[N];
void calc1(int x,int fa){
	worked[be[x]]=1;
	int id=be[x],sz=vec[id].size();
	for (int i=0;i<sz;i++){
		int y=vec[id][i];
		int mx0=0,mx1=-1e9;
		for (int j=0;j<e[y].size();j++){
			int to=e[y][j];
			if (to==fa||id==be[to]) continue;
			int val=SUB[be[to]]+1;
			if (val>mx0) mx1=mx0,mx0=val;
			else if (val>mx1) mx1=val;
		}
		sub[y]=mx0;
		SUB[id]=max(SUB[id],mx0+min(i+1,sz-1-i));
		for (int j=0;j<e[y].size();j++){
			int to=e[y][j];
			if (to==fa||id==be[to]) continue;
			vfa[to]=(SUB[be[to]]+1==mx0?mx1+1:mx0+1);
		}
	}
}
void work1(int x,int fa){
	vis[x]=1;
	for (int i=0;i<e[x].size();i++)
		if (!vis[e[x][i]]) work1(e[x][i],x);
	if (!worked[be[x]]&&ok[x]) calc1(x,fa);
}
int v[N*2],q[N*2],wzp[N*2];
void calc2(int x,int fa){
	worked[be[x]]=1;
	sub[x]=max(sub[x],vfa[x]);
	for (int i=0;i<e[x].size();i++){
		int to=e[x][i];
		if (be[to]!=be[x]&&to!=fa)
			vfa[to]=max(vfa[to],vfa[x]+1);
	}
	int id=be[x];
	int lim=0,sz=vec[id].size();
	for (int times=0;times<2;times++)
		for (int i=0;i<sz;i++){
			wzp[lim]=0;
			v[lim++]=sub[vec[id][i]];
		}
	for (int i=0;i<lim;i++) q[i]=0;
	int h=1,t=0;
	for (int i=lim-1;i>=0;i--){
		if (q[h]>i+sz/2) h++;
		if (h<=t) wzp[i]=max(wzp[i],v[q[h]]+q[h]-i);
		for (;h<=t&&v[q[t]]+q[t]<=v[i]+i;t--);
		q[++t]=i;
	}
	for (int i=0;i<lim;i++) q[i]=0;
	h=1,t=0;
	for (int i=0;i<lim;i++){
		if (q[h]<i-sz/2) h++;
		if (h<=t) wzp[i]=max(wzp[i],v[q[h]]-q[h]+i);
		for (;h<=t&&v[q[t]]-q[t]<=v[i]-i;t--);
		q[++t]=i;
	}
	for (int i=0;i<sz;i++){
		int to=vec[id][i];
		if (to!=x)
			vfa[to]=max(vfa[to],max(wzp[i+sz],wzp[i]));
		for (int j=0;j<e[to].size();j++){
			int y=e[to][j];
			if (be[y]!=be[x]&&y!=fa)
				vfa[y]=max(vfa[y],max(wzp[i+sz],wzp[i])+1);
		}
	}
}
void work2(int x,int fa){
	vis[x]=1;
	if (!worked[be[x]]) calc2(x,fa);
	for (int i=0;i<e[x].size();i++)
		if (!vis[e[x][i]]) work2(e[x][i],x);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	findring(1);
	memset(vis,0,sizeof(vis));
	work1(1,0);
	memset(vis,0,sizeof(vis));
	memset(worked,0,sizeof(worked)); 
	work2(1,0);
	for (int i=1;i<=n;i++)
		printf("%d ",max(ok[i]?SUB[be[i]]:0,max(sub[i],vfa[i])));
}