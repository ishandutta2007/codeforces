#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string st[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string t;
int n,kk,ok[2005][2005],num[10],cost[1<<7][10],x,a[2005],mdr,zy[2005][2005],rk[2005][2005],cnt=0;
bool cmp(int x,int y){return rk[mdr][x]<rk[mdr][y];}
vector<int>buc[10];
int conv(string h)
{
	int ans=0;
	for(int i=6;i>=0;i--)if(h[6-i]=='1')ans+=(1<<i);
	return ans;
}
int main()
{
	for(int i=0;i<10;i++)num[i]=conv(st[i]);
	for(int i=0;i<(1<<7);i++)
	{
		for(int j=0;j<10;j++)
		{
			if((i&num[j])!=i)cost[i][j]=-1;
			else cost[i][j]=__builtin_popcount(i^num[j]);
			//printf("%d %d %d %d %d %d\n",i,j,cost[i][j],num[i]^num[j],num[j],num[i]);
		}
	}
	cin>>n>>kk;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=conv(t);
		//printf("#%d\n",a[i]);
	}
	ok[n+1][0]=1;
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<10;j++)buc[j].clear();
		for(int j=0;j<=kk;j++)
		{
			ok[i][j]=0;
			for(int k=9;k>=0;k--)
			{
				if(cost[a[i]][k]>j||cost[a[i]][k]==-1||!ok[i+1][j-cost[a[i]][k]])continue;
				zy[i][j]=k;
				ok[i][j]=1;
				break;
			}
			//printf("%d %d %d\n",i,j,ok[i][j]);
		}
	}
	if(ok[1][kk]==0)printf("-1\n");
	else
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d",zy[i][kk]);
			kk-=cost[a[i]][zy[i][kk]];
		}
	}
	return 0;
}