#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e5+10;
bool bj[MAX];
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
    int t;
    for(t=rin();t>0;t--)
    {
    	memset(bj,0,sizeof(bj));
    	int n=rin();
    	int ans=0;
    	for(i=1;i<=n;i++)
    	{
    		int k=rin();
    		bool now=0;
    		for(j=1;j<=k;j++)
    		{
    			int x=rin();
    			if(now)continue;
    			if(!bj[x])bj[x]=1,now=1;
			}
    		if(!now)ans=i;
		}
		if(ans!=0)
    	{
    	printf("IMPROVE\n");
    	for(i=1;i<=n;i++)if(!bj[i]){printf("%d %d\n",ans,i);break;}
		}
    	else printf("OPTIMAL\n");
	}
    
    return 0;
}