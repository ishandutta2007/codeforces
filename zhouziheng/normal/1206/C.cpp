#include<cstdio>

using namespace std;

int a[200010];

int main()
{
	int n=0;scanf("%d",&n);
	if(!(n&1)){puts("NO");}
	else
	{
		puts("YES");
		int p=1;
		for(int i=1;i<=2*n;i++)
		{
			a[p]=i;
			if(i&1){if(p<=n)p+=n;else p-=n;}
			else{p++;}
		}
		for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
	}
	return 0;
}