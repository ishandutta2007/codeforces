/*************************************************************************
    > File Name: 876_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 16 Oct 2017 11:28:08 PM CST
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

int min(int a, int b)
{
	if(a <= b) return a;
	else return b;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int tmp=min(a, min(b, c));
		int ans=0;
		if((a==tmp) || (b==tmp))
			ans=(n-1)*tmp;
		else
		{
			if(n >= 2) ans=min(a+(n-2)*tmp, b+(n-2)*tmp);
			else if(n == 1) ans=0;
		}
		printf("%d\n", ans);
	}
	return 0;
}