#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005

using namespace std;
typedef pair <int,int> P;

int T[SIZE];
int cnt[SIZE];
int ans[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&T[i]);
		T[i]--;
	}
	for(int i=0;i<n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		P p=P(-1,-1);
		for(int j=i;j<n;j++)
		{
			cnt[T[j]]++;
			p=max(p,P(cnt[T[j]],-T[j]));
			ans[-p.second]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}