#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> data;
const int maxn=1e6+10;
int n,ptr[2],p=0,np=1;
ll a[maxn],K,ans;
data q[2][maxn];
pii lef[maxn],rig[maxn];
pii cal(int l,int r,int i){
	int ans=l-1,L=l,R=r;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]>>i&1)r=mid-1;
		else l=mid+1,ans=mid;
	}
	return pii(ans-L+1,R-ans);
}
int main(){
//	n=1000000,K=700000;
	scanf("%d%lld",&n,&K);
	for(int i=2;i<=n;++i){
		int pi;
		ll x;
//		pi=rand()%(i-1)+1,x=rand()<<15|rand();
		scanf("%d%lld",&pi,&x);
		a[i]=a[pi]^x;
	}
	sort(a+1,a+n+1);
	/*
	vector<ll> v;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			v.push_back(a[i]^a[j]);
	sort(v.begin(),v.end());printf("[%lld]",v[K-1]);*/
	q[np][++ptr[np]]=data(pii(1,n),pii(1,n));
	for(int i=61;i>=0;--i,swap(p,np)){
		ptr[p]=0;
		ll sum=0;
		for(int j=1;j<=ptr[np];++j){
			lef[j]=cal(q[np][j].xx.xx,q[np][j].xx.yy,i);
			rig[j]=cal(q[np][j].yy.xx,q[np][j].yy.yy,i);
//			printf("[(%d,%d)%d,%d]",q[np][j].xx.xx,q[np][j].xx.yy,lef[j].xx,rig[j].xx);
			sum+=(ll)lef[j].xx*rig[j].xx+(ll)lef[j].yy*rig[j].yy;
		}
		if(K<=sum){
			for(int j=1;j<=ptr[np];++j){
				data d=q[np][j];
				if(lef[j].xx&&rig[j].xx)q[p][++ptr[p]]=data(pii(d.xx.xx,d.xx.xx+lef[j].xx-1),
															pii(d.yy.xx,d.yy.xx+rig[j].xx-1));
				if(lef[j].yy&&rig[j].yy)q[p][++ptr[p]]=data(pii(d.xx.yy-lef[j].yy+1,d.xx.yy),
															pii(d.yy.yy-rig[j].yy+1,d.yy.yy));
			}
		} else {
			K-=sum;
			for(int j=1;j<=ptr[np];++j){
				data d=q[np][j];
				if(lef[j].xx&&rig[j].yy)q[p][++ptr[p]]=data(pii(d.xx.xx,d.xx.xx+lef[j].xx-1),
															pii(d.yy.yy-rig[j].yy+1,d.yy.yy));
				if(lef[j].yy&&rig[j].xx)q[p][++ptr[p]]=data(pii(d.xx.yy-lef[j].yy+1,d.xx.yy),
															pii(d.yy.xx,d.yy.xx+rig[j].xx-1));
			}
			ans|=(1ll<<i);
		}
	}
	printf("%lld",ans);
}