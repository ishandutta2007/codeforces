#include<bits/stdc++.h>
int T,a,b,n,i,ans;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&a,&b,&n);ans=0;n%=3;
		for(i=0;i<30;++i){
			int x=a>>i&1,y=b>>i&1;
			if(x==1 && y==1 && n!=2)ans|=1<<i;
			if(x==1 && y==0 && n!=1)ans|=1<<i;
			if(x==0 && y==1 && n!=0)ans|=1<<i;
		}
		printf("%d\n",ans);
	}
}