#include<bits/stdc++.h>
using namespace std;

int n,k;

int Ask(int x)
{
	printf("? %d\n",x+1);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}

int main()
{
	srand(time(NULL));
	scanf("%d%d",&n,&k);
	int B=sqrt(n);
	while(1)
	{
		int x=(x+B-1)%n;
		int s=Ask(x);
		if(s>k)
		{
			int l=x-(n+1)/2,r=x;
			while(r-l>1)
			{
				int mid=l+(r-l)/2;
				if(Ask((mid+n)%n)>k)
					r=mid;
				else
					l=mid;
			} 
			printf("! %d\n",(l+n)%n+1);
			return 0;
		}
		if(s<k)
		{
			int l=x,r=x+(n+1)/2;
			while(r-l>1)
			{
				int mid=l+(r-l)/2;
				if(Ask((mid+n)%n)<k)
					l=mid;
				else
					r=mid;
			}
			printf("! %d\n",(r+n)%n+1);
			return 0;
		}
	}
}