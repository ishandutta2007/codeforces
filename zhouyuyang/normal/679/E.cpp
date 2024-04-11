#include<bits/stdc++.h>
#define ll long long
#define N 400005
using namespace std;
int n,q,fl,x,y,z,flag[N];
ll mn[N],tg[N],val[N],jdb[20];
void pushdown(int k){
	if (flag[k]){
		flag[k*2]=flag[k*2+1]=true;
		mn[k*2]=mn[k*2+1]=mn[k];
		val[k*2]=val[k*2+1]=val[k];
		tg[k]=0; flag[k]=false;
	}
	if (tg[k]){
		tg[k*2]+=tg[k]; tg[k*2+1]+=tg[k];
		mn[k*2]-=tg[k]; mn[k*2+1]-=tg[k];
		tg[k]=0;
	}
}
void pushup(int k){
	mn[k]=min(mn[k*2],mn[k*2+1]); 
}
bool get(ll x,ll &val,ll &mn){
	for (int i=0;;i++)
		if (x<jdb[i]){
			mn=(val=jdb[i])-x;
			return x==jdb[i-1];
		} 
}
void build(int k,int l,int r){
	if (l==r){
		int x;
		scanf("%d",&x);
		get(x,val[k],mn[k]);
		flag[k]=1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void reset(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		flag[k]=1;
		get(v,val[k],mn[k]);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) reset(k*2,l,mid,x,y,v);
	else if (x>mid) reset(k*2+1,mid+1,r,x,y,v);
	else reset(k*2,l,mid,x,mid,v),reset(k*2+1,mid+1,r,mid+1,y,v);
	pushup(k);
}
bool add(int k,int l,int r,int x,int y,int v){
	bool ans=false;
	if (l==x&&r==y&&(v<mn[k]||flag[k])){
		tg[k]+=v; mn[k]-=v;
		if (mn[k]<=0) ans=get(val[k]-mn[k],val[k],mn[k]);
		return ans;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) ans=add(k*2,l,mid,x,y,v);
	else if (x>mid) ans=add(k*2+1,mid+1,r,x,y,v);
	else ans=add(k*2,l,mid,x,mid,v)|add(k*2+1,mid+1,r,mid+1,y,v);
	pushup(k);
	return ans;
}
ll ask(int k,int l,int r,int x){
	if (l==r||flag[k]) return val[k]-mn[k];
	int mid=(l+r)/2;
	pushdown(k);
	if (x<=mid) return ask(k*2,l,mid,x);
	return ask(k*2+1,mid+1,r,x);
}
int main(){
	jdb[0]=1;
	for (int i=1;i<=12;i++)
		jdb[i]=jdb[i-1]*42;
	scanf("%d%d",&n,&q);
	build(1,1,n);
	while (q--){
		scanf("%d%d",&fl,&x);
		if (fl==1) printf("%I64d\n",ask(1,1,n,x));
		else{
			scanf("%d%d",&y,&z);
			if (fl==2) reset(1,1,n,x,y,z);
			else for (;add(1,1,n,x,y,z););
		}
	}
}