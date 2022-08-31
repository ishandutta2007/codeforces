#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#define INF 1000000000

using namespace std;

vector <int> bk[2];
int rui[105][2];
int all=0;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t,v;
		scanf("%d %d",&t,&v);t--;
		bk[t].push_back(v);
		all+=v;
	}
	sort(bk[0].begin(),bk[0].end(),greater <int>());
	sort(bk[1].begin(),bk[1].end(),greater <int>());
	rui[0][0]=0;rui[0][1]=0;
	for(int i=1;i<=bk[0].size();i++)
	{
		rui[i][0]=bk[0][i-1];
		rui[i][0]+=rui[i-1][0];
	}
	for(int i=1;i<=bk[1].size();i++)
	{
		rui[i][1]=bk[1][i-1];
		rui[i][1]+=rui[i-1][1];
	}
	int ret=INF;
	for(int i=0;i<=bk[0].size();i++)
	{
		for(int j=0;j<=bk[1].size();j++)
		{
			int w=1*i+2*j;
			int l=all-(rui[i][0]+rui[j][1]);
			//printf("[%d %d]%d %d\n",i,j,w,l);
			if(w>=l) ret=min(ret,w);
		}
	}
	printf("%d\n",ret);
	return 0;
}