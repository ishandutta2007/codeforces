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
    int t;
	for(t=rin();t>0;t--)
	{
		int a,b;
		a=rin(),b=rin();
		int ans=(b-(a%b));
		if(a%b==0)printf("0\n");
		else printf("%d\n",ans);
		
	 } 
    
    return 0;
}