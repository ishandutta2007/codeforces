#include<bits/stdc++.h>
int n,k,i,m;
int main(){
	scanf("%d%d",&n,&k);m=n-k+2>>1;//m=n-k+1;//m=std::min(k,n-k+2>>1);
	for(i=0;i<n;++i)putchar(i%m>=(k>=m?1:m-k)?'0':'1');puts("");
	return 0;
}