#include<stdio.h>
#include<queue>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
int a[100002],n,c;
int main()
{
	while((c=getchar())>='a')a[++n]=(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
	if(c!='\n')while(getchar()!='\n');
	for(int i=1;i<=n;i++)
	{
		c=getchar();
		if(c<'a'||((c=='a'||c=='e'||c=='i'||c=='o'||c=='u')^a[i]))
		{
			printf("No");
			return 0;
		}
	}
	if(getchar()<'a')printf("Yes");
	else printf("No");
}