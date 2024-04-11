#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define INF 1000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int X[SIZE],Y[SIZE];
vector <P> vx,vy;
int n;

ll solve()
{
	vx.clear();
	vy.clear();
	for(int i=0;i<n;i++)
	{
		vx.push_back(P(X[i],i));
		vy.push_back(P(Y[i],i));
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	if(n%2==0)
	{
		ll ret=0;
		int k=n/2;
		for(int i=0;i<k-1;i++) ret+=vx[i+k+1].first-vx[i].first;
		for(int i=0;i<k;i++) ret+=vy[i+k].first-vy[i].first;
		ll nxt=0;
		for(int i=0;i<k;i++) nxt+=vx[i+k].first-vx[i].first;
		for(int i=0;i<k-1;i++) nxt+=vy[i+k+1].first-vy[i].first;
		return 2LL*max(ret,nxt);
	}
	else
	{
		int k=n/2;
		ll ret=0;
		for(int i=0;i<k;i++) ret+=vx[i+k+1].first-vx[i].first;
		for(int i=0;i<k;i++) ret+=vy[i+k+1].first-vy[i].first;
		if(vx[k].second==vy[k].second)
		{
			ret-=min(min(vx[k+1].first-vx[k].first,vx[k].first-vx[k-1].first),min(vy[k+1].first-vy[k].first,vy[k].first-vy[k-1].first));
		}
		return 2LL*ret;
	}
}
ll solve2()
{
	vector <ll> A,B;
	for(int i=0;i<n;i++)
	{
		A.push_back(X[i]+Y[i]);
		B.push_back(X[i]-Y[i]);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	ll ret=0,nxt=0;
	for(int i=0;i<n/2;i++) ret+=A[n-i-1]-A[i];
	for(int i=0;i<n/2;i++) nxt+=B[n-i-1]-B[i];
	return 2LL*max(ret,nxt);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d %d",&X[i],&Y[i]);
	printf("%lld\n",max(solve(),solve2()));
	return 0;
}