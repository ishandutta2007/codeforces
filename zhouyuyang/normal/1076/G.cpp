#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
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
using namespace std;
int n,m,Q,tg[1<<19];
ll v[200005];
struct node{
	int a[6];
	node operator +(const node &b)const{
		node c;
		For(i,0,m) c.a[i]=a[b.a[i]];
		return c;
	}
}t[1<<19][2],tr[2];
void build(int k,int l,int r){
	if (l==r){
		t[k][(v[l]&1)^1]=tr[0];
		t[k][v[l]&1]=tr[1];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k][0]=t[k*2][0]+t[k*2+1][0];
	t[k][1]=t[k*2][1]+t[k*2+1][1];
}
void pushdown(int k){
	if (!tg[k]) return;
	tg[k*2]^=1; tg[k*2+1]^=1;
	swap(t[k*2][0],t[k*2][1]);
	swap(t[k*2+1][0],t[k*2+1][1]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		tg[k]^=1;
		swap(t[k][0],t[k][1]);
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) change(k*2,l,mid,x,y);
	else if (x>mid) change(k*2+1,mid+1,r,x,y);
	else{
		change(k*2,l,mid,x,mid);
		change(k*2+1,mid+1,r,mid+1,y);
	}
	t[k][0]=t[k*2][0]+t[k*2+1][0];
	t[k][1]=t[k*2][1]+t[k*2+1][1];
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k][0];
	int mid=(l+r)/2;
	pushdown(k); 
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,0,m) tr[0].a[i]=min(i+1,m);
	tr[1]=tr[0]; tr[0].a[m]=0;
	For(i,1,n) scanf("%lld",&v[i]);
	build(1,1,n);
	while (Q--){
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1){
			scanf("%lld",&v[0]);
			if (v[0]&1) change(1,1,n,l,r);
		}
		else
			printf("%d\n",(ask(1,1,n,l,r).a[m]==0)+1);
	}
}