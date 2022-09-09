#include<bits/stdc++.h>
const int N=1000005;
int n,i,ans,x;
char c[N];
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	memcpy(c+n+1,c+1,n);
	for(i=1;i<=n*2;++i){
		if(c[i]!=c[i-1])++x;else x=1;
		if(x>ans)ans=x;
	}
	if(ans>n)ans=n;
	printf("%d\n",ans);
	return 0;
}