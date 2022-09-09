#include<bits/stdc++.h>
using namespace std;
int n,a[200005],s,i;
long long ans;
int main(){
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	ans=abs(a[n/2+1]-s);
	for(i=1;i<=n/2;++i){
		if(a[i]>s)ans+=a[i]-s;
		if(a[n-i+1]<s)ans+=s-a[n-i+1];
	}
	printf("%lld\n",ans);
	return 0;
}