#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector < vector <ll> > dp;
map <ll,int> mp;
vector <ll> vec;

ll solve(ll L,ll R,ll zan,int l,int r)
{
	ll m=(L+R)/2;
	if(zan==1)
	{
		if(l!=-1&&vec[l]==R-L+1) return m;
		if(r!=-1&&vec[r]==R-L+1) return m;
	}
	int id=mp[m-L];
	ll nm=0;
	if(l!=-1) nm+=dp[id][l];
	if(r!=-1) nm+=dp[id][r];
	//printf("%lld %d : %lld\n",m-L,id,nm);
	//if(L+1<=R) printf("%lld %d : %lld\n",m-L,id,nm);
	if(nm>=zan) return solve(L,m-1,zan,l,r);
	return solve(m+1,R,zan-nm,l,r);
}
int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	if(k==1)
	{
		printf("%d\n",1);
		return 0;
	}
	if(k==2)
	{
		printf("%lld\n",n);
		return 0;
	}
	//[1,n-2]
	set <ll> st;
	set <ll>::iterator it;
	st.insert(n-2);
	ll last=n;
	while(1)
	{
		it=st.lower_bound(last);
		if(it==st.begin()) break;
		it--;
		ll v=*it;
		if(v%2==0)
		{
			st.insert(v/2);
			if(v/2>1) st.insert(v/2-1);
		}
		else
		{
			if(v/2>0) st.insert(v/2);
		}
		last=v;
	}
	for(it=st.begin();it!=st.end();it++)
	{
		ll v=*it;
		mp[v]=vec.size();
		vec.push_back(v);
	}
	//for(int i=0;i<vec.size();i++) printf("%lld ",vec[i]);puts("");
	for(int i=0;i<vec.size();i++)
	{
		vector <ll> now;
		now.resize(vec.size());
		now[i]=1;
		ll v=vec[i];
		ll l=-1,r=-1;
		if(v%2==0)
		{
			r=v/2;
			if(r>1) l=r-1;
		}
		else
		{
			if(v/2>0)
			{
				l=r=v/2;
			}
		}
		int L=-1,R=-1;
		if(l!=-1) L=mp[l];
		if(r!=-1) R=mp[r];
		for(int j=0;j<vec.size();j++)
		{
			if(L!=-1) now[j]+=dp[L][j];
			if(R!=-1) now[j]+=dp[R][j];
		}
		dp.push_back(now);
	}
	int goal=vec.size();
	ll zan=k-2;
	for(int j=vec.size()-1;j>=0;j--)
	{
		ll gt=dp[vec.size()-1][j];
		if(zan<=gt)
		{
			goal=j;
			break;
		}
		zan-=gt;
	}
	ll dt=(vec[goal]-1LL)/2LL;
	int l=-1,r=-1;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]==2LL*dt+2LL) l=i;
		else if(vec[i]==2LL*dt+1LL) r=i;
	}
	zan=k-2;
	for(int j=vec.size()-1;j>=0;j--)
	{
		if(vec[j]>=2LL*dt+3LL) zan-=dp[vec.size()-1][j];
	}
	//for(int j=0;j<vec.size();j++) printf("%lld ",vec[j]);puts("");
	//for(int j=0;j<vec.size();j++) printf("%lld ",dp[vec.size()-1][j]);puts("");
	//printf("%lld : %d %d\n",zan,l,r);
	//printf("%lld %lld\n",vec[l],vec[r]);
	ll L=2,R=n-1;
	printf("%lld\n",solve(L,R,zan,l,r));
	return 0;
}