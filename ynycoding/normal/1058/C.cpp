#include <cstdio>
#include <iostream>
using namespace std;
int n;
int s[101], tot;
bool check(int sum)
{
	int sm=0;
	for(int i=1; i<=n; ++i)
	{
		sm+=s[i];
		if(sm==sum) sm=0;
		if(sm>sum) return 0;
	}
	return sm==0;
}
int main()
{
	scanf("%d", &n);
	char tmp;
	for(int i=1; i<=n; ++i) cin>>tmp, s[i]=tmp-'0', tot+=s[i];
	if(tot==0) return puts("YES"), 0;
	for(int i=1; i<tot; ++i)
		if(tot%i==0) if(check(i)) return puts("YES"), 0;
	puts("NO");	
	return 0;
}