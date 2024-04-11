#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 2000005
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

char str[1000005];
int lc[SIZE],rc[SIZE],qc[SIZE];
ll inv[SIZE],fac[SIZE],finv[SIZE];
ll two[SIZE];

void make()
{
	inv[1]=1;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	two[0]=1;
	for(int i=1;i<SIZE;i++) two[i]=two[i-1]*2LL%MOD;
}
ll C(int a,int b)
{
	if(a<b||b<0) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll solve(int l,int L,int r,int R)
{
	//printf("%d %d : %d %d\n",l,L,r,R);
	return (C(L+R,L+l-r)*(ll) (l)%MOD+C(L+R-1,L+l-r)*(ll) L%MOD)%MOD;
}
int main()
{
	make();
	scanf("%s",&str);
	string S=str;
	int n=S.size();
	for(int i=0;i<n;i++)
	{
		if(i>0)
		{
			lc[i]=lc[i-1],rc[i]=rc[i-1],qc[i]=qc[i-1];
		}
		if(S[i]=='(') lc[i]++;
		else if(S[i]==')') rc[i]++;
		else qc[i]++;
	}
	ll ret=0;
	for(int i=0;i+1<n;i++)
	{
		//if(S[i]==')'||S[i+1]=='(') continue;
		int l=0,r=0,vl=0,vr=0;
		l=lc[i],vl=qc[i];
		r=rc[n-1]-rc[i];
		vr=qc[n-1]-qc[i];
		ret+=solve(l,vl,r,vr);
		if(ret>=MOD) ret-=MOD;
	}
	printf("%lld\n",ret);
	return 0;
}