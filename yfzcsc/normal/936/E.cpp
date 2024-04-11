#include<bits/stdc++.h>
#define xx first
#define yy second
#define maxn 300100
using namespace std;
typedef pair<int,int> pii;
set<int>G[maxn];
vector<int>g[maxn],q[maxn],wxh;
vector<pii>A,B;
map<pii,int>id;
queue<int> joker;
pii a[maxn],dis[maxn]; 
int n,Q,anses[maxn],tra[maxn],trb[maxn],tim[maxn],bel[maxn],sz[maxn];
int mn=0,num=0,rt=0;
void init(int u,int f){
	num+=sz[u],wxh.push_back(u);
	for(auto p:G[u])if(p!=f)
		init(p,u);
}
int findrt(int u,int f){
	int mxsize=0,s=0,S=sz[u];
	for(auto p:G[u])if(p!=f){
		s=findrt(p,u),S+=s;
		if(mxsize<s)mxsize=s;
	}
	if(mxsize<num-S)mxsize=num-S;
	if(mxsize<mn)mn=mxsize,rt=u;
	return S;
}
void solve(int u){
//	printf("solve:%d\n",u);
	wxh.clear();
	mn=1<<25,num=0;
	init(u,0),findrt(u,0),u=rt;
//	printf("{rt=%d}",rt);
	for(auto p:wxh)if(p!=rt)
		for(int i=0;i<sz[p];++i)
			dis[i+p]=pii(1<<25,0);
	for(int i=0;i<sz[rt];++i)
		dis[rt+i]=pii(0,i+1),joker.push(rt+i);
	for(int i=1;i<=sz[rt];++i)tra[i]=trb[i]=1<<25;
	while(joker.size()){
		int u=joker.front();
		joker.pop();
		for(auto p:g[u]){
			if(dis[p].xx<=dis[u].xx+1)continue;
			dis[p]=pii(dis[u].xx+1,dis[u].yy);
			joker.push(p);
		}
	}
	A.clear(),B.clear();
	for(auto p:wxh)
		for(int i=0;i<sz[p];++i){
			if(tim[i+p])A.push_back(pii(tim[i+p],i+p));
			for(auto f:q[i+p])B.push_back(pii(f,i+p));
		}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int i=0;
//	puts("OK");
	for(auto p:B){
		while(i<A.size()&&A[i].xx<p.xx){
//			printf("add:<%d,%d>\n",dis[A[i].yy].xx,dis[A[i].yy].yy);
			for(int j=dis[A[i].yy].yy;j<=sz[rt];j+=j&-j)
				tra[j]=min(tra[j],dis[A[i].yy].xx-dis[A[i].yy].yy);
			for(int j=dis[A[i].yy].yy;j;j-=j&-j)
				trb[j]=min(trb[j],dis[A[i].yy].xx+dis[A[i].yy].yy);
			i++;
		}
//		printf("Query[%d(%d)]<%d(%d),anses=%d>\n",p.xx,p.yy,dis[p.yy].yy,dis[p.yy].xx,anses[p.xx]);
		for(int j=dis[p.yy].yy;j;j-=j&-j)
			anses[p.xx]=min(anses[p.xx],dis[p.yy].xx+dis[p.yy].yy+tra[j]);
		for(int j=dis[p.yy].yy;j<=sz[rt];j+=j&-j)
			anses[p.xx]=min(anses[p.xx],dis[p.yy].xx-dis[p.yy].yy+trb[j]);
	}
	for(auto p:G[u])G[p].erase(u);
	for(auto p:G[u])solve(p);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].xx,&a[i].yy);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(i!=1&&a[i].xx==a[i-1].xx&&a[i].yy==a[i-1].yy+1){
			bel[i]=bel[i-1];
			g[i].push_back(i-1);
			g[i-1].push_back(i);
		} else bel[i]=i;
		if(id.find(pii(a[i].xx-1,a[i].yy))!=id.end()){
			int x=id[pii(a[i].xx-1,a[i].yy)];
			g[i].push_back(x);
			g[x].push_back(i);
			G[bel[x]].insert(bel[i]);
			G[bel[i]].insert(bel[x]);
//			printf("{%d,%d}",x,i);
		}
		sz[bel[i]]++;
		id[a[i]]=i;
	}
	scanf("%d",&Q);
	for(int i=1,op,x,y;i<=Q;++i){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			if(!tim[id[pii(x,y)]])
				tim[id[pii(x,y)]]=i;
			anses[i]=-19260817;
		} else q[id[pii(x,y)]].push_back(i);
		if(op==2)anses[i]=1<<30;
	}
	solve(1);
	for(int i=1;i<=Q;++i){
		if(anses[i]==-19260817)continue;
		printf("%d\n",anses[i]>n?-1:anses[i]);
	}
}