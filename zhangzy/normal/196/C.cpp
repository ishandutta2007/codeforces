#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define xxx 1510
#define ll long long
#define db long double
using namespace std;
struct P{
	ll x,y,id;
}p[xxx];
vector<P>vec[xxx],vv[xxx];
int n;
struct R{
	int to,nex;
}r[23333];
int hea[xxx]={0},cnt=1,ans[xxx],sz[xxx],realans[xxx],xx[xxx],yy[xxx];

void A(int u,int v){
	r[++cnt]=(R){v,hea[u]};
	hea[u]=cnt;
	r[++cnt]=(R){u,hea[v]};
	hea[v]=cnt;
}

void dfs(int x,int fa){
	sz[x]=1;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
	return;
}

bool cmp(P p1,P p2){
	return p1.x*p2.y-p1.y*p2.x < 0;
}
bool high(P p1,P p2){
	return p1.y!=p2.y?p1.y<p2.y:p1.x<p2.x;
}

void doit(int x,int fa){
	sort(vv[x].begin(),vv[x].end(),high);
	ans[x]=vv[x][0].id;
	int vsz=vv[x].size()-1,tt,pos=-1,t;
	for (int i=1;i<=vsz;i++){
		vec[x].push_back(vv[x][i]);
	}
	for (int i=0;i<vsz;i++){
		vec[x][i].x-=xx[ans[x]];
		vec[x][i].y-=yy[ans[x]];
	}
	sort(vec[x].begin(),vec[x].end(),cmp);
	//printf("%d:(%d)\n",x,ans[x]);for (int i=0;i<vsz;i++){printf(" %lld %lld %lld\n",vec[x][i].id,vec[x][i].x,vec[x][i].y);}
	for (int i=hea[x];i>0;i=r[i].nex){
		tt=r[i].to;
		if (tt==fa) continue;
		for (int j=0;j<sz[tt];j++){
			t=vec[x][++pos].id;
			vv[tt].push_back((P){xx[t],yy[t],t});
			//printf("(%d)",pos);
		}
		doit(tt,x);
	}
}

int main(){
	scanf("%d",&n);
	int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		A(u,v);
	}
	dfs(1,1);
	
	for (int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		xx[i]=p[i].x;yy[i]=p[i].y;
		p[i].id=i;
	}
	
	for (int i=1;i<=n;i++){
		vv[1].push_back((P){p[i].x,p[i].y,p[i].id});
	}
	doit(1,1);
	
	for (int i=1;i<=n;i++){
		realans[ans[i]]=i;
	}
	for (int i=1;i<=n;i++){
		printf("%d ",realans[i]);
	}
}