#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define INF 3000000000000000005LL

using namespace std;
typedef long long int ll;

ll A[SIZE],B[SIZE],C[SIZE],D[SIZE];
int n,T;
ll ansX,ansY,ansZ;

bool check(ll L)
{
	ll la,lb,lc,ld;
	ll ra,rb,rc,rd;
	la=lb=lc=ld=-INF;
	ra=rb=rc=rd=INF;
	for(int i=0;i<n;i++)
	{
		la=max(la,A[i]-L);
		ra=min(ra,A[i]+L);
		lb=max(lb,B[i]-L);
		rb=min(rb,B[i]+L);
		lc=max(lc,C[i]-L);
		rc=min(rc,C[i]+L);
		ld=max(ld,D[i]-L);
		rd=min(rd,D[i]+L);
	}
	//if(L==0) printf("[%lld %lld][%lld %lld] [%lld %lld] [%lld %lld]\n",la,ra,lb,rb,lc,rc,ld,rd);
	for(int t=0;t<2;t++)
	{
		ll a1=la,a2=ra;
		if(abs(a1)%2!=t) a1++;
		if(abs(a2)%2!=t) a2--;
		ll b1=lb,b2=rb;
		if(abs(b1)%2!=t) b1++;
		if(abs(b2)%2!=t) b2--;
		ll c1=lc,c2=rc;
		if(abs(c1)%2!=t) c1++;
		if(abs(c2)%2!=t) c2--;
		ll d1=ld,d2=rd;
		if(abs(d1)%2!=t) d1++;
		if(abs(d2)%2!=t) d2--;
		if(a1<=a2&&b1<=b2&&c1<=c2&&d1<=d2&&max(a1+b1,c1+d1)<=min(a2+b2,c2+d2))
		{
			ll v=max(a1+b1,c1+d1);
			ll a=a1,b=b1,c=c1,d=d1;
			if(a+b<v)
			{
				if(a2+b>v) a=v-b;
				else a=a2,b=v-a2;
			}
			if(c+d<v)
			{
				if(c2+d>v) c=v-d;
				else c=c2,d=v-c2;
			}
			ansX=(a+b)/2;
			ansY=(a-b)/2;
			ansZ=(c-d)/2;
			ll y=(ansY+ansZ)/2;
			ll z=(ansY-ansZ)/2;
			ansY=y;
			ansZ=z;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			ll x,y,z;
			scanf("%lld %lld %lld",&x,&y,&z);
			ll Y=y+z,Z=y-z;
			A[i]=x+Y,B[i]=x-Y;
			C[i]=x+Z,D[i]=x-Z;
		}/*
		for(int i=0;i<n;i++)
		{
			printf("%lld %lld %lld %lld\n",A[i],B[i],C[i],D[i]);
		}return 0;*/
		ll s=-1,e=INF;
		while(e-s>1)
		{
			ll m=(s+e)/2;
			if(check(m)) e=m;
			else s=m;
		}
		check(s);
		printf("%lld %lld %lld\n",ansX,ansY,ansZ);
	}
	return 0;
}