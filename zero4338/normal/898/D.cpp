#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int n,m,k;
int last;
int a[maxn],t[maxn<<4];
int now,ans;
int comp(int a,int b)
{
	return a<b;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t[a[i]]=1;
		last=max(last,a[i]);
	}
	for(int i=1;i<=last;i++)
	{
		if(t[i])now++;
		if(i>m&&t[i-m])now--;
		if(now>=k)now--,t[i]=0,ans++;
	}
	printf("%d\n",ans);
	return 0;
}//1