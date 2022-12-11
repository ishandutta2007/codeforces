#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
int length(int x)
{
	int s=0;
	while(x)
	{
		s++;
		x/=10;
	}
	return s;
}
char s[100010];
char s2[100010];
int f[100010];
int fail[100010];
int n;
void solve(int x)
{
	memcpy(s2+1,s+x,sizeof s+x);
	int m=n-x+1;
	int i;
	fail[0]=fail[1]=0;
	for(i=2;i<=m;i++)
	{
		fail[i]=fail[i-1];
		while(fail[i]&&s2[fail[i]+1]!=s2[i])
			fail[i]=fail[fail[i]];
		if(s2[fail[i]+1]==s2[i])
			fail[i]++;
	}
	for(i=1;i<=m;i++)
	{
		if(i%(i-fail[i])==0)
			f[x+i-1]=min(f[x+i-1],f[x-1]+i-fail[i]+length(i/(i-fail[i])));
		else
			f[x+i-1]=min(f[x+i-1],f[x-1]+i+1);
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int i;
	memset(f,0x7f,sizeof f);
	f[0]=0;
	for(i=1;i<=n;i++)
		solve(i);
	printf("%d\n",f[n]);
	return 0;
}