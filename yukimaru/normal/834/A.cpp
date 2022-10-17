/*************************************************************************
    > File Name: 834_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 30 Jul 2017 10:36:43 PM CST
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
	char c1, c2;
	char tmp;
	while(scanf("%c%c%c%c", &c1, &tmp, &c2, &tmp) != EOF)
	{
		int n;
		scanf("%d%c", &n, &tmp);
		int flag=2;
		if(c1 == '^')
		{
			if(c2 == '^') flag=0;
			if(c2 == '>')
			{
				if((n-1) % 4 == 0) flag=1;
				else if((n-3) % 4 == 0) flag=-1;
				else flag=0;
			}
			if(c2 == 'v') flag=0;
			if(c2 == '<')
			{
				if((n-3) % 4 == 0) flag=1;
				else if((n-1) % 4 == 0) flag=-1;
				else flag=0;
			}
		}
		if(c1 == '>')
		{
			if(c2 == '^')
			{
				if((n-3) % 4 == 0) flag=1;
				else if((n-1) % 4 == 0) flag=-1;
				else flag=0;
			}
			if(c2 == '>') flag=0;
			if(c2 == 'v')
			{
				if((n-1) % 4 == 0) flag=1;
				else if((n-3) % 4 == 0) flag=-1;
				else flag=0;
			}
			if(c2 == '<') flag=0;
		}
		if(c1 == 'v')
		{
			if(c2 == '^') flag=0;
			if(c2 == '>')
			{
				if((n-3) % 4 == 0) flag=1;
				else if((n-1) % 4 == 0) flag=-1;
				else flag=0;
			}
			if(c2 == 'v') flag=0;
			if(c2 == '<')
			{
				if((n-1) % 4 == 0) flag=1;
				else if((n-3) % 4 == 0) flag=-1;
				else flag=0;
			}
		}
		if(c1 == '<')
		{
			if(c2 == '^')
			{
				if((n-1) % 4 == 0) flag=1;
				else if((n-3) % 4 == 0) flag=-1;
				else flag=0;
			}
			if(c2 == '>') flag=0;
			if(c2 == 'v')
			{
				if((n-3) % 4 == 0) flag=1;
				else if((n-1) % 4 == 0) flag=-1;
				else flag=0;
			}
			if(c2 == '<') flag=0;
		}
		if(flag == 1) printf("cw\n");
		if(flag == -1) printf("ccw\n");
		if(flag == 0) printf("undefined\n");
	}
	return 0;
}