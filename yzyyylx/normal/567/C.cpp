#include<iostream>
#include<cstdio>
#include<map>
#define ll long long
#define N 200100
using namespace std;

ll n,m,num[N],ans,k;
map<ll,ll>cn1,cn2;

int main()
{
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		if(i>=2) cn2[num[i]]++;
		cn1[num[i]]=0;
	}
	cn1[num[1]]=1;
	for(i=2;i<n;i++)
	{
		cn2[num[i]]--;
		if(num[i]%k==0)
		{
			ans+=cn1[num[i]/k]*cn2[num[i]*k];
		}
		cn1[num[i]]++;
	}
	cout<<ans;
}