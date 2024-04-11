#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		sort(s+1,s+n+1);
		puts(s+1);
	}
}