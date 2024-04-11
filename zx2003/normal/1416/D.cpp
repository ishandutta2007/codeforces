#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
mt19937 R(114514);
struct node{int l,r,fa,v,mx,sz,p;}t[N];
inline void upd(int x){
	t[x].mx=max(max(t[t[x].l].mx,t[t[x].r].mx),t[x].v);
	t[x].sz=t[t[x].l].sz+t[t[x].r].sz+1;
}
int merge(int x,int y){
	if(!x || !y)return x|y;
	if(t[x].p>t[y].p)return t[x].r=merge(t[x].r,y),t[t[x].r].fa=x,upd(x),x;
		else return t[y].l=merge(x,t[y].l),t[t[y].l].fa=y,upd(y),y;
}
void split(int x,int&p,int&q,int k){
	if(!x){p=q=0;return;}
	if(t[t[x].l].sz+1<=k)p=x,split(t[x].r,t[p].r,q,k-t[t[x].l].sz-1),t[t[p].r].fa=p,upd(p);
		else q=x,split(t[x].l,p,t[q].l,k),t[t[q].l].fa=q,upd(q);
}
inline int getrt(int x){for(;t[x].fa;x=t[x].fa);return x;}
inline int getrk(int x){
	int ans=t[t[x].l].sz+1;
	for(;t[x].fa;x=t[x].fa)if(x==t[t[x].fa].r)ans+=t[t[t[x].fa].l].sz+1;
	return ans;
}
inline void mdy(int x){for(t[x].v=0;x;upd(x),x=t[x].fa);}
int n,m,Q,i,ip[N],p,q,r,ea[N],eb[N],g[N],o1[N],o2[N],dad[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
bool del[N],vi[N],ont[N];
vector<int>e[N];
inline void tryuni(int i){
	int x=gfa(ea[i]),y=gfa(eb[i]);
	if(x!=y)g[x]=y,e[ea[i]].push_back(eb[i]),e[eb[i]].push_back(ea[i]),ont[i]=1;
}
void dfs(int x){
	p=merge(p,x*2-1);vi[x]=1;
	for(int y:e[x])if(!vi[y])dfs(y),dad[y]=x;
	p=merge(p,x*2);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(i=1;i<=n;++i){
		scanf("%d",&p);
		t[i*2-1]=node{0,0,0,p,p,1,(int)R()};
		t[i*2]=node{0,0,0,0,0,1,(int)R()};
		ip[p]=i;g[i]=i;
	}
	for(i=1;i<=m;++i)scanf("%d%d",ea+i,eb+i);
	for(i=1;i<=Q;++i){
		scanf("%d%d",o1+i,o2+i);
		if(o1[i]==2)del[o2[i]]=1;
	}
	for(i=1;i<=m;++i)if(!del[i])tryuni(i);
	for(i=Q;i;--i)if(o1[i]==2)tryuni(o2[i]);
	for(i=1;i<=n;++i)if(!vi[i])p=0,dfs(i);
	for(i=1;i<=Q;++i){
		if(o1[i]==1){
			int x=t[getrt(o2[i]*2-1)].mx;
			if(x)mdy(ip[x]*2-1);
			printf("%d\n",x);
		}else if(ont[o2[i]]){
			int x=ea[o2[i]],y=eb[o2[i]];
			if(dad[x]==y)swap(x,y);
			split(getrt(y*2-1),p,q,getrk(y*2-1)-1);t[p].fa=t[q].fa=0;
			split(q,q,r,getrk(y*2));t[q].fa=t[r].fa=0;
			p=merge(p,r);
		}
	}
}