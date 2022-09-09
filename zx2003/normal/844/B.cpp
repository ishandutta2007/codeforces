#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[55][55],rb[55],rw[55],cb[55],cw[55],i,j;
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			scanf("%d",a[i]+j);
			if(a[i][j])++rb[i],++cb[j];
				else ++rw[i],++cw[j];
		}
	for(i=1;i<=n;++i)ans+=((1ll<<rb[i])-1)+((1ll<<rw[i])-1);
	//cout<<rb[1]<<endl;
	for(i=1;i<=m;++i)ans+=((1ll<<cb[i])-1)+((1ll<<cw[i])-1);
	std::cout<<ans-n*m<<std::endl;
	return 0;
}