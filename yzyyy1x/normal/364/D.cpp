#pragma GCC optimize(3,"inline","Ofast")
#include<bits/stdc++.h>
#define iter map<ll,int>::iterator
#define ll long long
using namespace std;
const int N=1e6+100;

void read(ll &x)
{
	char c=getchar();x=0;bool f=0;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	if(f)x=-x;
}

int n;
ll a[N];

ll gcd(ll x,ll y)
{
	ll tp;
	while(y)
	{
		tp=x%y,
		x=y,y=tp;
	}
	return x;
}

int main()
{
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	int md=(n+1)/2,ps;ll ans=0,res;
	for(int test=1;test<=13;test++)
	{
		ps=1LL*rand()*rand()%n+1;
		map<ll,int>vis;
		for(int i=1;i<=n;i++)
			vis[gcd(a[ps],a[i])]++;
		iter ii,jj;
		ii=vis.end(),ii--;
		for(int tmp;;ii--)
		{
			tmp=(ii->second);
			res=(ii->first);
			if(res<=ans)break;
			jj=ii,jj++;
			for(;tmp<md&&jj!=vis.end();jj++)
				if((jj->first)%res==0)tmp+=(jj->second);
			if(tmp>=md)ans=max(ans,res);
			if(ii==vis.begin())break;
		}
	}
	printf("%lld\n",ans);
}