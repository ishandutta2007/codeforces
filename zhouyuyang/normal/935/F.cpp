#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long LL;
LL a[N],sum;int n,m;
struct Tree{
	LL num[N];int id[N<<2];
	void upd(int pos,LL val,int x=1,int l=1,int r=n){
		if (l==r){
			num[l]=val;id[x]=l;return;
		}int mid=(l+r)>>1;
		if (pos<=mid) upd(pos,val,x<<1,l,mid);
				else  upd(pos,val,x<<1|1,mid+1,r);
		id[x]=num[id[x<<1]]>num[id[x<<1|1]]?id[x<<1]:id[x<<1|1];
	}
	int ask(int ql,int qr,int x=1,int l=1,int r=n){
		if (ql<=l&&r<=qr) return id[x];
		int mid=(l+r)>>1,tl=0,tr=0;
		if (ql<=mid) tl=ask(ql,qr,x<<1,l,mid);
		if (qr>mid)  tr=ask(ql,qr,x<<1|1,mid+1,r);
		return (!tl||tr&&num[tr]>num[tl])?tr:tl;
	}
}A,B,C;
void Renew(int x){
	if (x<=1||x>=n) return;
	A.upd(x,a[x]>=0&&a[x+1]<=0);
	B.upd(x,a[x]<0&&a[x+1]>0);
	C.upd(x,-max(-a[x],a[x+1]));
}
LL Query(int l,int r,LL val){
	int _=A.ask(l,r);
	if (A.num[_]==1) return 2ll*val;
	_=B.ask(l,r);
	if (B.num[_]==0){
		//printf("%lld\n",C.ask(l,r));
		return max(0ll,2ll*(val+C.num[C.ask(l,r)]));
	}
	LL p=-a[_],q=a[_+1],ret;
	//printf("%lld %lld %d\n",p,q,_);
	if (p>q) swap(p,q);
	if (val<=p) ret=-2ll*val;
	else if (val<=q) ret=-2ll*p;
	else ret=(2ll*val-p-q)-(p+q);
	
	if (l<_) ret=max(ret,max(0ll,2ll*(val+C.num[C.ask(l,_-1)])));
	if (_<r) ret=max(ret,max(0ll,2ll*(val+C.num[C.ask(_+1,r)])));
	
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=n;i>1;i--)
		sum+=abs(a[i]-=a[i-1]);
	for (int i=2;i<n;i++)
		Renew(i);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int opt,l,r;LL val;scanf("%d%d%d%lld",&opt,&l,&r,&val);
		if (opt==2){
			sum-=abs(a[l]);
			sum+=abs(a[l]+=val);
			sum-=abs(a[r+1]);
			sum+=abs(a[r+1]-=val);
			Renew(l-1);
			Renew(l);
			if (l<r) Renew(r);
			Renew(r+1);
		}
		else
			//printf("!!%lld\n",A.num[A.ask(2,4)]),
			printf("%lld\n",sum+Query(l,r,val));
	}
	
}