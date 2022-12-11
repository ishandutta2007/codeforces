#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define SZ 666666
int n,a[SZ];
int M=0,fst[SZ],vb[SZ],nxt[SZ];
void ad_de(int a,int b)
{
	++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;
}
int ds[SZ],qs[SZ];
void adde(int a,int b) {++ds[a]; ++ds[b]; ad_de(a,b); ad_de(b,a);}
void fc()
{
	int h=0,t=0;
	for(int i=1;i<=n;i++)
	{
		if(ds[i]==1)
		{
			ds[i]=0; qs[t++]=i;
		}
	}
	while(h!=t)
	{
		int x=qs[h++];
		for(int e=fst[x];e;e=nxt[e])
		{
			int b=vb[e]; --ds[b];
			if(ds[b]==1)
			{
				ds[b]=0; qs[t++]=b;
			}
		}
	}
}
int ff[SZ];
int gf(int x)
{
	return ff[x]?ff[x]=gf(ff[x]):x;
}
void uni(int a,int b)
{
	int ga=gf(a),gb=gf(b);
	if(ga^gb) ff[ga]=gb;
}
int cyc[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		adde(i,a[i]);
		uni(i,a[i]);
	}
	fc();
	int ff=n;
	for(int i=1;i<=n;i++)
	{
		if(ds[i]==2) --ff, cyc[gf(i)]++;
	}
	ll ans=1,MOD=1000000007;
	for(int i=1;i<=ff;i++) ans=ans*2%MOD;
	for(int i=1;i<=n;i++)
	{
		if(!cyc[i]) continue;
		ll tmp=1;
		for(int j=1;j<=cyc[i];j++) tmp=tmp*2%MOD;
		tmp=(tmp-2)%MOD;
		ans=ans*tmp%MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}