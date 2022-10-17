#include<iostream>
#include<cstdio>
#define ll long long
#define N 100100
#define M 1000000007
using namespace std;

ll n,k,num[N],jc[N],qz[N],ans;
char str[N];

inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}

inline ll zh(ll u,ll v)
{
	return jc[u]*po(jc[v],M-2)%M*po(jc[u-v],M-2)%M;
}

int main()
{
	ll i,j,bs,now;
	cin>>n>>k;
	scanf("%s",str+1);
	for(i=1;i<=n;i++) num[i]=str[i]-'0';
	jc[0]=1;for(i=1;i<=n;i++) jc[i]=jc[i-1]*i%M;
//	cout<<zh(2,1)<<endl;
	for(i=1;i<=n;i++) qz[i]=qz[i-1]+num[i];
	for(i=bs=1;i<=n-k;i++,bs=bs*10%M)
	{
		ans+=qz[n-i]*zh(n-i-1,k-1)%M*bs%M+num[n-i+1]*bs%M*zh(n-i,k)%M;
		ans%=M;
//		cout<<ans<<endl;
	}
	cout<<ans;
}//