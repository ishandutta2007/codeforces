/*************************************************************************
    > File Name: 1076_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 14 Nov 2018 10:24:56 PM CST
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
	int n;
	while(scanf("%d", &n) != EOF)
	{
		char s[200005]={0};
		scanf("%s", s);
		int pos=-1;
		for(int i=0; i<n-1; i++)
		{
			if(s[i] > s[i+1])
			{
				pos=i;
				break;
			}
		}
		if(pos == -1)
			pos=n-1;
		for(int i=0; i<n; i++)
			if(i != pos) printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}