#include<bits/stdc++.h>
using namespace std;
int n,a[2010],ans=1000000007,flag;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),flag|=a[i]==1;
	if(flag){
		ans=0;
		for(int i=1;i<=n;++i)if(a[i]!=1)ans++;
		return printf("%d",ans),0;
	}
	for(int i=1;i<=n;++i){
		int g=0;
		for(int j=i;j>=1;--j){
			g=__gcd(a[j],g);
			if(g==1){ans=min(ans,n+i-j-1);break;}
		}
	}
	if(ans==1000000007)printf("-1");
	else printf("%d\n",ans);
}