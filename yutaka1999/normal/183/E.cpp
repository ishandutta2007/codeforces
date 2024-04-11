#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll A[SIZE];
ll zan[SIZE];
P st[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	ll ret=0;
	int AAA=0;
	for(int k=1;k*n<=m;k++)
	{
		ll sum=0;
		bool up=true;
		for(int i=0;i<n;i++)
		{
			zan[i]=A[i];
			zan[i]-=(ll) (i+1)*(ll) k+(ll) n*(ll) k*(ll) (k-1)/2LL;
			if(zan[i]<0)
			{
				up=false;
				break;
			}
			sum+=A[i]-zan[i];
		}
		if(!up) break;
		AAA++;
		ll bef=sum;
		int sz=0;
		for(int i=n-1;i>=0;i--)
		{
			if(sz>0&&st[sz-1].first<=zan[i]) continue;
			st[sz++]=P(zan[i],i);
		}
		//printf("%lld\n",sum);
		//for(int i=0;i<sz;i++) printf("[%lld %d] ",st[i].first,st[i].second);puts("");
		ll nm=st[sz-1].first;
		int all=m-k*n;
		if(nm/k>=all) sum+=(ll) min(nm/k,(ll) all)*(ll) n*(ll) k;
		else
		{
			sum+=(ll) nm*(ll) n;
			ll cn=(ll) all*(ll) k-nm;cn=min(cn,(ll) all);
			for(int i=sz-2;i>=0;i--)
			{
				ll cnt=st[i].first-st[i+1].first;
				int gt=n-st[i+1].second-1;
				//gt+(k-1)R Anm-=(k-1),all--
				//kR Anm-=k,all--
				//nm<all*k O <=> cn 
				ll g=min(cn,cnt);
				sum+=(ll) gt*(ll) g;
				cn-=g;
			}
		}
		assert(sum>=bef);
		ret=max(ret,sum);
	}
	//if(ret==0) assert(AAA==0);
	printf("%lld\n",ret);
	return 0;
}