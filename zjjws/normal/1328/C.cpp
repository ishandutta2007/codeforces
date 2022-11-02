#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=5e4+10;
int a[MAX];
int b[MAX];
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
    	int n=rin();
    	bool bj=0;
    	char x;
    	for(i=1;i<=n;i++)
    	{
    		if(bj==0)
    		{
    			scanf("%c",&x);
    			if(x=='0')a[i]=b[i]=0;
    			if(x=='1')a[i]=1,b[i]=0,bj=1;//a 
    			if(x=='2')a[i]=1,b[i]=1;
			}
    		else
    		{
    			scanf("%c",&x);
    			if(x=='0')a[i]=b[i]=0;
    			if(x=='1')a[i]=0,b[i]=1;
    			if(x=='2')a[i]=0,b[i]=2;
			}
		}
    	for(i=1;i<=n;i++)printf("%d",a[i]);printf("\n");
    	for(i=1;i<=n;i++)printf("%d",b[i]);printf("\n");
	}
    
    return 0;
}
// 0-->1+2,2+1,0+0
// 1-->1+0,0+1,2+2
// 2-->1+1,0+2,2+0