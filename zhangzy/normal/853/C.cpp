#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct LT{
	int lc,rc,sz;
}tr[23333333],nil;
int cnt=0,rt[201000]={0},n,m;

int nnd(){
	tr[++cnt]=nil;
	return cnt;
}
void bui(int p1,int p2,int l,int r,int v){
	if (l==r){
		tr[p2].sz=tr[p1].sz+1;
		return;
	}
	int mid=(l+r)>>1;
	if (v<=mid){
		tr[p2].lc=nnd(); tr[p2].rc=tr[p1].rc;
		bui(tr[p1].lc,tr[p2].lc,l,mid,v);
	}else{
		tr[p2].lc=tr[p1].lc; tr[p2].rc=nnd();
		bui(tr[p1].rc,tr[p2].rc,mid+1,r,v);
	}
	tr[p2].sz = tr[tr[p2].lc].sz + tr[tr[p2].rc].sz;
}

int que(int p1,int p2,int l,int r,int st,int en){
	if (st>en) return 0;
	if (l==st&&r==en) return tr[p2].sz-tr[p1].sz;
	int mid=(l+r)>>1;
	return que(tr[p1].lc,tr[p2].lc,l,mid,max(l,st),min(mid,en))\
	      +que(tr[p1].rc,tr[p2].rc,mid+1,r,max(mid+1,st),min(r,en));
}

int doit(int x,int y,int xx,int yy){
	if (x>xx||y>yy) return 0;
	return que(rt[x-1],rt[xx],1,n,y,yy);
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y,xx,yy;
	nil.lc=nil.rc=nil.sz=0;
	tr[0]=nil;
	rt[0]=nnd();
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		rt[i]=nnd();
		bui(rt[i-1],rt[i],1,n,x);
	}
	
	ll ans;
	for (int c9,c1,c2,c3,c4,c5,c6,c7,c8;m--;){
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		c1=doit(1,1,x-1,y-1); c2=doit(1,y,x-1,yy); c3=doit(1,yy+1,x-1,n);
		c4=doit(x,1,xx,y-1);  c5=doit(x,y,xx,yy);  c6=doit(x,yy+1,xx,n);
		c7=doit(xx+1,1,n,y-1);c8=doit(xx+1,y,n,yy);c9=doit(xx+1,yy+1,n,n);
		ans= (ll)c1*(c5+c6+c8+c9) +(ll)c2*(c4+c5+c6+c7+c8+c9) +(ll)c3*(c4+c5+c7+c8) \
		    +(ll)c4*(c5+c6+c8+c9) +(ll)c5*(c5-1)/2 +(ll)c5*(c6+c7+c8+c9) +(ll)c6*(c7+c8) ;
		printf("%I64d\n",ans);
	}
}