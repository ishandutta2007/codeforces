#include<bits/stdc++.h>
using namespace std;
int T,a,b,n,i,ans;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&a,&b,&n);ans=999;
		for(i=0;a<=n && b<=n;++i){
			ans=min(ans,min((n-a+b)/b,(n-b+a)/a)+i);
			if(a<b)a+=b;else b+=a;
		}
		printf("%d\n",ans);
	}
}