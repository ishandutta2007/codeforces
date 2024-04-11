#include<bits/stdc++.h>
const int mo=998244353,N=200005;
int n,k,i,p[N],lst,ans=1;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",p+i);
		if(p[i]>=n-k+1){
			if(lst)ans=1ll*ans*(i-lst)%mo;
			lst=i;
		}
	}
	printf("%lld %d\n",1ll*(n-k+1+n)*k/2,ans);
}