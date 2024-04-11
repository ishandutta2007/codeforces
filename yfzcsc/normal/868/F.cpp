#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
typedef long long ll;
const ll inf=(ll)1e18;
struct data{
	int l,r,ql,qr;
}q[maxn];
int n,m,l,r,nwl,nwr,a[maxn];
ll f[25][maxn],ans,cnt[maxn];
void solve(ll* f,ll* lst,int l,int r,int L,int R){
	if(l>r)return ;
	int mid=l+r>>1;
	ll mn=inf,pos=-1;
	while(nwr<mid)ans+=cnt[a[nwr+1]],cnt[a[nwr+1]]++,nwr++;
	while(nwr>mid)ans-=cnt[a[nwr]]-1,cnt[a[nwr]]--,nwr--;
	while(nwl<min(mid,R))ans-=cnt[a[nwl]]-1,cnt[a[nwl]]--,nwl++;
	while(nwl>min(mid,R))ans+=cnt[a[nwl-1]],cnt[a[nwl-1]]++,nwl--;
	while(nwl>=L){
		ll ret=lst[nwl-1]+ans;
		if(ret<mn)mn=ret,pos=nwl;
		ans+=cnt[a[--nwl]]++;
	}
	f[mid]=mn;
	q[::r++]=data{l,mid-1,L,pos};
	q[::r++]=data{mid+1,r,pos,R};
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),f[0][i]=inf;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)cnt[j]=0;
		nwl=nwr=l=r=ans=0,nwl=1;
		q[r++]=data{1,n,1,n};
		while(l<r)solve(f[i],f[i-1],q[l].l,q[l].r,q[l].ql,q[l].qr),l++;
//		printf("[%lld]",f[i][n]);
	}
	printf("%lld",f[m][n]);
}