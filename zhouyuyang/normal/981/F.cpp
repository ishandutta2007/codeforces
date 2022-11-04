#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2333333;
ll a[N],b[N];
int n,L;
int main(){
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	sort(a+1,a+n+1); sort(b+1,b+n+1);
	a[0]=b[0]=n;
	for (int j=1;j<=5;j++){
		for (int i=1;i<=n;i++){
			a[++a[0]]=a[i]+1ll*L*j;
			b[++b[0]]=b[i]+1ll*L*j;
		}
	}
	ll l=0,r=L-1,ans=-1;
	while (l<=r){
		ll mid=(l+r)/2;
		int j1=1,j2=1,ok=0,mx=-1e9;
		for (int i=2*n+1;i<=4*n;i++){
			for (;b[j1]<a[i]-mid;j1++);
			for (;b[j2]<=a[i]+mid;j2++);
			mx=max(mx,j1-i);
			if (j2-i-1<mx){
				ok=1; break;
			}
		}
		if (ok) l=mid+1;
		else ans=mid,r=mid-1;
	}
	printf("%lld",ans);
}