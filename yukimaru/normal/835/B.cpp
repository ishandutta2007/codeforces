/*************************************************************************
    > File Name: 835_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 31 Jul 2017 10:42:39 PM CST
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
	int k;
	while(scanf("%d", &k) != EOF)
	{
		char s[100005]={0};
		scanf("%s", s);
		int l=strlen(s);
		int sum=0;
		for(int i=0; i<l; i++) sum=sum+s[i]-'0';
//		printf("%d\n", sum);
		if(sum >= k) printf("0\n");
		else
		{
			sort(s, s+l);
			int num=0, tmp=0;
			for(int i=0; i<l; i++)
			{
				tmp=tmp+9-(s[i]-'0');
//				printf("%d\n", tmp);
				num++;
				if(tmp >= (k-sum)) break;
			}
			printf("%d\n", num);
		}
	}
	return 0;
}