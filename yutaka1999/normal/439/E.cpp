#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];

void make()
{
	inv[0]=inv[1]=1;
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
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
int main()
{
	make();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int n,f;
		scanf("%d %d",&n,&f);
		int N=n;
		vector <int> prm;
		for(int j=2;j*j<=n;j++)
		{
			if(n%j==0)
			{
				prm.push_back(j);
				while(n%j==0) n/=j;
			}
		}
		if(n!=1) prm.push_back(n);
		ll ret=0;
		for(int S=0;S<1<<(prm.size());S++)
		{
			int pd=1,cnt=0;
			for(int j=0;j<prm.size();j++)
			{
				if(S>>j&1)
				{
					pd*=prm[j];
					cnt++;
				}
			}
			ll val=C(N/pd-1,f-1);
			if(cnt%2==1) ret+=MOD-val;
			else ret+=val;
			if(ret>=MOD) ret-=MOD;
		}
		printf("%llld\n",ret);
	}
	return 0;
}