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
char a[1000010];
char b[1000010];
int n,m;
ll s1[110];
ll s2[110];
ll s3[110];
int check(int x)
{
	int i;
	ll sum=0;
	memset(s3,0,sizeof s3);
	for(i=1;i<=26;i++)
		if(s1[i]<x*s2[i])
			sum+=s3[i]=x*s2[i]-s1[i];
	if(sum<=s1[0])
		return 1;
	return 0;
}
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	int i;
	memset(s1,0,sizeof s1);
	memset(s2,0,sizeof s2);
	for(i=1;i<=n;i++)
		if(a[i]=='?')
			s1[0]++;
		else
			s1[a[i]-'a'+1]++;
	for(i=1;i<=m;i++)
		s2[b[i]-'a'+1]++;
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	check(l);
	int t=1;
	for(i=1;i<=n;i++)
		if(a[i]=='?')
		{
			while(t<26&&!s3[t])
				t++;
			a[i]=t+'a'-1;
			s3[t]--;
		}
	printf("%s\n",a+1);
	return 0;
}