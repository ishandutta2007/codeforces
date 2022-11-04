#include<bits/stdc++.h>
#define mo 1000000007
#define N 100005
using namespace std;
int a[N],f[N],n,ans,s;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),s+=a[i];
	f[1]=1ll*(s-1)*(s-1)%mo*power(s,mo-2)%mo;
	for (int i=1;i<=100000;i++)
		f[i+1]=(2ll*f[i]+2ll*mo-f[i-1]-1ll*(s-1)*power(s-i+mo,mo-2)%mo)%mo;
	for (int i=1;i<=n;i++)
		ans=(ans+f[a[i]])%mo;
	printf("%d",ans);
}