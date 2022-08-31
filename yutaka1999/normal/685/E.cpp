#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1005
#define MX 200005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,P> PP;

vector <PP> vec[MX];
int dist[SIZE][SIZE];
int left[MX],right[MX];
bool ans[MX];

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--,right[i]--;
	}
	for(int i=0;i<q;i++)
	{
		int l,r,s,t;
		scanf("%d %d %d %d",&l,&r,&s,&t);
		l--,r--,s--,t--;
		vec[l].push_back(PP(P(r,i),P(s,t)));
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) dist[i][j]=MX;
		dist[i][i]=0;
	}
	for(int i=m-1;i>=0;i--)
	{
		int l=left[i],r=right[i];
		for(int j=0;j<n;j++)
		{
			dist[l][j]=min(dist[l][j],dist[r][j]);
			dist[r][j]=min(dist[r][j],dist[l][j]);
		}
		dist[l][r]=dist[r][l]=i;
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j].second;
			P q=vec[i][j].first;
			int d=dist[p.first][p.second];
			//printf("%d %d : %d\n",i,q.second,d);
			ans[q.second]=d<=q.first;
		}
	}
	for(int i=0;i<q;i++) puts(ans[i]?"Yes":"No");
	return 0;
}