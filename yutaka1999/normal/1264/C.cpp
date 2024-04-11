#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 200005
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll mpow(ll m,ll t)
{
	if(t==0) return 1;
	ll ret=mpow(m,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
ll inv(ll a)
{
	return mpow(a,MOD-2);
}
ll prob[SIZE];
ll pre[SIZE],sum[SIZE];

ll get_score(int i,int j)
{
	ll ret=sum[j]-(i==0?0:sum[i-1]);
	if(ret<0) ret+=MOD;
	return ret*inv(pre[j+1])%MOD;
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		prob[i]=(ll) p*inv(100)%MOD;
		if(prob[i]<0) prob[i]+=MOD;
	}
	pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]*prob[i-1]%MOD;
	sum[0]=1;
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+pre[i])%MOD;
	set <int> st;
	set <int>::iterator it;
	st.insert(0);
	st.insert(n);
	ll now=get_score(0,n-1);
	//printf("%lld\n",get_score(0,1));
	//printf("%lld\n",now);
	while(q--)
	{
		int u;
		scanf("%d",&u);u--;
		if(st.count(u))
		{
			st.erase(u);
			it=st.lower_bound(u);
			int to=*it;
			it--;
			int bef=*it;
			now-=get_score(u,to-1);
			if(now<0) now+=MOD;
			now-=get_score(bef,u-1);
			if(now<0) now+=MOD;
			now+=get_score(bef,to-1);
			if(now>=MOD) now-=MOD;
		}
		else
		{
			it=st.lower_bound(u);
			int to=*it;
			it--;
			int bef=*it;
			now+=get_score(u,to-1);
			if(now>=MOD) now-=MOD;
			now+=get_score(bef,u-1);
			if(now>=MOD) now-=MOD;
			now-=get_score(bef,to-1);
			if(now<0) now+=MOD;
			st.insert(u);
		}
		printf("%lld\n",now);
	}
	return 0;
}