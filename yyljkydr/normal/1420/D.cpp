#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7,P=998244353;

ll fac[N],inv[N];

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

ll C(int n,int m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

int n,k;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>v;

int main()
{
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%P;
	inv[n]=qpow(fac[n],P-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v.push_back(mp(l,1));
		v.push_back(mp(r+1,-1));
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(auto [x,y]:v)
	{
		now+=y;
		if(y==1)
			(ans+=C(now-1,k-1))%=P;
	}
	printf("%d\n",ans);
}