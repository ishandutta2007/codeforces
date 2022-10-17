/*************************************************************************
    > File Name: 835_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 31 Jul 2017 10:37:36 PM CST
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
	int	s, v1, v2, t1, t2;
	while(scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2) != EOF)
	{
		int ans1=s*v1+2*t1;
		int ans2=s*v2+2*t2;
		if(ans1 < ans2) printf("First\n");
		if(ans1 > ans2) printf("Second\n");
		if(ans1 == ans2) printf("Friendship\n");
	}
	return 0;
}