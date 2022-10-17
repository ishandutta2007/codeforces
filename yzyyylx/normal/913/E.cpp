#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int n,k,k1,k2,a,b,x=0b00001111,y=0b00110011,z=0b01010101;
string dp[5][300],tmp,tmp2;
bool have;
//0 -- (),!
//1 -- &
//2 -- |
bool operator < (string u,string v)
{
	if(u==""||v=="") return v=="";
	if(u.size()!=v.size())return u.size()<v.size();
	int i;
	for(i=0; i<u.size(); i++)
	{
		if(u[i]!=v[i]) return u[i]<v[i];
	}
	return 0;
}

int main()
{
	int i,j;
	dp[0][x]='x';
	dp[0][y]='y';
	dp[0][z]='z';

	for(have=1; have;)
	{
		have=0;
		// ()
		for(i=0; i<=255; i++)
		{
			if(dp[2][i]=="") continue;
			tmp='('+dp[2][i]+')';
			if(tmp<dp[0][i])
			{
				have=1;
				dp[0][i]=tmp;
			}
		}

		// !
		for(i=0; i<=255; i++)
		{
			if(dp[0][i]=="") continue;
			tmp='!'+dp[0][i];
			if(tmp<dp[0][i^255])
			{
				have=1;
				dp[0][i^255]=tmp;
			}
		}

		// &
		for(i=0; i<=255; i++)
		{
			if(dp[0][i]=="") continue;
			if(dp[0][i]<dp[1][i])
			{
				have=1;
				dp[1][i]=dp[0][i];
			}
		}
		for(i=0; i<=255; i++)
		{
			if(dp[1][i]=="") continue;
			for(j=0; j<=255; j++)
			{
				if(dp[1][j]=="") continue;
				tmp=dp[1][i]+'&'+dp[1][j];
				if(tmp<dp[1][i&j])
				{
					have=1;
					dp[1][i&j]=tmp;
				}
			}
		}

		// |
		for(i=0; i<=255; i++)
		{
			if(dp[1][i]=="") continue;
			if(dp[1][i]<dp[2][i])
			{
				have=1;
				dp[2][i]=dp[1][i];
			}
		}
		for(i=0; i<=255; i++)
		{
			if(dp[2][i]=="") continue;
			for(j=0; j<=255; j++)
			{
				if(dp[2][j]=="") continue;
				tmp=dp[2][i]+'|'+dp[2][j];
				if(tmp<dp[2][i|j])
				{
					have=1;
					dp[2][i|j]=tmp;
				}
			}
		}
	}
 
	cin>>n;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&k);
		k1=0;
		for(j=0; j<=7; j++)
		{
			k1+=k%10*(1 << j);
			k/=10;
		}
		if(dp[0][k1]<dp[1][k1]&&dp[0][k1]<dp[2][k1])
		{
			cout<<dp[0][k1];
		}
		else if(dp[1][k1]<dp[2][k1])
		{
			cout<<dp[1][k1];
		}
		else
		{
			cout<<dp[2][k1];
		}
		puts("");
	}
}