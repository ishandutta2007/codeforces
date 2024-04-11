/*************************************************************************
    > File Name: 868_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 05 Oct 2017 03:05:29 PM CST
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

int main()
{
	char s[10];
	int n;
	while(scanf("%s%d", s, &n) != EOF)
	{
		char sx[105][10];
		for(int i=1; i<=n; i++) scanf("%s", sx[i]);
		bool flag1=0, flag2=0, flag3=0;
		for(int i=1; i<=n; i++)
		{
			if(sx[i][0] == s[1]) flag1=1;
			if(sx[i][1] == s[0]) flag2=1;
			if(sx[i][0]==s[0] && sx[i][1]==s[1]) flag3=1;
		}
		if((flag1==1&&flag2==1) || (flag3==1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}