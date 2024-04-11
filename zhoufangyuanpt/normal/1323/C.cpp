#include<cstdio>
#include<cstring>
using namespace std;
char a[1010000];
int main()
{
	int n;scanf("%d%s",&n,a+1);
	int g=0;
	for(int i=1;i<=n;i++)if(a[i]=='(')g++;else g--;
	if(g!=0){printf("-1\n");return 0;}
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(')
		{
			g++;
			if(g==0)ss++;
		}
		else
		{
			g--;
		}
		if(g<0)ss++;
	}
	printf("%d\n",ss);
	return 0;
}