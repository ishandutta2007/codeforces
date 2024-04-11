/*************************************************************************
    > File Name: 987_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 03 Jun 2018 09:46:03 AM CST
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
	char s1[10][10]={"purple", "green", "blue", "orange", "red", "yellow"};
	char s2[10][10]={"Power", "Time", "Space", "Soul", "Reality", "Mind"};
	int n;
	while(scanf("%d", &n) != EOF)
	{
		char tmp[10];
		bool f[10]={0};
		int num=0;
		while(n--)
		{
			scanf("%s", tmp);
			for(int i=0; i<6; i++)
				if(strcmp(tmp, s1[i]) == 0)
				{
					f[i]=1;
					num++;
				}
		}
		printf("%d\n", 6-num);
		for(int i=0; i<6; i++)
			if(f[i] == 0)
				printf("%s\n", s2[i]);
	}
	return 0;
}