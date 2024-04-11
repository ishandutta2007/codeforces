#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1000005
#define SQR 1400

using namespace std;
typedef pair <int,int> P;

int to[SIZE];
P pos[SIZE];
vector <P> vec[SQR];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pos[i]=P(x,y);
		vec[x/SQR].push_back(P(y,i));
	}
	vector <int> ans;
	for(int i=0;i<SQR;i++)
	{
		sort(vec[i].begin(),vec[i].end());
		for(int j=0;j<vec[i].size();j++) ans.push_back(vec[i][j].second);
	}
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}