#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1000005
#define INF 1000000000

using namespace std;
typedef long long int ll;

int A[SIZE];
int left[SIZE],right[SIZE];
ll L[SIZE],R[SIZE];
int n,a,b;

ll go(int p)
{
	for(int i=0;i<=n;i++)
	{
		if(i==0) left[i]=right[i]=0;
		else
		{
			if(A[i-1]%p==0) left[i]=left[i-1];
			else if((A[i-1]+1)%p==0) left[i]=left[i-1]+1;
			else if((A[i-1]-1)%p==0) left[i]=left[i-1]+1;
			else left[i]=INF;
			if(A[n-i]%p==0) right[i]=right[i-1];
			else if((A[n-i]+1)%p==0) right[i]=right[i-1]+1;
			else if((A[n-i]-1)%p==0) right[i]=right[i-1]+1;
			else right[i]=INF;
		}
		L[i]=(ll) left[i]*(ll) b-(ll) a*(ll) i;
		R[i]=(ll) right[i]*(ll) b-(ll) a*(ll) i;
	}
	for(int i=1;i<=n;i++)
	{
		L[i]=min(L[i],L[i-1]);
		R[i]=min(R[i],R[i-1]);
	}
	ll ret=(ll) INF*(ll) INF;
	for(int i=0;i<=n;i++) ret=min(ret,L[i]+R[n-i]+(ll) n*(ll) a);
	return ret;
}
ll solve()//A0c
{
	ll ret=(ll) n*(ll) a;
	int now=A[0];
	for(int i=2;i*i<=now;i++)
	{
		if(now%i==0)
		{
			ret=min(ret,go(i));
			while(now%i==0) now/=i;
		}
	}
	if(now!=1) ret=min(ret,go(now));
	return ret;
}
ll get()
{
	ll ret=solve();
	A[0]++;
	ret=min(ret,solve()+b);
	A[0]-=2;
	ret=min(ret,solve()+b);
	A[0]++;
	return ret;
}
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	ll ret=get();
	for(int l=0,r=n-1;l<r;l++,r--) swap(A[l],A[r]);
	ret=min(ret,get());
	printf("%lld\n",ret);
	return 0;
}