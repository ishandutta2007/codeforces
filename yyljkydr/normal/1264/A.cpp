#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int n,p[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		int m=n/2;
		int g=0,s=0,b=0;
		int x=1;
		while(p[x]==p[1]&&x<=m)
			g++,x++;
		int ls,lb;
		while(s<=g&&x<=m)
			ls=p[x],s++,x++;
		while(p[x]==ls&&x<=m)
			s++,x++;
		while(x<=m)
			lb=p[x],b++,x++;
		if(p[x]==lb)
			while(p[x-1]==lb)
				x--,b--;
		if(g>=s||g>=b)
			puts("0 0 0");
		else
			printf("%d %d %d\n",g,s,b);
	}
}