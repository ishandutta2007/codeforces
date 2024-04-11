#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define LL long long
using namespace std;
const int MAX=2e5+3;
struct milk
{
	int s;
	int to;
};
milk f_1[20][MAX];//max
milk f_2[20][MAX];//min
int lens[MAX];
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
    int i,j;
    int n,m;
    n=rin();m=rin();
    for(i=1;i<=n;i++)f_1[0][i].s=f_2[0][i].s=rin(),f_1[0][i].to=f_2[0][i].to=i;
    for(i=1;(1<<i)<=n;i++)for(j=1;j+(1<<i)-1<=n;j++)
    {
    	milk x=f_1[i-1][j],y=f_1[i-1][j+(1<<i-1)];
    	if(x.s>y.s)f_1[i][j]=x;
    	else f_1[i][j]=y;
    	x=f_2[i-1][j],y=f_2[i-1][j+(1<<i-1)];
    	if(x.s<y.s)f_2[i][j]=x;
    	else f_2[i][j]=y;
	}
    lens[1]=0;for(i=2;i<=n;i++){lens[i]=lens[i-1];if(i>(1<<lens[i]+1))lens[i]++;}
    for(i=1;i<=m;i++)
    {
    	int l,r,x;
    	l=rin();r=rin();x=rin();
    	int z=lens[r-l+1];
    	milk a,b,c;
    	a=f_1[z][l];b=f_1[z][r-(1<<z)+1];
    	if(a.s>b.s)c=a;else c=b;
    	if(c.s!=x)printf("%d\n",c.to);
    	else
    	{
    		a=f_2[z][l];b=f_2[z][r-(1<<z)+1];
        	if(a.s<b.s)c=a;else c=b;
    		if(c.s!=x)printf("%d\n",c.to);
    		else printf("-1\n");
		}
	}
    
	return 0;
}