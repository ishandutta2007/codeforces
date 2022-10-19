#include<bits/stdc++.h>
#define N 100010
#define ll long long
#define P pair<ll,ll>
using namespace std;

pair<ll,ll>ri[N];
priority_queue<int,vector<P>,greater<P> >t;
ll n,bm[N],nd[N],note[N],coin[N],m;

int main()
{
	ll i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&nd[i]);
		note[i]=nd[i]/100;
		coin[i]=nd[i]%100;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&bm[i]);
	}
	
	for(i=1;i<=n;i++)
	{
		m-=coin[i];
//		cout<<m<<" ";
		if(coin[i]!=0)
		t.push(P(bm[i]*(100-coin[i]),i));
		if(m<0)
		{
			m+=100;
			ans+=t.top().first;
			note[t.top().second]++;
			coin[t.top().second]=0;
			t.pop();
		}
	}
	cout<<ans<<endl;
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld\n",note[i],coin[i]);
	}
}