#include<bits/stdc++.h>
const int N=1005;
int i,n,s[N],j,x,ans=1;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=0;j<4;++j)scanf("%d",&x),s[i]+=x;
	}
	for(i=2;i<=n;++i)ans+=s[i]>s[1];
	printf("%d\n",ans);
	return 0;
}