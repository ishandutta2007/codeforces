#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200100],b[200100];
int main(){
	int n,m,ta,tb,k;
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	if(k>=n||k>=m){
		printf("-1");
		return 0;
	}
	ll ans=(ll)-1e18;
	for(int i=0;i<=k;++i){
		int nw=a[i+1];
		if(nw+ta>b[m]){
			puts("-1");
			return 0;
		}
		int pos=lower_bound(b+1,b+m+1,nw+ta)-b;
		int l=k-i+pos-1+1,r=m,nxt=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(b[mid]>=nw+ta)nxt=mid,r=mid-1;
			else l=mid+1;
		}
		if(nxt==-1){
			puts("-1");
			return 0;
		} else ans=max(ans,(ll)b[nxt]+tb);
	}
	cout<<ans;
}