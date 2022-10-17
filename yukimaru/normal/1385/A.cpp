/*********************************************************************
    > File Name: 1385_A.cpp
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
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int a=max(x, max(y, z));
		if(a==x && a==y)
			printf("YES\n%d %d %d\n", x, z, z);
		else if(a==x && a==z)
			printf("YES\n%d %d %d\n", y, x, y);
		else if(a==y && a==z)
			printf("YES\n%d %d %d\n", x, x, z);
		else printf("NO\n");
	}
	return 0;
}