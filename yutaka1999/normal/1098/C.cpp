#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll get(int d,int n)
{
	ll sum=0;
	ll pos=1,zan=n;
	for(int i=1;zan>0;i++)
	{
		ll cnt=min(zan,pos);
		sum+=(ll) i*cnt;
		zan-=cnt;
		pos*=(ll) d;
	}
	return sum;
}
ll cnt[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
	ll S;
	scanf("%lld",&S);
	if((ll) n*(ll) (n+1)/2LL==S)
	{
		puts("Yes");
		for(int i=2;i<=n;i++) printf("%d ",i-1);
		puts("");
	}
	else if((ll) n*(ll) (n+1)/2LL<S)
	{
		puts("No");
	}
	else
	{
		int l=1,r=n+1;
		while(r-l>1)
		{
			int d=(l+r)/2;
			if(get(d,n)>S) l=d;
			else r=d;
		}
		if(r==1||r==n+1)
		{
			puts("No");
		}
		else
		{
			int sz=1;
			ll pos=1,zan=n,sum=0;
			for(int i=1;zan>0;i++)
			{
				ll c=min(zan,pos);
				sum+=(ll) i*c;
				zan-=c;
				pos*=(ll) r;
				cnt[sz++]=c;
			}
			int p=0;
			for(int i=1;i<sz;i++) if(cnt[i]>1) p=i;
			while(sum<S)
			{
				while(cnt[p]==1) p--;
				if(S-sum>=sz-p)
				{
					cnt[p]--;
					cnt[sz]++;
					sum+=sz-p;
					sz++;
				}
				else
				{
					int to=p+(S-sum);
					cnt[p]--;
					cnt[to]++;
					break;
				}
			}
			puts("Yes");
			int now=0;
			for(int i=2;i<sz;i++)
			{
				for(int j=0;j<cnt[i];j++)
				{
					printf("%d ",now+j/r+1);
				}
				now+=cnt[i-1];
			}
			puts("");
		}
	}
	return 0;
}