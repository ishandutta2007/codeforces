#include<bits/stdc++.h>
using namespace std;

const int N=3e2+1e1+7;

int T,n;

char s[N][N];

int c[2][3];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		int k=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++)
				c[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(s[i][j]=='X')
					c[0][(i+j)%3]++,k++;
				else if(s[i][j]=='O')		
					c[1][(i+j)%3]++,k++;
		bool ok=0;
		for(int a=0;a<3&&!ok;a++)
			for(int b=0;b<3&&!ok;b++)
				if(a!=b&&c[0][a]+c[1][b]<=k/3)
				{
					for(int i=1;i<=n;i++)
						for(int j=1;j<=n;j++)
							if(s[i][j]!='.')
							{
								if((i+j)%3==a)
									s[i][j]='O';
								if((i+j)%3==b)
									s[i][j]='X';
							}
					for(int i=1;i<=n;i++)
						puts(s[i]+1);
					ok=1;
				} 
	}
}