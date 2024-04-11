#include<bits/stdc++.h>
int b,g,n,i,ans;
int main(){
	scanf("%d%d%d",&b,&g,&n);
	for(i=0;i<=n;++i)if(i<=b && n-i<=g)++ans;
	printf("%d\n",ans);
	return 0;
}