#include<cstdio>
#include<vector>

using namespace std;

pair<int,int> P[3000000];
long long r[3000],c[3000];
int a[3000][3000];

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){scanf("%d",&a[i][j]);P[a[i][j]]=make_pair(i,j);}
	}
	long long cnt_ang=0;
	for(int i=1;i<=n*n;i++)
	{
		int x=P[i].first,y=P[i].second;
		cnt_ang+=r[x]*c[y];
		r[x]++,c[y]++;
	}
	long long sum=(long long)n*(n-1)/2*n*(n-1)/2;
	printf("%lld",2*sum-cnt_ang);
}