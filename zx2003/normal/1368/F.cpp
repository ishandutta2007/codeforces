#include<bits/stdc++.h>
const int N=1005;
int n,i,j,k,p,a[N],xb;
bool b[N],bb[N];
int main(){
	scanf("%d",&n);
	if(n<=3){
		puts("0");fflush(stdout);
		return 0;
	}
	auto calc=[&](int x){return n-(n+x-1)/x-(x-1);};
	for(i=p=1;i<=n;++i)if(calc(i)>calc(p))p=i;
	for(i=1;i<n;++i)if((i-1)%p<p-1)b[i]=1;
	for(;;){
		xb=0;
		for(i=1;i<=n;++i)if(b[i] && !bb[i])a[++xb]=i,bb[i]=1;
		printf("%d ",xb);for(i=1;i<=xb;++i)printf("%d%c",a[i],i==xb?'\n':' ');fflush(stdout);
		scanf("%d",&k);
		for(i=0;i<xb;++i,k==n?k=1:++k)bb[k]=0;
		int cnt=0;for(i=1;i<=n;++i)cnt+=bb[i];if(cnt==calc(p))break;
	}
	puts("0");fflush(stdout);
}