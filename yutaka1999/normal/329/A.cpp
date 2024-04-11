#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SIZE 105

using namespace std;

int tt[SIZE],yy[SIZE];
char mp[SIZE][SIZE];
vector <int> vec;
int num[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&mp[i]);
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]=='E')
			{
				tt[i]++;
				yy[j]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(tt[i]==n&&yy[j]==n)
			{
				puts("-1");
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(tt[i]==n)
		{
			for(int j=0;j<n;j++)//c
			{
				for(int k=0;k<n;k++)//
				{
					if(tt[k]==n) continue;
					if(mp[k][j]!='E')
					{
						printf("%d %d\n",k+1,j+1);
						break;
					}
				}
			}
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]!='E')
			{
				printf("%d %d\n",i+1,j+1);
				break;
			}
		}
	}
	return 0;
}