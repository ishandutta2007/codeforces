#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#define SIZE 300005
#define MX 1000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];
int memo[SIZE];
int cl[MX],cr[MX];
int n,k;
ll ans;

void dfs(int l,int r)
{
	int m=(l+r)/2;
	if(m==l) return;
	int s=m-1,t=m;
	int ml=0,mr=0;
	int sl=0,sr=0;
	while(l<=s||t<r)
	{
		if(s<l||(t!=r&&max(ml,A[s])>=max(mr,A[t])))
		{
			mr=max(mr,A[t]);
			sr+=A[t];sr%=k;
			cr[sr]++;
			memo[t]=sr;
			int tg=(k+mr%k-sr)%k;
			ans+=cl[tg];
			t++;
		}
		else
		{
			ml=max(ml,A[s]);
			sl+=A[s];sl%=k;
			cl[sl]++;
			memo[s]=sl;
			int tg=(k+ml%k-sl)%k;
			ans+=cr[tg];
			s--;
		}
	}
	for(int i=l;i<m;i++) cl[memo[i]]--;
	for(int i=m;i<r;i++) cr[memo[i]]--;
	dfs(l,m);
	dfs(m,r);
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	dfs(0,n);
	printf("%I64d\n",ans);
	return 0;
}