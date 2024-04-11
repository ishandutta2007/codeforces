#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n;
	scanf("%lld",&n);
	vector <int> vx;
	int now=2;
	while(n)
	{
		vx.push_back(n%now);
		n/=now;
		now++;
	}
	now--;
	sort(vx.begin(),vx.end());
	//for(int i=0;i<vx.size();i++) printf("%d ",vx[i]);puts("");
	int pos=0;
	ll ret=1;
	for(int i=2;i<=now;i++)
	{
		while(pos<vx.size()&&vx[pos]<i) pos++;
		ret*=(ll) (pos-i+2);
	}
	for(int i=0;i<vx.size();)
	{
		int f=i;
		for(;i<vx.size()&&vx[i]==vx[f];i++);
		for(int j=1;j<=i-f;j++) ret/=j;
	}
	if(vx[0]==0)
	{
		ll ret2=1;
		int pos=0;
		for(int i=2;i<now;i++)
		{
			while(pos<vx.size()&&vx[pos]<i) pos++;
			ret2*=(ll) (pos-i+1);
		}
		for(int i=0;i<vx.size();)
		{
			int f=i;
			for(;i<vx.size()&&vx[i]==vx[f];i++);
			int c=i-f;
			if(f==0) c--;
			for(int j=1;j<=c;j++) ret2/=j;
		}
		ret-=ret2;
	}
	printf("%lld\n",ret-1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}