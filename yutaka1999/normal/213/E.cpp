#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define B1 89793
#define M1 1000000007
#define B2 981793
#define M2 1000000009

using namespace std;
typedef long long int ll;

ll C,MOD;
struct BIT
{
	ll bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,ll x)
	{
		while(k<SIZE)
		{
			bit[k]+=x;
			if(bit[k]>=MOD) bit[k]-=MOD;
			k+=k&-k;
		}
	}
	ll get(int k)
	{
		ll ret=0;
		while(k>0)
		{
			ret+=bit[k];
			if(ret>=MOD) ret-=MOD;
			k-=k&-k;
		}
		return ret;
	}
	ll get(int s,int t)
	{
		return (get(t)-get(s-1)+MOD)%MOD;
	}
};
BIT b1,b2;
int A[SIZE],B[SIZE];
ll rt[SIZE];
bool use[SIZE];
int n,m;

void solve(int t)
{
	if(t==0) C=B1,MOD=M1;
	else C=B2,MOD=M2;
	ll ha=0;
	for(int i=n-1;i>=0;i--)
	{
		ha*=C;
		ha+=(ll) A[i];
		ha%=MOD;
	}
	rt[0]=1;
	for(int i=1;i<=m;i++) rt[i]=rt[i-1]*C%MOD;
	ll hb=0;
	b1.init();
	b2.init();
	for(int i=m-1;i>=0;i--)
	{
		hb+=b1.get(B[i]+1,m+1);
		hb+=b2.get(B[i]+1)*rt[i]%MOD;
		hb%=MOD;
		b1.add(B[i]+1,rt[i]);
		b2.add(B[i]+1,1);
		//if(t==0) printf("%lld %lld\n",ha*rt[i]%MOD,hb);
		if(i+n<=m)
		{
			if(ha*rt[i]%MOD!=hb) use[i]=false;
			b1.add(B[i+n-1]+1,(MOD-rt[i+n-1])%MOD);
			b2.add(B[i+n-1]+1,MOD-1);
			hb-=b1.get(B[i+n-1]+1,m+1);
			if(hb<0) hb+=MOD;
			hb-=b2.get(B[i+n-1]+1)*rt[i+n-1]%MOD;
			if(hb<0) hb+=MOD;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		A[p]=i;
	}
	for(int i=0;i<m;i++)
	{
		int p;
		scanf("%d",&p);p--;
		B[p]=i;
	}
	//for(int i=0;i<n;i++) printf("%d ",A[i]);puts("");
	//for(int i=0;i<m;i++) printf("%d ",B[i]);puts("");
	for(int i=0;i+n<=m;i++) use[i]=true;
	solve(0);
	solve(1);
	int ret=0;
	for(int i=0;i+n<=m;i++) ret+=use[i];
	printf("%d\n",ret);
	return 0;
}