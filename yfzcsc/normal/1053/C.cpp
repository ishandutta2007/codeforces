#include<bits/stdc++.h>
#define maxn 210010
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int inf=1e9+7;
const int mod=1e9+7;
int n,q,a[maxn],ptr,wi[maxn];
ll tr1[maxn],tr2[maxn],tr3[maxn];
void mdy(ll tr[],int x,ll a,int flg=0){
	for(;x<=n;x+=x&-x)
		flg?(tr[x]+=a)%=mod:tr[x]+=a;
}
ll qry(ll tr[],int x,int flg=0){
	ll ans=0;
	for(;x;x-=x&-x)
		flg?(ans+=tr[x])%=mod:ans+=tr[x];
	return ans;
}
ll qryi(ll tr[],int l,int r,int flg=0){
	if(l>r)return 0;
	return qry(tr,r,flg)-qry(tr,l-1,flg);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]=a[i]-i;
	for(int i=1;i<=n;++i)scanf("%d",&wi[i]); 
	for(int i=1;i<=n;++i){
		mdy(tr2,i,(ll)a[i]*wi[i]%mod,1);
		mdy(tr3,i,wi[i]);
	}
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<0){
			x=-x;
			mdy(tr2,x,(ll)a[x]*(y-wi[x]+mod)%mod,1);
			mdy(tr3,x,y-wi[x]);
			wi[x]=y;
		} else {
			int pos=0,l=x,r=y;
			ll S=qry(tr3,l-1),ALL=qry(tr3,r)-S;
			while(l<=r){
				int mid=l+(r-l)/2;
//				printf("{%d,%d}",l,r);
				if((qry(tr3,mid)-S)*2>=ALL)
					pos=mid,r=mid-1;
				else l=mid+1;
			}
//			printf("[pos=%d]",pos);
			ll sum=0;
//			for(int i=x;i<=y;++i)sum+=wi[i]*abs(a[i]-a[pos]),printf("{%d}",a[i]);

			sum+=qryi(tr3,x,pos,1)*a[pos]-qryi(tr2,x,pos,1);
			sum%=mod;
			sum+=qryi(tr2,pos+1,y,1)-qryi(tr3,pos+1,y,1)*a[pos];
			sum%=mod;
			sum=(sum%mod+mod)%mod;
			printf("%lld\n",sum);
		}
	}
}