#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(n&1)
			puts("NO");
		else if(s[1]==')'||s[n]=='(')
			puts("NO");
		else
			puts("YES");
	}
}