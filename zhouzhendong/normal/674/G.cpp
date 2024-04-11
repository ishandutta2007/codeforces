#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=150005<<2;
typedef vector <pair <int,int> > vp;
int n,q,k;
int a[N],sz[N];
vp p[N];
int tag[N];
bool cmp(pair <int,int> a,pair <int,int> b){
	return a.se>b.se;
}
bool cmp2(pair <int,int> a,pair <int,int> b){
	return a.fi>b.fi;
}
vp emptyvp;
vp Merge(vp a,vp b){
	vp c=a,d;
	for (auto i : b)
		c.pb(i);
	sort(c.begin(),c.end(),cmp);
	while (!c.empty()){
		if (d.empty()||d.back().se!=c.back().se)
			d.pb(c.back());
		else
			d.back().fi+=c.back().fi;
		c.pop_back();
	}
	if ((int)d.size()>=k)
		sort(d.begin(),d.end(),cmp2);
	while ((int)d.size()>=k){
		int v=d.back().fi;
		For(i,1,k)
			d[(int)d.size()-i].fi-=v;
		while (!d.empty()&&d.back().fi==0)
			d.pop_back();
	}
	return d;
}
void pushup(int rt){
	p[rt]=Merge(p[rt<<1],p[rt<<1|1]);
	sz[rt]=sz[rt<<1]+sz[rt<<1|1];
}
void build(int rt,int L,int R){
	if (L==R){
		p[rt].pb(mp(1,a[L]));
		sz[rt]=1;
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	pushup(rt);
}
void pushson(int rt,int v){
	tag[rt]=v,p[rt].clear(),p[rt].pb(mp(sz[rt],v));
}
void pushdown(int rt){
	int ls=rt<<1,rs=ls|1;
	if (tag[rt]){
		pushson(ls,tag[rt]);
		pushson(rs,tag[rt]);
		tag[rt]=0;
	}
}
vp query(int rt,int L,int R,int xL,int xR){
/*	if (R<xL||L>xR)
		return emptyvp;*/
	if (xL<=L&&R<=xR)
		return p[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (xR<=mid)
		return query(ls,L,mid,xL,xR);
	else if (xL>mid)
		return query(rs,mid+1,R,xL,xR);
	else
		return Merge(query(ls,L,mid,xL,xR),query(rs,mid+1,R,xL,xR));
}
void update(int rt,int L,int R,int xL,int xR,int v){
	if (R<xL||L>xR)
		return;
	if (xL<=L&&R<=xR)
		return pushson(rt,v);
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	update(ls,L,mid,xL,xR,v);
	update(rs,mid+1,R,xL,xR,v);
	pushup(rt);
}
int main(){
	n=read(),q=read(),k=100/read()+1;
	outval(k);
	For(i,1,n)
		a[i]=read();
	build(1,1,n);
	while (q--){
		int type=read(),L=read(),R=read();
		if (type==1){
			int x=read();
			update(1,1,n,L,R,x);
		}
		else {
			vp res=query(1,1,n,L,R);
			printf("%d",(int)res.size());
			for (auto i : res)
				printf(" %d",i.se);
			puts("");
		}
	}
	return 0;
}