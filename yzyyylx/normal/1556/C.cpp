#include<bits/stdc++.h>
#define ll long long
#define Ul unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
using namespace std;

ll T,n,aa,mn,num[N],a[N];
Ul ans;

int main()
{
	ll i,j,p,q,t,res;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	for(i=1;i<=n;i+=2)
	{
		t=num[i],mn=INF;
		for(j=i+1;j<=n;j+=2)
		{
			ans+=max(0ll,min(mn+1,min(t,num[i]))-max(0ll,(t-num[j])));
//			cout<<" "<<i<<" "<<j<<" "<<max(0ll,min(mn,min(t,num[i]))-max(0ll,(t-num[j])))<<endl;
			t-=num[j];
			mn=min(mn,t);
			t+=num[j+1];
		}
	}
	cout<<ans;
}