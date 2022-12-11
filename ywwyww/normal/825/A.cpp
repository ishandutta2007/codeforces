#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxint=0x7fffffff;
const int minint=0x80000000;
const ll maxll=0x7fffffffffffffffll;
const ll minll=0x8000000000000000ll;
char s[100010];
int main()
{
	int ans=0;
	int i,n;
	scanf("%d%s",&n,s+1);
	int cnt=0;
	for(i=1;i<=n;i++)
		if(s[i]=='1')
			cnt++;
		else
		{
			ans=ans*10+cnt;
			cnt=0;
		}
	ans=ans*10+cnt;
	printf("%d\n",ans);
	return 0;
}