#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#define SIZE 300005
#define MX 1000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll A[SIZE],B[SIZE];
ll X[SIZE];

bool check(ll a1,ll b1,ll a2,ll b2)//check if b1/a1<=b2/a2 
{
	//I want to use __int128!!!
	ll X=(b1/MX)*a2+(b1%MX)*a2/MX;
	ll Y=(b2/MX)*a1+(b2%MX)*a1/MX;
	if(X!=Y) return X<Y;
	return (b1%MX)*a2%MX<(b2%MX)*a1%MX;
}
int main()
{
	ll n;
	int q;
	scanf("%lld %d",&n,&q);
	int sz=0;
	X[sz]=n,A[sz]=0,B[sz]=0;
	sz++;
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%lld",&n);
			n+=X[sz-1];
			sz=0;
			X[sz]=n,A[sz]=0,B[sz]=0;
			sz++;
		}
		else if(t==2)
		{
			scanf("%lld",&n);
			while(sz>=2)
			{
				ll x1=(sz==2?0:X[sz-3]),y1=(A[sz-2]+A[sz-1])*x1+(B[sz-2]+B[sz-1]);
				ll x2=X[sz-2],y2=A[sz-1]*x2+B[sz-1];
				ll x3=X[sz-1],y3=0;
				//printf("[%lld %lld] [%lld %lld] [%lld %lld]\n",x1,y1,x2,y2,x3,y3);
				if(check(x3-x1,y1,x3-x2,y2))
				{
					sz--;
					X[sz-1]=X[sz];
					A[sz-1]+=A[sz];
					B[sz-1]+=B[sz];
				}
				else break;
			}
			X[sz]=X[sz-1]+n;
			A[sz]=B[sz]=0;
			sz++;
		}
		else
		{
			ll a,b;
			scanf("%lld %lld",&b,&a);
			A[sz-1]+=a,B[sz-1]+=b;
		}
		while(sz>=2)
		{
			ll x1=(sz==2?0:X[sz-3]),y1=(A[sz-2]+A[sz-1])*x1+(B[sz-2]+B[sz-1]);
			ll x2=X[sz-2],y2=A[sz-1]*x2+B[sz-1];
			if(y1<=y2)
			{
				sz--;
				X[sz-1]=X[sz];
				A[sz-1]+=A[sz];
				B[sz-1]+=B[sz];
			}
			else break;
		}
		//for(int j=0;j<sz;j++) printf("[%lld %lld %lld] ",X[j],A[j],B[j]);puts("");
		ll x=(sz==1?0:X[sz-2]),y=A[sz-1]*x+B[sz-1];
		printf("%lld %lld\n",x+1,y);
	}
	return 0;
}