#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,mm[30][30],dp[(1 << 20)][25],ans;//.

int main()
{
	ll i,j,k,p,q;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		mm[p][q]=mm[q][p]=1;
	}
	
	/*
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<mm[i][j];
		}
		cout<<endl;
	}
	//*/
	
	for(i=1;i<=n;i++) dp[(1 << (i-1))][i]=1;
	for(i=1;i<=(1 << n)-1;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dp[i][j]!=0)
			{
//				cout<<i<<endl;
				for(k=1;k<=n;k++)
				{
					if(mm[k][j]!=0&&(1 << (k-1))>=(i & (-i)))
					{
						if((i & (1 << (k-1)))!=0)
						{
							if((1 << (k-1))==(i & (-i)))
							ans+=dp[i][j];
						}
						else
						{
							dp[i | (1 << (k-1))][k]+=dp[i][j];
						}
					}
				}
			}
		}
	}
	cout<<(ans-m)/2;
}