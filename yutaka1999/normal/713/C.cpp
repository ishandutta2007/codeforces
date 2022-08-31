#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 3005
#define LINF 100000000000000000LL

using namespace std;
typedef long long int ll;

vector <int> vx[SIZE];
ll dp[SIZE];
ll nxt[SIZE];
int A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			vx[i].push_back(A[j]+i-j);
		}
		sort(vx[i].begin(),vx[i].end());
		vx[i].erase(unique(vx[i].begin(),vx[i].end()),vx[i].end());
	}
	for(int i=0;i<n;i++)
	{
		int to=0;
		ll mn=LINF;
		for(int j=0;j<vx[i].size();j++)
		{
			int v=vx[i][j];
			if(i==0) nxt[j]=(ll) abs(A[i]-v);
			else
			{
				while(to<vx[i-1].size()&&vx[i-1][to]<v) mn=min(mn,dp[to++]);
				nxt[j]=mn+(ll) abs(A[i]-v);
			}
		}
		for(int j=0;j<vx[i].size();j++) dp[j]=nxt[j];
	}
	ll mn=LINF;
	for(int i=0;i<vx[n-1].size();i++) mn=min(mn,dp[i]);
	printf("%lld\n",mn);
	return 0;
}