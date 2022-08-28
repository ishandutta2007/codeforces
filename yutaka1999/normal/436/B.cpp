#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2005

using namespace std;

char str[SIZE];
int sum[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<m;j++)
		{
			if(str[j]=='L')
			{
				if(j-i>=0) sum[j-i]++;
			}
			else if(str[j]=='R')
			{
				if(j+i<m) sum[j+i]++;
			}
			else if(str[j]=='U')
			{
				if(i%2==0) sum[j]++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",sum[i]);
	}puts("");
	return 0;
}