#include <bits/stdc++.h>
#define LL long long
using namespace std;
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
    for(int t=rin();t>0;t--)
	{
		int n,k;
		n=rin(),k=rin();
		int b1,b2;
		int l=1,r=n-1,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			LL now=n-mid;
			if(k<=(now*(now+1)>>1))b1=mid,l=mid+1;
			else r=mid-1;
		}
		LL now=n-b1;
		b2=n-(k-((now-1)*now>>1))+1;
		//printf("\nb1:%d,b2:%d\n",b1,b2);
		for(i=1;i<=n;i++)if(i==b1||i==b2)printf("b");else printf("a");
		printf("\n");
	 } 
    return 0;
}
/*
1: n-1,n;
2: n-2,n;
3: n-2,n-1;
4: n-3,n;
*/