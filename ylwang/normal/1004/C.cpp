#include<bits/stdc++.h>
using namespace std;
#define int long long
struct number
{
	int num,ind;
	bool operator<(const number& ano)const
	{
		return num==ano.num?ind<ano.ind:num<ano.num;
	}
}a[100001];
int l[100001],r[100001],cnt=1,s[100001];
signed main()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].num);
		a[i].ind=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		if(a[i].num!=a[i+1].num)
		{
			r[cnt++]+=a[i].ind;
			l[a[i+1].ind]++;
		}
	l[a[1].ind]++;
	r[cnt]=a[n].ind;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+l[i];
	int ans=0;
	for(int i=1;i<=cnt;i++)
		ans+=s[r[i]-1];
	printf("%lld\n",ans);
	return 0;
}