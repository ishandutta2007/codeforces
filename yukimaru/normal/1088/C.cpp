/*********************************************************************
    > File Name: 1088_C.cpp
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
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int a[2005]={0};
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		int add=0, mod=1e5+3;
		int tmp=0;
		int ans[2005]={0};
		for(int i=n; i>=1; i--)
		{
			tmp=(a[i]+add)%mod;
			if(tmp > i) ans[i]=mod+i-tmp;
			else ans[i]=i-tmp;
			add=(add+ans[i])%mod;
		}
		int cnt=0;
		for(int i=1; i<=n; i++)
			if(ans[i] != 0) cnt++;
		printf("%d\n", cnt+1);
		for(int i=1; i<=n; i++)
			if(ans[i] != 0) printf("1 %d %d\n", i, ans[i]);
		printf("2 %d %d\n", n, mod);
	}
	return 0;
}