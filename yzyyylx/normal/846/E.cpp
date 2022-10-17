#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

ll gen[N],gs[N],n;
double ch[N];

int main()
{
	ll i,a;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ch[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>a;
		ch[i]=a-ch[i];
	}
	for(i=2;i<=n;i++)
	{
		cin>>gen[i]>>gs[i];
	}

	for(i=n;i>1;i--)
	{
		if(ch[i]>0)
		{
			ch[gen[i]]+=gs[i]*ch[i];
		}
		else
		{
			ch[gen[i]]+=ch[i];
		}
		ch[i]=0;
	}
	if(ch[1]<=0)
		cout<<"YES";
	else
		cout<<"NO";
}