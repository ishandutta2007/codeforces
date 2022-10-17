#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7,M=1e5+1e3+7;

int T,n,s[N][N],m,ans[N][N];

char op[M];

int a[3],b[3];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<3;i++)
			a[i]=0,b[i]=i;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&s[i][j]),s[i][j]--;
		scanf("%s",op+1);
		for(int i=1;i<=m;i++)
		{
			if(op[i]=='U')
				a[b[0]]=(a[b[0]]-1+n)%n;
			if(op[i]=='D') 
				a[b[0]]=(a[b[0]]+1)%n;
			if(op[i]=='L')
				a[b[1]]=(a[b[1]]-1+n)%n;
			if(op[i]=='R')
				a[b[1]]=(a[b[1]]+1)%n;
			if(op[i]=='I')
				swap(b[1],b[2]);
			if(op[i]=='C')
				swap(b[0],b[2]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int as[3],t[3]={i,j,s[i][j]};
				as[0]=(t[b[0]]+a[b[0]])%n;
				as[1]=(t[b[1]]+a[b[1]])%n;
				as[2]=(t[b[2]]+a[b[2]])%n;
				ans[as[0]][as[1]]=as[2];
			}
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<n;j++,putchar(' '))
				printf("%d",ans[i][j]+1);
	}
}