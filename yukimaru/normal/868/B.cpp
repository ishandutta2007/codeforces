/*************************************************************************
    > File Name: 868_B_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 05 Oct 2017 03:40:18 PM CST
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
	int h, m, s, t1, t2;
	while(scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2) != EOF)
	{
		if(h == 12) h=0;
		h=h*30;
		if(m!=0 || s!=0) h=(h+3)%360;
		m=m*6; s=s*6;
		if(s != 0) m=(m+3)%360;
		if(t1 == 12) t1=0;
		if(t2 == 12) t2=0;
		t1=t1*30; t2=t2*30;
		bool flag1=1, flag2=1;
		for(int i=t1; i!=t2; i=(i+3)%360)
		{
			if(i==h || i==m || i==s) flag1=0;
		}
		for(int i=t1; i!=t2; i=(i+357)%360)
		{
			if(i==h || i==m || i==s) flag2=0;
		}
		if(flag1==1 || flag2==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}