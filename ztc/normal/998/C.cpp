#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
bool a[300002];
long long cnt=0,n,x,y,i;
char C;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	a[0]=1;
	C=getchar();
	for(i=1;i<=n;i++)
	{
		C=getchar();
		a[i]=C-'0';
		if(a[i]!=a[i-1])cnt++;
	}
	if(a[n]!=1)cnt++;
	cnt/=2;
	if(!cnt)printf("0");
	else
	{
		if(x>=y)printf("%I64d",cnt*y);
		else printf("%I64d",y+(cnt-1)*x);
	}
	return 0;
}