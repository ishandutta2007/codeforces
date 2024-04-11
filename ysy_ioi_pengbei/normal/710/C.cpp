#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;
int n,mat[50][50],px,py;
#define FO(s) {freopen(#s".in","r",stdin);freopen(#s".out","w",stdout);}
int main()
{
	cin>>n;
	memset(mat,0,sizeof(mat));
	px=1; py=(n+1)/2;
	mat[px][py]=1;
	for(int i=2;i<=n*n;i++)
	{
		if(px==1&&py!=n)
		{
			px=n; ++py; mat[px][py]=i;
		}
		else if(py==n&&px!=1)
		{
			--px; py=1; mat[px][py]=i;
		}
		else if(px==1&&py==n)
		{
			++px; mat[px][py]=i;
		}
		else
		{
			if(!mat[px-1][py+1])
			{
				--px; ++py; mat[px][py]=i;
			}
			else
			{
				++px; mat[px][py]=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d",mat[i][j]);
			if(j!=n) putchar(' ');
		}
		putchar('\n');
	}
}