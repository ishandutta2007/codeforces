/*********************************************************************
    > File Name: 1088_B.cpp
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
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		int a;
		set<int> num;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a);
			num.insert(a);
		}
		int ans[100005]={0}, cnt=0;
		for(int i : num)
		{
			cnt++;
			ans[cnt]=i;
		}
		for(int i=1; i<=cnt; i++)
		{
			printf("%d\n", ans[i]-ans[i-1]);
			k--;
			if(k == 0) break;
		}
		for(int i=1; i<=k; i++) printf("0\n");
	}
	return 0;
}