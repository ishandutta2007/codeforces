#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
int n,d,b,a[maxn],c[maxn];
int chk(int x){
	int l=x+1,r=n-x;
	if(l>r)return 1;
	int lp=1,rp=n;
	x++;
	for(int i=1;i<=n;++i)c[i]=a[i];
	while(l<=r){
		int rest=b;
		while(rest&&abs(lp-l)<=1ll*x*d&&lp<=n){
			if(!c[lp])lp++;
			else if(c[lp]<rest)rest-=c[lp],c[lp]=0;
			else c[lp]-=rest,rest=0;
		}
		if(rest)return 0;
		if(l==r)break;
		rest=b;
		while(rest&&abs(rp-r)<=1ll*x*d&&rp>=1){
			if(!c[rp])rp--;
			else if(c[rp]<rest)rest-=c[rp],c[rp]=0;
			else c[rp]-=rest,rest=0;
		}
		x++;
		if(rest)return 0;
		l++,r--;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&d,&b);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}