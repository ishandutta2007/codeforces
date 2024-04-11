#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
long long a;
long long ll,rr;
long long sum;
void init()
{
	scanf(LLFORMAT"d",&a);
}
int count(long long x)
{
	int s=0;
	while (x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
void solve()
{
	if (a==1)
	{
		printf("1 1\n");
		return;
	}
	long long p10[17];
	int di[17]={0};
	p10[0]=1;
	for (int i=1;i<=16;++i)
		p10[i]=p10[i-1]*10;
	for (int i=16;i>=0;--i)
	{
		for (int j=0;j<10;++j)
		{
			long long tmp=j*p10[i]+i*45*p10[i-1];
			for (int k=i+1;k<=16;++k) tmp+=di[k]*p10[i];
			if (sum+tmp<=a) sum+=tmp,rr+=p10[i],++di[i];
			else break;
		}
	}
	while (sum<a)
	{
		int t;
		t=count(rr);
		while (sum<=a) sum+=t,++rr,t=count(rr);
		t=count(ll);
		while (sum>a) sum-=t,++ll,t=count(ll);
	}
	if (ll==0) ll=1;
	--rr;
	printf(LLFORMAT"d "LLFORMAT"d\n",ll,rr);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}