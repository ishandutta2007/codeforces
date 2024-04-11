/*********************************************************************
    > File Name: 1088_A.cpp
    > Author: yuki
 *********************************************************************/

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

int main()
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		bool flag=0;
		for(int i=1; i<=x; i++)
		{
			for(int j=i; j<=x; j+=i)
			{
				if(j/i<x && j*i>x)
				{
					printf("%d %d\n", j, i);
					flag=1;
				}
				if(flag == 1) break;
			}
			if(flag == 1) break;
		}
		if(flag == 0) printf("-1\n");
	}
	return 0;
}