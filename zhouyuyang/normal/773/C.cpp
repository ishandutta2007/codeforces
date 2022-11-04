#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int n,s[N],p[N];ll a[N];
bool check(int x)
{
	if (x>s[1]) return 0;
	int now=0,re=x;
	for (int i=1;i<=60;i++)
	{
		now+=p[i];
		if (s[i]>=re) now+=s[i]-re;
		else
		{
			int tmp=re-s[i];
			if (now<tmp) now=0;
			else now-=tmp;re-=tmp;
		}
	}
	return now<=re;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ll now=1;int x=1;
		while (a[i]>now) now*=2,x++;
		if (a[i]==now) s[x]++;
		else p[x]++;
	}
	//cout<<s[1]<<' '<<s[2]<<endl;
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		if (check(i))
			printf("%d ",i),flag=1;
	}
	if (!flag) puts("-1");
}