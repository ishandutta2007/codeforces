#include<bits/stdc++.h>
typedef long long ll;
ll a[3];
int x,i,b[3];
int main(){
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	printf("First\n9982443530\n");fflush(stdout);
	scanf("%d",&x);if(x==0)return 0;
	a[x-1]+=9982443530ll;
	for(i=0;i<3;++i)b[i]=i;std::sort(b,b+3,[&](int x,int y){return a[x]<a[y];});
	printf("%lld\n",a[b[2]]*2-a[b[0]]-a[b[1]]);fflush(stdout);
	scanf("%d",&x);if(x==0)return 0;
	a[x-1]+=a[b[2]]*2-a[b[0]]-a[b[1]];
	for(i=0;i<3;++i)b[i]=i;std::sort(b,b+3,[&](int x,int y){return a[x]<a[y];});
	printf("%lld\n",a[b[2]]-a[b[1]]);fflush(stdout);
	scanf("%d",&x);if(x==0)return 0;
	assert(0);	
}