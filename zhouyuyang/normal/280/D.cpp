#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

struct range{
	int l,r,v;
	bool operator <(const range &a)const{
		return v<a.v;
	}
	friend range operator +(const range &a,const range &b){
		return (range){a.l,b.r,a.v+b.v};
	}
};
struct node{
	range lmx,lmn,rmx,rmn,mx,mn,all;
	bool rev;
	void rever(){
		rev^=1;
		swap(lmx,lmn);
		swap(rmx,rmn);
		swap(mx,mn);
		mx.v*=-1; mn.v*=-1;
		lmx.v*=-1; lmn.v*=-1;
		rmx.v*=-1; rmn.v*=-1;
		all.v*=-1;
	}
	friend node operator +(const node &a,const node &b){
		node res; res.rev=0;
		res.mx=max(max(a.mx,b.mx),a.rmx+b.lmx);
		res.mn=min(min(a.mn,b.mn),a.rmn+b.lmn);
		res.lmx=max(a.lmx,a.all+b.lmx);
		res.lmn=min(a.lmn,a.all+b.lmn);
		res.rmx=max(b.rmx,a.rmx+b.all);
		res.rmn=min(b.rmn,a.rmn+b.all);
		res.all=a.all+b.all;
		return res;
	}
}t[265000];
int a[100005];
#define rever(k) t[k].rever()
void pushdown(int k){
	if (!t[k].rev) return;
	rever(k*2); rever(k*2+1); t[k].rev=0;
}
void build(int k,int l,int r){
	if (l==r){
		t[k].mx=(range){l,l,a[l]};
		t[k].lmx=t[k].rmx=t[k].all=t[k].mx;
		t[k].lmn=t[k].rmn=t[k].mn=t[k].mx;
		return;
	}
	int mid=(l+r)/2;
	build(LS3); build(RS3);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k].mx=(range){l,l,v};
		t[k].lmx=t[k].rmx=t[k].all=t[k].mx;
		t[k].lmn=t[k].rmn=t[k].mn=t[k].mx;
		return;
	}
	GET;
	if (p<=mid) change(LS3,p,v);
	else change(RS3,p,v);
	t[k]=t[k*2]+t[k*2+1];
}
void reverse(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		rever(k); return;
	}
	GET;
	if (x<=mid) reverse(LS5);
	if (y>mid) reverse(RS5);
	t[k]=t[k*2]+t[k*2+1];
}
node ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	GET;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	int n,Q;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==0) change(1,1,n,x,y);
		else{
			vector<pii> tmp;
			int cnt;
			scanf("%d",&cnt);
			int ans=0;
			For(j,1,cnt){
				range res=ask(1,1,n,x,y).mx;
				if (res.v<=0) break; ans+=res.v;
				reverse(1,1,n,res.l,res.r);
				tmp.PB(pii(res.l,res.r));
			}
			For(j,0,tmp.size()-1)
				reverse(1,1,n,tmp[j].fi,tmp[j].se);
			printf("%d\n",ans);
		}
	}
}