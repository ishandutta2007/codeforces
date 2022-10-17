/*********************************************************************
    > File Name: 1095_A.cpp
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
		char s[60]={0};
		scanf("%s", s);
		int step=1;
		for(int i=0; i<n;)
		{
			printf("%c", s[i]);
			i+=step;
			step+=1;
		}
		printf("\n");
	}
	return 0;
}