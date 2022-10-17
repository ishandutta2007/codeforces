/*********************************************************************
    > File Name: 1095_B.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int a[100005]={0};
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		int ans=a[n]-a[1];
		ans=min(ans, a[n-1]-a[1]);
		ans=min(ans, a[n]-a[2]);
		printf("%d\n", ans);
	}
	return 0;
}