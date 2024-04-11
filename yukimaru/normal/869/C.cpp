/*************************************************************************
    > File Name: 869_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Fri 06 Oct 2017 09:49:36 PM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

const long long mod = 998244353;

long long cc[5005][5005], f[5005];

void init2()
{
	cc[0][0]=1;
	for(int i=1; i<=5000; i++)
	{
		cc[i][0]=1;
		for(int j=1; j<=i; j++)
			cc[i][j]=(cc[i-1][j]+cc[i-1][j-1])%mod;
	}
	f[0]=1;
	f[1]=1;
	for(int i=2; i<=5000; i++) f[i]=f[i-1]*i%mod;
}

int main()
{
	init2();
	long long a, b, c;
	while(scanf("%lld%lld%lld", &a, &b, &c) != EOF)
	{
		long long tmp=0;
		for(int i=0; i<=a; i++)
			tmp=(tmp+cc[a][i]*cc[b][i]%mod*f[i]%mod)%mod;
		long long ttmp=0;
		for(int i=0; i<=b; i++)
			ttmp=(ttmp+cc[b][i]*cc[c][i]%mod*f[i]%mod)%mod;
		long long tttmp=0;
		for(int i=0; i<=c; i++)
			tttmp=(tttmp+cc[c][i]*cc[a][i]%mod*f[i]%mod)%mod;
		long long ans=tmp*ttmp%mod*tttmp%mod;
		printf("%lld\n", ans);
	}
	return 0;
}