#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e5+3;
const int MOD=1e9+7;
struct milk
{
	int l,r;
}a[MAX];
LL f[MAX];
LL add[MAX];
inline bool myru(milk x,milk y){return x.r<y.r;}
LL rin()
{
	LL s=0;
	bool bj=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')bj=1,c=getchar();
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
	if(bj)return -s;
	return s;
}
int main()
{
	int i,j;
    int n,m;
    LL ans=0;
    n=rin();m=rin();
    
	for(i=1;i<=m;i++)a[i].l=rin(),a[i].r=rin();
	sort(a+1,a+m+1,myru);
	f[0]=1;add[0]=1;
	a[0].r=0;
    for(i=1;i<=m;)
    {
    	for(j=i-1;j<m&&a[j+1].r==a[i].r;)
    	{
    		j++;
    		int l=0,r=i-1,last=i;
    		for(;l<=r;)
    		{
    			int mid=(l+r)>>1;
    			if(a[mid].r>=a[j].l)last=mid,r=mid-1;
    			else l=mid+1;
			}
//			printf("j:%d ,l:%d,r:%d ;f:%lld\n",j,a[j].l,a[j].r,f[j]);
    		if(last==0)f[j]=add[i-1];
			else f[j]=(add[i-1]-add[last-1]+MOD)%MOD;
	    	add[j]=(add[j-1]+f[j])%MOD;
   	 		if(a[j].r==n)ans=(ans+f[j])%MOD;	
		}
		i=j+1;
	}
	printf("%lld",ans);
	return 0;
}