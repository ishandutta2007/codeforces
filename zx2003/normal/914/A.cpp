#include<bits/stdc++.h> 
int x,y,n,i,ans;
int main(){
	scanf("%d",&n);ans=-1000000;
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(x>=0){
			y=sqrt(x);
			if(y*y!=x)ans=std::max(ans,x);
		}else ans=std::max(ans,x);
	}
	printf("%d\n",ans);
	return 0;
}