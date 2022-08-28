#include <bits/stdc++.h>
#define SIZE 100005
#define MX 1000000005
using namespace std;
typedef long long int ll;

int A[SIZE];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	map <ll,int> mp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		int a=A[i];
		int to=1;
		for(int j=2;j*j<=a;j++)
		{
			if(a%j==0)
			{
				int c=0;
				while(a%j==0)
				{
					a/=j;
					c++;
					if(c==k) c=0;
				}
				while(c)
				{
					to=to*(ll) j;
					c--;
				}
			}
		}
		to=to*a;
		A[i]=to;
		mp[to]++;
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int a=A[i];
		ll to=1;
		mp[a]--;
		for(int j=2;j*j<=a;j++)
		{
			if(a%j==0)
			{
				int c=k;
				while(a%j==0)
				{
					a/=j;
					c--;
					if(c<0) c+=k;
				}
				while(c)
				{
					to=to*(ll) j;
					if(to>MX) break;
					c--;
				}
				if(to>MX) break;
			}
		}
		if(to<MX)
		{
			if(a>1)
			{
				for(int j=0;j<k-1;j++)
				{
					to=to*(ll) a;
					if(to>MX) break;
				}
			}
			//printf("%d : %d\n",A[i],mp[to]);
			ret+=mp[to];
		}
		mp[A[i]]++;
	}
	printf("%lld\n",ret/2);
	return 0;
}