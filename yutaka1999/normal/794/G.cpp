#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define SIZE 1000005

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll rt[SIZE];
char A[SIZE],B[SIZE];

void init()
{
	inv[1]=1;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*2LL%MOD;
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int euler(int n)
{
	int ret=n;
	int now=n;
	for(int i=2;i*i<=now;i++)
	{
		if(now%i==0)
		{
			ret-=ret/i;
			while(now%i==0) now/=i;
		}
	}
	if(now>=2) ret-=ret/now;
	return ret;
}
int main()
{
	init();
	scanf("%s",&A);
	scanf("%s",&B);
	int n;
	scanf("%d",&n);
	ll ret=0;
	int cnt=0,nm=0;
	int sa=strlen(A),sb=strlen(B);
	for(int i=0;i<sa;i++) 
	{
		if(A[i]=='A') cnt++;
		else if(A[i]=='?') nm++;
	}
	for(int i=0;i<sb;i++) 
	{
		if(B[i]=='B') cnt++;
		else if(B[i]=='?') nm++;
	}
	for(int i=0;i<=nm;i++)
	{
		int da=cnt+i-sb,db=cnt+i-sa;
		if(da<0) da*=-1,db*=-1;
		if(da==0||db<=0) continue;
		int g=gcd(da,db);
		da/=g,db/=g;
		int to=min(n/da,n/db);
		ll ad=C(nm,i)*((rt[to+1]+MOD-2)%MOD)%MOD;
		//printf("%d %d : %lld\n",da,db,ad);
		ret+=ad;
		if(ret>=MOD) ret-=MOD;
	}
	if(sa==sb)
	{
		ll ct=0;
		int na=0,nb=0;
		int aa=0,ba=0;
		for(int i=0;i<sa;i++) 
		{
			if(A[i]=='A') aa++;
			else if(A[i]=='?') na++;
		}
		for(int i=0;i<sb;i++) 
		{
			if(B[i]=='A') ba++;
			else if(B[i]=='?') nb++;
		}
		for(int i=0;i<=sa;i++)
		{
			if(i>=aa&&i>=ba&&i<=aa+na&&i<=ba+nb)
			{
				//printf("%d %d %d %d : %d\n",na,nb,aa,ba,i);
				ct+=C(na,i-aa)*C(nb,i-ba)%MOD;
				if(ct>=MOD) ct-=MOD;
			}
		}
		//Sv
		int nt=0;
		for(int i=0;i<sa;i++)
		{
			if(A[i]=='?'&&B[i]=='?'&&nt!=-1) nt++;
			else if(A[i]!='?'&&B[i]!='?'&&A[i]!=B[i]) nt=-1;
		}
		if(nt>=0)
		{
			ct-=rt[nt];
			if(ct<0) ct+=MOD;
		}
		for(int i=1;i<=n;i++)
		{
			int way=2*euler(i);
			if(i==1) way--;
			ret+=ct*(ll) way%MOD*((rt[n/i+1]-2+MOD)%MOD)%MOD;
			if(ret>=MOD) ret-=MOD;
		}
		if(nt>=0)
		{
			ret+=rt[nt]*((rt[n+1]-2+MOD)%MOD)%MOD*((rt[n+1]-2+MOD)%MOD)%MOD;
			if(ret>=MOD) ret-=MOD;
		}
	}
	printf("%lld\n",ret);
	return 0;
}