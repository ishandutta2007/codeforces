/*************************************************************************
    > File Name: 987_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 03 Jun 2018 10:02:01 AM CST
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

const double eps=1e-8;

int main()
{
	double x, y;
	while(scanf("%lf%lf", &x, &y) != EOF)
	{
		double tmp=y*log(x)-x*log(y);
		if(fabs(tmp) <= eps)
			printf("=\n");
		else if(tmp < eps)
			printf("<\n");
		else printf(">\n");
	}
	return 0;
}