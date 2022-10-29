#include<bits/stdc++.h>
#define maxn 2001000
using namespace std;
int a[maxn],n,x,y,mx;
long long sum,b[maxn];
int main(){
	scanf("%d%d%d",&n,&x,&y);
	int z=x/y;
	for(int i=1,z;i<=n;++i)
		scanf("%d",&z),a[z]++,mx=max(mx,z);
	if(mx==1)mx=3;
	for(int i=1;i<=mx*2;++i)b[i]=1ll*i*a[i]*y+b[i-1],a[i]+=a[i-1];
	for(int i=2;i<=mx;++i){
		long long nwsum=0;
		for(int j=i;;j+=i){
			if(i<=z)nwsum+=1ll*(a[j-1]-a[j-i])*j*y-(b[j-1]-b[j-i]);
			else nwsum+=1ll*(a[j-1]-a[j-z-1])*j*y-(b[j-1]-b[j-z-1])+1ll*(a[j-z-1]-a[j-i])*x;
			if(j>=mx)break;
		}
		if(i==2)sum=nwsum;
		else sum=min(sum,nwsum);
	}
	printf("%lld\n",sum);
}