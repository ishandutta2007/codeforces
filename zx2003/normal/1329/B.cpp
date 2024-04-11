#include<bits/stdc++.h>
int T,d,m,i,ans;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&d,&m);
		ans=1;
		for(i=0;1<<i<=d;++i)ans=1ll*ans*(((1<<i+1)-1<=d?1<<i:d-(1<<i)+1)+1)%m;
		ans=(ans+m-1)%m;
		printf("%d\n",ans);
	}
}