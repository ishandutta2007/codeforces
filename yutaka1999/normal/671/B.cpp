#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005

using namespace std;
typedef long long int ll;

ll A[SIZE];
int n;

ll get(ll K)
{
	ll zan=K;
	for(int i=0;i<n;i++)
	{
		if(i+1<n&&(A[i+1]-A[i])*(ll) (i+1)<=zan) zan-=(A[i+1]-A[i])*(ll) (i+1);
		else
		{
			return A[i]+zan/(i+1);
		}
	}
}
int main()
{
	ll K;
	scanf("%d %lld",&n,&K);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	sort(A,A+n);
	ll gt=get(K);
	//printf("%lld\n",gt);
	for(int l=0,r=n-1;l<r;l++,r--) swap(A[l],A[r]);
	for(int i=0;i<n;i++) A[i]=-A[i];
	ll gt2=-get(K);
	//printf("%lld\n",gt2);
	ll sum=0;
	for(int i=0;i<n;i++) sum+=A[i];
	printf("%lld\n",max(gt2-gt,sum%n==0?0LL:1LL));
	return 0;
}