#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
const int N=100005;
int x,n,m,a[N];
struct node{
	int ln,rn,all,L,R;
	ll ans;
	pii l[22],r[22];
	node(){ln=rn=all=ans=0;}
	node(int p,int v){
		L=R=l[1].se=r[1].se=p;
		ans=(v<x); ln=rn=1;
		l[1].fi=r[1].fi=all=v;
	}
	friend node operator +(const node &a,const node &b){
		node c;
		c.ans=a.ans+b.ans;
		c.all=a.all|b.all;
		c.L=a.L; c.R=b.R;
		CPY(c.l,a.l); CPY(c.r,b.r);
		c.ln=a.ln; c.rn=b.rn;
		for (int i=a.rn,j=0;i;i--){
			for (;j<b.ln&&(a.r[i].fi|b.l[j+1].fi)<x;j++);
			c.ans+=1ll*(a.r[i].se-(i<a.rn?a.r[i+1].se:a.L-1))*
					   ((j<b.ln?b.l[j+1].se:b.R+1)-b.L);
		}
		For(i,1,b.ln)
			if ((b.l[i].fi|a.all)!=c.l[c.ln].fi)
				c.l[++c.ln]=b.l[i],c.l[c.ln].fi|=a.all;
		For(i,1,a.rn)
			if ((a.r[i].fi|b.all)!=c.r[c.rn].fi)
				c.r[++c.rn]=a.r[i],c.r[c.rn].fi|=b.all;
		return c;
	}
}t[N*4];
void build(int k,int l,int r){
	if (l==r){
		t[k]=node(l,a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k]=node(l,v);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	t[k]=t[k*2]+t[k*2+1];
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	For(i,1,m){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(1,1,n,x,y); 
		else printf("%lld\n",1ll*(y-x+1)*(y-x+2)/2-ask(1,1,n,x,y).ans);
	}
}