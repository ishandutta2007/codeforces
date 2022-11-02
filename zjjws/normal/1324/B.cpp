#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=5e3+10;
int bj[MAX];
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
    int t=rin();
    for(;t>0;t--)
    {
    	memset(bj,0,sizeof(bj));
    	int n=rin();
    	int x;
    	bool ans=0;
    	for(i=1;i<=n;i++)
    	{
    		x=rin();
    		if(bj[x]>0&&bj[x]!=i-1)ans=1;
    		if(bj[x]==0)bj[x]=i;
		}
    	if(ans==1&&n>=3)printf("YES\n");
    	else printf("NO\n");
	}
    
    return 0;
}