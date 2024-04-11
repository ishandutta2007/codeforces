#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e6+1,M=21000001;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
    e[++s_e]={y,head[x]},head[x]=s_e;
}
struct A{
    int cnt,pos;
    bool operator <(const A &q) const {
	return cnt^q.cnt?cnt>q.cnt:pos<q.pos;
    }
};
int n,rt[N];
namespace Segment_Tree{
    int tot,ls[M],rs[M];
    A t[M];
    inline void upd(int p){t[p]=min(t[ls[p]],t[rs[p]]);}
    void modify(int &p,int l,int r,int x){
	if(!p)p=++tot;
	if(l==r){t[p].cnt++,t[p].pos=l;return;}
	int mid=(l+r)>>1;
	x<=mid?modify(ls[p],l,mid,x):modify(rs[p],mid+1,r,x);
	upd(p);
    }
    int merge(int p1,int p2,int l,int r){
	if(!p1 || !p2)return p1|p2;
	if(l==r){
	    t[p1].cnt+=t[p2].cnt;
	    return p1;
	}
	int mid=(l+r)>>1;
	ls[p1]=merge(ls[p1],ls[p2],l,mid);
	rs[p1]=merge(rs[p1],rs[p2],mid+1,r);
	return upd(p1),p1;
    }
}
using namespace Segment_Tree;
int ans[N];
void dfs(int x,int fa,int dep){
    modify(rt[x],1,n,dep);
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;
	if(y!=fa)dfs(y,x,dep+1),rt[x]=merge(rt[x],rt[y],1,n);
    }
    ans[x]=t[rt[x]].pos-dep;
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	add_e(x,y),add_e(y,x);
    }
    dfs(1,0,1);
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}