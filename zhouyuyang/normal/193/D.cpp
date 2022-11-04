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
#define sqr(x) ((x)*(x))
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
const int N=300005;
struct node{
	int v,tg,cnt1,cnt2;
};
node t[N*4];
int a[N],p[N],n;
ll ans;
void build(int k,int l,int r){
	t[k].cnt1=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	if (!t[k].tg) return;
	t[k*2].tg+=t[k].tg;
	t[k*2+1].tg+=t[k].tg;
	t[k*2].v+=t[k].tg;
	t[k*2+1].v+=t[k].tg;
	t[k].tg=0;
}
void pushup(int k){
	t[k].v=min(t[k*2].v,t[k*2+1].v);
	t[k].cnt1=t[k*2].cnt1*(t[k*2].v==t[k].v);
	t[k].cnt1+=t[k*2+1].cnt1*(t[k*2+1].v==t[k].v);
	t[k].cnt2=t[k*2].cnt2*(t[k*2].v==t[k].v);
	t[k].cnt2+=t[k*2+1].cnt2*(t[k*2+1].v==t[k].v);
	t[k].cnt2+=t[k*2].cnt1*(t[k*2].v==t[k].v+1);
	t[k].cnt2+=t[k*2+1].cnt1*(t[k*2+1].v==t[k].v+1);
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k].tg+=v;
		t[k].v+=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
void ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		ans+=t[k].cnt1*(t[k].v<=2);
		ans+=t[k].cnt2*(t[k].v==1);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if (y<=mid) ask(k*2,l,mid,x,y);
	else if (x>mid) ask(k*2+1,mid+1,r,x,y);
	else{
		ask(k*2,l,mid,x,mid);
		ask(k*2+1,mid+1,r,mid+1,y);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		p[x]=i;
	}
	build(1,1,n);
	Rep(i,n,1){
		a[p[i]]=i;
		int x=a[p[i]-1];
		int y=a[p[i]+1];
		if (x>y) swap(x,y);
		if (x&&y){
			change(1,1,n,i,x-1,1);
			change(1,1,n,y,n,-1);
		}
		else if (y) change(1,1,n,i,y-1,1);
		else change(1,1,n,i,n,1);
		ask(1,1,n,i,n);
	}
	printf("%lld",ans-n);
}