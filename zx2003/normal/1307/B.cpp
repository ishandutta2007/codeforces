#include<bits/stdc++.h>
int T,n,x,a,ma,i,ans;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&x);ma=0;
		bool fl=0;
		for(i=1;i<=n;++i)scanf("%d",&a),ma=std::max(ma,a),fl|=a==x;
		ans=(x+ma-1)/ma;if(ans==1 && !fl)ans=2;
		printf("%d\n",ans);
	}
}