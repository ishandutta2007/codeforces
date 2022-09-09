#include<bits/stdc++.h>
int a[105],n,i,j,ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
		for(j=i-1;j && a[i]%a[j];--j);
		ans+=!j;
	}
	printf("%d\n",ans);
}