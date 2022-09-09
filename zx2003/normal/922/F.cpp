#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,k,d[N],i,j,a[N],xb;
bool b[N];
pair<int,int>c[N];
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n>>1;++i)
		for(j=i<<1;j<=n;j+=i)d[j]++;
	for(i=1;i<=n;++i)d[i]+=d[i-1];
	if(k>d[n])return puts("No"),0;
	for(i=1;i<=n;++i)if(d[i]>=k)break;n=i;
	for(i=n;i<<1>n;--i)c[++xb]=make_pair(d[i]-d[i-1],i);
	sort(c+1,c+xb+1);j=d[n]-k;
	for(i=xb;i;--i)if(j>=c[i].first)j-=c[i].first,b[c[i].second]=1;
	for(i=1,xb=0;i<=n;++i)if(!b[i])a[++xb]=i;
	printf("Yes\n%d\n",xb);
	for(i=1;i<=xb;++i)printf("%d ",a[i]);
	return 0;
}