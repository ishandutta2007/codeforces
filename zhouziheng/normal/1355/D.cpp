#include<cstdio>

using namespace std;

int main()
{
	int n=0,s=0;scanf("%d%d",&n,&s);
	if(s%2==0)
	{
		if(n>s/2){puts("NO");}
		else{puts("YES");for(int i=1;i<n;i++)printf("2 ");printf("%d ",s-2*(n-1));printf("\n1");}
	}
	else
	{
		if(n>s/2){puts("NO");}
		else{puts("YES");for(int i=1;i<n;i++)printf("2 ");printf("%d ",s-2*(n-1));printf("\n1");}
	}
	return 0;
}