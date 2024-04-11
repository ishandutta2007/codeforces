#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

P pos[SIZE];
ll sum[SIZE],ans[SIZE];
int n,A,f,m;
ll M;

bool check(int x,int k)//min>=xA0`k-1 
{
	int p=lower_bound(pos,pos+k,P(x+1,-1))-pos-1;
	if(p==-1) return true;
	//0`px
	ll gt=(ll) (p+1)*(ll) x-sum[p];
	//printf("%d %lld\n",p,gt);
	return gt<=M;
}
int main()
{
	scanf("%d %d %d %d",&n,&A,&f,&m);
	scanf("%lld",&M);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		pos[i]=P(a,i);
	}
	sort(pos,pos+n);
	for(int i=0;i<n;i++)
	{
		sum[i]=pos[i].first;
		if(i>0) sum[i]+=sum[i-1];
	}
	ll mx=-1;
	int memo=-1,N;
	for(int i=0;i<n;i++)//perfect 
	{
		int s=0,t=A;
		while(t-s>1)
		{
			int m=(s+t)/2;
			if(check(m,n-i)) s=m;
			else t=m;
			//printf("%d : %d %d\n",i,s,t);
		}
		ll vl=(ll) i*(ll) f+(ll) s*(ll) m;
		if(mx<vl)
		{
			mx=vl;
			memo=i;
			N=s;
		}
		M-=A-pos[n-i-1].first;
		if(M<0) break;
	}
	if(M>=0)
	{
		ll vl=(ll) n*(ll) f+(ll) A*(ll) m;
		if(vl>mx)
		{
			printf("%lld\n",vl);
			for(int i=0;i<n;i++)
			{
				if(i!=0) printf(" ");
				printf("%d",A);
			}puts("");
			return 0;
		}
	}
	for(int i=0;i<n;i++) ans[pos[i].second]=pos[i].first;
	for(int i=0;i<memo;i++) ans[pos[n-i-1].second]=A;
	for(int i=0;i<n-memo;i++) if(pos[i].first<=N) ans[pos[i].second]=N;
	printf("%lld\n",mx);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%lld",ans[i]);
	}puts("");
	return 0;
}