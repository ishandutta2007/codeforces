/*********************************************************************
    > File Name: 1399_A.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[55]={0};
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		bool f=1;
		for(int i=1; i<n; i++)
			if(fabs(a[i]-a[i+1]) > 1)
			{
				f=0;
				break;
			}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}