#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 200005
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll A[SIZE];
void init()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll solve(vector <ll> vec)
{
	if(vec.size()==1) return vec[0]%MOD;
	int n=vec.size();
	if(vec.size()%2==0)
	{
		ll s=0,t=0;
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			{
				s+=vec[i]*C(n/2-1,i/2)%MOD;
				if(s>=MOD) s-=MOD;
			}
			else
			{
				t+=vec[i]*C(n/2-1,i/2)%MOD;
				if(t>=MOD) t-=MOD;
			}
		}
		if((n/2)%2==1) return (s+t)%MOD;
		return (s-t+MOD)%MOD;
	}
	else
	{
		vector <ll> nxt;
		for(int i=0;i+1<n;i++)
		{
			if(i%2==0) nxt.push_back((vec[i]+vec[i+1])%MOD);
			else nxt.push_back((vec[i]-vec[i+1]+MOD)%MOD);
		}
		return solve(nxt);
	}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	ll ret=0;
	vector <ll> vec;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		vec.push_back(A[i]);
	}
	printf("%lld\n",solve(vec));
	return 0;
}