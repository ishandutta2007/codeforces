#include<bits/stdc++.h>
#define ll long long
using namespace std;

int zt[10][10],cnt;
bool p[10];

bool pdh(int u)
{
	if(zt[u][1]==zt[u][2]&&zt[u][3]==zt[u][4]) return 1;
	return 0;
}

bool pds(int u)
{
	if(zt[u][1]==zt[u][3]&&zt[u][2]==zt[u][4]) return 1;
	return 0;
}

int main()
{
	int i,j;
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=4;j++)
		{
			scanf("%d",&zt[i][j]);
		}
		bool now=0;
		for(j=1;j<4&&!now;j++)
		{
			if(zt[i][j]!=zt[i][j+1]) now=1;
		}
		if(now)
		{
			p[i]=1;
			cnt++;
		}
	}
	if(cnt!=4)
	{
		printf("NO");
		return 0;
	}
	if(p[1])
	{
		if(pdh(1))
		{
			if(zt[5][1]==zt[1][1])
			{
				if(pdh(3)&&pds(5)&&pds(4)&&zt[5][2]==zt[3][1]&&zt[3][3]==zt[4][2]&&zt[4][1]==zt[1][3])
				{
					printf("YES");
					return 0;
				}
			}
			if(zt[4][2]==zt[1][1])
			{
				if(pdh(3)&&pds(5)&&pds(4)&&zt[4][1]==zt[3][1]&&zt[3][3]==zt[5][1]&&zt[5][2]==zt[1][3])
				{
					printf("YES");
					return 0;
				}
			}
		}
		if(pds(1))
		{
			if(pds(2)&&pds(3)&&pds(6))
			{
				if(zt[1][1]==zt[2][2]&&zt[2][1]==zt[3][2]&&zt[3][1]==zt[6][1]&&zt[6][2]==zt[1][2])
				{
					printf("YES");
					return 0;
				}
				if(zt[1][1]==zt[6][1]&&zt[6][2]==zt[3][2]&&zt[3][1]==zt[2][2]&&zt[2][1]==zt[1][2])
				{
					printf("YES");
					return 0;
				}
			}
		}
	}
	else if(pdh(2)&&pdh(4)&&pdh(5)&&pdh(6))
	{
		if(zt[4][1]==zt[2][3]&&zt[2][1]==zt[5][3]&&zt[5][1]==zt[6][4]&&zt[6][2]==zt[4][3])
		{
			printf("YES");
			return 0;
		}
		if(zt[4][1]==zt[6][4]&&zt[6][2]==zt[5][3]&&zt[5][1]==zt[2][3]&&zt[2][1]==zt[4][3])
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}