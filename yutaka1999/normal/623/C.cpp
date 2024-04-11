#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 100005
#define INF 100000000000000000LL

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

vector <P> A;
vector <P> B,C;
ll L1[SIZE],R1[SIZE];
ll L2[SIZE],R2[SIZE];
int n;

bool check(ll x)
{
	int to=0;
	for(int i=0;i<n;i++)
	{
		L1[i]=INF;
		R1[i]=-INF;
		if(i>0)
		{
			L1[i]=min(L1[i],min(L1[i-1],(ll) A[i-1].second));
			R1[i]=max(R1[i],max(R1[i-1],(ll) A[i-1].second));
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		L2[i]=INF;
		R2[i]=-INF;
		if(i+1<n)
		{
			L2[i]=min(L2[i],min(L2[i+1],(ll) A[i+1].second));
			R2[i]=max(R2[i],max(R2[i+1],(ll) A[i+1].second));
		}
	}
	for(int i=0;i<n;i++)
	{
  		while(to<n&&(ll) (A[i].first-A[to].first)*(ll) (A[i].first-A[to].first)<=x) to++;
		if(i==0&&to==n) return true;
		ll l=min(L1[i],L2[to-1]);
		ll r=max(R1[i],R2[to-1]);
		ll mx=max(abs(A[i].first),abs(A[to-1].first));
		ll D=max(abs(l),abs(r));
		if((r-l)*(r-l)<=x&&mx*mx+D*D<=x) return true;
	}
	int l=B.size(),r=C.size();
	l--;r--;
	ll low=INF,up=-INF;
	for(int i=0;i<n;i++)
	{
		if(l<0||(r>=0&&C[r].first>=B[l].first))
		{
			ll x=C[r--].second;
			low=min(low,x);
			up=max(up,x);
		}
		else
		{
			ll x=B[l--].second;
			low=min(low,x);
			up=max(up,x);
		}
		ll b=0,c=0;
		if(l>=0) b=B[l].first;
		if(r>=0) c=-C[r].first;
		if((b-c)*(b-c)<=x&&(up-low)*(up-low)<=x&&(i==n-1||max(low*low,up*up)+max(b*b,c*c)<=x)) return true;
	}
	return false;
}
ll solve()
{
	ll l=-1,r=INF;
	while(l+1<r)
	{
		ll m=(l+r)/2;
		if(check(m)) r=m;
		else l=m;
		//printf("%lld %lld\n",l,r);
	}
	return r;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		A.push_back(P(x,y));
		if(x>0) B.push_back(P(x,y));
		else C.push_back(P(-x,y));
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	ll ret=solve();
	for(int i=0;i<n;i++) A[i].first=-A[i].first;
	sort(A.begin(),A.end());
	swap(B,C);
	ret=min(ret,solve());
	/*
	B.clear(),C.clear();
	for(int i=0;i<n;i++)
	{
		swap(A[i].first,A[i].second);
		if(A[i].first>0) B.push_back(A[i]);
		else C.push_back(P(-A[i].first,A[i].second));
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	ret=min(ret,solve());
	swap(B,C);
	ret=min(ret,solve());
	*/
	printf("%lld\n",ret);
	return 0;
}