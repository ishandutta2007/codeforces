#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int k;
int main()
{
	scanf("%d",&k);
	printf("3 2\n");
	printf("%d %d \n",(1<<18)-1,(1<<17));
	printf("%d %d \n",k,(1<<18)-1);
	printf("%d %d \n",0,k);
	return 0;
}
/*
3 2
(1<<18)-1 (1<<17)
k (1<<18)-1
0 k
*/