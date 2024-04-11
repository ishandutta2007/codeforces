#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MX 205

using namespace std;
typedef long long int ll;

int L[SIZE],R[SIZE];
vector <int> vt;
int dp[SIZE][MX];
int A[SIZE];
int all,n,p,t;

int solve1()//O(L/p*log)
{
	for(int i=n-1;i>=0;i--)
	{
		int last=(R[i]-L[i])/p*p+L[i];
		int q=upper_bound(vt.begin(),vt.end(),-(last+t))-vt.begin();
		if((R[i]-L[i])/p+q>vt.size())
		{
			while((R[i]-L[i])/p+q>vt.size())
			{
				int l=L[i],r=R[i];
				while(r-l>1)
				{
					int m=(l+r)/2;
					int lp=(R[i]-m)/p*p+m;
					int qp=upper_bound(vt.begin(),vt.end(),-(lp+t))-vt.begin();
					if((R[i]-m)/p+qp>=vt.size()+1) l=m;
					else r=m;
				}
				vt.push_back(-l);
			}
		}
	}
	//for(int i=0;i<vt.size();i++) printf("%d ",-vt[i]);puts("");
	return vt.size();
}
int solve2()//O(p*n)
{
	int back=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<p;j++)
		{
			if(i<n-1)
			{
				int nxt=lower_bound(R,R+n,R[i]-j+t)-R;
				if(nxt<n)
				{
					int pos=max(L[nxt],R[i]-j+t);
					dp[i][j]=max(dp[i][j],dp[nxt][(R[nxt]-pos)%p]+(R[nxt]-pos)/p);
				}
				if(nxt+1<n) dp[i][j]=max(dp[i][j],A[nxt+1]);
			}
		}
		back=A[i]=max(back,(R[i]-L[i])/p+dp[i][(R[i]-L[i])%p]);
	}
	return back;
}
int main()
{
	scanf("%d %d %d %d",&all,&n,&p,&t);
	int sz=0;
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if(r-l>=p) L[sz]=l,R[sz++]=r;
	}
	n=sz;
	if(n==0)
	{
		puts("0");
		return 0;
	}
	//printf("%d %d\n",solve1(),solve2());return 0;
	if(p<MX) printf("%d\n",solve2());
	else printf("%d\n",solve1());
	return 0;
}