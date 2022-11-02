#include<bits/stdc++.h>
#define lld I64d
using namespace std;
typedef long long LL;

LL n,m,k;

LL count(LL n)
{
	LL t=1LL<<n;
	return (t*t-1)/3;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&k);
		m=min(n,31LL);
		
		bool ok=0;
		
		LL cnt=count(m);
//		cout<<"n:"<<n<<" "<<cnt<<endl;
		
		for (int s=1;s<=m&&!ok;++s)
		{
			LL L=(1LL<<(s+1))-2-s;
			if (L>k)	break;
			LL R=cnt-((1LL<<(s+1))-1)*count(m-s);
//			cout<<s<<" "<<L<<" "<<R<<endl;
			if (k<=R)	ok=1,printf("YES %lld\n",n-s);
		}
		
		if (!ok)
			puts("NO");
	}
	return 0;
}