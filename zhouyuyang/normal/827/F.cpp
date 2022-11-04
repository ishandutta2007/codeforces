#include<bits/stdc++.h>
#define pa pair<int,int>
#define gc() getchar() 
#define N 500005
using namespace std;
int read(){
	int x=0;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
int x[N],y[N],l[N],r[N],R[N*4];
int head[N*4],dis[N*4],vis[N*4];
struct edge{int to,next,v,mx;}e[N*12];
vector<pa> v[N*2];
vector<int> id[N*2];
priority_queue<pa> q;
int n,m,tot,num;
int find(const vector<pa> &v,int fuck){
	int l=0,r=v.size()-1,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (v[mid].second>=fuck)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
} 
void add(int p,int tg,int l,int r){
	l+=tg; r+=tg;
	l+=l&1; r-=r&1;
	l-=tg; r-=tg;
	v[p*2+tg].push_back(pa(l,r));
}
void addedge(int x,int y,int v1,int v2){
	//printf("%d %d %d %d\n",x,y,v1,v2);
	e[++tot]=(edge){y,head[x],v1,v2};
	head[x]=tot;
} 
void addedge(int x,int tgx,int y,int tgy,int l,int r){
	int L=l,R=r; 
	l+=tgx; r+=tgx;
	l+=l&1; r-=r&1;
	l-=tgx; r-=tgx;
	int xid=x*2+tgx;
	int yid=y*2+tgy;
	int p=find(v[xid],l);
	int q=find(v[yid],l);
	if (v[yid][q].first<=R)
		addedge(id[xid][p],id[yid][q],l,min(v[yid][q].second,R)-1);
	if (v[xid][p].second<R&&v[xid][p].second+1==v[yid][q+1].first)
		addedge(id[xid][p],id[yid][q+1],r,r);
}
void dijk_heap(){
	memset(dis,120,sizeof(dis));
	memset(vis,0,sizeof(vis));
	if (id[2].size()==0) return;
	int S=id[2][0]; dis[S]=0; q.push(pa(0,S));
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue; vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>max(dis[x],e[i].v)+1){
				if (dis[x]>e[i].mx) continue;
				dis[e[i].to]=max(dis[x],e[i].v)+1;
				q.push(pa(-dis[e[i].to],e[i].to));
			}
	}
}
int main(){
	n=read(); m=read();
	if (n==1) return puts("0"),0;
	for (int i=1;i<=m;i++){
		x[i]=read(); y[i]=read();
		l[i]=read(); r[i]=read();
		add(x[i],0,l[i],r[i]);
		add(x[i],1,l[i],r[i]);
		add(y[i],0,l[i],r[i]);
		add(y[i],1,l[i],r[i]);
	}
	v[2].push_back(pa(0,0));
	for (int i=2;i<=2*n+1;i++){
		sort(v[i].begin(),v[i].end());
		int sz=v[i].size();
		if (!sz) continue;
		int top=0,l=v[i][0].first,r=v[i][0].second;
		id[i].resize(sz);
		for (int j=1;j<sz;j++){
			if (v[i][j].first>r){
				v[i][top]=pa(l,r);
				id[i][top++]=++num;
				R[num]=r;
				l=v[i][j].first;
			}
			r=max(r,v[i][j].second);
		}
		v[i][top]=pa(l,r);
		id[i][top++]=++num;
		R[num]=r;
		v[i].resize(top);
		id[i].resize(top);
		v[i].push_back(pa(2e9,2e9));
	}
	for (int i=1;i<=m;i++){
		addedge(x[i],0,y[i],1,l[i],r[i]);
		addedge(x[i],1,y[i],0,l[i],r[i]);
		addedge(y[i],0,x[i],1,l[i],r[i]);
		addedge(y[i],1,x[i],0,l[i],r[i]);
	}
	dijk_heap();
	int ans=2e9;
	for (int i=n*2;i<=n*2+1;i++)
		for (int j=0;j<id[i].size();j++)
			ans=min(ans,dis[id[i][j]]);
	printf("%d",ans==2e9?-1:ans);
}