/*********************************************************************
    > File Name: 1367_A.cpp
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
		char s[1005]={0};
		scanf("%s", s);
		int l=strlen(s);
		printf("%c", s[0]);
		for(int i=1; i<l-1; i+=2) printf("%c", s[i]);
		printf("%c\n", s[l-1]);
	}
	return 0;
}