#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
struct qtype{int x,y,z;}a[N*3];
int n,p,q,r,tot;
int tg[N*3],mn[N*3];
ll sum[N*3];
bool cmp(qtype a,qtype b){
	return a.x>b.x;
}
void pushdown(int k,int l,int r){
	if (!tg[k]) return;
	int mid=(l+r)/2;
	tg[k*2]=tg[k*2+1]=tg[k];
	mn[k*2]=mn[k*2+1]=mn[k];
	sum[k*2]=1ll*tg[k]*(mid-l+1);
	sum[k*2+1]=1ll*tg[k]*(r-mid);
	tg[k]=0; 
}
int find(int k,int l,int r,int v){
	if (l==r) return l;
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if (v>=mn[k*2]) return find(k*2,l,mid,v);
	return find(k*2+1,mid+1,r,v);
}
void change(int k,int l,int r,int x,int y,int v){
	//printf("%d %d %d %d %d\n",k,l,r,x,y);
	if (l==x&&r==y){
		tg[k]=mn[k]=v;
		sum[k]=1ll*v*(r-l+1);
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	sum[k]=sum[k*2]+sum[k*2+1];
	mn[k]=min(mn[k*2],mn[k*2+1]); 
}
int main(){
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for (int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[++tot]=(qtype){p,y,z};
		a[++tot]=(qtype){x,q,z};
		a[++tot]=(qtype){x,y,r};
	}
	sort(a+1,a+tot+1,cmp);
	ll ans=1ll*p*q*r;
	for (int i=p,la=1;i;i--){
		for (;la<=tot&&a[la].x==i;la++)
			if (mn[1]<=a[la].z){
				int tmp=find(1,1,q,a[la].z);
				if (a[la].y>=tmp)
					change(1,1,q,tmp,a[la].y,a[la].z);
			}
		ans-=sum[1];
	}
	printf("%lld\n",ans);
}