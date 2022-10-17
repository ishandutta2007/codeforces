#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int ans=0;
	set<int>s;
	while(n)
	{
		if(s.find(n%m)!=s.end())
		{
			puts("NO");
			return 0;
		}
		s.insert(n%m);
		n/=m;
	}
	puts("YES");
}