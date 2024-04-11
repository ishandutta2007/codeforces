#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
int a[N],q[N],n;
ll h1[N],h2[N],h3[N],ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		h1[i]=h1[i-1]+a[i];
		h2[i]=h2[i-1]+1ll*a[i]*i;
		h3[i]=1ll*h1[i]*i-h2[i];
	}
	int t=1; q[1]=0;
	for (int i=1;i<=n;i++){
		int l=1,r=t;
		while (l<r){
			int mid=(l+r)/2;
			if ((q[mid+1]-q[mid])*h1[i]>=h3[q[mid+1]]-h3[q[mid]])
				r=mid;
			else l=mid+1;
		}
		ans=max(ans,h2[i]-h2[q[l]]-(h1[i]-h1[q[l]])*q[l]);
		for (;t>1&&(h3[i]-h3[q[t]])*(q[t]-q[t-1])>(h3[q[t]]-h3[q[t-1]])*(i-q[t]);t--);
		q[++t]=i;
	}
	printf("%lld",ans);
}