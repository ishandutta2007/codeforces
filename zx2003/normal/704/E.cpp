#include<bits/stdc++.h>
using namespace std;
inline double dcmp(const double&x){return fabs(x)<1e-12?0:(x>0?1:-1);}
const int N=1e5+5;
int n,m,a,b,i;
double nw,ans=1ll<<60;
struct seg{
	double x1,x2,y1,y2;
	inline double F()const{return dcmp(y1-y2)==0?y1:(nw-y1)/(y2-y1)*(x2-x1)+x1;}
	inline bool operator<(const seg&rhs)const{return F()<rhs.F();}
	inline bool onseg(const double&x,const double&y)const{
		return dcmp((x-x1)*(y-y2)-(y-y1)*(x-x2))==0 && dcmp((x-x1)*(x-x2))<=0 && dcmp((y-y1)*(y-y2))<=0;
	}
};
namespace scanline{
multiset<seg>S;
inline void updans(const seg&a,const seg&b){
	if(dcmp(a.y1-a.y2)==0){
		if(b.onseg(a.x1,a.y1))ans=min(ans,a.y1);
	}else if(dcmp(b.y1-b.y2)==0){
		if(a.onseg(b.x1,b.y1))ans=min(ans,b.y1);
	}else{
		double yh=min(max(a.y1,a.y2),max(b.y1,b.y2)),yl=max(min(a.y1,a.y2),min(b.y1,b.y2));
		if(dcmp(yh-yl)==-1)return;
		double ka=(a.x2-a.x1)/(a.y2-a.y1),kb=(b.x2-b.x1)/(b.y2-b.y1),
			ba=a.x1-ka*a.y1,bb=b.x1-kb*b.y1,yy;
		if(dcmp(ka-kb)==0){if(dcmp(ba-bb)==0)ans=min(ans,yl);}else{
			yy=(bb-ba)/(ka-kb);
			if(dcmp(yl-yy)<=0 && dcmp(yy-yh)<=0)ans=min(ans,yy);
		}
	}
}
multiset<seg>::iterator itt[N];
pair<double,int>ev[N*2];
inline void mai(const vector<seg>&v){
	int xb=0,i;
	for(i=0;i<v.size();++i)ev[++xb]=make_pair(min(v[i].y1,v[i].y2),i),
		ev[++xb]=make_pair(max(v[i].y1,v[i].y2),i+N);
	sort(ev+1,ev+xb+1);
	S.clear();
	for(i=1;i<=xb;++i){
		nw=ev[i].first;if(nw>=ans)return;
		bool fl=1;int id=ev[i].second>=N?fl=0,ev[i].second-N:ev[i].second;seg u=v[id];
		if(fl){
			auto it=S.lower_bound(u);
			if(it!=S.end())updans(u,*it);
			if(it!=S.begin())updans(u,*--it);
			itt[id]=S.insert(u);
		}else{
			auto it=S.upper_bound(u),it2=it;
			S.erase(itt[id]);
			if(it!=S.end() && it!=S.begin())updans(*--it2,*it);
		}
	}
/*
	for(int i=0;i<v.size();++i)for(int j=i+1;j<v.size();++j){
if(i==0 && j==6)
++i,--i;
		updans(v[i],v[j]);
		if(ans==2)
++i,--i;
	}
*/
}
}
namespace HLD{
int sz[N],dep[N],dad[N],ma[N],top[N],dfn[N],id[N],en[N],xb,len[N];
vector<int>e[N];
inline void addedge(int x,int y){e[x].push_back(y);e[y].push_back(x);}
void dfs1(int x,int fa){
	sz[x]=1;dep[x]=dep[fa]+1;dad[x]=fa;
	for(int y:e[x])if(y!=fa){
		dfs1(y,x);sz[x]+=sz[y];
		if(sz[y]>sz[ma[x]])ma[x]=y;
	}
	len[x]=len[ma[x]]+1;
}
void dfs2(int x,int fa){
	dfn[id[x]=++xb]=x;
	if(ma[x])top[ma[x]]=top[x],dfs2(ma[x],x);
	for(int y:e[x])if(y!=fa && y!=ma[x])top[y]=y,dfs2(y,x);
	en[x]=xb;
}
inline void ini(){dfs1(1,0);top[1]=1;dfs2(1,0);}
int lca(int x,int y){
	for(;top[x]!=top[y];y=dad[top[y]])if(dep[top[x]]>dep[top[y]])swap(x,y);
	return dep[x]<dep[y]?x:y;
}
vector<seg>v[N];
inline void addline(){
	int x,y,t,c,d,dd,d2,d3;
	scanf("%d%d%d%d",&t,&c,&x,&y);
	d=dep[x]+dep[y]-dep[lca(x,y)]*2;d2=0;
	for(;top[x]!=top[y];)if(dep[top[x]]<dep[top[y]]){
		dd=dep[y]-dep[dad[top[y]]];
		v[top[y]].push_back((seg){(double)0,(double)dd,(d-dd)*1.0/c+t,d*1.0/c+t});
		y=dad[top[y]];d-=dd;
	}else{
		dd=dep[x]-dep[dad[top[x]]];
		v[top[x]].push_back((seg){(double)0,(double)dd,(d2+dd)*1.0/c+t,d2*1.0/c+t});
		x=dad[top[x]];d2+=dd;
	}
	d3=dep[dad[top[y]]];
	v[top[x]].push_back((seg){(double)dep[y]-d3,(double)dep[x]-d3,d*1.0/c+t,d2*1.0/c+t});
}
inline void work(){for(int i=1;i<=n;++i)if(!v[i].empty())scanline::mai(v[i]);}
}
int main(){
	scanf("%d%d",&n,&m);for(i=1;i<n;++i)scanf("%d%d",&a,&b),HLD::addedge(a,b);
	HLD::ini();for(;m--;)HLD::addline();HLD::work();
	if(ans>1e6)puts("-1");else printf("%.8f\n",ans);
	return 0;
}