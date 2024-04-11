#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int T;

int tot;

char QS[15];

int SP;

int num=0;

int query(int x)
{
	assert(x<=1e14);
	num++;
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",QS);
	// QS[0]=x<=SP?'L':'F';
	if(QS[0]=='L')
	{
		tot+=x;
		return 1;
	}
	else
	{
		tot-=x;
		return 0;
	}
}

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		// scanf("%lld",&SP);
		// SP = 34359738368;
		num=0;
		tot=1;
		int l,r;
		for(int i=1;;i<<=1)
		{
			int ok=query(i);
			if(!ok)
			{
				l=i>>1,r=i;
				break;
			}
			if(i*2>=(int)1e14)
			{
				l=i,r=((int)1e14)+1;
				break;
			}
		}
		while(r-l>1)
		{
			int mid=l+(r-l)*0.3;
			if(mid==l)
				mid++;
			while(tot<mid)
				query(l);
			if(tot>=(l+r))
				mid=(l+r)>>1;
			if(query(mid))
				l=mid;
			else
				r=mid;
		}
		printf("! %lld\n",l);
		// printf("Query number = %lld\n",num);
		fflush(stdout);
	}
}