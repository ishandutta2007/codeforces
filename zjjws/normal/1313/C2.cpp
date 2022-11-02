#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define LL long long
using namespace std;
const int MAX=5e5+3;
LL a[MAX];
LL b[MAX];
LL f_1[MAX];//l
LL f_2[MAX];//r
LL l[MAX];
LL r[MAX];
LL d[MAX];
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
    LL i,j;
    LL n;
    n=rin();
    for(i=1;i<=n;i++)a[i]=rin();
    int tail=0;
    for(i=n;i>=1;i--){for(;tail>0&&a[i]<a[d[tail]];tail--)l[d[tail]]=i;d[++tail]=i;}
	for(;tail>0;tail--)l[d[tail]]=0;
	tail=0;
	for(i=1;i<=n;i++){for(;tail>0&&a[i]<a[d[tail]];tail--)r[d[tail]]=i;d[++tail]=i;}
	for(;tail>0;tail--)r[d[tail]]=n+1;
	
	f_1[0]=f_2[n+1]=0;
	for(i=1;i<=n;i++)f_1[i]=f_1[l[i]]+(i-l[i])*a[i];
	for(i=n;i>=1;i--)f_2[i]=f_2[r[i]]+(r[i]-i)*a[i];
	
	LL ans=0;
	int st;
	for(i=1;i<=n;i++)if(ans<f_1[i]+f_2[i]-a[i])ans=f_1[i]+f_2[i]-a[i],st=i;
	b[st]=a[st];
	for(i=st-1;i>=1;i--)b[i]=min(b[i+1],a[i]);
	for(i=st+1;i<=n;i++)b[i]=min(b[i-1],a[i]);
	for(i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}