#include<bits/stdc++.h>
using namespace std;
const int N=15e4;
int n,i,j,b[N];
long long tot,c[N];
int pre(int x){return x==1?n:x-1;}
int nxt(int x){return x==n?1:x+1;}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",b+i),tot+=b[i];
	if(tot==0){puts("YES");for(i=1;i<=n;++i)printf("1 ");puts("");return 0;}
	for(i=1;i<=n;++i)if(b[i]>b[pre(i)])break;if(i>n){puts("NO");return 0;}
	puts("YES");
	tot=b[i];
	bool fl=0;
	for(j=i;c[j]=tot,j=pre(j),j!=i;){if(!fl)tot<<=20,fl=1;tot+=b[j];}
	c[i]=b[i];
	for(i=1;i<=n;++i)printf("%lld%c",c[i],i==n?'\n':' ');
	for(i=1;i<=n;++i)assert(c[i]%c[i%n+1]==b[i]);
	return 0;
}