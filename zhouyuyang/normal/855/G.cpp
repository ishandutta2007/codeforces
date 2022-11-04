#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
struct Path{int at,sz;ll ansm;int el,er;};
int p[N],In[N],Out[N],head[N],fa[N];
int sz[N],top[N],s[N],Sz[N];
ll dp1[N],dp2[N],ansM[N];
vector<Path> path,path2;
int tot,n,m,Tim;
ll ans;
int get(int x){
	return x==p[x]?x:p[x]=get(p[x]);
} 
bool isp(int x,int y){
	return In[x]<=In[y]&&Out[x]>=In[y];
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void uni(int x,int y){
	x=get(x); y=get(y);
	if (x==y) return;
	if (s[x]>s[y]) swap(x,y);
	p[x]=y; s[y]+=(s[x]==s[y]);
	if (In[top[x]]<In[top[y]]){
		sz[top[x]]+=sz[top[y]];
		top[y]=top[x];
	}
	else
		sz[top[y]]+=sz[top[x]];
}
void findpath(int x,int y){
	x=top[get(x)],y=top[get(y)];
	int lastx=0,lasty=0;
	for (;!isp(x,y);lastx=Sz[x],x=top[get(fa[x])])
		path.push_back((Path){x,sz[x],ansM[x],lastx,n-Sz[x]});
	path2.clear();
	for (;x!=y;lasty=Sz[y],y=top[get(fa[y])])
		path2.push_back((Path){y,sz[y],ansM[y],n-Sz[y],lasty});
	path.push_back((Path){x,sz[x],ansM[x],lastx,lasty});
	for (int i=path2.size()-1;i>=0;i--)
		path.push_back(path2[i]);
}
void addedge(int x,int y){
	if (get(x)==get(y)) return;
	path.clear(); findpath(x,y);
	//3 in x-y 
	#define t path[i]
	ll cnt0=1,cnt1=0,cnt2=0;
	for (int i=0;i<path.size();i++){
		ans-=2ll*t.sz*cnt2+2ll*t.sz*(t.sz-1)*cnt1+1ll*t.sz*(t.sz-1)*(t.sz-2);
		cnt2+=1ll*t.sz*cnt1+1ll*t.sz*(t.sz-1)*cnt0;
		cnt1+=1ll*t.sz*cnt0;
	}
	ll sum=cnt1;
	ans+=1ll*cnt1*(cnt1-1)*(cnt1-2);
	//2 in x,y
	cnt1=0;
	for (int i=0;i<path.size();i++){
		ans+=2ll*cnt1*(t.el-cnt1)*t.sz;
		cnt1+=t.sz;
	}
	cnt1=0;
	for (int i=path.size()-1;i>=0;i--){
		ans+=2ll*cnt1*(t.er-cnt1)*t.sz;
		cnt1+=t.sz;
	}
	//1 in x,y
	cnt1=cnt2=0;
	for (int i=0;i<path.size();i++){
		ans+=2ll*cnt2*t.sz;
		cnt2+=1ll*(n-t.er-t.el-t.sz)*cnt1;
		cnt1+=n-t.er-t.el-t.sz;
	}
	cnt1=cnt2=0;
	for (int i=path.size()-1;i>=0;i--){
		ans+=2ll*cnt2*t.sz;
		cnt2+=1ll*(n-t.er-t.el-t.sz)*cnt1;
		cnt1+=n-t.er-t.el-t.sz;
	}
	ll jdb1=0,jdb2=0;
	for (int i=0;i<path.size();i++){
		ll fks1=n-t.el-t.er-t.sz;
		ll fks2=t.ansm-2ll*fks1*(t.el+t.er)-2ll*t.el*t.er;
		ans+=1ll*fks2*(sum-t.sz);
		jdb2=jdb2+fks2+2ll*jdb1*fks1;
		jdb1+=fks1;
	}
	for (int i=1;i<path.size();i++)
		uni(path[i-1].at,path[i].at);
	ansM[top[get(path[0].at)]]=jdb2;
	#undef t
}
int dfs(int x,int f){
	Sz[x]=1; fa[x]=f; In[x]=++Tim;
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to==f) continue;
		Sz[x]+=dfs(e[i].to,x);
		ans+=2ll*dp1[e[i].to]*dp1[x];
		ans+=2ll*dp2[e[i].to]*dp1[x];
		ans+=2ll*dp1[e[i].to]*dp2[x];
		ansM[x]+=2ll*dp1[e[i].to]*dp1[x];
		ans+=2ll*dp2[e[i].to];
		dp1[x]+=dp1[e[i].to];
		dp2[x]+=dp2[e[i].to];
	}
	ansM[x]+=2ll*(n-Sz[x])*dp1[x];
	dp2[x]+=dp1[x]; dp1[x]++;
	Out[x]=Tim;
	return Sz[x];
}
//dp1:sum
//dp2:sigma(dep) 
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++){
		p[i]=i; s[i]=0;
		top[i]=i; sz[i]=1;
	}
	printf("%I64d\n",ans);
	scanf("%d",&m);
	while (m--){
		int x,y; scanf("%d%d",&x,&y);
		addedge(x,y); printf("%I64d\n",ans);
	}
}