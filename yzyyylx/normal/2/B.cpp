#include<bits/stdc++.h>
#define ll int
#define N 1005
using namespace std;

ll a[N][N],er[N][N],wu[N][N],n,dp5[N][N],dp2[N][N],pd=0;
char an2[N][N],an5[N][N],ans[N*2];

ll f1(ll m)
{
	ll a=0;
	if(m==0)
	{
		return 1000000000;
	}
	while(m%2==0)
	{
		m/=2;
		a++;
	}
	return a;
}

ll f2(ll m)
{
	ll a=0;
	if(m==0)
	{
		return 1000000000;
	}
	while(m%5==0)
	{
		m/=5;
		a++;
	}
	return a;
}

void print(ll m)
{
	ll i,u,v;
	char p;
	u=v=n;
	i=2*(n-1);
	if(m==5)
	{
		p=an5[n][n];
		while(p!='Q')
		{
			if(p=='D')
			{
				ans[i]='D';
				i--;
				u--;
			}
			else
			{
				ans[i]='R';
				i--;
				v--;
			}
			p=an5[u][v];
//			cout<<p;
		}
		for(i=1;i<=2*(n-1);i++)
		{
			printf("%c",ans[i]);
		}
	}
	if(m==2)
	{
		p=an2[n][n];
		while(p!='Q')
		{
			if(p=='D')
			{
				ans[i]='D';
				i--;
				u--;
			}
			else
			{
				ans[i]='R';
				i--;
				v--;
			}
			p=an2[u][v];
		}
		for(i=1;i<=2*(n-1);i++)
		{
			printf("%c",ans[i]);
		}
	}
}

void pp(int u,int v)
{
	int i,j,p=0;
	pd=1;
	for(i=1;i<=u-1;i++)
	{
		p++;
		ans[p]='D';
	}
	for(i=1;i<=n-1;i++)
	{
		p++;
		ans[p]='R';
	}
	for(i=1;i<=n-u+1;i++)
	{
		p++;
		ans[p]='D';
	}
}

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			{
				pp(i,j);
			}
			dp2[i][j]=er[i][j]=f1(a[i][j]);
			dp5[i][j]=wu[i][j]=f2(a[i][j]);
		}
	}
	/*
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<er[i][j];
		}
		cout<<endl;
	}
	//*/
//	cout<<dp2[1][1]<<dp5[1][1];
	an2[1][1]=an5[1][1]='Q';
	for(i=2;i<=n;i++)
	{
		dp2[1][i]+=dp2[1][i-1];
		dp2[i][1]+=dp2[i-1][1];
		dp5[i][1]+=dp5[i-1][1];
		dp5[1][i]+=dp5[1][i-1];
		an2[i][1]=an5[i][1]='D';
		an2[1][i]=an5[1][i]='R';
	}
	/*
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<dp2[i][j]<<" ";
		}
		cout<<endl;
	}
	//*/
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			if(dp2[i-1][j]>dp2[i][j-1])
			{
				dp2[i][j]+=dp2[i][j-1];
				an2[i][j]='R';
			}
			else
			{
				dp2[i][j]+=dp2[i-1][j];
				an2[i][j]='D';
			}
			if(dp5[i-1][j]>dp5[i][j-1])
			{
				dp5[i][j]+=dp5[i][j-1];
				an5[i][j]='R';
			}
			else
			{
				dp5[i][j]+=dp5[i-1][j];
				an5[i][j]='D';
			}
		}
	}
//	cout<<char(68);
	/*
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<dp2[i][j]<<" ";
		}
		cout<<endl;
	}
	//*/
//	cout<<dp5[n][n]<<endl;
	if(min(dp2[n][n],dp5[n][n])!=0&&pd==1)
	{
		cout<<1<<endl;
		for(i=1;i<=(n-1)*2;i++)
		{
			printf("%c",ans[i]);
		}
		return 0;
	}
	
	if(dp2[n][n]>dp5[n][n])
	{
		cout<<dp5[n][n]<<endl;
		print(5);
	}
	else if(dp2[n][n]<=dp5[n][n])
	{
		cout<<dp2[n][n]<<endl;
		print(2);
	}
}