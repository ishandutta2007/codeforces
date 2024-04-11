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
    int t=rin();
    for(;t>0;t--)
    {
    	int n,m;
    	n=rin(),m=rin();
    	int s=0;
    	for(i=1;i<=n;i++)s+=rin();
    	printf("%d\n",min(s,m));
	}
    
    return 0;
}