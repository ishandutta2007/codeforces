#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 2005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <ll,P> PP;

vector <PP> va,vb;
ll A[SIZE];
ll B[SIZE];
P ans[5];
int n,m;
int sz;

bool check(ll x)
{
	ll sa=0,sb=0;
	for(int i=0;i<n;i++) sa+=A[i];
	for(int i=0;i<m;i++) sb+=B[i];
	if(llabs(sa-sb)<=x)
	{
		sz=0;
		return true;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ll aa=sa-A[i]+B[j];
			ll bb=sb+A[i]-B[j];
			if(llabs(aa-bb)<=x)
			{
				sz=1;
				ans[0]=P(i,j);
				return true;
			}
		}
	}
	//|sa+(b-a)-sb-(a-b)|=|(sa-sb)-(2*a-2*b)|<=x
	//(sa-sb)-x<=2*a-2*b<=(sa-sb)+x
	int pos=0;
	for(int i=0;i<va.size();i++)
	{
		ll a=va[i].first;
		ll l=a-(sa-sb)-x;
		ll r=a-(sa-sb)+x;
		while(pos<vb.size()&&vb[pos].first<l) pos++;
		if(pos<vb.size()&&vb[pos].first<=r)
		{
			sz=2;
			P p=va[i].second,q=vb[pos].second;
			ans[0]=P(p.first,q.first);
			ans[1]=P(p.second,q.second);
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			va.push_back(PP(2LL*(A[i]+A[j]),P(i,j)));
		}
	}
	sort(va.begin(),va.end());
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%lld",&B[i]);
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			vb.push_back(PP(2LL*(B[i]+B[j]),P(i,j)));
		}
	}
	sort(vb.begin(),vb.end());
	ll l=-1,r=INF;
	while(l+1<r)
	{
		ll m=(l+r)/2;
		if(check(m)) r=m;
		else l=m;
	}
	check(r);
	printf("%lld\n",r);
	printf("%ld\n",sz);
	for(int i=0;i<sz;i++)
	{
		P p=ans[i];
		printf("%d %d\n",p.first+1,p.second+1);
	}
	return 0;
}