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
    LL n,k;
    int t;
    //printf("%d\n%d\n%d\n%d\n",(1^0),(0^1),(1^1),(0^0));
    for(t=rin();t>0;t--)
    {
    	n=rin(),k=rin();
    	if(((n&1)^(k&1)))
    	{
    		printf("NO\n");
    		continue;
		}
    	if(k>sqrt(n))
    	{
    		printf("NO\n");
    		continue;
		}
    	printf("YES\n");
	}
    
    
    return 0;
}