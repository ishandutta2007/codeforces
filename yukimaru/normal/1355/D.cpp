/*********************************************************************
    > File Name: 1355_D.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n, s;
	while(scanf("%d%d", &n, &s) != EOF)
	{
		if(s-2*n >= 0)
		{
			printf("YES\n");
			for(int i=1; i<=n-1; i++) printf("1 ");
			printf("%d\n", s-n+1);
			printf("%d\n", n);
		}
		else printf("NO\n");
	}
	return 0;
}