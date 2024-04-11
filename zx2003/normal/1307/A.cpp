#include<bits/stdc++.h>
int T,n,d,a[105],ans,i,x;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&d);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		ans=a[1];
		for(i=2;i<=n;++i){
			x=std::min(a[i],d/(i-1));
			ans+=x;d-=(i-1)*x;
		}
		printf("%d\n",ans);
	}
}