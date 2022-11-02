#include<bits/stdc++.h>
using namespace std;
const int N=30,D=18;
int n,k,a[N]={};
long long S,d[N]={1},ans=0;
map<long long,int> f[N];
void init()
{
	cin>>n>>k>>S;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=D;++i)
		d[i]=d[i-1]*i;
}
void tryy(int t,long long s,int c)
{
	if(t>n)
	{
		++f[c][s];
		return;
	}
	if(a[t]<=D)
		tryy(t+1,s+d[a[t]],c+1);
	tryy(t+1,s+a[t],c);
	tryy(t+1,s,c);
}
void calc(int t,long long s,int c)
{
	if(t>n/2)
	{
		for(int i=0;i<=k-c;++i)
			ans+=f[i][S-s];
		return;
	}
	if(a[t]<=D)
		calc(t+1,s+d[a[t]],c+1);
	calc(t+1,s+a[t],c);
	calc(t+1,s,c);
}
void work()
{
	tryy(n/2+1,0,0);
	calc(1,0,0);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}