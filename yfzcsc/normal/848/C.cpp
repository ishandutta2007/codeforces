#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
typedef set<int>::iterator sit;
struct data{int lc,rc;ll sum;}s[maxn*120];
set<int>st[maxn];
int rt[maxn],ptr,a[maxn],n,m,b[maxn],c[maxn];
void modify(int &rt,int l,int r,int k,ll tg){
	if(!rt)rt=++ptr;
	s[rt].sum+=tg;
	if(l==r)return ;
	int mid=l+r>>1;
	if(k<=mid)modify(s[rt].lc,l,mid,k,tg);
	else modify(s[rt].rc,mid+1,r,k,tg);
}
ll query(int rt,int l,int r,int ql){
	if(!rt)return 0;
	if(l>=ql)return s[rt].sum;
	int mid=l+r>>1;
	if(ql<=mid)return query(s[rt].lc,l,mid,ql)+s[s[rt].rc].sum;
	else return query(s[rt].rc,mid+1,r,ql);
}
void _modify(int x,int y,ll tg){
	for(;x<=n;x+=x&-x)modify(rt[x],1,n,y,tg);
}
ll _query(int l,int r){
	ll ans=0;
	for(;r;r-=r&-r)ans+=query(rt[r],1,n,l);
	return ans;
}
sit pre(sit it){return --it;}
sit nxt(sit it){return ++it;}
void upd(int x,int nwc){
	if(c[x])_modify(x,c[x],c[x]-x);
	if(nwc)_modify(x,nwc,x-nwc);
	c[x]=nwc;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x),b[i]=x;
		if(st[x].size())
			c[i]=*st[x].rbegin(),_modify(i,c[i],i-c[i]);
		st[x].insert(i);
	}
	for(int i=1,op,x,y;i<=m;++i){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			sit it=st[b[x]].find(x);
			if(nxt(it)!=st[b[x]].end())
				upd(*nxt(it),(it==st[b[x]].begin()?0:*pre(it)));
			st[b[x]].erase(x),b[x]=y;
			it=st[y].insert(x).first;
			upd(x,(it==st[y].begin()?0:*pre(it)));
			if(nxt(it)!=st[y].end())
				upd(*nxt(it),x);
		} else {
			printf("%lld\n",_query(x,y));
		}
	}
}