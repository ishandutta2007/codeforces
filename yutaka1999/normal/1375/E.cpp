#include <bits/stdc++.h>
#define SIZE 1005
using namespace std;
typedef pair <int,int> P;

int A[SIZE];
P pos[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		pos[i]=P(A[i],i);
	}
	sort(pos,pos+n);
	vector <P> ans;
	for(int i=0;i<n;i++)
	{
		int v=pos[i].second;
		vector <int> vx;
		for(int j=0;j<i;j++)
		{
			int u=pos[j].second;
			if(u>v) vx.push_back(u);
		}
		sort(vx.begin(),vx.end());
		for(int j=(int) vx.size()-1;j>=0;j--) ans.push_back(P(v,vx[j]));
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	return 0;
}