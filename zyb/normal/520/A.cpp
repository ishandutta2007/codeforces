#include<stdio.h>
using namespace std;
int a[1005];
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		char c=getchar();
		while (!(('A'<=c&&'Z'>=c)||('a'<=c&&'z'>=c)))
		c=getchar();
		if (c>'Z')
		a[int(c)-96]=1;
		else
		a[int(c)-64]=1;
	}
	for (i=1;i<=26;i++)
	if (!a[i])
	{
		printf("NO");
		return 0;
	}
	
	printf("YES");
}