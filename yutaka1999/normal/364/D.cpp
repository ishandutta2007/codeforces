#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#define SIZE 1000005

using namespace std;
typedef long long int ll;

vector <ll> vx;
ll in[SIZE];
int cnt[SIZE],id[SIZE];
bool use[SIZE];
int n;

ll gcd(ll x,ll y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
ll solve(ll v)
{
	vector <ll> div;
	for(ll i=1;i*i<=v;i++)
	{
		if(v%i==0)
		{
			div.push_back(i);
			if(v/i!=i) div.push_back(v/i);
		}
	}
	memset(cnt,0,sizeof(cnt));
	sort(div.begin(),div.end());
	for(int i=0;i<n;i++)
	{
		ll val=gcd(in[i],v);
		int p=lower_bound(div.begin(),div.end(),val)-div.begin();
		cnt[p]++;
	}
	for(int i=((int)div.size())-1;i>=0;i--)
	{
		int sum=0;
		for(int j=i;j<div.size();j++)
		{
			if(div[j]%div[i]==0)
			{
				sum+=cnt[j];
			}
		}
		if(sum*2>=n) return div[i];
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%llld",&in[i]);
		vx.push_back(in[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++) id[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
	srand((unsigned) time(NULL));
	ll ret=0;
	int zc=0;
	if(vx.size()<=10)
	{
		for(int i=0;i<vx.size();i++) ret=max(ret,solve(vx[i]));
	}
	else
	{
		for(int T=0;T<10&&zc<=100000;T++)
		{
			int pos=rand()%n;
			if(use[id[pos]])
			{
				T--;
				zc++;
			}
			else
			{
				use[id[pos]]=true;
				ret=max(ret,solve(in[pos]));
			}
		}
	}
	printf("%llld\n",ret);
	return 0;
}