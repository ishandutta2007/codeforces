#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int a[10];
bool ok[10];

int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==0) puts("-1");
	else
	{
	/*
	else if(n<10)
	{
		for(int i=0;i<n;i++) a[i]=i;
		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",i);
		}printf("\n");
		do
		{
			bool up=true;
			memset(ok,false,sizeof(ok));
			for(int i=0;i<n;i++)
			{
				int c=i+a[i];c%=n;
				if(ok[c])
				{
					up=false;
					break;
				}
			}
			if(up)
			{
				for(int i=0;i<n;i++)
				{
					if(i!=0) printf(" ");
					printf("%d",a[i]);
				}printf("\n");
				for(int i=0;i<n;i++)
				{
					if(i!=0) printf(" ");
					int c=i+a[i];c%=n;
					printf("%d",c);
				}printf("\n");
				break;
			}
		}while(a,a+n);
	}*/
		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",i);
		}printf("\n");
		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",i);
		}printf("\n");
		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",(i*2)%n);
		}printf("\n");
	}
	return 0;
}