#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define MX 105
#define EPS 1e-10

using namespace std;

double dp[SIZE][MX];
int mx[SIZE],all[SIZE];

/*
all
in
want
want_in
A

(in)C(want_in) * (all-in)C(want-want_in)/(all)C(want)
=in(in-1)...(in-want_in+1)(all-in)...(all-in-want+want_in+1)/all(all-1)...(all-want+1) * want!/want_in!(want-want_in)!
*/
int main()
{
	int n;
	scanf("%d",&n);
	double ret=0.0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&mx[i]);
		all[i]=mx[i];
		dp[i][mx[i]]=1.0;
		ret+=dp[i][0];
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);a--;b--;
		ret-=dp[a][0];
		for(int j=0;j<=mx[a];j++)
		{
			double nw=dp[a][j];dp[a][j]=0.0;
			int f=max(0,j+k-all[a]);
			double d=1.0;
			for(int p=0;p<k-f;p++)
			{
				d*=(double) (all[a]-j-p)/(double) (all[a]-p);
				d*=(double) (k-p)/(double) (p+1);
			}
			for(int p=0;p<f;p++) d*=(double) (j-p)/(double) (all[a]-k+f-p);			
			for(int p=f;p<=min(j,k);p++)
			{
				dp[a][j-p]+=nw*d;
				d*=(double) (j-p)/(double) (all[a]-j-k+p+1);
				d*=(double) (k-p)/(double) (p+1);
			}
		}
		ret+=dp[a][0];
		all[a]-=k;
		all[b]+=k;
		printf("%.10lf\n",ret);
	}
	return 0;
}