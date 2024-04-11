#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 205

using namespace std;

int A[SIZE],B[SIZE];
char str[SIZE];

int getA(int a,int b)
{
	return A[b]-(a==0?0:A[a-1]);
}
int getB(int a,int b)
{
	return B[b]-(a==0?0:B[a-1]);
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	for(int i=0;i<n;i++)
	{
		if(str[i]=='L') A[i]=1;
		else if(str[i]=='R') A[i]=-1;
		else if(str[i]=='U') B[i]=1;
		else B[i]=-1;
		if(i>0)
		{
			A[i]+=A[i-1];
			B[i]+=B[i-1];
		}
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(getA(i,j)==0&&getB(i,j)==0)
			{
				ret++;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}